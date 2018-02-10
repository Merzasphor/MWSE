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

#include "TES3MACP.h"
#include "TES3NPC.h"

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
		void SearchForEffects(TES3::Reference* reference);
		void SearchForEffects(TES3::SPLLNode* node);
		double CalculateTotal(TES3::Reference* reference);
		double CalculateCorrection(TES3::Reference* reference);

		// Data storage for current implementation of looping active effects.
		std::set<const TES3::SPLLNode*> visitedNodes;
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
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetEncumbrance: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		// Get record for reference.
		TES3::BaseObject* record = reference->objectPointer;
		if (record == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetEncumbrance: No record found for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		// This function only supports creatures and NPCs.
		if (record->objectType != TES3::ObjectType::NPC && record->objectType != TES3::ObjectType::Creature) {
#if _DEBUG
			mwse::log::getLog() << "xGetEncumbrance: Called on unsupported record type " << record->objectType << "." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		double encumbrance = -999999.0;

		// Get associated MACP node.
		TES3::MACP* macp = tes3::getAttachedMACPRecord(reference);
		if (macp == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetEncumbrance: No associated macp record found for reference." << std::endl;
#endif
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
				TES3::MACP::ActiveEffect* currentEffect = macp->activeEffects->next;
				for (int i = 0; i < macp->num_active_effects; i++) {
					if (currentEffect->effectType == TES3::EffectBurden || currentEffect->effectType == TES3::EffectFeather) {
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

	void xGetEncumbrance::SearchForEffects(TES3::Reference* reference) {
	TES3::NPCInstance* npcCopy = reinterpret_cast<TES3::NPCInstance*>(reference->objectPointer);
		entityName = npcCopy->objectID;

		unsigned long address = 0x7C67DC;
		unsigned long* pointer = reinterpret_cast<unsigned long*>(address);
		address = (*pointer) + 0x70;
		pointer = reinterpret_cast<unsigned long*>(address);
		address = (*pointer) + 0xC;
		pointer = reinterpret_cast<unsigned long*>(address);
		address = *pointer;
		TES3::SPLLNode* root = reinterpret_cast<TES3::SPLLNode*>(address);
		address = 0x7C7C8C;
		pointer = reinterpret_cast<unsigned long*>(address);
		address = *pointer;
		TES3::SPLLNode const* const leaf = reinterpret_cast<TES3::SPLLNode*>(address);

		visitedNodes.clear();
		visitedNodes.insert(NULL);
		visitedNodes.insert(leaf);
		activeEffects.clear();
		SearchForEffects(root);
	}

	void xGetEncumbrance::SearchForEffects(TES3::SPLLNode* node) {
		if (visitedNodes.count(node) != 0) return;
		visitedNodes.insert(node);
		TES3::SPLL* activeSpell = node->object;
		if (activeSpell != NULL) {
			float time = 0.0f;
			double magnitude = 0.0;
			for (int effect = 0; effect < 8; effect++) {
				short const effect_id = activeSpell->spell->effects[effect].ID;
				if (effect_id == TES3::EffectBurden || effect_id == TES3::EffectFeather) {
					unsigned long const size = activeSpell->effects[effect].size;
					TES3::SPLL::ActiveSpell** activeSpells = activeSpell->effects[effect].activeSpells;
					for (unsigned long index = 0; index < size; index++) {
						TES3::SPLL::ActiveSpell* currentSpell = activeSpells[index];
						if (currentSpell != NULL && entityName == currentSpell->id) {
							time = currentSpell->time;
							if (effect_id == TES3::EffectBurden) {
								// Burden is modified by Magicka Resistance. We
								// must take into account any MR that was active
								// when Burden went into effect.
								if (currentSpell->statistic == 0.0f) {
									magnitude -= currentSpell->magnitude;
								}
								else {
									magnitude -= currentSpell->magnitude * (100.0 - currentSpell->statistic) / 100.0;
								}
							}
							else if (effect_id == TES3::EffectFeather) {
								magnitude += currentSpell->magnitude;
							}
						}
					}
				}
			}
			if (magnitude != 0.0) {
				activeEffects.insert(std::make_pair(activeSpell->id, std::make_pair(magnitude, time)));
			}
		}
		SearchForEffects(node->first);
		SearchForEffects(node->second);
		SearchForEffects(node->third);
	}

	double xGetEncumbrance::CalculateTotal(TES3::Reference* reference) {
		SearchForEffects(reference);
		double magnitude = 0.0;
		for (EffectsMap::const_iterator it = activeEffects.begin();
			it != activeEffects.end(); ++it) {
			magnitude += it->second.first;
		}
		return magnitude;
	}

	double xGetEncumbrance::CalculateCorrection(TES3::Reference* reference) {
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