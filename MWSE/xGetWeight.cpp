#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include "TES3ItemData.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse {
	class xGetWeight : mwse::InstructionInterface_t {
	public:
		xGetWeight();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetWeight xGetWeightInstance;

	xGetWeight::xGetWeight() : mwse::InstructionInterface_t(OpCode::xGetWeight) {}

	void xGetWeight::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetWeight::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetWeight: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		// Get weight.
		float weight = 0.0f;
		try {
			// Get record.
			auto object = reference->baseObject;
			if (object == NULL) {
				throw std::exception("No base object found.");
			}

			// Get base weight for the record.
			weight = object->getWeight();

			// Multiply the value by the count of the item.
			auto varNode = reference->getAttachedItemData();
			if (varNode) {
				weight *= varNode->count;
			}
		}
		catch (std::exception& e) {
#if _DEBUG
			mwse::log::getLog() << "xGetWeight: " << e.what() << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		mwse::Stack::getInstance().pushFloat(weight);

		return 0.0f;
	}
}