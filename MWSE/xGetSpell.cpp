/************************************************************************
	
	xGetSpell.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetSpell : mwse::InstructionInterface_t
	{
	public:
		xGetSpell();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xGetSpellOpcode = 0x3927;
	static xGetSpell xGetSpellInstance;

	xGetSpell::xGetSpell() : mwse::InstructionInterface_t(xGetSpellOpcode) {}

	void xGetSpell::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetSpell::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwShort_t result = 0;

		// Get spell id from the stack.
		mwseString_t spellId = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xGetSpell: Could not find reference." << std::endl;
			mwse::Stack::getInstance().pushShort(result);
			return 0.0f;
		}
		else if (reference->recordPointer->recordType != RecordTypes::NPC) {
			mwse::log::getLog() << "xGetSpell: Target is not an NPC." << std::endl;
			mwse::Stack::getInstance().pushShort(result);
			return 0.0f;
		}

		NPCBaseRecord_t* npc = reinterpret_cast<NPCCopyRecord_t*>(reference->recordPointer)->baseNPC;
		ListNode_t<SPELRecord_t>* currentNode = npc->spellStart;
		while (currentNode != NULL) {
			SPELRecord_t* spell = currentNode->dataPtr;
			if (strcmp(spell->id, spellId.c_str()) == 0) {
				result = 1;
				break;
			}
			currentNode = currentNode->nextNode;
		}

		mwse::Stack::getInstance().pushShort(result);

		return 0.0f;
	}
}