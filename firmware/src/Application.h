#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "state_machine/States.h"

class I2SSampler;
class State;

class Application
{
private:
    State* m_detect_wake_word_state;
    State* m_current_state;

public:
    // Constructor: initialize application with the sample provider
    explicit Application(I2SSampler* sample_provider);

    // Destructor: clean up dynamically allocated states
    ~Application();

    // Run the current state and process audio samples
    void run();
};

#endif // _APPLICATION_H_
