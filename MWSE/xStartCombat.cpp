/************************************************************************
	
	xStartCombat.cpp - Copyright (c) 2008 The MWSE Project
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
	class xStartCombat : mwse::InstructionInterface_t
	{
	public:
		xStartCombat();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xStartCombat xStartCombatInstance;

	xStartCombat::xStartCombat() : mwse::InstructionInterface_t(OpCode::xStartCombat) {}

	void xStartCombat::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xStartCombat::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		REFRRecord_t* target = reinterpret_cast<REFRRecord_t*>(mwse::Stack::getInstance().popLong());

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xStartCombat: Called on invalid reference." << std::endl;
#endif
			return 0.0f;
		}

		// Call the original function.
		SCPTRecord_t* script = &virtualMachine.getScript();
		mwse::mwscript::StartCombat(script, reference, target);

		return 0.0f;
	}
}