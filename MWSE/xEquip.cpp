#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "mwAdapter.h"
#include "VirtualMachine.h"
#include "ScriptUtil.h"

using namespace mwse;

namespace mwse
{
	class xEquip : mwse::InstructionInterface_t
	{
	public:
		xEquip();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xEquip xEquipInstance;

	xEquip::xEquip() : mwse::InstructionInterface_t(OpCode::xEquip) {}

	void xEquip::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xEquip::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& id = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xEquip: Called on invalid reference." << std::endl;
#endif
			return 0.0f;
		}

		// Get spell template by the id.
		TES3::BaseObject* itemTemplate = virtualMachine.getTemplate(id.c_str());
		if (itemTemplate == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xAddSpell: No template found with id '" << id << "'." << std::endl;
#endif
			return 0.0f;
		}

		// Call the original function.
		TES3::Script* script = virtualMachine.getScript();
		mwse::mwscript::Equip(script, reference, itemTemplate);

		return 0.0f;
	}
}