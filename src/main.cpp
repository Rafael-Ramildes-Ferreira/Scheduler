#include <iostream>
#include "FileClass.h"
#include "FeedClass.h"

using namespace std;

/* Program entry point -------------------------------------------------------*/
int main(int argc, char* argv[]){
	// Creates objects
	File file;
	file.read();
	Feed rm_feed = new Feed(file.get_praocesses(),RMSCHEDULING);

	// Prints diagram header

	// Runs
	while (rm_feed.step_time() == 0);
	

	return 0;
}
