/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "ArrayUtil.h"

using namespace mwse;

namespace mwse
{
	class xGetArraySize : mwse::InstructionInterface_t
	{
	public:
		xGetArraySize();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetArraySize xGetArraySizeInstance;

	xGetArraySize::xGetArraySize() : mwse::InstructionInterface_t(OpCode::xGetArraySize) {}

	void xGetArraySize::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetArraySize::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 1) {
			mwse::log::getLog() << "xGetArraySize: Function called with no arguments." << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		long id = mwse::Stack::getInstance().popLong();

		long size = mwse::Arrays::getInstance().getSize("xGetArraySize", id);

		mwse::Stack::getInstance().pushLong(size);

		return 0.0f;
	}
}