#ifndef MWSE_GETGSSTRINGFUNCTION_H_
#define MWSE_GETGSSTRINGFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class GetGsStringFunction : public FUNCTION
{
public:
	GetGsStringFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_GETGSSTRINGFUNCTION_H_