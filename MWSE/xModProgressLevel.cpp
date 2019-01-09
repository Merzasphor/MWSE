/************************************************************************
	
	xModProgressLevel.cpp - Copyright (c) 2008 The MWSE Project
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
	class xModProgressLevel : mwse::InstructionInterface_t
	{
	public:
		xModProgressLevel();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xModProgressLevel xModProgressLevelInstance;

	xModProgressLevel::xModProgressLevel() : mwse::InstructionInterface_t(OpCode::xModProgressLevel) {}

	void xModProgressLevel::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xModProgressLevel::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 1) {
#if _DEBUG
			mwse::log::getLog() << "xModProgressLevel: Function called with too few arguments." << std::endl;
#endif
			return 0.0f;
		}

		long modValue = mwse::Stack::getInstance().popLong();

		// Get the MACP record.
		auto mobileObject = TES3::WorldController::get()->getMobilePlayer();

		// Modify value.
		long newValue = mobileObject->levelUpProgress + modValue;
		if (newValue < 0) {
			newValue = 0;
		}
		mobileObject->levelUpProgress = newValue;

		// Push to indicate success.
		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}