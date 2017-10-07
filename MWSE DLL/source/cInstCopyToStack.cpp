#include "cInstCopyToStack.h"
#include "cLog.h"

int cInstCopyToStack::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result = -1;

	if(machine.ReadMem(operanddata, &stackpos, sizeof(stackpos)))
		result = sizeof(stackpos);
	else
		result = -1;

	return result;
}

bool cInstCopyToStack::execute()
{
	VMREGTYPE stackpointer = 0;
	VMREGTYPE value = 0;

	bool result = machine.GetRegister(SP, stackpointer)
		&& machine.ReadMem((VPVOID)stackpointer, &value, sizeof(value))
		&& machine.WriteMem((VPVOID)stackpointer + stackpos, &value, sizeof(value));

#ifdef DEBUGGING
	cLog::mLogMessage("%lx= cInstCopyToStack(%d) %s\n",value,(int)stackpos,result?"succeeded":"failed");
#endif

	return result;
}