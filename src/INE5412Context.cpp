#include "INE5412Context.hpp"
#include <stdint>

void INE5412Context::setR1(unsigned uint64_t r1_){
	r1 = r1_;
}
void INE5412Context::setR2(unsigned uint64_t r2_){
	r2 = r2_;
}
void INE5412Context::setR3(unsigned uint64_t r3_){
	r3 = r3_;
}
void INE5412Context::setR4(unsigned uint64_t r4_){
	r4 = r4_;
}
void INE5412Context::setR5(unsigned uint64_t r5_){
	r5 = r5_;
}
void INE5412Context::setR0(unsigned uint64_t r0_){
	r0 = r0_;
}
unsigned uint64_t INE5412Context::getR1(void){
	return r1;
}
unsigned uint64_t INE5412Context::getR2(void){
	return r2;
}
unsigned uint64_t INE5412Context::getR3(void){
	return r3;
}
unsigned uint64_t INE5412Context::getR4(void){
	return r4;
}
unsigned uint64_t INE5412Context::getR5(void){
	return r5;
}
unsigned uint64_t INE5412Context::getR0(void){
	return r0;
}
