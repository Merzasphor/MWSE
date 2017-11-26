/************************************************************************
	
	xSetBaseGold.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetBaseGold : mwse::InstructionInterface_t
	{
	public:
		xSetBaseGold();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xSetBaseGoldOpcode = 0x3F25;
	static xSetBaseGold xSetBaseGoldInstance;

	xSetBaseGold::xSetBaseGold() : mwse::InstructionInterface_t(xSetBaseGoldOpcode) {}

	void xSetBaseGold::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetBaseGold::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		mwShort_t gold = mwse::Stack::getInstance().popShort();

		// Get the gold based on the base record type.
		BaseRecord_t* baseRecord = reference->recordPointer;
		if (baseRecord->recordType == RecordTypes::NPC) {
			NPCCopyRecord_t* npc = reinterpret_cast<NPCCopyRecord_t*>(baseRecord);
			if (npc->baseNPC) {
				npc->baseNPC->baseGold = gold;
			}
			else {
				mwse::log::getLog() << "xSetBaseGold: Could not get base NPC record for \"" << npc->IDStringPtr << "\"" << std::endl;
			}
		}
		else if (baseRecord->recordType == RecordTypes::CREATURE) {
			CREACopyRecord_t* creature = reinterpret_cast<CREACopyRecord_t*>(baseRecord);
			if (creature->baseCreature) {
				creature->baseCreature->baseGold = gold;
			}
			else {
				mwse::log::getLog() << "xSetBaseGold: Could not get base creature record for \"" << creature->IDStringPtr << "\"" << std::endl;
			}
		}

		return 0.0f;
	}
}