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

	static xSetTrap xSetTrapInstance;

	xSetTrap::xSetTrap() : mwse::InstructionInterface_t(OpCode::xSetTrap) {}

	void xSetTrap::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetTrap::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwLong spellId = mwse::Stack::getInstance().popLong();

		// Get reference to what we're finding the trap of.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetTrap: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Verify record type.
		TES3::ObjectType::ObjectType type = reference->objectPointer->objectType;
		if (type != TES3::ObjectType::CONTAINER && type != TES3::ObjectType::DOOR) {
#if _DEBUG
			log::getLog() << "xSetTrap: Called on a non-container, non-door reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get attached lock node.
		mwLockNode_t* lockNode = tes3::getAttachedLockNode(reference);
		if (!lockNode) {
#if _DEBUG
			log::getLog() << "xSetTrap: Could not obtain lock node." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// If we have a spellId, set it. Otherwise we'll clear it.
		TES3::Spell* spell = NULL;
		if (spellId) {
			// Get the spell based on the ID given.
			mwseString_t& spellObjId = virtualMachine.getString(spellId);
			spell = tes3::getSpellRecordById(spellObjId);
			if (!spell) {
#if _DEBUG
				log::getLog() << "xSetTrap: No spell could be found with id '" << spellObjId << "'." << std::endl;
#endif
				mwse::Stack::getInstance().pushLong(false);
				return 0.0f;
			}
		}

		// Set the new reference.
		lockNode->trapSpell = spell;

		// Return success.
		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}