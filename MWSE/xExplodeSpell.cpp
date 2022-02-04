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
	class xExplodeSpell : mwse::InstructionInterface_t
	{
	public:
		xExplodeSpell();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xExplodeSpell xExplodeSpellInstance;

	xExplodeSpell::xExplodeSpell() : mwse::InstructionInterface_t(OpCode::xExplodeSpell) {}

	void xExplodeSpell::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xExplodeSpell::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& id = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xExplodeSpell: Called on invalid reference." << std::endl;
#endif
			return 0.0f;
		}

		// Get spell template by the id.
		TES3::BaseObject* spellTemplate = virtualMachine.getTemplate(id.c_str());
		if (spellTemplate == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xExplodeSpell: No template found with id '" << id << "'." << std::endl;
#endif
			return 0.0f;
		}

		// Call the original function.
		TES3::Script* script = virtualMachine.getScript();
		mwse::mwscript::ExplodeSpell(script, reference, spellTemplate);

		return 0.0f;
	}
}