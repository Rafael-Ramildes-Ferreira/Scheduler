#include <iostream>
#include "FileClass.h"
#include "FeedClass.h"

using namespace std;

/* Program entry point -------------------------------------------------------*/
int main(int argc, char* argv[]){
	// Creates objects
	File file;
	file.read_file();
	Feed rm_feed = *(new Feed(file.get_processes(),RMSCHEDULING));

	// Prints diagram header
	cout << "Tempo\t";
	int i = 0;
	for(Process* p:rm_feed.get_processes()){
		cout << " P" << ++i << " ";
	}
	cout << endl;

	// Runs
	for(int i = 0;i <= 30;i++){
		rm_feed.step_time()
		cout << rm_feed.get_time()-1 << rm_feed.get_time();
		cout << "\t";
		for(Process *p:rm_feed.get_processes()){
			switch(p->get_current_state()){
				case READY:
					cout << " -- ";
					break;
				case EXECUTING:
					cout << " ## ";
					break;
				case CREATED:
				case FINISHED:
					cout << "    ";
					break;
			}
		}
		cout << endl;
	}
	

	return 0;
}
