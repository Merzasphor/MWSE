/************************************************************************
	
	xGetProgressSkill.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3Skill.h"

using namespace mwse;

namespace mwse
{
	class xGetProgressSkill : mwse::InstructionInterface_t
	{
	public:
		xGetProgressSkill();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const float INVALID_VALUE = -1.0f;
	};

	static xGetProgressSkill xGetProgressSkillInstance;

	xGetProgressSkill::xGetProgressSkill() : mwse::InstructionInterface_t(OpCode::xGetProgressSkill) {}

	void xGetProgressSkill::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetProgressSkill::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter off the stack.
		long skillIndex = mwse::Stack::getInstance().popLong();
		if (skillIndex < TES3::SkillID::FirstSkill || skillIndex > TES3::SkillID::LastSkill) {
#if _DEBUG
			mwse::log::getLog() << "xGetProgressSkill: Invalid skill index provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference("player");
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetProgressSkill: Could not find reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get the associated MACP record.
		auto mobileObject = tes3::getAttachedMobilePlayer(reference);
		if (mobileObject == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetProgressSkill: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}
		else if (mobileObject->objectType != TES3::ObjectType::MobilePlayer) {
#if _DEBUG
			mwse::log::getLog() << "xGetProgressSkill: Attached mobile object is not for the player." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(INVALID_VALUE);
			return 0.0f;
		}

		float progress = mobileObject->skillProgress[skillIndex];
		float normalized = 100.0f * progress / tes3::getSkillRequirement(reference, skillIndex);

		// Push the desired values.
		mwse::Stack::getInstance().pushFloat(normalized);
		mwse::Stack::getInstance().pushFloat(progress);

		return 0.0f;
	}
}