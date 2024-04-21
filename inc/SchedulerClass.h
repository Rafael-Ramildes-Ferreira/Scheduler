#ifndef _SCHEDULER_CLASS_H
#define _SCHEDULER_CLASS_H

#include <list>
#include "process.h"
#include "ProcessorCore.hpp"

/**
 * @brief Defines basic structure for a Scheduler class
*/
class AbstractScheduler {
	public:
		AbstractScheduler(unsigned int quanta);
		AbstractScheduler();
		~AbstractScheduler();
		virtual int add_to_ready(Process* process) { return 0; };
		virtual int swap_context();// {return 0;};
		virtual bool check_first_in_ready() { return false;};
		virtual unsigned int get_time_quanta(void);
		virtual int set_time_quanta(int quanta);
		virtual std::list<Process*> get_ready_list(void);
		virtual int set_ready_list(std::list<Process*> process_vec);
		virtual Process* get_running_process(void);
		virtual int set_running_process(Process* process);
		virtual ProcessorCore* get_cpu_core(void);
		virtual int set_cpu_core(ProcessorCore* core_vec);

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
		RMScheduler(unsigned int quanta) : AbstractScheduler(quanta) {};
		RMScheduler();
		int add_to_ready(Process* process) override;
		int swap_context() override;
		bool check_first_in_ready() override;
		unsigned int get_time_quanta(void) override;// : get_time_quanta() {};
		int set_time_quanta(int quanta) override;// : set_time_quanta(quanta) {};
		std::list<Process*> get_ready_list(void) override;// : get_ready_list() {};
		int set_ready_list(std::list<Process*> process_vec) override;// : set_ready_list(process_vec) {};
		Process* get_running_process(void) override;// : get_running_process() {};
		int set_running_process(Process* process) override;// : set_running_process(process) {};
		ProcessorCore* get_cpu_core(void) override;// : get_cpu_core() {};
		int set_cpu_core(ProcessorCore* core_vec) override;// : set_cpu_core(core_vec) {};

	private:
		unsigned int time_quanta;
		std::list<Process*> ready_list;
		Process* running_process;
		ProcessorCore* cpu_core;
};

/**
 * @brief Declares all functions of a class to describe a Earliest Deadline First Scheduler
*/
// class EDFScheduler : public AbstractScheduler {
// 	public:
// 		EDFScheduler(unsigned int quanta) : AbstractScheduler(quanta) {};
// 		EDFScheduler();
// 		int add_to_ready(Process* process) override;
// 		// int swap_context() override { return 0;};
// 		bool check_first_in_ready() override;

// 	private:
// 		unsigned int time_quanta;
// 		std::list<Process*> ready_list;
// 		Process* running_process;
// 		ProcessorCore* cpu_core;
// };

#endif