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
	class xSetLevel : mwse::InstructionInterface_t
	{
	public:
		xSetLevel();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetLevel xSetLevelInstance;

	xSetLevel::xSetLevel() : mwse::InstructionInterface_t(OpCode::xSetLevel) {}

	void xSetLevel::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xSetLevel::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		short level = mwse::Stack::getInstance().popShort();

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetLevel: Called on invalid reference." << std::endl;
#endif
			return 0.0f;
		}

		// Call the original function.
		TES3::Script* script = virtualMachine.getScript();
		mwse::mwscript::SetLevel(script, reference, level);

		return 0.0f;
	}
}