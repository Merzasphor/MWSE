#ifndef MWSE_SETSKILLINFOFUNCTION_H_
#define MWSE_SETSKILLINFOFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class SetSkillInfoFunction : public FUNCTION
{
public:
	SetSkillInfoFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_SETSKILLINFOFUNCTION_H_