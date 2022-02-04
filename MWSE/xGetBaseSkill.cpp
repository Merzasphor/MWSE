#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3MobileNPC.h"
#include "TES3Skill.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetBaseSkill : mwse::InstructionInterface_t
	{
	public:
		xGetBaseSkill();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const float INVALID_VALUE = -1.0f;
	};

	static xGetBaseSkill xGetBaseSkillInstance;

	xGetBaseSkill::xGetBaseSkill() : mwse::InstructionInterface_t(OpCode::xGetBaseSkill) {}

	void xGetBaseSkill::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetBaseSkill::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 1) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseSkill: Function called with too few arguments." << std::endl;
#endif
			return 0.0f;
		}

		// Get skill id argument.
		long skillId = mwse::Stack::getInstance().popLong();
		if (skillId < TES3::SkillID::FirstSkill || skillId > TES3::SkillID::LastSkill) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseSkill: Invalid skill id: " << skillId << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get the associated MACP record.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == nullptr) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseShortBlade: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		auto mobileObject = reference->getAttachedMobileNPC();
		if (mobileObject == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseSkill: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Push the base value of that skill.
		mwse::Stack::getInstance().pushFloat(mobileObject->skills[skillId].base);

		return 0.0f;
	}
}