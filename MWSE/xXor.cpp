#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	class xXor : InstructionInterface_t {
	public:
		xXor();
		virtual float execute(VMExecuteInterface &virtualMachine);
	};

	static xXor xXorInstance;

	xXor::xXor() : mwse::InstructionInterface_t(OpCode::xXor) {}

	float xXor::execute(mwse::VMExecuteInterface &virtualMachine) {
		long param1 = mwse::Stack::getInstance().popLong();
		long param2 = mwse::Stack::getInstance().popLong();

		mwse::Stack::getInstance().pushLong((param1 || param2) && !(param1 && param2));

		return 0.0f;
	}
}
