#include "SchedulerClass.h"


/* RMS Scheduler methods -----------------------------------------------------*/
int RMSScheduler::swap_context(){
	return 0;
}

int RMSScheduler::get_time_quanta(){
	return 0;
}

int RMSScheduler::set_time_quanta(int quanta){
	return 0;
}

// std::vector<Process*> RMSScheduler::get_ready_list(){
// }

int RMSScheduler::set_ready_list(std::vector<Process*> process_vec){
	return 0;
}

Process* RMSScheduler::get_running_process(){
	Process *p;
	return p;
}

int RMSScheduler::set_running_process(Process* process){
	return 0;
}

// std::vector<ProcessorCore*> RMSScheduler::get_cpu_core(){
// }

int RMSScheduler::set_cpu_core(std::vector<ProcessorCore*> core_vec){
	return 0;
}


/* EDF Scheduler methods -----------------------------------------------------*/
int EDFScheduler::swap_context(){
	return 0;
}

int EDFScheduler::get_time_quanta(){
	return 0;
}

int EDFScheduler::set_time_quanta(int quanta){
	return 0;
}

// std::vector<Process*> EDFScheduler::get_ready_list(){
// }

int EDFScheduler::set_ready_list(std::vector<Process*> process_vec){
	return 0;
}

Process* EDFScheduler::get_running_process(){
	Process *p;
	return p;
}

int EDFScheduler::set_running_process(Process* process){
	return 0;
}

// std::vector<ProcessorCore*> EDFScheduler::get_cpu_core(){
// }

int EDFScheduler::set_cpu_core(std::vector<ProcessorCore*> core_vec){
	return 0;
}