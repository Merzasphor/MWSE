#ifndef MWSE_GETENCUMBRANCEFUNCTION_H_
#define MWSE_GETENCUMBRANCEFUNCTION_H_

#include <map>
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
	std::set<const SPLLNode*> visited_nodes_;
	typedef std::multimap<std::string const,
		std::pair<double const, float const> const> EffectsMap;
	EffectsMap active_effects_;
	std::string entity_name_;
	void SearchForEffects(unsigned char const* const reference);
	void SearchForEffects(SPLLNode const* const node);
	double CalculateTotal(unsigned char const* const reference);
	double CalculateCorrection(unsigned char const* const reference);
};

#endif // MWSE_GETENCUMBRANCEFUNCTION_H_
