#ifndef _FEEDCLASS_H
#define _FEEDCLASS_H


#include <vector>
#include "SchedulerClass.h"
// #include "ProcessClass.h"

/**
 * @defgroup Scheduling_rules
*/
#define RMSCHEDULING	0
#define EDFSCHEDULING	1


/**
 * @brief Class responsable to feed new processes to the Scheduler
*/
class Feed{
	public:
		Feed(std::vector<Process*> p_vec, int rule);
		int step_time();
		unsigned int get_time();
		int set_time(int t);
		std::vector<Process*> get_processes();
		int set_processes(std::vector<Process*> p_vec);
		AbstractScheduler* get_scheduler();
		int set_scheduler(AbstractScheduler *s);

	private:
		unsigned int time;
		std::vector<Process*> processes;
		AbstractScheduler *scheduler;
		RMSScheduler rm_scheduler;
		EDFScheduler edf_scheduler;
};

#endif