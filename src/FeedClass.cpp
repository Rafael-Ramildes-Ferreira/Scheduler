#include "FeedClass.h"
#include <iostream>

/**
 * @brief Constructor for the Feed class
 * @param p_vec: Process list
 * @param rule: Desired Scheduler rule from Scheduling_rules defgroup
 * 			RMSCHEDULING: Rate Monotonic
 * 			EDFSCHEDULING: Earliest Deadline First
*/
Feed::Feed(std::list<Process*> p_vec, int rule){
	this->time = 0;
	this->processes = p_vec;
	switch(rule){
		case RMSCHEDULING: this->scheduler = (AbstractScheduler*) &rm_scheduler; break;
		case EDFSCHEDULING:this->scheduler = (AbstractScheduler*) &edf_scheduler; break;
	}
	// this->scheduler->add_cpu_core();
	this->scheduler->set_time_quanta(1);
}

int Feed::step_time(){
	int retval = 0;
	// Feeds newer processes to the scheduler
		// std::cout << "Itering throught the processes" << std::endl;
	for(Process *p: this->processes){
		if(p->get_creation_time() == this->time ||
			p->get_creation_time()+p->get_period() == this->time)
		{
		// std::cout << "Trying to readd process" << std::endl;
			p->set_creation_time(this->time); // Creates the periodicity
			p->set_executed_time(0); // Creates the periodicity
			
			if(!this->scheduler->is_in_ready(p)) scheduler->add_to_ready(p);
			else std::cout << "Eureka!!" << std::endl;
		}
	}

	// Checks the necessity of swaping the context
	// std::cout << "Trying to create process" << std::endl;
	Process *process = this->scheduler->get_running_process();
	if(process == nullptr){
		std::cout << "No running process" << std::endl;
		retval = this->scheduler->swap_context();
		}
	else if(process->get_state() == FINISHED){//} ||
		std::cout << "process->get_state() == FINISHED" << std::endl;
		retval = this->scheduler->swap_context();} 
	else if(this->scheduler->check_first_in_ready()){
		std::cout << "this->scheduler->check_first_in_ready()" << std::endl;
		retval = this->scheduler->swap_context();}
	
			
	
	// Steps time in the program
	process = this->scheduler->get_running_process();
	process->increment_executed_time();

	this->time++;

	return retval;
}

unsigned int Feed::get_time(){
	return this->time;
}

int Feed::set_time(int t){
	this->time = t;

	return 0;	// No error
}

std::list<Process*> Feed::get_processes(){
	return this->processes;
}

int Feed::set_processes(std::list<Process*> p_vec){
	this->processes = p_vec;

	return 0;	// No error
}

AbstractScheduler* Feed::get_scheduler(){
	return (AbstractScheduler*) this->scheduler;
}

int Feed::set_scheduler(AbstractScheduler *s){
	this->scheduler = (AbstractScheduler*) s;

	return 0;	//No error
}

