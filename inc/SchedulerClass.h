#ifndef _SCHEDULER_CLASS_H
#define _SCHEDULER_CLASS_H

#include <list>
#include "process.h"

class ProcessorCore{};

/**
 * @brief Defines basic structure for a Scheduler class
*/
class AbstractScheduler {
	public:
		AbstractScheduler(unsigned int quanta, unsigned int core_n);
		AbstractScheduler();
		~AbstractScheduler();
		virtual int add_to_ready(Process* process) { return 0; };
		int swap_context();
		virtual bool check_first_in_ready() { return false;};
		unsigned int get_time_quanta(void);
		int set_time_quanta(int quanta);
		std::list<Process*> get_ready_list(void);
		int set_ready_list(std::list<Process*> process_vec);
		Process* get_running_process(void);
		int set_running_process(Process* process);
		ProcessorCore* get_cpu_core(void);
		int set_cpu_core(ProcessorCore* core_vec);

	private:
		unsigned int time_quanta;
		std::list<Process*> ready_list;
		Process* running_process;
		ProcessorCore* cpu_core;
};

/**
 * @brief Declares all functions of a class to describe a Rate Monotonic Scheduler
*/
class RMScheduler : public AbstractScheduler {
	public:
		RMScheduler(unsigned int quanta, unsigned int core_n) : AbstractScheduler(quanta,core_n) {};
		RMScheduler();
		int add_to_ready(Process* process) override;
		bool check_first_in_ready() override;

	private:
		unsigned int time_quanta;
		std::list<Process*> ready_list;
		Process* running_process;
		ProcessorCore* cpu_core;
};

/**
 * @brief Declares all functions of a class to describe a Earliest Deadline First Scheduler
*/
class EDFScheduler : public AbstractScheduler {
	public:
		EDFScheduler(unsigned int quanta, unsigned int core_n) : AbstractScheduler(quanta,core_n) {};
		EDFScheduler();
		int add_to_ready(Process* process) override;
		bool check_first_in_ready() override;

	private:
		unsigned int time_quanta;
		std::list<Process*> ready_list;
		Process* running_process;
		ProcessorCore* cpu_core;
};

#endif