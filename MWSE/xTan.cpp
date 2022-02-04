#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	class xTan : InstructionInterface_t {
	public:
		xTan();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xTan xTanInstance;

	xTan::xTan() : mwse::InstructionInterface_t(OpCode::xTan) {}

	float xTan::execute(mwse::VMExecuteInterface& virtualMachine) {
		mwse::Stack::getInstance().pushFloat(std::tan(mwse::Stack::getInstance().popFloat()));
		return 0.0f;
	}
}
