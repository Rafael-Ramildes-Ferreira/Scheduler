#ifndef _PROCESSCORE_CLASS_HPP
#define _PROCESSCORE_CLASS_HPP
#include "AbstractContext.hpp"


class ProcessCore {
	private:
		Context *context;
	public:
		void setContext(Context *cont_);
		Context* currentContext();
		Context* getOutContext();
};

#endif
