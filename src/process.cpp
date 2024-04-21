#include "process.h"

Process::Process(int creation_time, int duration, int priority, Context *context)
{
    this->creation_time = creation_time;
    this->duration = duration;
    this->priority = priority;
    this->context = context;
}

Process::~Process()
{
    delete context;
}

int Process::get_creation_time()
{
    return this->creation_time;
}

int Process::get_duration()
{
    return this->duration;
}

int Process::get_priority()
{
    return this->priority;
}

int Process::get_executed_time()
{
    return this->executed_time;
}

ProcessState Process::get_state()
{
    return this->state;
}

Context *Process::get_context()
{
    return this->context;
}

void Process::set_creation_time(int creation_time)
{
    this->creation_time = creation_time;
}

void Process::set_duration(int duration)
{
    this->duration = duration;
}

void Process::set_priority(int priority)
{
    this->priority = priority;
}

void Process::set_context(Context *context)
{
    this->context = context;
}

void Process::increment_executed_time(){
    this->executed_time++;
    if (this->executed_time == 1) {
        this->state = EXECUTING;
    } else if (this->executed_time == duration) {
        this->executed_time = FINISHED;
    }
};
