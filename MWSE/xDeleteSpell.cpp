/************************************************************************

xDeleteSpell.cpp - Copyright (c) 2008 The MWSE Project
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
	class xDeleteSpell : mwse::InstructionInterface_t
	{
	public:
		xDeleteSpell();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xDeleteSpellOpcode = 0x394A;
	static xDeleteSpell xDeleteSpellInstance;

	xDeleteSpell::xDeleteSpell() : mwse::InstructionInterface_t(xDeleteSpellOpcode) {}

	void xDeleteSpell::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xDeleteSpell::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwLong_t id = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Get spell.
		SPELRecord_t* spell = tes3::getSpellRecordById(id);
		if (spell == NULL) {
			mwse::log::getLog() << "xDeleteSpell: No spell found with id '" << id << "'." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Manipulate the record list to remove this object.
		LinkedList_t<SPELRecord_t>* spellsList = tes3::getCellMaster()->recordLists->spellsList;
		if (spell == spellsList->head) {
			spell->nextRecord->prevRecord = NULL;
			spellsList->head = spell->nextRecord;
		}
		else if (spell == spellsList->tail) {
			spell->prevRecord->nextRecord = NULL;
			spellsList->tail = spell->prevRecord;
		}
		else {
			SPELRecord_t* nextSpell = spell->nextRecord;
			SPELRecord_t* previousSpell = spell->prevRecord;
			spell->nextRecord->prevRecord = previousSpell;
			previousSpell->nextRecord = spell->nextRecord;
		}
		spellsList->size--;

		// Delete the spell from memory.
		delete spell->friendlyName;
		delete spell->id;
		delete spell;

		/*
			TODO: Calling AddSpell on a deleted spell does not cause an error. There
			must be some other data structure that should be updated when deleting a
			spell.
		*/

		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}