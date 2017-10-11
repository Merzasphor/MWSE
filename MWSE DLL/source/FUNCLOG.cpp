//FuncLog.cpp

#include "FUNCLOG.h"
#include "cLog.h"
#include "DEBUGGING.h"
#include "FUNCTEXT.h"

FUNCLOG::FUNCLOG(TES3MACHINE& vm) :	machine(vm)
{
}

// 2005-06-28  CDC reworked for better formatting options (.4f notation)
bool FUNCLOG::execute(void)
{
	bool result = false;
	const char* format;
	VMREGTYPE pFormat = 0;
	if(machine.pop(pFormat) 
		&& (format = machine.GetString((VPVOID)pFormat)) != 0) {
			bool suppress_null = false;
			std::string bad_codes;
			std::string new_string = interpolate(format, &machine,
				&suppress_null, &bad_codes);
			if (bad_codes != "") {
				cLog::mLogMessage(
				"xLogMessage: bad format \"%s\" in \"%s\" generating \"%s\"\n",
				bad_codes.c_str(), format, new_string.c_str());
			}
			new_string += '\n';
			cLog::mLogMessage("%s", new_string.c_str());
	}
	return result;
}
