/************************************************************************
	
	xCreateSpell.cpp - Copyright (c) 2008 The MWSE Project
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
			mwse::log::getLog() << "xCreateSpell: Spell id length of '" << spellId << "' is invalid. Must be 31 characters of less." << std::endl;
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Verify spell Id length.
		if (spellName.length() > 31) {
			mwse::log::getLog() << "xCreateSpell: Spell name length of '" << spellName << "' is invalid. Must be 31 characters of less." << std::endl;
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}
		
		// Verify that a spell of this id doesn't already exist.
		if (tes3::getSpellRecordById(spellId) != NULL) {
			mwse::log::getLog() << "xCreateSpell: A spell of the given id '" << spellId << "' already exists." << std::endl;
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get spell list.
		LinkedList_t<SPELRecord_t>* spellsList = tes3::getCellMaster()->recordLists->spellsList;
		SPELRecord_t* spellListTail = spellsList->tail;

		// Create new spell.
		SPELRecord_t* newSpell = reinterpret_cast<SPELRecord_t*>(tes3::malloc(sizeof(SPELRecord_t)));
		memset(newSpell, 0, sizeof(SPELRecord_t));
		newSpell->vTable = spellListTail->vTable;
		newSpell->recordType = RecordTypes::SPELL;
		newSpell->spellsList = spellsList;
		newSpell->cost = 1;

		// Set ID.
		newSpell->id = reinterpret_cast<char*>(tes3::malloc(spellId.length() + 1));
		strcpy(newSpell->id, spellId.c_str());

		// Set name.
		newSpell->friendlyName = reinterpret_cast<char*>(tes3::malloc(spellName.length() + 1));
		strcpy(newSpell->friendlyName, spellName.c_str());

		// Set effects.
		for (int i = 0; i < 8; i++) {
			newSpell->effects[i].effectId = Effects::NoEffect;
		}
		
		// Set the first effect just so that there is something? TODO: Why?
		tes3::setEffect(newSpell->effects, 1, Effects::WaterBreathing, mwse::NoSkill, Effects::RangeSelf, 0, 1, 0, 0);

		// Add object to the game.
		tes3::addObject(reinterpret_cast<BaseRecord_t*>(newSpell));

		Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}