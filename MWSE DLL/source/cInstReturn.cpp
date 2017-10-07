#include "cInstReturn.h"
#include "cLog.h"

int cInstReturn::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	return 0;
}

bool cInstReturn::execute()
{
	VMREGTYPE ip = 0;
	bool result = machine.pop(ip)
		&& machine.SetRegister(IP, ip);

#ifdef DEBUGGING
	cLog::mLogMessage("cInstReturn(%lx) %s\n", ip, result?"succeeded":"failed");
#endif

	return result;
}