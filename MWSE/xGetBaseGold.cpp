/************************************************************************

	xGetBaseGold.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetBaseGold : mwse::InstructionInterface_t
	{
	public:
		xGetBaseGold();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xGetBaseGoldOpcode = 0x3F23;
	static xGetBaseGold xGetBaseGoldInstance;

	xGetBaseGold::xGetBaseGold() : mwse::InstructionInterface_t(xGetBaseGoldOpcode) {}

	void xGetBaseGold::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetBaseGold::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		mwShort_t gold = 0;

		// Get the gold based on the base record type.
		BaseRecord_t* baseRecord = reference->recordPointer;
		if (baseRecord->recordType == RecordTypes::NPC) {
			NPCCopyRecord_t* npc = reinterpret_cast<NPCCopyRecord_t*>(baseRecord);
			if (npc->baseNPC) {
				gold = npc->baseNPC->baseGold;
			}
			else {
				mwse::log::getLog() << "xGetBaseGold: Could not get base NPC record for \"" << npc->IDStringPtr << "\"" << std::endl;
			}
		}
		else if (baseRecord->recordType == RecordTypes::CREATURE) {
			CREACopyRecord_t* creature = reinterpret_cast<CREACopyRecord_t*>(baseRecord);
			if (creature->baseCreature) {
				gold = creature->baseCreature->baseGold;
			}
			else {
				mwse::log::getLog() << "xGetBaseGold: Could not get base creature record for \"" << creature->IDStringPtr << "\"" << std::endl;
			}
		}

		// Push the base value of that skill.
		mwse::Stack::getInstance().pushShort(gold);

		return 0.0f;
	}
}