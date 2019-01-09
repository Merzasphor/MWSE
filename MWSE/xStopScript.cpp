/************************************************************************
	
	xStopScript.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3DataHandler.h"
#include "TES3Script.h"

using namespace mwse;

namespace mwse
{
	class xStopScript : mwse::InstructionInterface_t
	{
	public:
		xStopScript();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xStopScript xStopScriptInstance;

	xStopScript::xStopScript() : mwse::InstructionInterface_t(OpCode::xStopScript) {}

	void xStopScript::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xStopScript::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter: script name. We allow a value of 0 to target the current script.
		long scriptNameId = mwse::Stack::getInstance().popLong();
		const char* scriptName = NULL;
		if (scriptNameId == 0) {
			scriptName = virtualMachine.getScript()->name;
		}
		else {
			scriptName = virtualMachine.getString(scriptNameId).c_str();
		}

		// Try to get the target script.
		TES3::Script* targetScript = TES3::DataHandler::get()->nonDynamicData->findScriptByName(scriptName);
		if (targetScript == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xStopScript: No script could be found with name '" << scriptName << "'." << std::endl;
#endif
			return 0.0f;
		}

		// Call the original function.
		TES3::Script* script = virtualMachine.getScript();
		mwse::mwscript::StopScript(script, targetScript);

		return 0.0f;
	}
}