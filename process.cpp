#include "context.cpp"
#include "process.h"

Process::Process(int creation_time, int duration, int priority, Context *last_context)
{
    this->creation_time = creation_time;
    this->duration = duration;
    this->priority = priority;
    this->last_context = last_context;
}

Process::~Process()
{
    delete last_context;
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

Context *Process::get_last_context()
{
    return this->last_context;
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

void Process::set_last_context(Context *last_context)
{
    this->last_context = last_context;
}