#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include "TES3MobileNPC.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xSetGold : mwse::InstructionInterface_t
	{
	public:
		xSetGold();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetGold xSetGoldInstance;

	xSetGold::xSetGold() : mwse::InstructionInterface_t(OpCode::xSetGold) {}

	void xSetGold::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetGold::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long gold = mwse::Stack::getInstance().popLong();

		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == nullptr) {
#if _DEBUG
			mwse::log::getLog() << "xSetGold: No reference provided." << std::endl;
#endif
			return 0.0f;
		}

		TES3::MobileActor* mobile = reference->getAttachedMobileActor();
		if (mobile == nullptr) {
#if _DEBUG
			mwse::log::getLog() << "xSetGold: Could not find attached mobile actor." << std::endl;
#endif
			return 0.0f;
		}

		mobile->barterGold = gold;

		return 0.0f;
	}
}