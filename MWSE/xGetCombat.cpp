/************************************************************************

	xGetCombat.cpp - Copyright (c) 2008 The MWSE Project
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
#include "Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetCombat : mwse::InstructionInterface_t
	{
	public:
		xGetCombat();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xGetCombatOpcode = 0x3C20;
	static xGetCombat xGetCombatInstance;

	xGetCombat::xGetCombat() : mwse::InstructionInterface_t(xGetCombatOpcode) {}

	void xGetCombat::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetCombat::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xGetCombat: No reference provided." << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get attached MACP record.
		MACPRecord_t* macp = reinterpret_cast<MACPRecord_t*>(mwse::tes3::getFirstAttachmentByType(reference, RecordTypes::MACHNODE));
		if (macp == NULL) {
			mwse::log::getLog() << "xGetCombat: No mach node found." << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Push the reference of the combat target, or 0 if no target reference is found.
		if (macp->combatTarget && macp->combatTarget->reference) {
			Reference fixed(macp->combatTarget->reference);
			mwse::Stack::getInstance().pushLong(fixed);
		}
		else {
			mwse::Stack::getInstance().pushLong(0);
		}

		return 0.0f;
	}
}