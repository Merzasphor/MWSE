#include "cInstCopyFromStack.h"
#include "cLog.h"

int cInstCopyFromStack::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result = -1;

	if(machine.ReadMem(operanddata, &stackpos, sizeof(stackpos)))
		result = sizeof(stackpos);
	else
		result = -1;

	return result;
}

bool cInstCopyFromStack::execute()
{
	VMREGTYPE stackpointer = 0;
	VMREGTYPE value = 0;

	bool result = machine.GetRegister(SP, stackpointer)
		&& machine.ReadMem((VPVOID)stackpointer + stackpos, &value, sizeof(value))
		&& machine.push(value);

#ifdef DEBUGGING
	cLog::mLogMessage("%lx= cInstCopyFromStack(%d) %s\n",value,(int)stackpos,result?"succeeded":"failed");
#endif

	return result;
}