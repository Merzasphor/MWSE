#ifndef MWSE_RANDOMFLOATFUNCTION_H_
#define MWSE_RANDOMFLOATFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class RandomFloatFunction : public FUNCTION
{
public:
	RandomFloatFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_RANDOMFLOATFUNCTION_H_
