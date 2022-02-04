#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xRadDeg : mwse::InstructionInterface_t
	{
	public:
		xRadDeg();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xRadDeg xRadDegInstance;

	xRadDeg::xRadDeg() : mwse::InstructionInterface_t(OpCode::xRadDeg) {}

	void xRadDeg::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xRadDeg::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwse::Stack::getInstance().pushFloat(mwse::Stack::getInstance().popFloat() / M_PI * 180);
		return 0.0f;
	}
}