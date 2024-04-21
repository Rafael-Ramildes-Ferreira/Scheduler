#include "FeedClass.h"

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
	// Feeds newer processes to the scheduler
	for(Process *p: this->processes){
		if(p->get_creation_time() == this->time ||
			p->get_creation_time()+p->get_period() == this->time)
		{
			p->set_creation_time(this->time); // Creates the periodicity
			scheduler->add_to_ready(p);
		}
	}

	// Checks the necessity of swaping the context
	Process *process = this->scheduler->get_running_process();
	if(process == nullptr)
		if(scheduler->swap_context() == -1)
			return -1;
	else if(process->get_state() == FINISHED || this->scheduler->check_first_in_ready())
		if(scheduler->swap_context() == -1)
			return -1;
	
			
	
	// Steps time in the program
	process->increment_executed_time();

	time++;

	return 0;	// No error
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

