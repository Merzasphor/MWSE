/************************************************************************
	
	xModProgressSkill.cpp - Copyright (c) 2008 The MWSE Project
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
	class xModProgressSkill : mwse::InstructionInterface_t
	{
	public:
		xModProgressSkill();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xModProgressSkill xModProgressSkillInstance;

	xModProgressSkill::xModProgressSkill() : mwse::InstructionInterface_t(OpCode::xModProgressSkill) {}

	void xModProgressSkill::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xModProgressSkill::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 3) {
			mwse::log::getLog() << "xModProgressSkill: Function called with too few arguments." << std::endl;
			return 0.0f;
		}

		mwLong_t skillId = mwse::Stack::getInstance().popLong();
		mwFloat_t modValue = mwse::Stack::getInstance().popFloat();
		mwLong_t normalize = mwse::Stack::getInstance().popLong();

		// Verify attribute range.
		if (skillId < FirstSkill || skillId > LastSkill) {
			mwse::log::getLog() << "xModProgressSkill: Invalid skill id: " << skillId << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Make sure we're looking at an NPC or creature.
		mwse::REFRRecord_t* reference = virtualMachine.getReference();
		if (reference->recordPointer->recordType != RecordTypes::NPC) {
			mwse::log::getLog() << "xModProgressSkill: Called on non-NPC reference." << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get the associated MACP record.
		MACPRecord_t* macp = tes3::getAttachedMACPRecord(reference);
		if (macp == NULL) {
			mwse::log::getLog() << "xModProgressSkill: Could not find MACP record for reference." << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Mod value.
		mwFloat_t progress = macp->skillProgress[skillId];
		// Normalize progress, then add mod, then convert back.
		// This avoids some floating point precision errors.
		if (normalize) {
			const mwFloat_t requirement = tes3::getSkillRequirement(reference, skillId);
			progress = 100.0f * progress / requirement + modValue;
			progress = requirement * progress / 100.0f;
		}
		else {
			progress += modValue;
		}

		if (progress < 0.0f) {
			progress = 0.0f;
		}
		macp->skillProgress[skillId] = progress;

		// Call Morrowind's native CheckForSkillUp function.
		tes3::checkForSkillUp(reference, skillId);

		// Push to indicate success.
		mwse::Stack::getInstance().pushLong(1);

		return 0.0f;
	}
}