#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	//----------------------------------------
	class Pop : public InstructionInterface_t {
	public:
		Pop();
		virtual float execute(VMExecuteInterface& virtualMachine);
		virtual void loadParameters(VMExecuteInterface& virtualMachine);
	protected:
	private:
		short popLength;
	};

	static Pop popInstance;

	Pop::Pop() : InstructionInterface_t(OpCode::_Pop) {}

	void Pop::loadParameters(mwse::VMExecuteInterface& virtualMachine) {
		popLength = virtualMachine.getShortValue();
	}

	float Pop::execute(mwse::VMExecuteInterface& virtualMachine) {
		short items = popLength / 4; //number of items to throw off the stack
		Stack::getInstance().popFrames(items);
		return 0.0f;
	}
	//----------------------------------------
}