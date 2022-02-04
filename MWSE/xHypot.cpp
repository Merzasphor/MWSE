#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xHypot : mwse::InstructionInterface_t
	{
	public:
		xHypot();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xHypot xHypotInstance;

	xHypot::xHypot() : mwse::InstructionInterface_t(OpCode::xHypot) {}

	void xHypot::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xHypot::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		float param1 = mwse::Stack::getInstance().popFloat();
		float param2 = mwse::Stack::getInstance().popFloat();

		mwse::Stack::getInstance().pushFloat(std::hypotf(param1, param2));

		return 0.0f;
	}
}