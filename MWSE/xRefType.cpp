#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xRefType : InstructionInterface_t
	{
	public:
		xRefType();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xRefType xRefTypeInstance;

	xRefType::xRefType() : InstructionInterface_t(OpCode::xRefType) {}

	void xRefType::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xRefType::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		TES3::Reference * refr = virtualMachine.getReference();
		if (refr == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xRefType: Called on invalid reference." << std::endl;
#endif
			Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		TES3::BaseObject * temp = reinterpret_cast<TES3::BaseObject*>(refr->baseObject);

		long type = static_cast<long>(temp->objectType);

		Stack::getInstance().pushLong(type);

		return 0.0f;
	}
}