#ifndef MWSE_GETMAXMAGICKAFUNCTION_H_
#define MWSE_GETMAXMAGICKAFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class GetMaxMagickaFunction : public FUNCTION
{
public:
	GetMaxMagickaFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_GETMAXMAGICKAFUNCTION_H_