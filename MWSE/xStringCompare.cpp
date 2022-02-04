/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "Log.h"
#include "StringUtil.h"

using namespace mwse;

namespace mwse
{
	class xStringCompare : mwse::InstructionInterface_t
	{
	public:
		xStringCompare();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xStringCompare xStringCompareInstance;

	xStringCompare::xStringCompare() : mwse::InstructionInterface_t(OpCode::xStringCompare) {}

	void xStringCompare::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xStringCompare::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwseString& string1 = virtualMachine.getString(Stack::getInstance().popLong());
		mwseString& string2 = virtualMachine.getString(Stack::getInstance().popLong());

		long result = strcmp(string1.c_str(), string2.c_str());

		mwse::Stack::getInstance().pushLong(result);

		return 0.0f;
	}
}