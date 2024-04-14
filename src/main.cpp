#include <iostream>
#include <fstream>
#include "SchedulerClass.h"

using namespace std;

/* Class declaration ---------------------------------------------------------*/
class File{
	public:
		File();	
		void read_file();
		void print_processes_params();
		~File();
		vector<Process *> get_processes();

	private:
		ifstream myfile; 
		vector<Process *> processes;
};

/* Program entry point -------------------------------------------------------*/
int main(int argc, char* argv[]){
	RMSScheduler scheduler = new RMSScheduler(1,1);
	return 0;
}


/* File class methods implementation -----------------------------------------*/
File::File() {
	myfile.open("entrada.txt");
	if (!myfile.is_open()) {
		cout << "Erro ao abrir o arquivo!\n";
	}
}

File::~File() {
	for(int i = 0; i < processes.size() ; i++) {
		Process *p = processes[i];
		delete p;
	}
}

void File::print_processes_params() {
	vector<Process *>::iterator iter = processes.begin();

	for(iter; iter < processes.end(); iter++) {
		Process *p = *iter;
		cout << *p;
	}
}

void File::read_file() {
	int a, b, c;
	
	if (!myfile.is_open()) {
		cout << "Arquivo não está aberto!" << endl;
	}
	
	while (myfile >> a >> b >> c) {
		Process *p = new Process(a, b, c);
		processes.push_back(p);
	}

	cout << "Quantidade de processos lidos do arquivo: " << processes.size() << endl;
}

int File::get_processes(){
	return processes;
}