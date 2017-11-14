#ifndef MWSE_GETRACEFUNCTION_H_
#define MWSE_GETRACEFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class GetRaceFunction : public FUNCTION
{
public:
	GetRaceFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_GETRACEFUNCTION_H_
