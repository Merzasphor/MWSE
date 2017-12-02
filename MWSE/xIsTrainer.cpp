/************************************************************************
	
	xIsTrainer.cpp - Copyright (c) 2008 The MWSE Project
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

namespace mwse {
	class xIsTrainer : mwse::InstructionInterface_t {
	public:
		xIsTrainer();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xIsTrainerOpcode = 0x3F5E;
	static xIsTrainer xIsTrainerInstance;

	xIsTrainer::xIsTrainer() : mwse::InstructionInterface_t(xIsTrainerOpcode) {}

	void xIsTrainer::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xIsTrainer::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();

		mwLong_t npcServiceFlags = 0;
		mwLong_t classServiceFlags = 0;

		// Get the gold based on the base record type.
		NPCCopyRecord_t* npc = reinterpret_cast<NPCCopyRecord_t*>(reference->recordPointer);
		if (npc->recordType == RecordTypes::NPC) {
			// Get NPC's services.
			if (npc->baseNPC) {
				npcServiceFlags = npc->baseNPC->servicesMask;
				npcServiceFlags &= 0x00004000;
			}
			else {
				mwse::log::getLog() << "xIsTrainer: Could not get base NPC record for \"" << npc->objectId << "\"" << std::endl;
			}

			// Get 
			if (npc->baseNPC && npc->baseNPC->classRecord) {
				classServiceFlags = npc->baseNPC->classRecord->services;
				classServiceFlags &= 0x00004000;
			}
			else {
				mwse::log::getLog() << "xIsTrainer: Could not get class record for \"" << npc->objectId << "\"" << std::endl;
			}
		}
		else {
			mwse::log::getLog() << "xIsTrainer: Called on non-NPC target." << std::endl;
		}

		mwse::Stack::getInstance().pushLong(npcServiceFlags | classServiceFlags);

		return 0.0f;
	}
}