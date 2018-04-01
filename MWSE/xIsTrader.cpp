/************************************************************************

	xIsTrader.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3NPC.h"
#include "TES3Class.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse {
	class xIsTrader : mwse::InstructionInterface_t {
	public:
		xIsTrader();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xIsTrader xIsTraderInstance;

	xIsTrader::xIsTrader() : mwse::InstructionInterface_t(OpCode::xIsTrader) {}

	void xIsTrader::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xIsTrader::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xIsTrader: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		long npcServiceFlags = 0;
		long classServiceFlags = 0;

		// Get the gold based on the base record type.
		TES3::AIConfig* aiConfig = reference->baseObject->vTable.object->getAIConfig(reference->baseObject);
		if (aiConfig) {
			npcServiceFlags = aiConfig->merchantFlags & 0x000037FF;

			// Get the class flags.
			TES3::Class* npcClass = reference->baseObject->vTable.object->getClass(reference->baseObject);
			if (npcClass) {
				npcServiceFlags = npcClass->services & 0x000037FF;
			}
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xIsTrader: Failed to get AI configuration for target." << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushLong(npcServiceFlags | classServiceFlags);

		return 0.0f;
	}
}