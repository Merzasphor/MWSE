/************************************************************************
	
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
	class xGetSpellEffects : mwse::InstructionInterface_t
	{
	public:
		xGetSpellEffects();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetSpellEffects xGetSpellEffectsInstance;

	xGetSpellEffects::xGetSpellEffects() : mwse::InstructionInterface_t(OpCode::xGetSpellEffects) {}

	void xGetSpellEffects::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xGetSpellEffects::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter.
		mwseString& id = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetSpellEffects: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get spell template by the id.
		TES3::BaseObject* spellTemplate = virtualMachine.getTemplate(id.c_str());
		if (spellTemplate == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetSpellEffects: No template found with id '" << id << "'." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Call the original function.
		TES3::Script* script = virtualMachine.getScript();
		bool result = mwse::mwscript::GetSpellEffects(script, reference, spellTemplate);

		mwse::Stack::getInstance().pushLong(result);

		return 0.0f;
	}
}