/************************************************************************
	
	xSetProgressSkill.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetProgressSkill : mwse::InstructionInterface_t
	{
	public:
		xSetProgressSkill();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xSetProgressSkillOpcode = 0x392D;
	static xSetProgressSkill xSetProgressSkillInstance;

	xSetProgressSkill::xSetProgressSkill() : mwse::InstructionInterface_t(xSetProgressSkillOpcode) {}

	void xSetProgressSkill::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetProgressSkill::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwLong_t skillIndex = mwse::Stack::getInstance().popLong();
		mwLong_t normalized = mwse::Stack::getInstance().popLong();
		mwFloat_t progress = mwse::Stack::getInstance().popFloat();

		// Get the associated MACP record.
		mwse::REFRRecord_t* reference = virtualMachine.getReference();
		MACPRecord_t* macp = tes3::getAttachedMACPRecord(reference);
		if (macp == NULL) {
			mwse::log::getLog() << "xSetProgressSkill: Could not find MACP record for reference." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Verify skill index.
		if (skillIndex < FirstSkill || skillIndex > LastSkill) {
			mwse::log::getLog() << "xSetProgressSkill: Skill index out of bounds." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Verify progress.
		if (progress >= 0) {
			mwse::log::getLog() << "xSetProgressSkill: Progress cannot be negative." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Normalize skill progress.
		if (normalized) {
			progress = tes3::getSkillRequirement(reference, skillIndex) * progress / 100.0f;
		}

		// Set progress.
		macp->skillProgress[skillIndex] = progress;

		// Check for skill level up.
		tes3::checkForSkillUp(reference, skillIndex);

		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}