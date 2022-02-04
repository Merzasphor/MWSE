/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "ArrayUtil.h"

using namespace mwse;

namespace mwse
{
	class xGetArrayValue : mwse::InstructionInterface_t
	{
	public:
		xGetArrayValue();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetArrayValue xGetArrayValueInstance;

	xGetArrayValue::xGetArrayValue() : mwse::InstructionInterface_t(OpCode::xGetArrayValue) {}

	void xGetArrayValue::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetArrayValue::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 2) {
			mwse::log::getLog() << "xGetArrayValue: Function requires 2 arguments." << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		long id = mwse::Stack::getInstance().popLong();
		long index = mwse::Stack::getInstance().popLong();

		long value = mwse::Arrays::getInstance().getValue("xGetArrayValue", id, index);

		mwse::Stack::getInstance().pushLong(value);

		return 0.0f;
	}
}