#ifndef _SCHEDULER_CLASS_H
#define _SCHEDULER_CLASS_H

class AbstractScheduler {
	public:
		virtual int swap_context();
		virtual int get_time_quanta();
		virtual int set_time_quanta(int quanta);
};

#endif