#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3MobileNPC.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetCombat : mwse::InstructionInterface_t
	{
	public:
		xGetCombat();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetCombat xGetCombatInstance;

	xGetCombat::xGetCombat() : mwse::InstructionInterface_t(OpCode::xGetCombat) {}

	void xGetCombat::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetCombat::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get MACP record.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == nullptr) {
#if _DEBUG
			mwse::log::getLog() << "xGetCombat: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		auto mobileObject = reference->getAttachedMobileActor();
		if (mobileObject == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetCombat: No mach node found." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Push the reference of the combat target, or 0 if no target reference is found.
		if (mobileObject->actionData.target && mobileObject->actionData.target->reference) {
			mwse::Stack::getInstance().pushLong((long)mobileObject->actionData.target->reference);
		}
		else {
			mwse::Stack::getInstance().pushLong(0);
		}

		return 0.0f;
	}
}