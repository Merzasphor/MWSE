/************************************************************************
	
	xSetGlobal.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3GlobalVariable.h"

using namespace mwse;

namespace mwse {
	class xSetGlobal : mwse::InstructionInterface_t {
	public:
		xSetGlobal();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetGlobal xSetGlobalInstance;

	xSetGlobal::xSetGlobal() : mwse::InstructionInterface_t(OpCode::xSetGlobal) {}

	void xSetGlobal::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetGlobal::execute(mwse::VMExecuteInterface &virtualMachine) {
		mwseString& variable = virtualMachine.getString(Stack::getInstance().popLong());
		float value = Stack::getInstance().popFloat();

		TES3::GlobalVariable* global = TES3::DataHandler::get()->nonDynamicData->findGlobalVariable(variable.c_str());
		if (global == NULL) {
			mwse::log::getLog() << "xSetGlobal: No global could be found with id '" << variable << "'." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		global->value = value;
		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}