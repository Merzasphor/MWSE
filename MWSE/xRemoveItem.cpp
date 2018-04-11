/************************************************************************
	
	xRemoveItem.cpp - Copyright (c) 2008 The MWSE Project
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
	class xRemoveItem : mwse::InstructionInterface_t
	{
	public:
		xRemoveItem();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xRemoveItem xRemoveItemInstance;

	xRemoveItem::xRemoveItem() : mwse::InstructionInterface_t(OpCode::xRemoveItem) {}

	void xRemoveItem::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xRemoveItem::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& id = virtualMachine.getString(mwse::Stack::getInstance().popLong());
		long count = mwse::Stack::getInstance().popLong();

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xRemoveItem: Called on invalid reference." << std::endl;
#endif
			return 0.0f;
		}

		// Get spell template by the id.
		TES3::BaseObject* itemTemplate = virtualMachine.getTemplate(id.c_str());
		if (itemTemplate == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xRemoveItem: No template found with id '" << id << "'." << std::endl;
#endif
			return 0.0f;
		}

		// Call the original function.
		TES3::Script* script = virtualMachine.getScript();
		mwse::mwscript::RemoveItem(script, reference, itemTemplate, count);

		return 0.0f;
	}
}