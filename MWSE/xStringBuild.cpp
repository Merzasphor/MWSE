#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "Log.h"
#include "StringUtil.h"

using namespace mwse;

namespace mwse
{
	class xStringBuild : mwse::InstructionInterface_t
	{
	public:
		xStringBuild();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xStringBuild xStringBuildInstance;

	xStringBuild::xStringBuild() : mwse::InstructionInterface_t(OpCode::xStringBuild) {}

	void xStringBuild::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xStringBuild::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwseString& format = virtualMachine.getString(Stack::getInstance().popLong());

		bool suppressNull = false;
		std::string badCodes;

		std::string result = mwse::string::interpolate(format, virtualMachine, &suppressNull, &badCodes);
		if (!badCodes.empty()) {
			mwse::log::getLog() << "xLogMessage: bad format \"" << badCodes << "\" in \"" << format << "\" generating \"" << result << "\"" << badCodes << std::endl;
		}

		mwse::Stack::getInstance().pushString(result);

		return 0.0f;
	}
}