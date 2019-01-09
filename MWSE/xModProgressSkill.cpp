/************************************************************************
	
	xModProgressSkill.cpp - Copyright (c) 2008 The MWSE Project
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
#if _DEBUG
			mwse::log::getLog() << "xModProgressSkill: Function called with too few arguments." << std::endl;
#endif
			return 0.0f;
		}

		long skillId = mwse::Stack::getInstance().popLong();
		float modValue = mwse::Stack::getInstance().popFloat();
		long normalize = mwse::Stack::getInstance().popLong();

		// Verify attribute range.
		if (skillId < TES3::SkillID::FirstSkill || skillId > TES3::SkillID::LastSkill) {
#if _DEBUG
			mwse::log::getLog() << "xModProgressSkill: Invalid skill id: " << skillId << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// 
		auto macp = TES3::WorldController::get()->getMobilePlayer();

		// Mod value.
		float progress = macp->skillProgress[skillId];

		// Normalize progress, then add mod, then convert back.
		// This avoids some floating point precision errors.
		if (normalize) {
			const float requirement = macp->getSkillRequirement(skillId);
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
		macp->levelSkill(skillId);

		// Push to indicate success.
		mwse::Stack::getInstance().pushLong(1);

		return 0.0f;
	}
}