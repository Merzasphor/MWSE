#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xBitXor : mwse::InstructionInterface_t
	{
	public:
		xBitXor();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xBitXor xBitXorInstance;

	xBitXor::xBitXor() : mwse::InstructionInterface_t(OpCode::xBitXor) {}

	void xBitXor::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xBitXor::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long param1 = mwse::Stack::getInstance().popLong();
		long param2 = mwse::Stack::getInstance().popLong();

		mwse::Stack::getInstance().pushLong(param1 ^ param2);

		return 0.0f;
	}
}