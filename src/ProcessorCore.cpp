#include "ProcessorCore.hpp"
#include "AbstractContext.hpp"

void ProcessCore::setContext(AbstractContext *cont_){
	context = cont_;
	
}
AbstractContext* ProcessCore::currentContext(){
	return context;
}
AbstractContext* ProcessCore::getOutContext(){
	AbstractContext *contxt = context;
	return contxt;
}
