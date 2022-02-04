#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3Reference.h"
#include "TES3Enchantment.h"

using namespace mwse;

namespace mwse
{
	class xGetMaxCharge : mwse::InstructionInterface_t
	{
	public:
		xGetMaxCharge();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const float INVALID_VALUE = -1.0f;
	};

	static xGetMaxCharge xGetMaxChargeInstance;

	xGetMaxCharge::xGetMaxCharge() : mwse::InstructionInterface_t(OpCode::xGetMaxCharge) {}

	void xGetMaxCharge::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetMaxCharge::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		float charge = 0.0f;

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetMaxCharge: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get the base record.
		TES3::BaseObject* object = reference->baseObject;
		if (object == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetMaxCharge: No record found for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get  the maximum charge from the enchantment record.
		TES3::Enchantment* enchantment = object->vTable.object->getEnchantment(object);
		if (enchantment) {
			charge = enchantment->maxCharge;
		}

		mwse::Stack::getInstance().pushFloat(charge);

		return 0.0f;
	}
}