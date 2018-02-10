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
#include "TES3MACP.h"

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

		mwLong modValue = mwse::Stack::getInstance().popLong();

		// Get the associated MACP record.
		TES3::Reference* reference = virtualMachine.getReference("player");
		TES3::MACP* macp = tes3::getAttachedMACPRecord(reference);
		if (macp == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xModProgressLevel: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Modify value.
		mwLong newValue = macp->levelProgress + modValue;
		if (newValue < 0) {
			newValue = 0;
		}
		macp->levelProgress = newValue;

		// Push to indicate success.
		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}