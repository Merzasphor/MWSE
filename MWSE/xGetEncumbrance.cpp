/************************************************************************

	xGetEncumbrance.cpp - Copyright (c) 2008 The MWSE Project
	http://www.sourceforge.net/projects/mwse

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include <map>
#include <set>
#include <string>

using namespace mwse;

namespace mwse
{
	class xGetEncumbrance : mwse::InstructionInterface_t
	{
	public:
		xGetEncumbrance();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);

		enum EncumbranceQueryType {
			CurrentEncumbrance = 0,
			MaxEncumbrance = 1,
			BaseEncumbrance = 2
		};

	private:
		void SearchForEffects(REFRRecord_t* reference);
		void SearchForEffects(SPLLNode_t* node);
		double CalculateTotal(REFRRecord_t* reference);
		double CalculateCorrection(REFRRecord_t* reference);

		// Data storage for current implementation of looping active effects.
		std::set<const SPLLNode_t*> visitedNodes;
		typedef std::multimap<std::string const, std::pair<double const, float const> const> EffectsMap;
		EffectsMap activeEffects;
		std::string entityName;
	};

	static xGetEncumbrance xGetEncumbranceInstance;

	xGetEncumbrance::xGetEncumbrance() : mwse::InstructionInterface_t(OpCode::xGetEncumbrance) {}

	void xGetEncumbrance::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetEncumbrance::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		EncumbranceQueryType queryType = static_cast<EncumbranceQueryType>(mwse::Stack::getInstance().popLong());
		bool roundResult = mwse::Stack::getInstance().popLong();

		// Get reference to target.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xGetEncumbrance: No reference provided." << std::endl;
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		// Get record for reference.
		BaseRecord_t* record = reference->recordPointer;
		if (record == NULL) {
			mwse::log::getLog() << "xGetEncumbrance: No record found for reference." << std::endl;
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		// This function only supports creatures and NPCs.
		if (record->recordType != RecordTypes::NPC && record->recordType != RecordTypes::CREATURE) {
			mwse::log::getLog() << "xGetEncumbrance: Called on unsupported record type " << record->recordType << "." << std::endl;
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		double encumbrance = -999999.0;

		// Get associated MACP node.
		MACPRecord_t* macp = tes3::getAttachedMACPRecord(reference);
		if (macp == NULL) {
			mwse::log::getLog() << "xGetEncumbrance: No associated macp record found for reference." << std::endl;
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		// Get encumbrance.
		if (queryType == MaxEncumbrance) {
			encumbrance = macp->weight_limit.base;
		}
		else if (queryType == BaseEncumbrance || queryType == CurrentEncumbrance) {
			encumbrance = macp->weight_limit.current;
			if (macp->num_active_effects > 0) {
				MACPRecord_t::ActiveEffect* currentEffect = macp->active_effects->next;
				for (int i = 0; i < macp->num_active_effects; i++) {
					if (currentEffect->effect_type == Effects::Burden || currentEffect->effect_type == Effects::Feather) {
						encumbrance += (queryType == BaseEncumbrance) ? CalculateTotal(reference) : CalculateCorrection(reference);
					}

					currentEffect = currentEffect->next;
				}
			}
		}

		// Round result.
		if (roundResult) {
			encumbrance = round(encumbrance * 100.0) / 100.0;
		}

		mwse::Stack::getInstance().pushFloat(encumbrance);

		return 0.0f;
	}

	void xGetEncumbrance::SearchForEffects(REFRRecord_t* reference) {
		NPCCopyRecord_t* npcCopy = reinterpret_cast<NPCCopyRecord_t*>(reference->recordPointer);
		entityName = npcCopy->objectId;

		unsigned long address = 0x7C67DC;
		unsigned long* pointer = reinterpret_cast<unsigned long*>(address);
		address = (*pointer) + 0x70;
		pointer = reinterpret_cast<unsigned long*>(address);
		address = (*pointer) + 0xC;
		pointer = reinterpret_cast<unsigned long*>(address);
		address = *pointer;
		SPLLNode_t* root = reinterpret_cast<SPLLNode_t*>(address);
		address = 0x7C7C8C;
		pointer = reinterpret_cast<unsigned long*>(address);
		address = *pointer;
		SPLLNode_t const* const leaf = reinterpret_cast<SPLLNode_t*>(address);

		visitedNodes.clear();
		visitedNodes.insert(NULL);
		visitedNodes.insert(leaf);
		activeEffects.clear();
		SearchForEffects(root);
	}

	void xGetEncumbrance::SearchForEffects(SPLLNode_t* node) {
		if (visitedNodes.count(node) != 0) return;
		visitedNodes.insert(node);
		SPLLRecord_t* active_spell = node->record;
		if (active_spell != NULL) {
			float time = 0.0f;
			double magnitude = 0.0;
			for (int effect = 0; effect < 8; effect++) {
				short const effect_id = active_spell->spell->effects[effect].effectId;
				if (effect_id == Effects::Burden || effect_id == Effects::Feather) {
					unsigned long const size = active_spell->effects[effect].size;
					SPLLRecord_t::ActiveSpell_t** active_spells = active_spell->effects[effect].activeSpells;
					for (unsigned long index = 0; index < size; index++) {
						SPLLRecord_t::ActiveSpell_t* current_spell = active_spells[index];
						if (current_spell != NULL && entityName == current_spell->id) {
							time = current_spell->time;
							if (effect_id == Effects::Burden) {
								// Burden is modified by Magicka Resistance. We
								// must take into account any MR that was active
								// when Burden went into effect.
								if (current_spell->statistic == 0.0f) {
									magnitude -= current_spell->magnitude;
								}
								else {
									magnitude -= current_spell->magnitude * (100.0 - current_spell->statistic) / 100.0;
								}
							}
							else if (effect_id == Effects::Feather) {
								magnitude += current_spell->magnitude;
							}
						}
					}
				}
			}
			if (magnitude != 0.0) {
				activeEffects.insert(std::make_pair(active_spell->id, std::make_pair(magnitude, time)));
			}
		}
		SearchForEffects(node->first);
		SearchForEffects(node->second);
		SearchForEffects(node->third);
	}

	double xGetEncumbrance::CalculateTotal(REFRRecord_t* reference) {
		SearchForEffects(reference);
		double magnitude = 0.0;
		for (EffectsMap::const_iterator it = activeEffects.begin();
			it != activeEffects.end(); ++it) {
			magnitude += it->second.first;
		}
		return magnitude;
	}

	double xGetEncumbrance::CalculateCorrection(REFRRecord_t* reference) {
		SearchForEffects(reference);
		double magnitude = 0.0;
		EffectsMap::const_iterator it = activeEffects.begin();
		while (it != activeEffects.end()) {
			EffectsMap::const_iterator current = it;
			EffectsMap::const_iterator next = ++it;
			if (next != activeEffects.end() && current->first == next->first) {
				++it;
				if (current->second.second > next->second.second) {
					magnitude += next->second.first;
				}
				else {
					magnitude += current->second.first;
				}
			}
		}
		return magnitude;
	}
}