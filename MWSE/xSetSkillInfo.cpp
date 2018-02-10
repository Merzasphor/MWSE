/************************************************************************
	
	xSetSkillInfo.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3CellMaster.h"
#include "TES3Skill.h"

using namespace mwse;

namespace mwse
{
	class xSetSkillInfo : mwse::InstructionInterface_t
	{
	public:
		xSetSkillInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetSkillInfo xSetSkillInfoInstance;

	xSetSkillInfo::xSetSkillInfo() : mwse::InstructionInterface_t(OpCode::xSetSkillInfo) {}

	void xSetSkillInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetSkillInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter.
		mwLong skillIndex = mwse::Stack::getInstance().popLong();

		// Return values.
		mwLong attributeId = mwse::Stack::getInstance().popLong();
		mwLong specialization = mwse::Stack::getInstance().popLong();
		mwFloat action1 = mwse::Stack::getInstance().popFloat();
		mwFloat action2 = mwse::Stack::getInstance().popFloat();
		mwFloat action3 = mwse::Stack::getInstance().popFloat();
		mwFloat action4 = mwse::Stack::getInstance().popFloat();

		// Validate skill index.
		if (skillIndex < TES3::FirstSkill || skillIndex > TES3::LastSkill) {
#if _DEBUG
			mwse::log::getLog() << "xSetSkillInfo: Skill index out of range." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Validate attribute.
		if (attributeId < TES3::FirstAttribute || attributeId > TES3::LastAttribute) {
#if _DEBUG
			mwse::log::getLog() << "xSetSkillInfo: Attribute id out of range." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Validate specialization.
		if (specialization < TES3::FirstSpecialization || specialization > TES3::LastSpecialization) {
#if _DEBUG
			mwse::log::getLog() << "xSetSkillInfo: Specialization out of range." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get skill info.
		TES3::Skill& skillInfo = tes3::getCellMaster()->recordLists->skills[skillIndex];

		// Store old specialization for future check.
		mwLong oldSpecialization = skillInfo.specialization;

		// Set skill info values.
		skillInfo.attribute = attributeId;
		skillInfo.specialization = specialization;
		skillInfo.actions[0] = action1;
		skillInfo.actions[1] = action2;
		skillInfo.actions[2] = action3;
		skillInfo.actions[4] = action4;

		// If our specialization changed, check for a skill level up.
		if (oldSpecialization != specialization) {
			tes3::checkForSkillUp(virtualMachine.getReference(), skillIndex);
		}

		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}