#ifndef MWSE_GETENCUMBRANCEFUNCTION_H_
#define MWSE_GETENCUMBRANCEFUNCTION_H_

#include <set>

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
	double SearchForEffects(unsigned char const* const reference);
	double SearchForEffects(std::string const& entity_name,
		SPLLNode const* const node,
		std::set<SPLLNode const* const>* const visited_nodes);
};

#endif // MWSE_GETENCUMBRANCEFUNCTION_H_
