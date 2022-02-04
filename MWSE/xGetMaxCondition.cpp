/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetMaxCondition : mwse::InstructionInterface_t
	{
	public:
		xGetMaxCondition();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetMaxCondition xGetMaxConditionInstance;

	xGetMaxCondition::xGetMaxCondition() : mwse::InstructionInterface_t(OpCode::xGetMaxCondition) {}

	void xGetMaxCondition::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetMaxCondition::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetMaxCondition: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get the max condition.
		TES3::BaseObject* object = reference->baseObject;
		long value = object->vTable.object->getDurability(object);

		mwse::Stack::getInstance().pushLong(value);

		return 0.0f;
	}
}