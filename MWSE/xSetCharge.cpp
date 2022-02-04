/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include "TES3ItemData.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse {
	class xSetCharge : mwse::InstructionInterface_t {
	public:
		xSetCharge();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetCharge xSetChargeInstance;

	xSetCharge::xSetCharge() : mwse::InstructionInterface_t(OpCode::xSetCharge) {}

	void xSetCharge::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetCharge::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get charge from parameter.
		float charge = Stack::getInstance().popFloat();

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetCharge: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		// Get the base record.
		TES3::BaseObject* record = reference->baseObject;
		if (record == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetCharge: No record found for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		// Get the charge based on the record type. If the item doesn't have a varnode,
		// return the maximum charge from the enchantment record.
		auto varNode = reference->getAttachedItemData();
		if (varNode) {
			varNode->charge = charge;
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xSetCharge: Could not get attached VARNODE." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		mwse::Stack::getInstance().pushShort(1);

		return 0.0f;
	}
}