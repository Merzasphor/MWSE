/************************************************************************
	
	xGetSkillInfo.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3DataHandler.h"
#include "TES3MobileActor.h"
#include "TES3Skill.h"

using namespace mwse;

namespace mwse
{
	class xGetSkillInfo : mwse::InstructionInterface_t
	{
	public:
		xGetSkillInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const float INVALID_VALUE = -1.0f;
	};

	static xGetSkillInfo xGetSkillInfoInstance;

	xGetSkillInfo::xGetSkillInfo() : mwse::InstructionInterface_t(OpCode::xGetSkillInfo) {}

	void xGetSkillInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetSkillInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter.
		long skillIndex = Stack::getInstance().popLong();

		// Return values.
		long attributeId = TES3::Attribute::Invalid;
		long specialization = TES3::SkillSpecialization::Invalid;
		float actions[4] = { INVALID_VALUE, INVALID_VALUE, INVALID_VALUE, INVALID_VALUE };

		// Validate skill index.
		if (skillIndex >= TES3::SkillID::FirstSkill && skillIndex <= TES3::SkillID::LastSkill) {
			TES3::DataHandler* dataHandler = TES3::DataHandler::get();
			const TES3::Skill& skillRecord = dataHandler->nonDynamicData->skills[skillIndex];
			attributeId = skillRecord.governingAttribute;
			specialization = skillRecord.specialization;
			for (size_t i = 0; i < 4; i++) {
				actions[i] = skillRecord.progressActions[i];
			}
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetSkillInfo: Skill index out of range." << std::endl;
#endif
		}

		// Push desired values.
		mwse::Stack::getInstance().pushFloat(actions[3]);
		mwse::Stack::getInstance().pushFloat(actions[2]);
		mwse::Stack::getInstance().pushFloat(actions[1]);
		mwse::Stack::getInstance().pushFloat(actions[0]);
		mwse::Stack::getInstance().pushLong(specialization);
		mwse::Stack::getInstance().pushLong(attributeId);

		return 0.0f;
	}
}