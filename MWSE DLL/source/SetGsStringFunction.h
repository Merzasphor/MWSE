#ifndef MWSE_SETGSSTRINGFUNCTION_H_
#define MWSE_SETGSSTRINGFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class SetGsStringFunction : public FUNCTION
{
public:
	SetGsStringFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_SETGSSTRINGFUNCTION_H_