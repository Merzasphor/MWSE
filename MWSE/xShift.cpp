#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xShift : mwse::InstructionInterface_t
	{
	public:
		xShift();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xShift xShiftInstance;

	xShift::xShift() : mwse::InstructionInterface_t(OpCode::xShift) {}

	void xShift::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xShift::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long value = mwse::Stack::getInstance().popLong();
		long magnitude = mwse::Stack::getInstance().popLong();

		if (magnitude < 0) {
			mwse::Stack::getInstance().pushLong(value >> abs(magnitude));
		} else {
			mwse::Stack::getInstance().pushLong(value << magnitude);
		}

		return 0.0f;
	}
}