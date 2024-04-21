#ifndef _CONTEXT_CLASS_HPP
#define _CONTEXT_CLASS_HPP

class AbstractContext {
	private:
    unsigned uint64_t sp;
    unsigned uint64_t pc;
	public:
		void setSp(unsigned uint64_t sp_);
		void setPc(unsigned uint64_t pc_);
		unsigned uint64_t getSp(void);
		unsigned uint64_t getPc(void);
};
#endif
