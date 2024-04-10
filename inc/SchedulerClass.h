#ifndef _SCHEDULER_CLASS_H
#define _SCHEDULER_CLASS_H

#include <vector>

class Process{};
class ProcessorCore{};

class AbstractScheduler {
	public:
		virtual int swap_context();
		virtual int get_time_quanta(void);
		virtual int set_time_quanta(int quanta);
		virtual std::vector<Process*> get_ready_list(void);
		virtual int set_ready_list(std::vector<Process*> process_vec);
		virtual Process* get_running_process(void);
		virtual int set_running_process(Process* process);
		virtual std::vector<ProcessorCore*> get_cpu_core(void);
		virtual int set_cpu_core(std::vector<ProcessorCore*> core_vec);
};

class RMSScheduler {
	public:
		int swap_context();
		int get_time_quanta(void);
		int set_time_quanta(int quanta);
		std::vector<Process*> get_ready_list(void);
		int set_ready_list(std::vector<Process*> process_vec);
		Process* get_running_process(void);
		int set_running_process(Process* process);
		std::vector<ProcessorCore*> get_cpu_core(void);
		int set_cpu_core(std::vector<ProcessorCore*> core_vec);

	private:
		int time_quanta;
		std::vector<Process*> ready_list;
		Process* running_process;
		std::vector<ProcessorCore*> cpu_core;
};

class EDFScheduler {
	public:
		int swap_context();
		int get_time_quanta(void);
		int set_time_quanta(int quanta);
		std::vector<Process*> get_ready_list(void);
		int set_ready_list(std::vector<Process*> process_vec);
		Process* get_running_process(void);
		int set_running_process(Process* process);
		std::vector<ProcessorCore*> get_cpu_core(void);
		int set_cpu_core(std::vector<ProcessorCore*> core_vec);

	private:
		int time_quanta;
		std::vector<Process*> ready_list;
		Process* running_process;
		std::vector<ProcessorCore*> cpu_core;
};

#endif