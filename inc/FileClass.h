#ifndef _FILECLASS_H
#define _FILECLASS_H

#include <vector>
#include <fstream>
#include "SchedulerClass.h" // Temporary


/**
 * @brief Class implementing file reading and interpretation
*/
class File{
	public:
		File();	
		void read_file();
		void print_processes_params();
		~File();
		std::vector<Process*> get_processes();

	private:
		std::ifstream myfile; 
		std::vector<Process*> processes;
};

#endif