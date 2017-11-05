#include "GetEncumbranceFunction.h"

#include <set>
#include <string>

#include <boost/math/special_functions/round.hpp>

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"

bool GetEncumbranceFunction::execute()
{
	enum Encumbrance
	{
		kCurrent = 0,
		kMax = 1,
		kBase = 2
	};
	double encumbrance = -1.0;
	unsigned long record_type;
	unsigned char* reference;
	unsigned char* temp;
	unsigned char* base;
	if (GetTargetData(machine, &reference, &temp, &record_type, &base)
		&& (record_type == NPC || record_type == CREATURE)) {
		MACPRecord const* const macp =
			reinterpret_cast<MACPRecord*>(GetAttachPointer(
			machine, reference, MACHNODE));
		long encumbrance_type;
		long round_result;
		machine.pop(encumbrance_type);
		machine.pop(round_result);
		if (macp != NULL) {
			if (encumbrance_type == kCurrent) {
				encumbrance = macp->weight_limit.current;
			} else if (encumbrance_type == kMax) {
				encumbrance = macp->weight_limit.base;
			} else if (encumbrance_type == kBase) {
				encumbrance = macp->weight_limit.current;
				if (macp->num_active_effects > 0) {
					// first effect is a "dummy" node
					MACPRecord::ActiveEffect* current_effect =
						macp->active_effects->next;
					for (int i = 0; i < macp->num_active_effects; i++) {
						// It's not sufficient to simply read the current
						// magnitude of the effect (ActiveEffect.magnitude) for
						// two reasons: First, it does not take into account
						// any Magicka Resistance active when the effect was
						// applied to the actor (burden is affected by MR,
						// feather is not). Second, when a spell that is
						// already affecting an entity is cast again on that
						// entity, the game applies the effects of both copies
						// for one frame, doubling the effect on encumbrance
						// for that frame.
						if (current_effect->effect_type == kFeather ||
							current_effect->effect_type == kBurden) {
								encumbrance += SearchForEffects(reference);
								break;
						}
						current_effect = current_effect->next;
					}
				}
			}
			// The smallest item weight is 0.01, so round to nearest 0.01.
			if (round_result != 0)
				encumbrance = boost::math::round(encumbrance * 100.0) / 100.0;
		}
	}
	float value = static_cast<float>(encumbrance);
	return (machine.push(value));
}

double GetEncumbranceFunction::SearchForEffects(
	unsigned char const* const reference)
{
	TES3REFERENCE const* const npc_reference =
		reinterpret_cast<TES3REFERENCE const* const>(reference);
	// Note: using NPCCopyRecord also works for creatures.
	NPCCopyRecord const* const npc_copy =
		reinterpret_cast<NPCCopyRecord*>(npc_reference->templ);
	std::string const entity_name = npc_copy->IDStringPtr;
	unsigned long address = 0x7C67DC;
	unsigned long* pointer = reinterpret_cast<unsigned long*>(address);
	address = (*pointer) + 0x70;
	pointer = reinterpret_cast<unsigned long*>(address);
	address = (*pointer) + 0xC;
	pointer = reinterpret_cast<unsigned long*>(address);
	address = *pointer;
	SPLLNode const* const root = reinterpret_cast<SPLLNode*>(address);
	address = 0x7C7C8C;
	pointer = reinterpret_cast<unsigned long*>(address);
	address = *pointer;
	SPLLNode const* const leaf = reinterpret_cast<SPLLNode*>(address);
	std::set<SPLLNode const* const> visited_nodes;
	visited_nodes.insert(NULL);
	visited_nodes.insert(leaf);
	return SearchForEffects(entity_name, root, &visited_nodes);
}

double GetEncumbranceFunction::SearchForEffects(std::string const& entity_name,
	SPLLNode const* const node,
	std::set<SPLLNode const* const>* const visited_nodes)
{
	double magnitude = 0.0;
	if (visited_nodes->count(node) != 0) return magnitude;
	visited_nodes->insert(node);
	SPLLRecord const* const active_spell = node->spll_record;
	if (active_spell != NULL) {
		SPELRecord const* const spell = active_spell->spell;
		for (int effect = 0; effect < 8; effect++) {
			short const effect_id = spell->effects[effect].effectId;
			if (effect_id == kBurden || effect_id == kFeather) {
				unsigned long const size = active_spell->effects[effect].size;
				SPLLRecord::ActiveSpell const* const* const active_spells =
					active_spell->effects[effect].active_spells;
				for (unsigned long index = 0; index < size; index++) {
					SPLLRecord::ActiveSpell const* const current_spell =
						active_spells[index];
					if (current_spell != NULL &&
						entity_name == current_spell->id) {
						if (effect_id == kBurden) {
							// Burden is modified by Magicka Resistance. We
							// must take into account any MR that was active
							// when Burden went into effect.
							magnitude -= current_spell->magnitude *
								(100.0 - current_spell->statistic) / 100.0;
						} else if (effect_id == kFeather) {
							magnitude += current_spell->magnitude;
						}
					}
				}
			}
		}
	}
	magnitude += SearchForEffects(entity_name, node->first,	visited_nodes);
	magnitude += SearchForEffects(entity_name, node->second, visited_nodes);
	magnitude += SearchForEffects(entity_name, node->third,	visited_nodes);
	return magnitude;
}
