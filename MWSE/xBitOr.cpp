/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xBitOr : mwse::InstructionInterface_t
	{
	public:
		xBitOr();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xBitOr xBitOrInstance;

	xBitOr::xBitOr() : mwse::InstructionInterface_t(OpCode::xBitOr) {}

	void xBitOr::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xBitOr::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long param1 = mwse::Stack::getInstance().popLong();
		long param2 = mwse::Stack::getInstance().popLong();

		mwse::Stack::getInstance().pushLong(param1 | param2);

		return 0.0f;
	}
}