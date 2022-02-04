#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "mwAdapter.h"
#include "VirtualMachine.h"
#include "ScriptUtil.h"

#include "TES3DataHandler.h"

using namespace mwse;

namespace mwse
{
	class xStartScript : mwse::InstructionInterface_t
	{
	public:
		xStartScript();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xStartScript xStartScriptInstance;

	xStartScript::xStartScript() : mwse::InstructionInterface_t(OpCode::xStartScript) {}

	void xStartScript::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xStartScript::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& scriptName = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Try to get the target script.
		TES3::Script* targetScript = TES3::DataHandler::get()->nonDynamicData->findScriptByName(scriptName.c_str());
		if (targetScript == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xStartScript: No script could be found with name '" << scriptName << "'." << std::endl;
#endif
			return 0.0f;
		}

		// Call the original function.
		TES3::Reference* reference = virtualMachine.getReference();
		TES3::Script* script = virtualMachine.getScript();
		mwse::mwscript::StartScript(script, reference, targetScript);

		return 0.0f;
	}
}