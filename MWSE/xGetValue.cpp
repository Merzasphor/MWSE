/************************************************************************
	
	xGetValue.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3ItemData.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse {
	class xGetValue : mwse::InstructionInterface_t {
	public:
		xGetValue();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetValue xGetValueInstance;

	xGetValue::xGetValue() : mwse::InstructionInterface_t(OpCode::xGetValue) {}

	void xGetValue::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetValue::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetValue: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get value.
		long value = 0;
		try {
			// Get record.
			auto object = reference->baseObject;
			if (object == NULL) {
				throw std::exception("No base record found.");
			}

			// Get base value for the record.
			value = object->getValue();

			// Multiply the value by the count of the item.
			auto varNode = reference->getAttachedItemData();
			if (varNode) {
				value *= varNode->count;
			}
		}
		catch (std::exception& e) {
#if _DEBUG
			mwse::log::getLog() << "xGetValue: " << e.what() << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		mwse::Stack::getInstance().pushLong(value);

		return 0.0f;
	}
}