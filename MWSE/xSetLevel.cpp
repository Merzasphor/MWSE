/************************************************************************
	
	xSetLevel.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetLevel : mwse::InstructionInterface_t
	{
	public:
		xSetLevel();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xSetLevelOpcode = 0x394F;
	static xSetLevel xSetLevelInstance;

	xSetLevel::xSetLevel() : mwse::InstructionInterface_t(xSetLevelOpcode) {}

	void xSetLevel::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xSetLevel::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwShort_t level = virtualMachine.getString(mwse::Stack::getInstance().popShort());

		// Get other context information for original opcode.
		SCPTRecord_t* script = &virtualMachine.getScript();
		REFRRecord_t* reference = virtualMachine.getReference();

		// Call the original function.
		mwse::mwscript::SetLevel(script, reference, level);

		return 0.0f;
	}
}