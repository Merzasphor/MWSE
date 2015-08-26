#ifndef MWSE_SETLEVELFUNCTION_H_
#define MWSE_SETLEVELFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class SetLevelFunction : public FUNCTION
{
public:
	SetLevelFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_SETLEVELFUNCTION_H_
