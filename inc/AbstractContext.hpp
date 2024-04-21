#ifndef _CONTEXT_CLASS_HPP
#define _CONTEXT_CLASS_HPP
#include <stdint.h>

class AbstractContext {
	private:
    	uint64_t sp;
    	uint64_t pc;
	public:
		void setSp(uint64_t sp_);
		void setPc(uint64_t pc_);
		uint64_t getSp(void);
		uint64_t getPc(void);
};
#endif
