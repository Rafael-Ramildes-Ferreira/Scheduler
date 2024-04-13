#include "SchedulerClass.h"


/* RMS Scheduler methods -----------------------------------------------------*/
/**
 * @brief Exchange the current running context to the next one, according to the
 * 		Rate Monotonic algorithm
 * @param core_number: number of the core which contex has to be swiched
 * @returns 0: if successfull
 * 			-1: if failed
*/
int RMSScheduler::swap_context(unsigned int core_number){
	if(ready_list.empty()){
		return -1;	// Error
	}

	// Save the context object
	AbstractContex running_contex;
	std::copy(get_cpu_core()[core_number]->get_context(),&running_contex);

	// Pop next process from the ready list
	Process *next_to_run = ready_list.front();
	ready_list.erase(ready_list.begin());

	// Swaps Running process with next process
	RMSScheduler::add_to_ready(running_process);
	running_process = next_to_run;

	// Loads the next contex
	std::copy(running_process->get_contex(),&running_contex);
	get_cpu_core()[core_number]->set_context(&running_contex);
	
	return 0; // No error
}

/**
 * @brief Adds a Process to the ready list in the appropriated position
 * @param process: The Process descriptor object to be added
 * @returns 0: if successfull
 * 			-1: if failed
*/
int RMSScheduler::add_to_ready(Process* process){
	return 0;
}

/**
 * @brief Gets the time quanta the SO is setup to use
 * @returns time_quanta
*/
unsigned int RMSScheduler::get_time_quanta(){
	return time_quanta;
}

/**
 * @brief Sets a new time quanta for the SO to use
 * @param quanta: Integer representing the time quanta in a time unit
 * @returns 0: if successfull
 * 			-1: if failed
*/
int RMSScheduler::set_time_quanta(int quanta){
	time_quanta = quanta;

	return 0; // No error
}

/**
 * @brief Gets list of ready Process descriptor object has a vector
 * @returns Vector of the Processes in thr ready state
*/
std::vector<Process*> RMSScheduler::get_ready_list(){
	return ready_list;
}

/**
 *  @todo Add the option of adding many processes to the ready list at once
 * as a vector or as a list, or array. Add this options to set_ready list to
*/
/**
 * @todo Clean redy list before saving new Processes in it when set_ready_list is used
*/

/**
 * @brief Sets a new list of ready Processes
 * 		ATENTION: This will erase the previos list!!
 * @param process_vec: Process descriptor object to be added as a vector
 * @returns 0: if successfull
 * 			-1: if failed
*/
int RMSScheduler::set_ready_list(std::vector<Process*> process_vec){
	for(Process* pP : process_vec){
		// Ensures the list is sorted
		RMSScheduler::add_to_ready(pP);
	}

	return 0; // No error
}

/**
 * @brief Gets the currently running process
 * @returns Pointer to Process descriptor object of the currently running Process
*/
Process* RMSScheduler::get_running_process(){
	return running_process;
}

/**
 * @brief Sets a given Process to run
 * @param process: Pointer to the Process descriptor object to be set to run
 * @returns 0: if successfull
 * 			-1: if failed
*/
int RMSScheduler::set_running_process(Process* process){
	running_process = process;

	return 0; // No error
}

/**
 * @brief Gets all CPU registered
 * @return A vector of the CPU descriptor object
*/
std::vector<ProcessorCore*> RMSScheduler::get_cpu_core(){
	return cpu_core;
}

/**
 * @brief Sets a new vector of CPUs
 * @param core_vec: CPUs descriptor object as a vector
 * @returns 0: if successfull
 * 			-1: if failed
*/
int RMSScheduler::set_cpu_core(std::vector<ProcessorCore*> core_vec){
	cpu_core = core_vec;

	return 0; // No error
}


/* EDF Scheduler methods -----------------------------------------------------*/
/**
 * @brief Exchange the current running context to the next one, according to the
 * 		Rate Monotonic algorithm
 * @param core_number: number of the core which contex has to be swiched
 * @returns 0: if successfull
 * 			-1: if failed
*/
int EDFScheduler::swap_context(unsigned int core_number){
	if(ready_list.empty()){
		return -1;	// Error
	}

	// Save the context object
	AbstractContex running_contex;
	std::copy(get_cpu_core()[core_number]->get_context(),&running_contex);

	// Pop next process from the ready list
	Process *next_to_run = ready_list.front();
	ready_list.erase(ready_list.begin());

	// Swaps Running process with next process
	EDFScheduler::add_to_ready(running_process);
	running_process = next_to_run;

	// Loads the next contex
	std::copy(running_process->get_contex(),&running_contex);
	get_cpu_core()[core_number]->set_context(&running_contex);
	
	return 0; // No error
}

/**
 * @brief Adds a Process to the ready list in the appropriated position
 * @param process: The Process descriptor object to be added
 * @returns 0: if successfull
 * 			-1: if failed
*/
int EDFScheduler::add_to_ready(Process* process){
	return 0; // No error
}

/**
 * @brief Gets the time quanta the SO is setup to use
 * @returns time_quanta
*/
unsigned int EDFScheduler::get_time_quanta(){
	return time_quanta;
}

/**
 * @brief Sets a new time quanta for the SO to use
 * @param quanta: Integer representing the time quanta in a time unit
 * @returns 0: if successfull
 * 			-1: if failed
*/
int EDFScheduler::set_time_quanta(int quanta){
	time_quanta = quanta;

	return 0; // No error
}

/**
 * @brief Gets list of ready Process descriptor object has a vector
 * @returns Vector of the Processes in thr ready state
*/
std::vector<Process*> EDFScheduler::get_ready_list(){
	return ready_list;
}

/**
 * @brief Sets a new list of ready Processes
 * 		ATENTION: This will erase the previos list!!
 * @param process_vec: Process descriptor object to be added as a vector
 * @returns 0: if successfull
 * 			-1: if failed
*/
int EDFScheduler::set_ready_list(std::vector<Process*> process_vec){
	for(Process* pP : process_vec){
		// Ensures the list is sorted
		EDFScheduler::add_to_ready(pP);
	}

	return 0; // No error
}

/**
 * @brief Gets the currently running process
 * @returns Pointer to Process descriptor object of the currently running Process
*/
Process* EDFScheduler::get_running_process(){
	return running_process;
}

/**
 * @brief Sets a given Process to run
 * @param process: Pointer to the Process descriptor object to be set to run
 * @returns 0: if successfull
 * 			-1: if failed
*/
int EDFScheduler::set_running_process(Process* process){
	running_process = process;

	return 0; // No error
}

/**
 * @brief Gets all CPU registered
 * @return A vector of the CPU descriptor object
*/
std::vector<ProcessorCore*> EDFScheduler::get_cpu_core(){
	return cpu_core;
}

/**
 * @brief Sets a new vector of CPUs
 * @param core_vec: CPUs descriptor object as a vector
 * @returns 0: if successfull
 * 			-1: if failed
*/
int EDFScheduler::set_cpu_core(std::vector<ProcessorCore*> core_vec){
	cpu_core = core_vec;

	return 0; // No error
}