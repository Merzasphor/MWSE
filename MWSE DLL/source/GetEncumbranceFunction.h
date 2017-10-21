#ifndef MWSE_GETENCUMBRANCEFUNCTION_H_
#define MWSE_GETENCUMBRANCEFUNCTION_H_

#include <set>
#include <string>

#include "FUNCTION.h"
#include "TES3MACHINE.h"
#include "TES3TYPES.h"

class GetEncumbranceFunction : public FUNCTION
{
public:
	GetEncumbranceFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
	std::set<SPLLNode const* const> visited_;
	std::string name_;
	double SearchForBurden(SPLLNode const* const node);
};

#endif // MWSE_GETENCUMBRANCEFUNCTION_H_
