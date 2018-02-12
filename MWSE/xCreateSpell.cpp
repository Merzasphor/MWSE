/************************************************************************
	
	xCreateSpell.cpp - Copyright (c) 2008 The MWSE Project
	https://github.com/MWSE/MWSE/

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

#include "TES3Collections.h"
#include "TES3CellMaster.h"

using namespace mwse;

namespace mwse
{
	class xCreateSpell : mwse::InstructionInterface_t
	{
	public:
		xCreateSpell();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xCreateSpell xCreateSpellInstance;

	xCreateSpell::xCreateSpell() : mwse::InstructionInterface_t(OpCode::xCreateSpell) {}

	void xCreateSpell::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xCreateSpell::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString_t& spellId = virtualMachine.getString(Stack::getInstance().popLong());
		mwseString_t& spellName = virtualMachine.getString(Stack::getInstance().popLong());

		// Verify spell Id length.
		if (spellId.length() > 31) {
#if _DEBUG
			mwse::log::getLog() << "xCreateSpell: Spell id length of '" << spellId << "' is invalid. Must be 31 characters of less." << std::endl;
#endif
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Verify spell Id length.
		if (spellName.length() > 31) {
#if _DEBUG
			mwse::log::getLog() << "xCreateSpell: Spell name length of '" << spellName << "' is invalid. Must be 31 characters of less." << std::endl;
#endif
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}
		
		// Verify that a spell of this id doesn't already exist.
		if (tes3::getSpellRecordById(spellId) != NULL) {
#if _DEBUG
			mwse::log::getLog() << "xCreateSpell: A spell of the given id '" << spellId << "' already exists." << std::endl;
#endif
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get spell list.
		TES3::LinkedList<TES3::Spell>* spellsList = tes3::getCellMaster()->recordLists->spellsList;
		TES3::Spell* spellListHead = spellsList->head;

		// Create new spell.
		TES3::Spell* newSpell = tes3::malloc<TES3::Spell>();
		memset(newSpell, 0, sizeof(TES3::Spell));
		newSpell->vTable = spellListHead->vTable;
		newSpell->objectType = TES3::ObjectType::Spell;
		newSpell->spellsList = spellsList;
		newSpell->cost = 1;

		// Set ID.
		newSpell->objectID = tes3::malloc<char>(spellId.length() + 1);
		strcpy(newSpell->objectID, spellId.c_str());

		// Set name.
		newSpell->name = tes3::malloc<char>(spellName.length() + 1);
		strcpy(newSpell->name, spellName.c_str());

		// Set effects.
		for (int i = 0; i < 8; i++) {
			newSpell->effects[i].ID = TES3::EffectNone;
		}
		
		// Set the first effect just so that there is something? TODO: Why?
		tes3::setEffect(newSpell->effects, 1, TES3::EffectWaterBreathing, TES3::SkillInvalid, TES3::EffectRangeSelf, 0, 1, 0, 0);

		// Add object to the game.
		tes3::addObject(reinterpret_cast<TES3::BaseObject*>(newSpell));

		Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}