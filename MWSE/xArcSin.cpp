#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xArcSin : mwse::InstructionInterface_t
	{
	public:
		xArcSin();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xArcSin xArcSinInstance;

	xArcSin::xArcSin() : mwse::InstructionInterface_t(OpCode::xArcSin) {}

	void xArcSin::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xArcSin::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwse::Stack::getInstance().pushFloat(std::asin(mwse::Stack::getInstance().popFloat()));
		return 0.0f;
	}
}