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
	class xAITravel : mwse::InstructionInterface_t
	{
	public:
		xAITravel();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xAITravel xAITravelInstance;

	xAITravel::xAITravel() : mwse::InstructionInterface_t(OpCode::xAITravel) {}

	void xAITravel::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xAITravel::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		float x = mwse::Stack::getInstance().popFloat();
		float y = mwse::Stack::getInstance().popFloat();
		float z = mwse::Stack::getInstance().popFloat();

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xAITravel: Called on invalid reference." << std::endl;
#endif
			return 0.0f;
		}

		// Call the original function.
		TES3::Script* script = virtualMachine.getScript();
		mwse::mwscript::AITravel(script, reference, x, y, z);

		return 0.0f;
	}
}