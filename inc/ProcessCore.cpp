#include "ProcessCore.hpp"
#include<iostream>
#include <unistd.h>
#include<ctime>
#include "Context.hpp"

void ProcessCore::setContext(Context *cont_){
	int time_begins = time(NULL);
	cont_->setStart(time_begins);
	cont_->setNcontext();
	context = cont_;
	
}
Context* ProcessCore::currentContext(){
	return &context;
}
Context* ProcessCore::getOutContext(){
	Context *contxt = &context;
	int time_ends = time(NULL);
	contxt->setEnd(time_ends)
	return &contxt;
}
