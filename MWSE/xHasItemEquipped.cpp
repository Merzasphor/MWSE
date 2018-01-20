/************************************************************************
	
	xHasItemEquipped.cpp - Copyright (c) 2008 The MWSE Project
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
	class xHasItemEquipped : mwse::InstructionInterface_t
	{
	public:
		xHasItemEquipped();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xHasItemEquippedOpcode = 0x3C30;
	static xHasItemEquipped xHasItemEquippedInstance;

	xHasItemEquipped::xHasItemEquipped() : mwse::InstructionInterface_t(xHasItemEquippedOpcode) {}

	void xHasItemEquipped::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xHasItemEquipped::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString_t& id = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Get other context information for opcode call.
		SCPTRecord_t* script = &virtualMachine.getScript();
		REFRRecord_t* reference = virtualMachine.getReference();
		TES3DefaultTemplate_t* itemTemplate = virtualMachine.getTemplate(id.c_str());

		// Call the original function.
		bool result = mwse::mwscript::HasItemEquipped(script, reference, itemTemplate);

		mwse::Stack::getInstance().pushLong(result);

		return 0.0f;
	}
}