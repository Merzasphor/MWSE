/************************************************************************
	
	xCast.cpp - Copyright (c) 2008 The MWSE Project
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
	class xCast : mwse::InstructionInterface_t
	{
	public:
		xCast();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xCast xCastInstance;

	xCast::xCast() : mwse::InstructionInterface_t(OpCode::xCast) {}

	void xCast::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xCast::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& spellId = virtualMachine.getString(mwse::Stack::getInstance().popLong());
		mwseString& targetId = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xAITravel: Called on invalid reference." << std::endl;
#endif
			return 0.0f;
		}

		// Get spell template by the id.
		TES3::Spell* spell = TES3::DataHandler::get()->nonDynamicData->getSpellById(spellId.c_str());
		if (spell == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xCast: No template found with id '" << spellId << "'." << std::endl;
#endif
			return 0.0f;
		}

		// Get the target by id.
		TES3::Reference* target = virtualMachine.getReference(targetId.c_str());
		if (target == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xCast: Could not find valid target by id '" << targetId << "'." << std::endl;
#endif
			return 0.0f;
		}

		// This function isn't working yet.
		TES3::Script* script = virtualMachine.getScript();
		mwse::log::getLog() << "xCast: Function unimplemented." << std::endl;

		return 0.0f;
	}
}