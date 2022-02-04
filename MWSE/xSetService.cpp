#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3NPC.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse {
	class xSetService : mwse::InstructionInterface_t {
	public:
		xSetService();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetService xSetServiceInstance;

	xSetService::xSetService() : mwse::InstructionInterface_t(OpCode::xSetService) {}

	void xSetService::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetService::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get parameters.
		long flags = mwse::Stack::getInstance().popLong() & 0x0003FFFF;

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetService: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Set service mask.
		TES3::AIConfig* aiConfig = reference->baseObject->vTable.object->getAIConfig(reference->baseObject);
		if (aiConfig) {
			aiConfig->merchantFlags = flags;
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xSetService: Could not obtain AI configuration." << std::endl;
#endif
		}

		return 0.0f;
	}
}