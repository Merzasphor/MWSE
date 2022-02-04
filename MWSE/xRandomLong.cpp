#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "RngUtil.h"

using namespace mwse;

namespace mwse
{
	class xRandomLong : mwse::InstructionInterface_t
	{
	public:
		xRandomLong();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xRandomLong xRandomLongInstance;

	xRandomLong::xRandomLong() : mwse::InstructionInterface_t(OpCode::xRandomLong) {}

	void xRandomLong::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xRandomLong::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long min = mwse::Stack::getInstance().popLong();
		long max= mwse::Stack::getInstance().popLong();

		mwse::Stack::getInstance().pushLong(mwse::rng::getRandomLong(min, max));

		return 0.0f;
	}
}