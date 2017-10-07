#include "cInstReturnP.h"
#include "cLog.h"

int cInstReturnP::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result = -1;

	if(machine.ReadMem(operanddata, &paramsize, sizeof(paramsize)))
		result = sizeof(paramsize);
	else
		result = -1;

	return result;
}

bool cInstReturnP::execute()
{
	bool result = false;

	VMREGTYPE ip = 0;
	VMREGTYPE sp = 0;

	if(machine.pop(ip)
		&& machine.GetRegister(SP, sp))
	{
		sp += paramsize;
		result = machine.SetRegister(SP, sp)
			&& machine.SetRegister(IP, ip);
	}

#ifdef DEBUGGING
	cLog::mLogMessage("cInstReturnP(%lx, %x) %s\n", ip, (int)paramsize, result?"succeeded":"failed");
#endif

	return result;
}