#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xBitAnd : mwse::InstructionInterface_t
	{
	public:
		xBitAnd();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xBitAnd xBitAndInstance;

	xBitAnd::xBitAnd() : mwse::InstructionInterface_t(OpCode::xBitAnd) {}

	void xBitAnd::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xBitAnd::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long param1 = mwse::Stack::getInstance().popLong();
		long param2 = mwse::Stack::getInstance().popLong();

		mwse::Stack::getInstance().pushLong(param1 & param2);

		return 0.0f;
	}
}