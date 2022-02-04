#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include "TES3ItemData.h"
#include "TES3Reference.h"

namespace mwse {
	class xGetStackSize : mwse::InstructionInterface_t {
	public:
		xGetStackSize();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetStackSize xGetStackSizeInstance;

	xGetStackSize::xGetStackSize() : mwse::InstructionInterface_t(OpCode::xGetStackSize) {}

	void xGetStackSize::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetStackSize::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetStackSize: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get the associated variable node and its item count.
		long count = 0;
		auto varNode = reference->getAttachedItemData();
		if (varNode) {
			count = varNode->count;
		}

		mwse::Stack::getInstance().pushLong(count);

		return 0.0f;
	}
}