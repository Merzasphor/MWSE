/************************************************************************
	
	xSetService.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetService : mwse::InstructionInterface_t {
	public:
		xSetService();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetService xSetServiceInstance;

	xSetService::xSetService() : mwse::InstructionInterface_t(OpCode::xSetService) {}

	void xSetService::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetService::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get parameters.
		mwLong_t flags = mwse::Stack::getInstance().popLong() & 0x0003FFFF;

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetService: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Set service mask.
		NPCCopyRecord_t* npc = reinterpret_cast<NPCCopyRecord_t*>(reference->recordPointer);
		if (npc->recordType == RecordTypes::NPC) {
			if (npc->baseNPC) {
				npc->baseNPC->servicesMask = flags;
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xSetService: Could not get base NPC record for \"" << npc->objectId << "\"" << std::endl;
#endif
			}
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xSetService: Called on non-NPC target." << std::endl;
#endif
		}

		return 0.0f;
	}
}