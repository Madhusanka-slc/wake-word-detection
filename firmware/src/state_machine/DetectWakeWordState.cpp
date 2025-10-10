#include <Arduino.h>
#include "I2SSampler.h"
#include "AudioProcessor.h"
#include "NeuralNetwork.h"
#include "RingBuffer.h"
#include "DetectWakeWordState.h"

#define WINDOW_SIZE   320
#define STEP_SIZE     160
#define POOLING_SIZE  6
#define AUDIO_LENGTH  16000

DetectWakeWordState::DetectWakeWordState(I2SSampler* sample_provider)
    : m_sample_provider(sample_provider),
      m_nn(nullptr),
      m_audio_processor(nullptr),
      m_average_detect_time(0.0f),
      m_number_of_detections(0),
      m_number_of_runs(0)
{
}

void DetectWakeWordState::enterState()
{
    // Create our neural network
    m_nn = new NeuralNetwork();
    Serial.println("Created Neural Net");

    // Create our audio processor
    m_audio_processor = new AudioProcessor(AUDIO_LENGTH, WINDOW_SIZE, STEP_SIZE, POOLING_SIZE);
    Serial.println("Created Audio Processor");

    m_number_of_detections = 0;
}

bool DetectWakeWordState::run()
{
    long start = millis();

    // Get access to the samples from the ring buffer
    RingBufferAccessor* reader = m_sample_provider->getRingBufferReader();
    reader->rewind(AUDIO_LENGTH);  // Rewind by 1 second

    // Get neural network input buffer
    float* input_buffer = m_nn->getInputBuffer();

    // Process samples into spectrogram
    m_audio_processor->get_spectrogram(reader, input_buffer);

    // Finished with the sample reader
    delete reader;

    // Get prediction
    float output = m_nn->predict();
    long end = millis();

    // Update stats
    m_average_detect_time = (end - start) * 0.1f + m_average_detect_time * 0.9f;
    m_number_of_runs++;

    // Print prediction probability
    Serial.printf("Prediction #%d: %.4f (threshold: 0.78)\n", m_number_of_runs, output);

    // Log average timing every 100 runs
    if (m_number_of_runs >= 100)
    {
        m_number_of_runs = 0;
        Serial.printf("Average detection time: %.2f ms\n", m_average_detect_time);
    }

    // Detect wake word if output exceeds threshold
    if (output > 0.5)
    {
        m_number_of_detections++;
        if (m_number_of_detections > 1)
        {
            m_number_of_detections = 0;
            Serial.printf("P(%.2f): Wake word detected!\n", output);
            return true;  // Move to next state
        }
    }

    return false;  // Stay in current state
}

void DetectWakeWordState::exitState()
{
    // Clean up
    delete m_nn;
    m_nn = nullptr;

    delete m_audio_processor;
    m_audio_processor = nullptr;

    uint32_t free_ram = esp_get_free_heap_size();
    Serial.printf("Free RAM after DetectWakeWord cleanup: %d\n", free_ram);
}
