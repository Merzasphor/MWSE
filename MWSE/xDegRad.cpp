#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xDegRad : mwse::InstructionInterface_t
	{
	public:
		xDegRad();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xDegRad xDegRadInstance;

	xDegRad::xDegRad() : mwse::InstructionInterface_t(OpCode::xDegRad) {}

	void xDegRad::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xDegRad::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		float param = mwse::Stack::getInstance().popFloat();

		mwse::Stack::getInstance().pushFloat(param * M_PI / 180);
		return 0.0f;
	}
}