/************************************************************************
	
	xGetService.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetService : mwse::InstructionInterface_t {
	public:
		xGetService();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetService xGetServiceInstance;

	xGetService::xGetService() : mwse::InstructionInterface_t(OpCode::xGetService) {}

	void xGetService::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetService::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetRace: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		mwLong_t flags = 0;
		mwLong_t mask = mwse::Stack::getInstance().popLong();

		// Get the gold based on the base record type.
		NPCCopyRecord_t* npc = reinterpret_cast<NPCCopyRecord_t*>(reference->recordPointer);
		if (npc->recordType == RecordTypes::NPC) {
			if (npc->baseNPC) {
				flags = npc->baseNPC->servicesMask;
				flags &= mask;
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xGetService: Could not get base NPC record for \"" << npc->objectId << "\"" << std::endl;
#endif
			}
		} else {
#if _DEBUG
			mwse::log::getLog() << "xGetService: Called on non-NPC target." << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushLong(flags);

		return 0.0f;
	}
}