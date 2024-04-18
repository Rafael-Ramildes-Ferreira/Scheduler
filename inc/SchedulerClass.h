#ifndef _SCHEDULER_CLASS_H
#define _SCHEDULER_CLASS_H

#include <vector>

class Process{};
class ProcessorCore{};
class AbstractContex{};

/**
 * @brief Defines basic structure for a Scheduler class
*/
class AbstractScheduler {
	public:
		AbstractScheduler(unsigned int quanta, unsigned int core_n);
		AbstractScheduler();
		~AbstractScheduler();
		virtual int add_to_ready(Process* process) { return 0; };
		int swap_context(unsigned int core_number);
		unsigned int get_time_quanta(void);
		int set_time_quanta(int quanta);
		std::vector<Process*> get_ready_list(void);
		int set_ready_list(std::vector<Process*> process_vec);
		Process* get_running_process(void);
		int set_running_process(Process* process);
		std::vector<ProcessorCore*> get_cpu_core(void);
		int set_cpu_core(std::vector<ProcessorCore*> core_vec);
		int add_cpu_core();

	private:
		unsigned int time_quanta;
		std::vector<Process*> ready_list;
		Process* running_process;
		std::vector<ProcessorCore*> cpu_core;
};

/**
 * @brief Declares all functions of a class to describe a Rate Monotonic Scheduler
*/
class RMSScheduler : public AbstractScheduler {
	public:
		RMSScheduler(unsigned int quanta, unsigned int core_n) : AbstractScheduler(quanta,core_n) {};
		RMSScheduler();
		int add_to_ready(Process* process) override;

	private:
		unsigned int time_quanta;
		std::vector<Process*> ready_list;
		Process* running_process;
		std::vector<ProcessorCore*> cpu_core;
};

/**
 * @brief Declares all functions of a class to describe a Earliest Deadline First Scheduler
*/
class EDFScheduler : public AbstractScheduler {
	public:
		EDFScheduler(unsigned int quanta, unsigned int core_n) : AbstractScheduler(quanta,core_n) {};
		EDFScheduler();
		int add_to_ready(Process* process) override;

	private:
		unsigned int time_quanta;
		std::vector<Process*> ready_list;
		Process* running_process;
		std::vector<ProcessorCore*> cpu_core;
};

#endif