/************************************************************************
	
	xAITravel.cpp - Copyright (c) 2008 The MWSE Project
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
#include "mwAdapter.h"
#include "VirtualMachine.h"
#include "ScriptUtil.h"

using namespace mwse;

namespace mwse
{
	class xAITravel : mwse::InstructionInterface_t
	{
	public:
		xAITravel();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xAITravelOpcode = 0x3C04;
	static xAITravel xAITravelInstance;

	xAITravel::xAITravel() : mwse::InstructionInterface_t(xAITravelOpcode) {}

	void xAITravel::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xAITravel::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwFloat_t x = mwse::Stack::getInstance().popFloat();
		mwFloat_t y = mwse::Stack::getInstance().popFloat();
		mwFloat_t z = mwse::Stack::getInstance().popFloat();

		// Get other context information for opcode call.
		SCPTRecord_t* script = &virtualMachine.getScript();
		REFRRecord_t* reference = virtualMachine.getReference();

		// Call the original function.
		mwse::mwscript::AITravel(script, reference, x, y, z);

		return 0.0f;
	}
}