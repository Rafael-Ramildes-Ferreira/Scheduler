#ifndef _CONTEXT_CLASS_HPP
#define _CONTEXT_CLASS_HPP
#include <stdint>
#include "AbstractContext"

class INE5412Context : public AbstractContext {
	private:
    unsigned uint64_t r1;
    unsigned uint64_t r2;
    unsigned uint64_t r3;
    unsigned uint64_t r4;
    unsigned uint64_t r5;
    unsigned uint64_t r0;
	public:
		void setR1(unsigned uint64_t r1_);
		void setR2(unsigned uint64_t r2_);
		void setR3(unsigned uint64_t r3_);
		void setR4(unsigned uint64_t r4_);
		void setR5(unsigned uint64_t r5_);
		void setR0(unsigned uint64_t r0_);
		unsigned uint64_t getR1(void);
		unsigned uint64_t getR2(void);
		unsigned uint64_t getR3(void);
		unsigned uint64_t getR4(void);
		unsigned uint64_t getR5(void);
		unsigned uint64_t getR0(void);
};
#endif
