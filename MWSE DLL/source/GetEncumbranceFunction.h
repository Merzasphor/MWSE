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
	double SearchForEffect(Effects const target_effect,
		unsigned char const* const reference);
	double SearchForEffect(Effects const target_effect,
		std::string const& entity_name,
		SPLLNode const* const node,
		std::set<SPLLNode const* const>* const visited_nodes);
};

#endif // MWSE_GETENCUMBRANCEFUNCTION_H_
