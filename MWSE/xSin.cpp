#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xSin : mwse::InstructionInterface_t
	{
	public:
		xSin();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSin xSinInstance;

	xSin::xSin() : mwse::InstructionInterface_t(OpCode::xSin) {}

	void xSin::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSin::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwse::Stack::getInstance().pushFloat(std::sin(mwse::Stack::getInstance().popFloat()));
		return 0.0f;
	}
}