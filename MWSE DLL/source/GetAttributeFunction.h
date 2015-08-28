#ifndef MWSE_GETATTRIBUTEFUNCTION_H_
#define MWSE_GETATTRIBUTEFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class GetAttributeFunction : public FUNCTION
{
public:
	GetAttributeFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_GETATTRIBUTEFUNCTION_H_
