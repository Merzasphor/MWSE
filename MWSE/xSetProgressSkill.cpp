/************************************************************************
	
	xSetProgressSkill.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3Reference.h"
#include "TES3Skill.h"
#include "TES3WorldController.h"

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

	static xSetProgressSkill xSetProgressSkillInstance;

	xSetProgressSkill::xSetProgressSkill() : mwse::InstructionInterface_t(OpCode::xSetProgressSkill) {}

	void xSetProgressSkill::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetProgressSkill::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		long skillIndex = mwse::Stack::getInstance().popLong();
		float progress = mwse::Stack::getInstance().popFloat();
		long normalized = mwse::Stack::getInstance().popLong();

		// Get the associated MACP record.
		auto mobileObject = TES3::WorldController::get()->getMobilePlayer();
		if (mobileObject == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetProgressSkill: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Verify skill index.
		if (skillIndex < TES3::SkillID::FirstSkill || skillIndex > TES3::SkillID::LastSkill) {
#if _DEBUG
			mwse::log::getLog() << "xSetProgressSkill: Skill index out of bounds." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Verify progress.
		if (progress < 0) {
#if _DEBUG
			mwse::log::getLog() << "xSetProgressSkill: Progress cannot be negative." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Normalize skill progress.
		if (normalized) {
			progress = mobileObject->getSkillRequirement(skillIndex) * progress / 100.0f;
		}

		// Set progress.
		mobileObject->skillProgress[skillIndex] = progress;

		// Check for skill level up.
		mobileObject->levelSkill(skillIndex);

		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}