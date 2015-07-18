#ifndef MWSE_GETSKILLINFOFUNCTION_H_
#define MWSE_GETSKILLINFOFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class GetSkillInfoFunction : public FUNCTION
{
public:
	GetSkillInfoFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_GETSKILLINFOFUNCTION_H_
