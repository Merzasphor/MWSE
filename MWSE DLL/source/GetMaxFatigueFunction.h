#ifndef MWSE_GETMAXFATIGUEFUNCTION_H_
#define MWSE_GETMAXFATIGUEFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class GetMaxFatigueFunction : public FUNCTION
{
public:
	GetMaxFatigueFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_GETMAXFATIGUEFUNCTION_H_