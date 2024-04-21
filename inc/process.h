#ifndef _PROCESS_H
#define _PROCESS_H

#include "SchedulerClass.h" // Temporary
// #include "AbstractContext.h"

enum ProcessState {CREATED, READY, EXECUTING, FINISHED};

class AbstractContext{};

class Process
{

private:
    int creation_time, duration, priority, period, executed_time = 0;
    ProcessState state = CREATED;
    AbstractContext *context;

public:
    Process(int creation_time, int duration, int priority, int period, AbstractContext *context);

    ~Process();

    int get_creation_time();

    int get_duration();

    int get_priority();

    int get_period();

    int get_executed_time();

    ProcessState get_state();

    AbstractContext *get_context();

    void set_creation_time(int creation_time);

    void set_duration(int duration);

    void set_priority(int priority);

    void set_period(int priority);

    void set_context(AbstractContext *context);

    void set_state(ProcessState state);

    void increment_executed_time();

};

#endif