#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	class xDegRad : InstructionInterface_t {
	public:
		xDegRad();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xDegRad xDegRadInstance;

	xDegRad::xDegRad() : mwse::InstructionInterface_t(OpCode::xDegRad) {}

	float xDegRad::execute(mwse::VMExecuteInterface& virtualMachine) {
		float param = mwse::Stack::getInstance().popFloat();

		mwse::Stack::getInstance().pushFloat(param * M_PI / 180);
		return 0.0f;
	}
}
