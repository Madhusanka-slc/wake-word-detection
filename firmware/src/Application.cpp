#include <Arduino.h>
#include "Application.h"
#include "state_machine/DetectWakeWordState.h"

// Flag to trigger servo movement
volatile bool moveServoFlag = false;

Application::Application(I2SSampler *sample_provider)
{
    // Detect wake word state
    m_detect_wake_word_state = new DetectWakeWordState(sample_provider);
    m_current_state = m_detect_wake_word_state;
    m_current_state->enterState();

    // Initialize LED
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
}

void Application::run()
{
    bool wake_detected = m_current_state->run();

    if (wake_detected)
    {
        // Blink LED
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_BUILTIN, LOW);

        // Move servo
        moveServoFlag = true;
    }

    vTaskDelay(10);
}
