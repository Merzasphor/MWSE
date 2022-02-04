/************************************************************************
	
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
	class xScriptRunning : mwse::InstructionInterface_t
	{
	public:
		xScriptRunning();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xScriptRunning xScriptRunningInstance;

	xScriptRunning::xScriptRunning() : mwse::InstructionInterface_t(OpCode::xScriptRunning) {}

	void xScriptRunning::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xScriptRunning::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& scriptName = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Try to get the target script.
		TES3::Script* targetScript = TES3::DataHandler::get()->nonDynamicData->findScriptByName(scriptName.c_str());
		if (targetScript == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xScriptRunning: No script could be found with name '" << scriptName << "'." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Call the original function.
		TES3::Script* script = virtualMachine.getScript();
		bool result = mwse::mwscript::ScriptRunning(script, targetScript);

		mwse::Stack::getInstance().pushLong(result);

		return 0.0f;
	}
}