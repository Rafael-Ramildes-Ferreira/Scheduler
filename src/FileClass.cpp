#include <iostream>
#include "FileClass.h"

/* File class methods implementation -----------------------------------------*/
File::File() {
	myfile.open("entrada.txt");
	if (!myfile.is_open()) {
		std::cout << "Erro ao abrir o arquivo!\n";
	}
}

File::~File() {
	for(int i = 0; i < processes.size() ; i++) {
		Process *p = processes[i];
		delete p;
	}
}

void File::print_processes_params() {
	std::vector<Process *>::iterator iter = processes.begin();

	// for(iter; iter < processes.end(); iter++) {
	// 	Process *p = *iter;
	// 	std::cout << *p;
	// }
}

void File::read_file() {
	int a, b, c;
	
	if (!myfile.is_open()) {
		std::cout << "Arquivo não está aberto!" << std::endl;
	}
	
	while (myfile >> a >> b >> c) {
		Process *p = new Process(a, b, c);
		processes.push_back(p);
	}

	std::cout << "Quantidade de processos lidos do arquivo: " << processes.size() << std::endl;
}

std::vector<Process*> File::get_processes(){
	return processes;
}