#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "Log.h"
#include "StringUtil.h"

using namespace mwse;

namespace mwse
{
	class xStringMatch : mwse::InstructionInterface_t
	{
	public:
		xStringMatch();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xStringMatch xStringMatchInstance;

	xStringMatch::xStringMatch() : mwse::InstructionInterface_t(OpCode::xStringMatch) {}

	void xStringMatch::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xStringMatch::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwseString& string = virtualMachine.getString(Stack::getInstance().popLong());
		mwseString& pattern = virtualMachine.getString(Stack::getInstance().popLong());

		bool result = false;
		try {
			result = boost::regex_search(string, boost::regex(pattern));
		}
		catch (boost::regex_error&) {
			result = false;
		}

		mwse::Stack::getInstance().pushLong(result);

		return 0.0f;
	}
}