#include "cInstCall.h"
#include "cLog.h"

int cInstCall::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result = -1;
	
	if(machine.ReadMem(operanddata, &function, sizeof(function)))
		result = sizeof(function);
	else
		result = -1;

	return result;
}

bool cInstCall::execute()
{
	VMREGTYPE ip = 0;
	bool result = machine.GetRegister(IP, ip)
		&& machine.push(ip)
		&& machine.SetRegister(IP, (VMREGTYPE)function);

#ifdef DEBUGGING
	cLog::mLogMessage("cInstCall(%lx) %s\n", function, result?"succeeded":"failed");
#endif

	return result;
}