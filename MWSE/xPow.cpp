#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xPow : mwse::InstructionInterface_t
	{
	public:
		xPow();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xPow xPowInstance;

	xPow::xPow() : mwse::InstructionInterface_t(OpCode::xPow) {}

	void xPow::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xPow::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		float base = mwse::Stack::getInstance().popFloat();
		float exponent = mwse::Stack::getInstance().popFloat();

		mwse::Stack::getInstance().pushFloat(std::powf(base, exponent));

		return 0.0f;
	}
}