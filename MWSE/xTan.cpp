#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xTan : mwse::InstructionInterface_t
	{
	public:
		xTan();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xTan xTanInstance;

	xTan::xTan() : mwse::InstructionInterface_t(OpCode::xTan) {}

	void xTan::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xTan::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwse::Stack::getInstance().pushFloat(std::tan(mwse::Stack::getInstance().popFloat()));
		return 0.0f;
	}
}