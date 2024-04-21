#include "ProcessorCore.hpp"
#include "AbstractContext.hpp"

void ProcessCore::setContext(AbstractContext *cont_){
	context = &cont_;
	
}
Context* ProcessCore::currentContext(){
	return &context;
}
Context* ProcessCore::getOutContext(){
	Context *contxt = &context;
	return &contxt;
}
