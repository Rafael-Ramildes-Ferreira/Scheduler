#include "Context.hpp"

void Context::inicializa(int idP){
	idProcess = idP;
	ncontext = 0;
	timerun = 0;			
}
void Context::setStart(int st_){
	start = st_;
}
void Context::setEnd(int end_){
	end = end_;
}
void Context::setNcontext(void){
	ncontext = getNc() + 1;
}
void Context::setRunningTime(void){
	timerun = getRunningTime() + (getEnd() - getStart());
}

int Context::getId(void){
	return idProcess;
}
int Context::getStart(void){
	return start;
}
int Context::getEnd(void){
	return end;
}		
int Context::getNc(void){
	return ncontext;
}
int Context::getRunningTime(void){
	return timerun;
}
	
