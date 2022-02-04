/************************************************************************
	
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
		mobileObject->progressSkillLevelIfRequirementsMet(skillIndex);

		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}