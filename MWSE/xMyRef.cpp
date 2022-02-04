#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	class xMyRef : InstructionInterface_t
	{
	public:
		xMyRef();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xMyRef xMyRefInstance;

	xMyRef::xMyRef() : InstructionInterface_t(OpCode::xMyRef) {}

	float xMyRef::execute(mwse::VMExecuteInterface& virtualMachine) {
		// Get the reference.
		TES3::Reference* reference = virtualMachine.getReference();

		// Push back as long.
		Stack::getInstance().pushLong((long)reference);

		return 0.0f;
	}
}
