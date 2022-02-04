#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

namespace mwse {
	class xSetRef : public InstructionInterface_t {
	public:
		xSetRef();
		virtual float execute(VMExecuteInterface& virtualMachine);
	};

	static xSetRef xSetRefInstance;

	xSetRef::xSetRef() : InstructionInterface_t(OpCode::xSetRef) {}

	float xSetRef::execute(VMExecuteInterface& virtualMachine) {
		TES3::Reference* reference = reinterpret_cast<TES3::Reference*>(Stack::getInstance().popLong());
		virtualMachine.setReference(reference);
		return 0.0f;
	}
}
