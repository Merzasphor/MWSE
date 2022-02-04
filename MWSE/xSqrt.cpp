#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xSqrt : mwse::InstructionInterface_t
	{
	public:
		xSqrt();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSqrt xSqrtInstance;

	xSqrt::xSqrt() : mwse::InstructionInterface_t(OpCode::xSqrt) {}

	void xSqrt::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSqrt::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwse::Stack::getInstance().pushFloat(std::sqrt(mwse::Stack::getInstance().popFloat()));
		return 0.0f;
	}
}