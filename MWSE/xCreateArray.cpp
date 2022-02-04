/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "ArrayUtil.h"

using namespace mwse;

namespace mwse
{
	class xCreateArray : mwse::InstructionInterface_t
	{
	public:
		xCreateArray();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xCreateArray xCreateArrayInstance;

	xCreateArray::xCreateArray() : mwse::InstructionInterface_t(OpCode::xCreateArray) {}

	void xCreateArray::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xCreateArray::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long id = mwse::Arrays::getInstance().create("xCreateArray");

		mwse::Stack::getInstance().pushLong(id);

		return 0.0f;
	}
}