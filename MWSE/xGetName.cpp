#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetName : mwse::InstructionInterface_t
	{
	public:
		xGetName();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetName xGetNameInstance;

	xGetName::xGetName() : mwse::InstructionInterface_t(OpCode::xGetName) {}

	void xGetName::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetName::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetName: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		char* name = NULL;

		// Get the base record.
		TES3::BaseObject* record = reference->baseObject;
		if (record) {
			name = reference->baseObject->vTable.object->getName(reference->baseObject);
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetName: Could not obtain record from reference." << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushString(name);

		return 0.0f;
	}
}