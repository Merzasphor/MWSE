#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include "TES3MobileNPC.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetBaseAgi : mwse::InstructionInterface_t
	{
	public:
		xGetBaseAgi();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const float INVALID_VALUE = -1.0f;
	};

	static xGetBaseAgi xGetBaseAgiInstance;

	xGetBaseAgi::xGetBaseAgi() : mwse::InstructionInterface_t(OpCode::xGetBaseAgi) {}

	void xGetBaseAgi::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetBaseAgi::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get the associated MACP record.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == nullptr) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseAgi: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		auto mobileObject = reference->getAttachedMobileActor();
		if (mobileObject == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseAgi: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Push the current value of that attribute.
		mwse::Stack::getInstance().pushFloat(mobileObject->attributes[TES3::Attribute::Agility].base);

		return 0.0f;
	}
}