#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	class xSin : InstructionInterface_t {
	public:
		xSin();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xSin xSinInstance;

	xSin::xSin() : mwse::InstructionInterface_t(OpCode::xSin) {}

	float xSin::execute(mwse::VMExecuteInterface& virtualMachine) {
		mwse::Stack::getInstance().pushFloat(std::sin(mwse::Stack::getInstance().popFloat()));
		return 0.0f;
	}
}
