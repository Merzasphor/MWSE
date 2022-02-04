#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	class xBitNot : InstructionInterface_t {
	public:
		xBitNot();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xBitNot xBitNotInstance;

	xBitNot::xBitNot() : mwse::InstructionInterface_t(OpCode::xBitNot) {}

	float xBitNot::execute(mwse::VMExecuteInterface& virtualMachine) {
		long param = mwse::Stack::getInstance().popLong();

		mwse::Stack::getInstance().pushLong(~param);

		return 0.0f;
	}
}
