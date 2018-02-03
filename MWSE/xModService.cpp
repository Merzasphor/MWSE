/************************************************************************
	
	xModService.cpp - Copyright (c) 2008 The MWSE Project
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
	class xModService : mwse::InstructionInterface_t
	{
	public:
		xModService();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xModService xModServiceInstance;

	xModService::xModService() : mwse::InstructionInterface_t(OpCode::xModService) {}

	void xModService::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xModService::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 1) {
#if _DEBUG
			mwse::log::getLog() << "xModService: Function called with too few arguments." << std::endl;
#endif
			return 0.0f;
		}

		unsigned long data = Stack::getInstance().popLong();

		// Get reference.
		mwse::REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xModService: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Make sure we're looking at an NPC.
		NPCCopyRecord_t* npcCopy = reinterpret_cast<NPCCopyRecord_t*>(reference->recordPointer);
		if (!reference || !npcCopy || npcCopy->recordType != RecordTypes::NPC) {
#if _DEBUG
			mwse::log::getLog() << "xModService: Called on non-NPC reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get the NPC's class.
		CLASRecord_t* classRecord = npcCopy->baseNPC->classRecord;
		if (!classRecord) {
#if _DEBUG
			mwse::log::getLog() << "xModService: Failed to obtain NPC's class." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		mwLong_t services = npcCopy->baseNPC->servicesMask | classRecord->services;

		// Want to remove services.
		if (data < 0) {
			services = services & (~((unsigned long)(0-(signed long)data)));
		}
		// Want to add services.
		else {
			services = services | (data & 0x0003FFFF);
		}

		npcCopy->baseNPC->servicesMask = services;

		return 0.0f;
	}
}