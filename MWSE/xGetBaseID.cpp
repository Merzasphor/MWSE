#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3Reference.h"
#include "TES3Actor.h"

using namespace mwse;

namespace mwse
{
	class xGetBaseID : mwse::InstructionInterface_t
	{
	public:
		xGetBaseID();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetBaseID xGetBaseIDInstance;

	xGetBaseID::xGetBaseID() : mwse::InstructionInterface_t(OpCode::xGetBaseID) {}

	void xGetBaseID::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetBaseID::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseID: Called without reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Push the found objectId.
		const char* objectId = reference->getBaseObject()->getObjectID();
		if (objectId) {
			mwse::Stack::getInstance().pushString(objectId);
		}
		else {
			mwse::Stack::getInstance().pushString("unknown");
		}

		return 0.0f;
	}
}