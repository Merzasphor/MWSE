#include "cInstCopyReg.h"
#include "cLog.h"

int cInstCopyReg::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result = -1;

	if(machine.ReadMem(operanddata, &registers, sizeof(registers)))
		result = sizeof(registers);
	else
		result = -1;

	return result;
}

bool cInstCopyReg::execute()
{
	WORD sourcereg = registers&0x0f;
	WORD destreg = (registers>>4)&0x0f;
	VMREGTYPE value = 0;

	bool result = machine.GetRegister(GP + sourcereg, value)
		&& machine.SetRegister(GP + destreg, value);

#ifdef DEBUGGING
	cLog::mLogMessage("%lx= cInstCopyReg(%d,%d) %s\n",value,destreg,sourcereg,result?"succeeded":"failed");
#endif

	return result;
}