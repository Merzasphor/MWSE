/************************************************************************
	
	xIsFemale.cpp - Copyright (c) 2008 The MWSE Project
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
	class xIsFemale : mwse::InstructionInterface_t {
	public:
		xIsFemale();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xIsFemale xIsFemaleInstance;

	xIsFemale::xIsFemale() : mwse::InstructionInterface_t(OpCode::xIsFemale) {}

	void xIsFemale::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xIsFemale::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();

		mwLong_t value = 0;

		// Get the gold based on the base record type.
		NPCCopyRecord_t* npc = reinterpret_cast<NPCCopyRecord_t*>(reference->recordPointer);
		if (npc->recordType == RecordTypes::NPC) {
			value = npc->flags % 2;
		}
		else {
			mwse::log::getLog() << "xIsFemale: Called on non-NPC target." << std::endl;
		}

		mwse::Stack::getInstance().pushLong(value);

		return 0.0f;
	}
}