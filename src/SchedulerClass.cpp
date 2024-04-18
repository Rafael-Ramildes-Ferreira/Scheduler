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
 * @brief Gets list of ready Process descriptor object has a vector
 * @returns Vector of the Processes in thr ready state
*/
std::vector<Process*> AbstractScheduler::get_ready_list(){
	return this->ready_list;
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
int AbstractScheduler::set_ready_list(std::vector<Process*> process_vec){
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
 * @return A vector of the CPU descriptor object
*/
std::vector<ProcessorCore*> AbstractScheduler::get_cpu_core(){
	return this->cpu_core;
}

/**
 * @brief Sets a new vector of CPUs
 * @param core_vec: CPUs descriptor object as a vector
 * @returns 0: if successfull
 * 			-1: if failed
*/
int AbstractScheduler::set_cpu_core(std::vector<ProcessorCore*> core_vec){
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
	/**
	 * @todo ATTENTION: This should be changed to implement the scheduling
	 * algorithm, keeping the list sorted
	*/
	for(Process *pP: this->ready_list)
		this->ready_list.push_back(pP);

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
	return 0; // No error
}