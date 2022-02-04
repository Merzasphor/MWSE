#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include "TES3DataHandler.h"
#include "TES3GameSetting.h"

using namespace mwse;

namespace mwse
{
	class xGetGSString : mwse::InstructionInterface_t
	{
	public:
		xGetGSString();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetGSString xGetGSStringInstance;

	xGetGSString::xGetGSString() : mwse::InstructionInterface_t(OpCode::xGetGSString) {}

	void xGetGSString::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetGSString::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long gmstId = Stack::getInstance().popLong();

		if (gmstId < 0) {
			mwse::log::getLog() << "xGetGSString: Invalid GMST id." << std::endl;
			mwse::Stack::getInstance().pushLong(NULL);
			return 0.0f;
		}

		// Get the string. No real sanity checks here...
		char * value = TES3::DataHandler::get()->nonDynamicData->GMSTs[gmstId]->value.asString;

		mwse::Stack::getInstance().pushString(value);

		return 0.0f;
	}
}