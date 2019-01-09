/************************************************************************
	
	xGetGSString.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3DataHandler.h"
#include "TES3GameSetting.h"

using namespace mwse;

namespace mwse
{
	class xGetGSString : mwse::InstructionInterface_t
	{
	public:
		xGetGSString();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetGSString xGetGSStringInstance;

	xGetGSString::xGetGSString() : mwse::InstructionInterface_t(OpCode::xGetGSString) {}

	void xGetGSString::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetGSString::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long gmstId = Stack::getInstance().popLong();

		if (gmstId < 0) {
			mwse::log::getLog() << "xGetGSString: Invalid GMST id." << std::endl;
			mwse::Stack::getInstance().pushLong(NULL);
			return 0.0f;
		}

		// Get the string. No real sanity checks here...
		char * value = TES3::DataHandler::get()->nonDynamicData->GMSTs[gmstId]->value.asString;

		mwse::Stack::getInstance().pushString(value);

		return 0.0f;
	}
}