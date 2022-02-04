#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xArcTan2 : mwse::InstructionInterface_t
	{
	public:
		xArcTan2();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xArcTan2 xArcTan2Instance;

	xArcTan2::xArcTan2() : mwse::InstructionInterface_t(OpCode::xArcTan2) {}

	void xArcTan2::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xArcTan2::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		float param1 = mwse::Stack::getInstance().popFloat();
		float param2 = mwse::Stack::getInstance().popFloat();

		mwse::Stack::getInstance().pushFloat(std::atan2(param1, param2));

		return 0.0f;
	}
}
