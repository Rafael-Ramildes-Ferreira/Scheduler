#include "SchedulerClass.h"


/* Abstract Scheduler methods ------------------------------------------------*/
/**
 * @brief AbstractScheduler constructor
 * @param quanta: Time quanta to be used
 * @param core_n: Number os cores in the machine
 * @returns New object
*/
AbstractScheduler::AbstractScheduler(unsigned int quanta, unsigned int core_n){
		this->time_quanta = quanta;
		this->ready_list = {};
		this->running_process = nullptr;
		this->cpu_core = {};
		for(int i = 0;i < core_n;i++)
			this->cpu_core.push_back(new ProcessorCore);
}

/**
 * @brief Constructor with no input, necessary for the feed class, which 
 * automatically creates schedulers
*/
AbstractScheduler::AbstractScheduler(){
		this->time_quanta = 0;
		this->ready_list = {};
		this->running_process = nullptr;
		this->cpu_core = {};
}

/**
 * @brief AbstractScheduler destructor
*/
AbstractScheduler::~AbstractScheduler(){
	delete this->running_process;
}

/**
 * @brief Exchange the current running context to the next one, according to the
 * 		Rate Monotonic algorithm
 * @param core_number: number of the core which contex has to be swiched
 * @returns id: ID of the running process
 * 			-1: if failed
*/
int AbstractScheduler::swap_context(unsigned int core_number){
	if(this->ready_list.empty()){
		return -1;	// Error
	}

	// Save the context object
	if(this->running_process != nullptr){
		if(this->running_process->get_time_run() < this->running_process->get_duration()){
			AbstractContex *running_contex;
			running_contex = this->get_cpu_core()[core_number]->get_context();
			this->running_process->set_last_context(running_contex);
			this->add_to_ready(this->running_process);
		}
	}

	// Pop next process from the ready list
	Process *next_to_run;
	next_to_run = this->ready_list.front();
	this->ready_list.erase(this->ready_list.begin());

	// Save process that will be put to run
	this->running_process = next_to_run;

	// Loads the next contex
	AbstractContex *process_last_context;
	process_last_context = this->running_process->get_last_contex();
	this->get_cpu_core()[core_number]->set_context(process_last_context);
	
	return this->running_process->get_id(); // No error
}

/**
 * @brief Gets the time quanta the SO is setup to use
 * @returns time_quanta
*/
unsigned int AbstractScheduler::get_time_quanta(){
	return this->time_quanta;
}

/**
 * @brief Sets a new time quanta for the SO to use
 * @param quanta: Integer representing the time quanta in a time unit
 * @returns 0: if successfull
 * 			-1: if failed
*/
int AbstractScheduler::set_time_quanta(int quanta){
	this->time_quanta = quanta;

	return 0; // No error
}

/**
 * @brief Gets list of ready Process descriptor object has a list
 * @returns list of the Processes in thr ready state
*/
std::list<Process*> AbstractScheduler::get_ready_list(){
	return this->ready_list;
}

/**
 *  @todo Add the option of adding many processes to the ready list at once
 * as a list or as a list, or array. Add this options to set_ready list to
*/
/**
 * @todo Clean redy list before saving new Processes in it when set_ready_list is used
*/

/**
 * @brief Sets a new list of ready Processes
 * 		ATENTION: This will erase the previos list!!
 * @param process_vec: Process descriptor object to be added as a list
 * @returns 0: if successfull
 * 			-1: if failed
*/
int AbstractScheduler::set_ready_list(std::list<Process*> process_vec){
	for(Process* pP : process_vec){
		// Ensures the list is sorted
		this->add_to_ready(pP);
	}

	return 0; // No error
}

/**
 * @brief Gets the currently running process
 * @returns Pointer to Process descriptor object of the currently running Process
*/
Process* AbstractScheduler::get_running_process(){
	return this->running_process;
}

/**
 * @brief Sets a given Process to run
 * @param process: Pointer to the Process descriptor object to be set to run
 * @returns 0: if successfull
 * 			-1: if failed
*/
int AbstractScheduler::set_running_process(Process* process){
	this->running_process = process;

	return 0; // No error
}

/**
 * @brief Gets all CPU registered
 * @return A list of the CPU descriptor object
*/
std::list<ProcessorCore*> AbstractScheduler::get_cpu_core(){
	return this->cpu_core;
}

/**
 * @brief Sets a new list of CPUs
 * @param core_vec: CPUs descriptor object as a list
 * @returns 0: if successfull
 * 			-1: if failed
*/
int AbstractScheduler::set_cpu_core(std::list<ProcessorCore*> core_vec){
	this->cpu_core = core_vec;

	return 0; // No error
}

int AbstractScheduler::add_cpu_core(){
	this->cpu_core.push_back(new ProcessorCore);

	return 0; // No error
}


/* RM Scheduler methods -----------------------------------------------------*/
/**
 * @brief Constructor with no input, necessary for the feed class, which 
 * automatically creates schedulers
*/
RMSScheduler::RMSScheduler(){
	this->time_quanta = 0;
	this->ready_list = {};
	this->running_process = nullptr;
	this->cpu_core = {};
}

/**
 * @brief Adds a Process to the ready list in the appropriated position
 * @param process: The Process descriptor object to be added
 * @returns 0: if successfull
 * 			-1: if failed
*/
int RMSScheduler::add_to_ready(Process* process){
	// Process priority from entrada.txt lines with RM priority
	// Preemptive case
	if(process->get_priority() > this->running_process->get_priority()){
		this->ready_list.push_front(process);
		this->swap_context();
		return 0;
	}

	// Non-preemptive case
	int index = 0;
	for(Process *pP: this->ready_list){
		if(process->get_priority() > pP->get_priority())
			this->ready_list.insert(index, process);
		else index++;
	}

	return 0; // No error
}


/* EDF Scheduler methods -----------------------------------------------------*/
/**
 * @brief Constructor with no input, necessary for the feed class, which 
 * automatically creates schedulers
*/
EDFScheduler::EDFScheduler(){
	this->time_quanta = 0;
	this->ready_list = {};
	this->running_process = nullptr;
	this->cpu_core = {};
}

/**
 * @brief Adds a Process to the ready list in the appropriated position
 * @param process: The Process descriptor object to be added
 * @returns 0: if successfull
 * 			-1: if failed
*/
int EDFScheduler::add_to_ready(Process* process){
	int newbie_deadline = process->get_creation_time() + process->get_period();
	int deadline = this->running_process->get_creation_time() \
					+ this->running_process->get_period();

	// Preemptive case
	if(newbie_deadline < deadline){
		this->ready_list.push_front(process);
		this->swap_context();
		return 0;
	}

	// Non-preemptive case
	int index = 0;
	for(Process *pP: this->get_ready_list()){
		deadline = pP->get_creation_time() + pP->get_period();
		if(newbie_deadline < deadline)
			this->ready_list().insert(index,Process);
		else index++;
	}
	return 0; // No error
}