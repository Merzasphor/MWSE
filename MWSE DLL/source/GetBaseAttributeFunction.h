#ifndef MWSE_GETBASEATTRIBUTEFUNCTION_H_
#define MWSE_GETBASEATTRIBUTEFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class GetBaseAttributeFunction : public FUNCTION
{
public:
	GetBaseAttributeFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_GETBASEATTRIBUTEFUNCTION_H_
