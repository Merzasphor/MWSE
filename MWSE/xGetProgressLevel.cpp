/************************************************************************
	
	xGetProgressLevel.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3MobilePlayer.h"
#include "TES3WorldController.h"

using namespace mwse;

namespace mwse
{
	class xGetProgressLevel : mwse::InstructionInterface_t
	{
	public:
		xGetProgressLevel();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const long INVALID_VALUE = -1;
	};

	static xGetProgressLevel xGetProgressLevelInstance;

	xGetProgressLevel::xGetProgressLevel() : mwse::InstructionInterface_t(OpCode::xGetProgressLevel) {}

	void xGetProgressLevel::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetProgressLevel::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get the player's associated MACP record.
		auto mobileObject = TES3::WorldController::get()->getMobilePlayer();
		if (mobileObject == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetProgressLevel: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(INVALID_VALUE);
			return 0.0f;
		}
		else if (mobileObject->objectType != TES3::ObjectType::MobilePlayer) {
#if _DEBUG
			mwse::log::getLog() << "xGetProgressLevel: Attached mobile object is not for the player." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(INVALID_VALUE);
			return 0.0f;
		}

		mwse::Stack::getInstance().pushLong(mobileObject->levelUpProgress);

		return 0.0f;
	}
}