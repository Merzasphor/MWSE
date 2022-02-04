#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include "TES3ItemData.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xSetCondition : mwse::InstructionInterface_t
	{
	public:
		xSetCondition();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetCondition xSetConditionInstance;

	xSetCondition::xSetCondition() : mwse::InstructionInterface_t(OpCode::xSetCondition) {}

	void xSetCondition::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetCondition::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter.
		long value = Stack::getInstance().popLong();

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			log::getLog() << "xSetCondition: No reference provided." << std::endl;
#endif
			Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		// Get associated varnode, and the condition from it.
		auto varNode = reference->getAttachedItemData();
		if (varNode != NULL) {
			varNode->condition = value;
		}
		else {
#if _DEBUG
			log::getLog() << "xSetCondition: Could not get attached VARNODE." << std::endl;
#endif
			Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		Stack::getInstance().pushShort(1);

		return 0.0f;
	}
}