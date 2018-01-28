/************************************************************************
	
	xSpellList.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSpellList : mwse::InstructionInterface_t
	{
	public:
		xSpellList();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		void pushErrorResponse();
	};

	static xSpellList xSpellListInstance;

	xSpellList::xSpellList() : mwse::InstructionInterface_t(OpCode::xSpellList) {}

	void xSpellList::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSpellList::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get our next node.
		LinkedListNode_t<SPELRecord_t>* node = reinterpret_cast<LinkedListNode_t<SPELRecord_t>*>(mwse::Stack::getInstance().popLong());

		// Arguments we will be returning.
		mwLong_t spellCount = 0;
		mwString_t spellId = NULL;
		mwString_t spellName = NULL;
		mwLong_t spellType = 0;
		mwLong_t spellCost = 0;
		mwLong_t spellEffectCount = 0;
		mwLong_t spellFlags = 0;

		// Get the reference we're checking.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xSpellList: Could not get reference." << std::endl;
			pushErrorResponse();
			return 0.0f;
		}

		// Function only works on NPCs.
		NPCCopyRecord_t* npcCopyRecord = reinterpret_cast<NPCCopyRecord_t*>(reference->recordPointer);
		if (npcCopyRecord->recordType != RecordTypes::NPC) {
			mwse::log::getLog() << "xSpellList: Called on non-NPC reference." << std::endl;
			pushErrorResponse();
			return 0.0f;
		}

		// If we're not provided a node, get the first node of the NPC.
		if (node == NULL) {
			node = npcCopyRecord->baseNPC->spellStart;
		}

		// Get our data.
		SPELRecord_t* spell = node->data;
		spellCount = npcCopyRecord->baseNPC->numberOfSpells;
		spellId = spell->id;
		spellName = spell->friendlyName;
		spellType = spell->type;
		spellCost = spell->cost;
		spellEffectCount = tes3::getEffectCount(spell->effects);
		spellFlags = spell->flags;

		// Push the data back to mwscript.
		mwse::Stack::getInstance().pushLong((mwLong_t)node->next);
		mwse::Stack::getInstance().pushLong(spellFlags);
		mwse::Stack::getInstance().pushLong(spellEffectCount);
		mwse::Stack::getInstance().pushLong(spellCost);
		mwse::Stack::getInstance().pushLong(spellType);
		mwse::Stack::getInstance().pushString(spellName);
		mwse::Stack::getInstance().pushString(spellId);
		mwse::Stack::getInstance().pushLong(spellCount);

		return 0.0f;
	}

	void xSpellList::pushErrorResponse() {
		for (int i = 0; i < 8; i++) {
			mwse::Stack::getInstance().pushLong(0);
		}
	}
}
