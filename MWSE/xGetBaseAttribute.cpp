/************************************************************************
	
	xGetBaseAttribute.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3MACP.h"

using namespace mwse;

namespace mwse
{
	class xGetBaseAttribute : mwse::InstructionInterface_t
	{
	public:
		xGetBaseAttribute();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const mwFloat INVALID_VALUE = -1.0f;
	};

	static xGetBaseAttribute xGetBaseAttributeInstance;

	xGetBaseAttribute::xGetBaseAttribute() : mwse::InstructionInterface_t(OpCode::xGetBaseAttribute) {}

	void xGetBaseAttribute::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetBaseAttribute::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 1) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseAttribute: Function called with too few arguments." << std::endl;
#endif
			return 0.0f;
		}

		// Get attribute index as parameter.
		mwLong attributeId = mwse::Stack::getInstance().popLong();
		if (attributeId < TES3::FirstAttribute || attributeId > TES3::LastAttribute) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseAttribute: Invalid attribute id: " << attributeId << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get the associated MACP record.
		TES3::Reference* reference = virtualMachine.getReference();
		TES3::MACP* macp = tes3::getAttachedMACPRecord(reference);
		if (macp == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseAttribute: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Push the base value of that attribute.
		mwse::Stack::getInstance().pushFloat(macp->attributes[attributeId].base);

		return 0.0f;
	}
}