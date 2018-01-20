/************************************************************************
	
	xModProgressLevel.cpp - Copyright (c) 2008 The MWSE Project
	http://www.sourceforge.net/projects/mwse

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
			mwse::log::getLog() << "xModProgressLevel: Function called with too few arguments." << std::endl;
			return 0.0f;
		}

		mwLong_t modValue = mwse::Stack::getInstance().popFloat();

		// Get the associated MACP record.
		mwse::REFRRecord_t* reference = virtualMachine.getReference();
		MACPRecord_t* macp = tes3::getAttachedMACPRecord(reference);
		if (macp == NULL) {
			mwse::log::getLog() << "xModProgressLevel: Could not find MACP record for reference." << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Modify value.
		mwLong_t newValue = macp->levelProgress + modValue;
		if (newValue < 0) {
			newValue = 0;
		}
		macp->levelProgress = newValue;

		// Push to indicate success.
		mwse::Stack::getInstance().pushLong(1);

		return 0.0f;
	}
}