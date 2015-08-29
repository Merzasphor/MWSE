#ifndef MWSE_MODATTRIBUTEFUNCTION_H_
#define MWSE_MODATTRIBUTEFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class ModAttributeFunction : public FUNCTION
{
public:
	ModAttributeFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_MODATTRIBUTEFUNCTION_H_
