#include "cInstCallShort.h"
#include "cLog.h"

int cInstCallShort::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result = -1;
	VMSHORT func = 0;

	if(machine.ReadMem(operanddata, &func, sizeof(func)))
	{
		result = sizeof(func);
		function = (VPVOID)((int)func);
	}
	else
		result = -1;

	return result;
}

bool cInstCallShort::execute()
{
	VMREGTYPE ip = 0;
	bool result = machine.GetRegister(IP, ip)
		&& machine.push(ip)
		&& machine.SetRegister(IP, (VMREGTYPE)function);

#ifdef DEBUGGING
	cLog::mLogMessage("cInstCallShort(%lx) %s\n", function, result?"succeeded":"failed");
#endif
	
	return result;
}