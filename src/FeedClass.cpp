#include "FeedClass.h"

/**
 * @brief Constructor for the Feed class
 * @param p_vec: Process vector
 * @param rule: Desired Scheduler rule from Scheduling_rules defgroup
 * 			RMSCHEDULING: Rate Monotonic
 * 			EDFSCHEDULING: Earliest Deadline First
*/
Feed::Feed(std::vector<Process*> p_vec, int rule){
	time = 0;
	processes = p_vec;
	// scheduler = (rule)?(AbstractScheduler*) new EDFScheduler(1,1):(AbstractScheduler*) new RMSScheduler(1,1);
	switch(rule){
		case RMSCHEDULING: scheduler = (AbstractScheduler*) &rm_scheduler; break;
		case EDFSCHEDULING: scheduler = (AbstractScheduler*) &edf_scheduler; break;
	}
}

int Feed::step_time(){
	// Feeds newer processes to the scheduler
	for(Process *p: processes){
		if(p->get_start_time() == time){
			scheduler.add_to_ready(p);
		}
	}

	// Checks the necessity of swaping the context
	Process *process = scheduler.get_running_process();
	if(process == nullptr)
		if(scheduler.swap_context(0) == -1)
			return -1;
	else if(process->get_time_run()==process->get_duration())
		if(scheduler.swap_context(0) == -1)
			return -1;
	
	// Steps time in the program
	process->run();

	time++;

	return 0;	// No error
}

unsigned int Feed::get_time(){
	return time;
}

int Feed::set_time(int t){
	time = t;

	return 0;	// No error
}

std::vector<Process*> Feed::get_processes(){
	return processes;
}

int Feed::set_processes(std::vector<Process*> p_vec){
	processes = p_vec;

	return 0;	// No error
}

AbstractScheduler* Feed::get_scheduler(){
	return (AbstractScheduler*) scheduler;
}

int Feed::set_scheduler(AbstractScheduler *s){
	scheduler = (AbstractScheduler*) s;

	return 0;	//No error
}

