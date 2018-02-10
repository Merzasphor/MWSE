/************************************************************************
	
	xGetItemCount.cpp - Copyright (c) 2008 The MWSE Project
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
#include "mwAdapter.h"
#include "VirtualMachine.h"
#include "ScriptUtil.h"

using namespace mwse;

namespace mwse
{
	class xGetItemCount : mwse::InstructionInterface_t
	{
	public:
		xGetItemCount();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetItemCount xGetItemCountInstance;

	xGetItemCount::xGetItemCount() : mwse::InstructionInterface_t(OpCode::xGetItemCount) {}

	void xGetItemCount::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xGetItemCount::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter.
		mwseString_t& id = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Get who we're getting the item count of. mwscript's GetItemCount validates the
		// object type for us, we don't need to.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetItemCount: No reference found for function call." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get template for the item we want to get the count of.
		TES3::BaseObject* itemTemplate = virtualMachine.getTemplate(id.c_str());
		if (itemTemplate == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetItemCount: No template found with id " << id << "." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Call the original function.
		TES3::Script* script = &virtualMachine.getScript();
		mwLong result = mwse::mwscript::GetItemCount(script, reference, itemTemplate);
		mwse::Stack::getInstance().pushLong(result);

		return 0.0f;
	}
}