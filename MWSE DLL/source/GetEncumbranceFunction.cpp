#include "GetEncumbranceFunction.h"

#include <boost/math/special_functions/round.hpp>

#include "TES3OFFSETS.h"

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
			if (encumbrance_type == kMax) {
				encumbrance = macp->weight_limit.base;
			} else if (encumbrance_type == kBase || encumbrance_type == kCurrent) {
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
							if (encumbrance_type == kBase) {
								encumbrance += CalculateTotal(reference);
							} else {
								encumbrance += CalculateCorrection(reference);
							}
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

double GetEncumbranceFunction::CalculateTotal(
	unsigned char const* const reference)
{
	SearchForEffects(reference);
	double magnitude = 0.0;
	for (EffectsMap::const_iterator it = active_effects_.begin();
		it != active_effects_.end(); ++it) {
		magnitude += it->second.first;
	}
	return magnitude;
}

double GetEncumbranceFunction::CalculateCorrection(
	unsigned char const* const reference)
{
	SearchForEffects(reference);
	double magnitude = 0.0;
	EffectsMap::const_iterator it = active_effects_.begin();
	while (it != active_effects_.end()) {
		EffectsMap::const_iterator current = it;
		EffectsMap::const_iterator next = ++it;
		if (next != active_effects_.end() && current->first == next->first) {
			++it;
			if (current->second.second > next->second.second) {
				magnitude += next->second.first;
			} else {
				magnitude += current->second.first;
			}
		}
	}
	return magnitude;
}

void GetEncumbranceFunction::SearchForEffects(
	unsigned char const* const reference)
{
	TES3REFERENCE const* const npc_reference =
	reinterpret_cast<TES3REFERENCE const* const>(reference);
	// Note: using NPCCopyRecord also works for creatures.
	NPCCopyRecord const* const npc_copy =
		reinterpret_cast<NPCCopyRecord*>(npc_reference->templ);
	entity_name_ = npc_copy->IDStringPtr;
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
	visited_nodes_.clear();
	visited_nodes_.insert(NULL);
	visited_nodes_.insert(leaf);
	active_effects_.clear();
	SearchForEffects(root);
}

void GetEncumbranceFunction::SearchForEffects(SPLLNode const* const node)
{
	if (visited_nodes_.count(node) != 0) return;
	visited_nodes_.insert(node);
	SPLLRecord const* const active_spell = node->spll_record;
	if (active_spell != NULL) {
		float time = 0.0f;
		double magnitude = 0.0;
		for (int effect = 0; effect < 8; effect++) {
			short const effect_id = active_spell->spell->effects[effect].effectId;
			if (effect_id == kBurden || effect_id == kFeather) {
				unsigned long const size = active_spell->effects[effect].size;
				SPLLRecord::ActiveSpell const* const* const active_spells =
					active_spell->effects[effect].active_spells;
				for (unsigned long index = 0; index < size; index++) {
					SPLLRecord::ActiveSpell const* const current_spell =
						active_spells[index];
					if (current_spell != NULL &&
						entity_name_ == current_spell->id) {
						time = current_spell->time;
						if (effect_id == kBurden) {
							// Burden is modified by Magicka Resistance. We
							// must take into account any MR that was active
							// when Burden went into effect.
							if (current_spell->statistic == 0.0f) {
								magnitude -= current_spell->magnitude;
							} else {
								magnitude -= current_spell->magnitude *
									(100.0 - current_spell->statistic) / 100.0;
							}
						} else if (effect_id == kFeather) {
							magnitude += current_spell->magnitude;
						}
					}
				}
			}
		}
		if (magnitude != 0.0) {
			active_effects_.insert(
				std::make_pair(active_spell->id, std::make_pair(magnitude, time)));
		}
	}
	SearchForEffects(node->first);
	SearchForEffects(node->second);
	SearchForEffects(node->third);
}
