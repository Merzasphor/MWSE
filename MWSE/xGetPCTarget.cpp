#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	class xGetPCTarget : InstructionInterface_t
	{
	public:
		xGetPCTarget();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xGetPCTarget xGetPCTargetInstance;

	xGetPCTarget::xGetPCTarget() : InstructionInterface_t(OpCode::xGetPCTarget) {}

	float xGetPCTarget::execute(mwse::VMExecuteInterface& virtualMachine) {
		//get the current target
		TES3::Reference* target = virtualMachine.getCurrentTarget();

		//push the Reference on the stack.
		Stack::getInstance().pushLong((long)target);

		return 0.0f;
	}
}
