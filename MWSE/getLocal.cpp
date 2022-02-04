#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	//----------------------------------------
	class getLocal : public InstructionInterface_t
	{
	public:
		getLocal();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static getLocal getLocalInstance;

	getLocal::getLocal() : InstructionInterface_t(OpCode::_GetLocal) {}

	float getLocal::execute(mwse::VMExecuteInterface& virtualMachine)
	{
		char type = Stack::getInstance().popByte();
		short index = Stack::getInstance().popShort();

		switch (type)
		{
		case 's':
		{
			Stack::getInstance().pushShort(virtualMachine.getShortVariable(index));
		}
		break;
		case 'l':
		{
			Stack::getInstance().pushLong(virtualMachine.getLongVariable(index));
		}
		break;
		case 'f':
		{
			Stack::getInstance().pushFloat(virtualMachine.getFloatVariable(index));
		}
		break;
		default:
		{
			//throw exception
		}
		break;
		}
		return 0.0f;
	}
	//----------------------------------------

	//----------------------------------------
	class setLocal : public InstructionInterface_t {
	public:
		setLocal();
		virtual float execute(VMExecuteInterface& virtualMachine);
	private:
	};

	static setLocal setLocalInstance;

	setLocal::setLocal() : InstructionInterface_t(OpCode::_SetLocal) {}

	float setLocal::execute(mwse::VMExecuteInterface& virtualMachine) {
		char type = Stack::getInstance().popByte();
		char index = Stack::getInstance().popByte();

		switch (type)
		{
		case 's':
		{
			virtualMachine.setShortVariable(index, Stack::getInstance().popShort());	//get value of stack
		}
		break;
		case 'l':
		{
			virtualMachine.setLongVariable(index, Stack::getInstance().popLong());
		}
		break;
		case 'f':
		{
			virtualMachine.setFloatVariable(index, Stack::getInstance().popFloat());
		}
		break;
		default:
		{
			//throw exception
		}
		break;
		}
		return 0.0f;
	}
	//----------------------------------------
}