#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	class xArcCos : mwse::InstructionInterface_t
	{
	public:
		xArcCos();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};
	
	static xArcCos xArcCosInstance;

	xArcCos::xArcCos() : mwse::InstructionInterface_t(OpCode::xArcCos) {}

	void xArcCos::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xArcCos::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwse::Stack::getInstance().pushFloat(std::acos(mwse::Stack::getInstance().popFloat()));
		return 0.0f;
	}
}