#ifndef MWSE_GETMAXHEALTHFUNCTION_H_
#define MWSE_GETMAXHEALTHFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class GetMaxHealthFunction : public FUNCTION
{
public:
	GetMaxHealthFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_GETMAXHEALTHFUNCTION_H_
