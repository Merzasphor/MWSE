/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xOr : mwse::InstructionInterface_t
	{
	public:
		xOr();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xOr xOrInstance;

	xOr::xOr() : mwse::InstructionInterface_t(OpCode::xOr) {}

	void xOr::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xOr::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long param1 = mwse::Stack::getInstance().popLong();
		long param2 = mwse::Stack::getInstance().popLong();

		mwse::Stack::getInstance().pushLong(param1 || param2);

		return 0.0f;
	}
}