#ifndef MWSE_RANDOMLONGFUNCTION_H_
#define MWSE_RANDOMLONGFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class RandomLongFunction : public FUNCTION
{
public:
	RandomLongFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_RANDOMLONGFUNCTION_H_