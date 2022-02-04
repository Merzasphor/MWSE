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
	class xStartCombat : mwse::InstructionInterface_t
	{
	public:
		xStartCombat();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xStartCombat xStartCombatInstance;

	xStartCombat::xStartCombat() : mwse::InstructionInterface_t(OpCode::xStartCombat) {}

	void xStartCombat::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xStartCombat::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		TES3::Reference* target = reinterpret_cast<TES3::Reference*>(mwse::Stack::getInstance().popLong());

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xStartCombat: Called on invalid reference." << std::endl;
#endif
			return 0.0f;
		}

		// Call the original function.
		TES3::Script* script = virtualMachine.getScript();
		mwse::mwscript::StartCombat(script, reference, target);

		return 0.0f;
	}
}