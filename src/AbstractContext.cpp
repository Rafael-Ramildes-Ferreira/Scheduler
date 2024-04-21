#include "AbstractContext.hpp"
#include <stdint>

void AbstractContext::setSp(unsigned uint64_t sp_){
	sp = sp_;
}
void AbstractContext::setPc(unsigned uint64_t pc_){
	pc = pc_;
}
unsigned uint64_t AbstractContext::getSp(void){
	return sp;
}
unsigned uint64_t AbstractContext::getPc(void){
	return pc;
}
	
