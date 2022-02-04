#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse {
	class xRefID : mwse::InstructionInterface_t {
	public:
		xRefID();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xRefID xRefIDInstance;

	xRefID::xRefID() : mwse::InstructionInterface_t(OpCode::xRefID) {}

	void xRefID::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xRefID::execute(mwse::VMExecuteInterface &virtualMachine) {
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xRefID: Called on invalid reference." << std::endl;
#endif
			return 0.0f;
		}

		const char* objectId = reference->baseObject->getObjectID();

		Stack::getInstance().pushString(objectId);

		return 0.0f;
	}
}