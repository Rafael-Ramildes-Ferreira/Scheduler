#ifndef _SCHEDULER_CLASS_H
#define _SCHEDULER_CLASS_H

#include <vector>

/**
 * @brief Defines basic structure for a Scheduler class
*/
class AbstractScheduler {
	public:
		AbstractScheduler(unsigned int quanta, unsigned int core_n);
		~AbstractScheduler();
		virtual int add_to_ready(Process* process);
		int swap_context(unsigned int core_number);
		unsigned int get_time_quanta(void);
		int set_time_quanta(int quanta);
		std::vector<Process*> get_ready_list(void);
		int set_ready_list(std::vector<Process*> process_vec);
		Process* get_running_process(void);
		int set_running_process(Process* process);
		std::vector<ProcessorCore*> get_cpu_core(void);
		int set_cpu_core(std::vector<ProcessorCore*> core_vec);

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
		int add_to_ready(Process* process) override;
};

/**
 * @brief Declares all functions of a class to describe a Earliest Deadline First Scheduler
*/
class EDFScheduler : public AbstractScheduler {
	public:
		int add_to_ready(Process* process) override;
};

#endif