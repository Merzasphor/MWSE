#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "Log.h"
#include "StringUtil.h"

using namespace mwse;

namespace mwse
{
	class xStringLength : mwse::InstructionInterface_t
	{
	public:
		xStringLength();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xStringLength xStringLengthInstance;

	xStringLength::xStringLength() : mwse::InstructionInterface_t(OpCode::xStringLength) {}

	void xStringLength::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xStringLength::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwseString& parameter = virtualMachine.getString(Stack::getInstance().popLong());

		long result = parameter.length();

		mwse::Stack::getInstance().pushLong(result);

		return 0.0f;
	}
}