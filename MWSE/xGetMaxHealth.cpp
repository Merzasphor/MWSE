/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3MobileNPC.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetMaxHealth : mwse::InstructionInterface_t
	{
	public:
		xGetMaxHealth();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const float INVALID_VALUE = -1.0f;
	};

	static xGetMaxHealth xGetMaxHealthInstance;

	xGetMaxHealth::xGetMaxHealth() : mwse::InstructionInterface_t(OpCode::xGetMaxHealth) {}

	void xGetMaxHealth::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetMaxHealth::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get the associated MACP record.
		TES3::Reference* reference = virtualMachine.getReference();
		auto mobileObject = reference->getAttachedMobileActor();
		if (mobileObject == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetMaxHealth: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Push the base value of the statistic.
		mwse::Stack::getInstance().pushFloat(mobileObject->health.base);

		return 0.0f;
	}
}