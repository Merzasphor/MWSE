
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

#include "CodePatchUtil.h"

namespace mwse {
	class xGetMCPFeatureState : mwse::InstructionInterface_t {
	public:
		xGetMCPFeatureState();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetMCPFeatureState xGetMCPFeatureStateInstance;

	xGetMCPFeatureState::xGetMCPFeatureState() : mwse::InstructionInterface_t(OpCode::xGetMCPFeatureState) {}

	void xGetMCPFeatureState::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetMCPFeatureState::execute(mwse::VMExecuteInterface &virtualMachine) {
		mwLong id = mwse::Stack::getInstance().popLong();

		if (mwse::mcp::hasFeaturesFound()) {
			bool enabled = mwse::mcp::getFeatureEnabled(id);
			mwse::Stack::getInstance().pushShort(enabled);
		}
		else {
			mwse::Stack::getInstance().pushShort(-1);
		}

		return 0.0f;
	}
}