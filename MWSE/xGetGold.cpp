/************************************************************************
	
	xGetGold.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3MobileNPC.h"
#include "TES3NPC.h"
#include "TES3Creature.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetGold : mwse::InstructionInterface_t
	{
	public:
		xGetGold();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetGold xGetGoldInstance;

	xGetGold::xGetGold() : mwse::InstructionInterface_t(OpCode::xGetGold) {}

	void xGetGold::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetGold::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetGold: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		// Try to get the gold from the macp record.
		short gold = 0;
		auto mobileObject = reference->getAttachedMobileActor();
		if (mobileObject) {
			gold = mobileObject->barterGold;
		}
		else {
			// Get the gold based on the base record type if we can't get it from macp.
			TES3::BaseObject* baseRecord = reference->baseObject;
			if (baseRecord->objectType == TES3::ObjectType::NPC) {
				TES3::NPCInstance* npc = reinterpret_cast<TES3::NPCInstance*>(baseRecord);
				if (npc->baseNPC) {
					gold = npc->baseNPC->barterGold;
				}
				else {
#if _DEBUG
					mwse::log::getLog() << "xGetGold: Could not get base NPC record for \"" << npc->objectID << "\"" << std::endl;
#endif
				}
			}
			else if (baseRecord->objectType == TES3::ObjectType::Creature) {
				TES3::CreatureInstance* creature = reinterpret_cast<TES3::CreatureInstance*>(baseRecord);
				if (creature->baseCreature) {
					gold = creature->baseCreature->barterGold;
				}
				else {
#if _DEBUG
					mwse::log::getLog() << "xGetGold: Could not get base creature record for \"" << creature->objectID << "\"" << std::endl;
#endif
				}
			}
		}

		// Push the base value of that skill.
		mwse::Stack::getInstance().pushShort(gold);

		return 0.0f;
	}
}