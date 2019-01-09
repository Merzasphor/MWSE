/************************************************************************
	
	xGetSkill.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3MobileNPC.h"
#include "TES3Reference.h"
#include "TES3Skill.h"

using namespace mwse;

namespace mwse
{
	class xGetSkill : mwse::InstructionInterface_t
	{
	public:
		xGetSkill();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const float INVALID_VALUE = -1.0f;
	};

	static xGetSkill xGetSkillInstance;

	xGetSkill::xGetSkill() : mwse::InstructionInterface_t(OpCode::xGetSkill) {}

	void xGetSkill::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetSkill::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get skill id argument.
		long skillId = mwse::Stack::getInstance().popLong();
		if (skillId < TES3::SkillID::FirstSkill || skillId > TES3::SkillID::LastSkill) {
#if _DEBUG
			mwse::log::getLog() << "xGetSkill: Invalid skill id: " << skillId << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}
		
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetSkill: Call on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Verify target record type.
		if (reference->baseObject->objectType != TES3::ObjectType::NPC && reference->baseObject->objectType != TES3::ObjectType::Creature) {
#if _DEBUG
			mwse::log::getLog() << "xGetSkill: Reference is not a creature or NPC." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get the associated MACP record.
		auto mobileObject = reference->getAttachedMobileNPC();
		if (mobileObject == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetSkill: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Push the current value of that skill.
		mwse::Stack::getInstance().pushFloat(mobileObject->skills[skillId].current);

		return 0.0f;
	}
}