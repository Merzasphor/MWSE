#ifndef MWSE_GETSKILLFUNCTION_H_
#define MWSE_GETSKILLFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class GetSkillFunction : public FUNCTION
{
public:
	GetSkillFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_GETSKILLFUNCTION_H_
