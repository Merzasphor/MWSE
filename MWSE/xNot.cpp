#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xNot : mwse::InstructionInterface_t
	{
	public:
		xNot();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xNot xNotInstance;

	xNot::xNot() : mwse::InstructionInterface_t(OpCode::xNot) {}

	void xNot::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xNot::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long value = mwse::Stack::getInstance().popLong();
		mwse::Stack::getInstance().pushLong(!value);

		return 0.0f;
	}
}