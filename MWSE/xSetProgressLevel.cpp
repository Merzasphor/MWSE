/************************************************************************
	
	xSetProgressLevel.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetProgressLevel : mwse::InstructionInterface_t
	{
	public:
		xSetProgressLevel();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetProgressLevel xSetProgressLevelInstance;

	xSetProgressLevel::xSetProgressLevel() : mwse::InstructionInterface_t(OpCode::xSetProgressLevel) {}

	void xSetProgressLevel::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetProgressLevel::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter.
		mwLong_t progress = mwse::Stack::getInstance().popLong();

		// Get the associated MACP record.
		mwse::REFRRecord_t* reference = virtualMachine.getReference("player");
		MACPRecord_t* macp = tes3::getAttachedMACPRecord(reference);
		if (macp == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetProgressLevel: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Set progress.
		macp->levelProgress = progress;

		// Check for level up.
		tes3::checkForLevelUp(progress);

		// Push success.
		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}