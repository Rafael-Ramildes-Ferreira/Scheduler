#include "SchedulerClass.h"


/* RMS Scheduler methods -----------------------------------------------------*/
int RMSScheduler::swap_context(void){
	if(ready_list.empty()){
		return -1;	// Error
	}

	// Save the context object
	AbstractContex running_contex;
	std::copy(get_cpu_core()[0]->get_context(),&running_contex);

	// Pop next process from the ready list
	Process *next_to_run = ready_list.front();
	ready_list.erase(ready_list.begin());

	// Swaps Running process with next process
	RMSScheduler::add_to_ready(running_process);
	running_process = next_to_run;

	// Loads the next contex
	std::copy(running_process->get_contex(),&running_contex);
	get_cpu_core()[0]->set_context(&running_contex);
	
	return 0; // No error
}

int RMSScheduler::add_to_ready(Process* process){
	return 0;
}

unsigned int RMSScheduler::get_time_quanta(){
	return time_quanta;
}

int RMSScheduler::set_time_quanta(int quanta){
	time_quanta = quanta;

	return 0; // No error
}

std::vector<Process*> RMSScheduler::get_ready_list(){
	return ready_list;
}

int RMSScheduler::set_ready_list(std::vector<Process*> process_vec){
	ready_list = process_vec;

	return 0; // No error
}

Process* RMSScheduler::get_running_process(){
	return running_process;
}

int RMSScheduler::set_running_process(Process* process){
	running_process = process;

	return 0; // No error
}

std::vector<ProcessorCore*> RMSScheduler::get_cpu_core(){
	return cpu_core;
}

int RMSScheduler::set_cpu_core(std::vector<ProcessorCore*> core_vec){
	cpu_core = core_vec;

	return 0; // No error
}


/* EDF Scheduler methods -----------------------------------------------------*/
int EDFScheduler::swap_context(){
	if(ready_list.empty()){
		return -1;	// Error
	}

	// Save the context object
	AbstractContex running_contex;
	std::copy(get_cpu_core()[0]->get_context(),&running_contex);

	// Pop next process from the ready list
	Process *next_to_run = ready_list.front();
	ready_list.erase(ready_list.begin());

	// Swaps Running process with next process
	EDFScheduler::add_to_ready(running_process);
	running_process = next_to_run;

	// Loads the next contex
	std::copy(running_process->get_contex(),&running_contex);
	get_cpu_core()[0]->set_context(&running_contex);
	
	return 0; // No error
}

int EDFScheduler::add_to_ready(Process* process){
	return 0; // No error
}

unsigned int EDFScheduler::get_time_quanta(){
	return time_quanta;
}

int EDFScheduler::set_time_quanta(int quanta){
	time_quanta = quanta;

	return 0; // No error
}

std::vector<Process*> EDFScheduler::get_ready_list(){
	return ready_list;
}

int EDFScheduler::set_ready_list(std::vector<Process*> process_vec){
	ready_list = process_vec;

	return 0; // No error
}

Process* EDFScheduler::get_running_process(){
	return running_process;
}

int EDFScheduler::set_running_process(Process* process){
	running_process = process;

	return 0; // No error
}

std::vector<ProcessorCore*> EDFScheduler::get_cpu_core(){
	return cpu_core;
}

int EDFScheduler::set_cpu_core(std::vector<ProcessorCore*> core_vec){
	cpu_core = core_vec;

	return 0; // No error
}