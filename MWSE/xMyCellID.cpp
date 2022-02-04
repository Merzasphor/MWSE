#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3Reference.h"
#include "TES3Cell.h"

using namespace mwse;

namespace mwse
{
	class xMyCellID : mwse::InstructionInterface_t
	{
	public:
		xMyCellID();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xMyCellID xMyCellIDInstance;

	xMyCellID::xMyCellID() : mwse::InstructionInterface_t(OpCode::xMyCellID) {}

	void xMyCellID::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xMyCellID::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xMyCellID: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		TES3::ReferenceList* referenceList = reference->owningCollection.asReferenceList;
		if (referenceList && referenceList->cell) {
			mwse::Stack::getInstance().pushString(referenceList->cell->name);
		}
		else {
			mwse::Stack::getInstance().pushLong(0);
		}

		return 0.0f;
	}
}