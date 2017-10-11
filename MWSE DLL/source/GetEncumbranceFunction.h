#ifndef MWSE_GETENCUMBRANCEFUNCTION_H_
#define MWSE_GETENCUMBRANCEFUNCTION_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class GetEncumbranceFunction : public FUNCTION
{
public:
	GetEncumbranceFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

#endif // MWSE_GETENCUMBRANCEFUNCTION_H_
