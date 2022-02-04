/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3NPC.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse {
	class xIsFemale : mwse::InstructionInterface_t {
	public:
		xIsFemale();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xIsFemale xIsFemaleInstance;

	xIsFemale::xIsFemale() : mwse::InstructionInterface_t(OpCode::xIsFemale) {}

	void xIsFemale::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xIsFemale::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xIsFemale: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		long isFemale = reference->baseObject->vTable.object->isFemale(reference->baseObject);
		mwse::Stack::getInstance().pushLong(isFemale);

		return 0.0f;
	}
}