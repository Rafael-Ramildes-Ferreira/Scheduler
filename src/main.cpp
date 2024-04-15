#include <iostream>
#include <vector>
#include "SchedulerClass.h"
#include "FileClass.h"

using namespace std;

/* Program entry point -------------------------------------------------------*/
int main(int argc, char* argv[]){
	// Creates objects
	RMSScheduler scheduler = new RMSScheduler(1,1);
	File file;
	file.read();
	vector<Process*> all_process = file.get_processes();
	scheduler.set_ready_list(all_process);

	// Prints diagram header

	// Runs
	int swaps = 0, time = 0;
	unsigned int pid = 0;
	while (pid >= 0){
		pid = scheduler.swap_context();
		swaps++;
		
		cout << time << "-" << time+1 << "\t";
		for(Process p: all_process){
			if(p->get_id() == pid){
				cout << " ## ";
			} else if(p->get_creation_time() >= time){
				cout << " -- ";
			} else {
				cout << "    ";
			}
		}
		cout << endl;
		
		time++;
	}
	

	return 0;
}
