#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "ArrayUtil.h"

using namespace mwse;

namespace mwse
{
	class xClearArray : mwse::InstructionInterface_t
	{
	public:
		xClearArray();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xClearArray xClearArrayInstance;

	xClearArray::xClearArray() : mwse::InstructionInterface_t(OpCode::xClearArray) {}

	void xClearArray::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xClearArray::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 1) {
			mwse::log::getLog() << "xClearArray: Function called with no arguments." << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		long id = mwse::Stack::getInstance().popLong();

		long status = mwse::Arrays::getInstance().clear("xClearArray", id);

		mwse::Stack::getInstance().pushLong(status);

		return 0.0f;
	}
}