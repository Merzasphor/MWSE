/************************************************************************
	
	xGetGlobal.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3GlobalVariable.h"
#include "TES3DataHandler.h"

using namespace mwse;

namespace mwse {
	class xGetGlobal : mwse::InstructionInterface_t {
	public:
		xGetGlobal();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetGlobal xGetGlobalInstance;

	xGetGlobal::xGetGlobal() : mwse::InstructionInterface_t(OpCode::xGetGlobal) {}

	void xGetGlobal::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetGlobal::execute(mwse::VMExecuteInterface &virtualMachine) {
		mwseString& variable = virtualMachine.getString(Stack::getInstance().popLong());

		float value = 0.0f;

		// Get global.
		const TES3::GlobalVariable* global = TES3::DataHandler::get()->nonDynamicData->findGlobalVariable(variable.c_str());
		if (global == NULL) {
			mwse::log::getLog() << "xGetGlobal: Global '" << variable << "' could not be found." << std::endl;
			mwse::Stack::getInstance().pushFloat(0.0f);
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Push value if found.
		mwse::Stack::getInstance().pushFloat(global->value);
		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}