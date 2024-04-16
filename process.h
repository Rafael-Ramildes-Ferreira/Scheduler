#include "context.cpp"

class Process
{

private:
    int creation_time, duration, priority;
    Context *last_context;

public:
    Process(int creation_time, int duration, int priority, Context *last_context);

    ~Process();

    int get_creation_time();

    int get_duration();

    int get_priority();

    Context *get_last_context();

    void set_creation_time(int creation_time);

    void set_duration(int duration);

    void set_priority(int priority);

    void set_last_context(Context *last_context);
};