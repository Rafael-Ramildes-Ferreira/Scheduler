enum ProcessState {CREATED, EXECUTING, FINISHED};

class Process
{

private:
    int creation_time, duration, priority, executed_time = 0;
    ProcessState state = CREATED;
    Context *context;

public:
    Process(int creation_time, int duration, int priority, Context *context);

    ~Process();

    int get_creation_time();

    int get_duration();

    int get_priority();

    int get_executed_time();

    ProcessState get_state();

    Context *get_context();

    void set_creation_time(int creation_time);

    void set_duration(int duration);

    void set_priority(int priority);

    void set_context(Context *context);

    void increment_executed_time();

};