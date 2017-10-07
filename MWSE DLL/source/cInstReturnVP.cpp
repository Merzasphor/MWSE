#include "cInstReturnVP.h"
#include "cLog.h"

int cInstReturnVP::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result = -1;

	if(machine.ReadMem(operanddata, &paramsize, sizeof(paramsize)))
		result = sizeof(paramsize);
	else
		result = -1;

	return result;
}

bool cInstReturnVP::execute()
{
	bool result = false;

	VMREGTYPE funcresult = 0;
	VMREGTYPE ip = 0;
	VMREGTYPE sp = 0;

	if(machine.pop(funcresult)
		&& machine.pop(ip)
		&& machine.GetRegister(SP, sp))
	{
		sp += paramsize;
		result = machine.SetRegister(SP, sp)
			&& machine.push(funcresult)
			&& machine.SetRegister(IP, ip);
	}

#ifdef DEBUGGING
	cLog::mLogMessage("%lx = cInstReturnVP(%lx,%x) %s\n",funcresult,ip,(int)paramsize,result?"succeeded":"failed");
#endif

	return result;
}