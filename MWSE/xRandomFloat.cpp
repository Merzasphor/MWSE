/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "RngUtil.h"

using namespace mwse;

namespace mwse
{
	class xRandomFloat : mwse::InstructionInterface_t
	{
	public:
		xRandomFloat();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xRandomFloat xRandomFloatInstance;

	xRandomFloat::xRandomFloat() : mwse::InstructionInterface_t(OpCode::xRandomFloat) {}

	void xRandomFloat::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xRandomFloat::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		float min = mwse::Stack::getInstance().popFloat();
		float max = mwse::Stack::getInstance().popFloat();

		mwse::Stack::getInstance().pushFloat(mwse::rng::getRandomFloat(min, max));

		return 0.0f;
	}
}