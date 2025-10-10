#ifndef _DETECT_WAKE_WORD_STATE_H_
#define _DETECT_WAKE_WORD_STATE_H_

#include "States.h"

class I2SSampler;
class NeuralNetwork;
class AudioProcessor;

class DetectWakeWordState : public State
{
private:
    I2SSampler* m_sample_provider;
    NeuralNetwork* m_nn;
    AudioProcessor* m_audio_processor;
    float m_average_detect_time;
    int m_number_of_detections;
    int m_number_of_runs;

public:
    explicit DetectWakeWordState(I2SSampler* sample_provider);
    void enterState() override;
    bool run() override;
    void exitState() override;
};

#endif
