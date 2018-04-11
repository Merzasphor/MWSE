/************************************************************************
	
	xLuaRunScript.cpp - Copyright (c) 2008 The MWSE Project
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

#include "LuaManager.h"

#include "TES3Script.h"

using namespace mwse;

namespace mwse
{
	class xLuaRunScript : mwse::InstructionInterface_t
	{
	public:
		xLuaRunScript();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xLuaRunScript xLuaRunScriptInstance;

	xLuaRunScript::xLuaRunScript() : mwse::InstructionInterface_t(OpCode::xLuaRunScript) {}

	void xLuaRunScript::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xLuaRunScript::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& scriptName = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Build our script path.
		std::string path = "./Data Files/MWSE/lua/scripts/";
		path += scriptName;
		path += ".lua";

		// Update the LuaManager to reference our current context.
		lua::LuaManager& manager = lua::LuaManager::getInstance();
		manager.setCurrentReference(virtualMachine.getReference());
		manager.setCurrentScript(virtualMachine.getScript());

		// Run the script.
		sol::state& state = manager.getState();
		auto result = state.safe_script_file(path);
		if (!result.valid()) {
			sol::error error = result;
			log::getLog() << "Lua error encountered when executing script '" << virtualMachine.getScript()->name << "':" << std::endl << error.what() << std::endl;

			// Clear the stack, since we can't trust what the script did or did not do.
			mwse::Stack::getInstance().clear();
		}

		return 0.0f;
	}
}