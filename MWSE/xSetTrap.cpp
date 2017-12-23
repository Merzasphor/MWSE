/************************************************************************
	
	xSetTrap.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetTrap : mwse::InstructionInterface_t
	{
	public:
		xSetTrap();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xSetTrapOpcode = 0x3920;
	static xSetTrap xSetTrapInstance;

	xSetTrap::xSetTrap() : mwse::InstructionInterface_t(xSetTrapOpcode) {}

	void xSetTrap::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetTrap::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwseString_t spellId = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Get the spell based on the ID given.
		SPELRecord_t* spell = tes3::getSpellRecordById(spellId);
		if (!spell) {
			log::getLog() << "xSetTrap: No spell could be found with id '" << spellId << "'." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get reference to what we're finding the lock level of.
		REFRRecord_t* reference = virtualMachine.getReference();
		RecordTypes::recordType_t type = reference->recordPointer->recordType;
		if (type != RecordTypes::CONTAINER && type != RecordTypes::DOOR) {
			log::getLog() << "xSetTrap: Called on a non-container, non-door reference." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get attached lock node.
		mwLockNode_t* lockNode = tes3::getAttachedLockNode(reference);
		if (!lockNode) {
			log::getLog() << "xSetTrap: Could not obtain lock node." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Set the new reference.
		lockNode->trapSpell = spell;

		// Return success.
		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}