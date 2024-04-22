#include "process.h"

Process::Process(int creation_time, int duration, int period, int priority)
{
    this->creation_time = creation_time;
    this->duration = duration;
    this->period = period;
    this->priority = priority;
    this->context = nullptr;
    this->executed_time = 0;
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

int Process::get_period()
{
    return this->period;
}

int Process::get_executed_time()
{
    return this->executed_time;
}

ProcessState Process::get_state()
{
    return this->state;
}

AbstractContext *Process::get_context()
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

void Process::set_period(int period)
{
    this->period = period;
}

void Process::set_context(AbstractContext *context)
{
    this->context = context;
}

void Process::set_state(ProcessState state)
{
    this->state = state;
}

void Process::set_executed_time(int exec_time){
    this->executed_time = exec_time;
}

void Process::increment_executed_time(){
    this->executed_time++;
    if (this->executed_time == this->duration) {
        this->state = FINISHED;
    } else {
        this->state = EXECUTING;
    }
};
