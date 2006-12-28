
#include "FUNCLOG.h"
#include "LOG.h"
#include "DEBUGGING.h"
#include "FUNCTEXT.h"

FUNCLOG::FUNCLOG(TES3MACHINE& vm) :	machine(vm)
{
}

// 2005-06-28  CDC reworked for better formatting options (.4f notation)
bool FUNCLOG::execute(void)
{
	bool result= false;

	char buffer[BUFSIZ];
	const char* format;
	VMREGTYPE pFormat= 0;
	int len= 0;
	if(machine.pop(pFormat) && (format=machine.GetString((VPVOID)pFormat))!=0 )
	{
		len = BUFSIZ-1;
		if ( interpolate(machine, format, buffer, len) >= 0 )
		{
			buffer[len-1] = '\n';
			buffer[len] = 0;
		}
		LOG::log("%s",buffer);
	}
	
	return result;
}
