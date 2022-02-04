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
	class xGetBaseFatigue : mwse::InstructionInterface_t
	{
	public:
		xGetBaseFatigue();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const float INVALID_VALUE = -1.0f;
	};

	static xGetBaseFatigue xGetBaseFatigueInstance;

	xGetBaseFatigue::xGetBaseFatigue() : mwse::InstructionInterface_t(OpCode::xGetBaseFatigue) {}

	void xGetBaseFatigue::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetBaseFatigue::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get the associated MACP record.
		TES3::Reference* reference = virtualMachine.getReference();
		auto mobileObject = reference->getAttachedMobileActor();
		if (mobileObject == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseFatigue: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Push the base value of that skill.
		mwse::Stack::getInstance().pushFloat(mobileObject->fatigue.base);

		return 0.0f;
	}
}