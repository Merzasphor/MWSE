/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xBitNot : mwse::InstructionInterface_t
	{
	public:
		xBitNot();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xBitNot xBitNotInstance;

	xBitNot::xBitNot() : mwse::InstructionInterface_t(OpCode::xBitNot) {}

	void xBitNot::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xBitNot::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long param = mwse::Stack::getInstance().popLong();

		mwse::Stack::getInstance().pushLong(~param);

		return 0.0f;
	}
}