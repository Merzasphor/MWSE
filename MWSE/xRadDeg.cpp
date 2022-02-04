#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	class xRadDeg : InstructionInterface_t {
	public:
		xRadDeg();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xRadDeg xRadDegInstance;

	xRadDeg::xRadDeg() : mwse::InstructionInterface_t(OpCode::xRadDeg) {}

	float xRadDeg::execute(mwse::VMExecuteInterface& virtualMachine) {
		mwse::Stack::getInstance().pushFloat(mwse::Stack::getInstance().popFloat() / M_PI * 180);
		return 0.0f;
	}
}
