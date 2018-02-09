/************************************************************************
	
	xGetAttribute.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3MACP.h"

using namespace mwse;

namespace mwse
{
	class xGetAttribute : mwse::InstructionInterface_t
	{
	public:
		xGetAttribute();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const mwFloat INVALID_VALUE = -1.0f;
	};

	static xGetAttribute xGetAttributeInstance;

	xGetAttribute::xGetAttribute() : mwse::InstructionInterface_t(OpCode::xGetAttribute) {}

	void xGetAttribute::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetAttribute::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 1) {
			mwse::log::getLog() << "xGetAttribute: Function called with too few arguments." << std::endl;
			return 0.0f;
		}

		// Get attribute index as parameter.
		mwLong attributeId = mwse::Stack::getInstance().popLong();
		if (attributeId < TES3::FirstAttribute || attributeId > TES3::LastAttribute) {
#if _DEBUG
			mwse::log::getLog() << "xGetAttribute: Invalid attribute id: " << attributeId << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;

		}

		// Get the associated MACP record.
		TES3::Reference* reference = virtualMachine.getReference();
		TES3::MACP* macp = tes3::getAttachedMACPRecord(reference);
		if (macp == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetAttribute: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Push the current value of that attribute.
		mwse::Stack::getInstance().pushFloat(macp->attributes[attributeId].current);

		return 0.0f;
	}
}