/************************************************************************
	
	xStartScript.cpp - Copyright (c) 2008 The MWSE Project
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

using namespace mwse;

namespace mwse
{
	class xStartScript : mwse::InstructionInterface_t
	{
	public:
		xStartScript();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xStartScript xStartScriptInstance;

	xStartScript::xStartScript() : mwse::InstructionInterface_t(OpCode::xStartScript) {}

	void xStartScript::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xStartScript::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& scriptName = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Try to get the target script.
		TES3::Script* targetScript = TES3::DataHandler::get()->nonDynamicData->findScriptByName(scriptName.c_str());
		if (targetScript == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xStartScript: No script could be found with name '" << scriptName << "'." << std::endl;
#endif
			return 0.0f;
		}

		// Call the original function.
		TES3::Reference* reference = virtualMachine.getReference();
		TES3::Script* script = virtualMachine.getScript();
		mwse::mwscript::StartScript(script, reference, targetScript);

		return 0.0f;
	}
}