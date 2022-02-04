#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xArcTan : mwse::InstructionInterface_t
	{
	public:
		xArcTan();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xArcTan xArcTanInstance;

	xArcTan::xArcTan() : mwse::InstructionInterface_t(OpCode::xArcTan) {}

	void xArcTan::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xArcTan::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwse::Stack::getInstance().pushFloat(std::atan(mwse::Stack::getInstance().popFloat()));
		return 0.0f;
	}
}