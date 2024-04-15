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
	while (rm_feed.step_time() == 0);
	

	return 0;
}
