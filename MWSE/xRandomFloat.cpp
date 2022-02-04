#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "RngUtil.h"

namespace mwse {
	class xRandomFloat : InstructionInterface_t {
	public:
		xRandomFloat();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xRandomFloat xRandomFloatInstance;

	xRandomFloat::xRandomFloat() : mwse::InstructionInterface_t(OpCode::xRandomFloat) {}

	float xRandomFloat::execute(mwse::VMExecuteInterface& virtualMachine) {
		float min = mwse::Stack::getInstance().popFloat();
		float max = mwse::Stack::getInstance().popFloat();

		mwse::Stack::getInstance().pushFloat(mwse::rng::getRandomFloat(min, max));

		return 0.0f;
	}
}
