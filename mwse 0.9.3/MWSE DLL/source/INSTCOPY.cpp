//InstCopy.cpp

#include "INSTCOPY.h"
#include "DEBUGGING.h"
// 22-08-2006 Tp21
#include "warnings.h"

INSTCOPYREG::INSTCOPYREG(VIRTUALMACHINE& vm) : machine(vm)
{
}

int INSTCOPYREG::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	
	if(machine.ReadMem(operanddata,&registers,sizeof(registers)))
		result= sizeof(registers);
	else
		result= -1;
		
	return result;
}

bool INSTCOPYREG::execute(void)
{
	WORD sourcereg= registers&0x0f;
	WORD destreg= (registers>>4)&0x0f;
	VMREGTYPE value= 0;
	
	bool result= machine.GetRegister(GP+sourcereg,value)
		&& machine.SetRegister(GP+destreg,value);
		
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTCOPYREG(%d,%d) %s\n",value,destreg,sourcereg,result?"succeeded":"failed");
#endif	
	return result;
}

INSTCOPYFROMSTACK::INSTCOPYFROMSTACK(VIRTUALMACHINE& vm) : machine(vm)
{
}
int INSTCOPYFROMSTACK::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	
	if(machine.ReadMem(operanddata,&stackpos,sizeof(stackpos)))
		result= sizeof(stackpos);
	else
		result= -1;
		
	return result;
}

bool INSTCOPYFROMSTACK::execute(void)
{
	VMREGTYPE stackpointer= 0;
	VMREGTYPE value= 0;
	
	bool result= machine.GetRegister(SP,stackpointer)
		&& machine.ReadMem((VPVOID)stackpointer+stackpos,&value,sizeof(value))
		&& machine.push(value);
		
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTCOPYFROMSTACK(%d) %s\n",value,(int)stackpos,result?"succeeded":"failed");
#endif	
	return result;
}

INSTCOPYTOSTACK::INSTCOPYTOSTACK(VIRTUALMACHINE& vm) : machine(vm)
{
}

int INSTCOPYTOSTACK::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	
	if(machine.ReadMem(operanddata,&stackpos,sizeof(stackpos)))
		result= sizeof(stackpos);
	else
		result= -1;
		
	return result;
}

bool INSTCOPYTOSTACK::execute(void)
{
	VMREGTYPE stackpointer= 0;
	VMREGTYPE value;
	bool result= machine.GetRegister(SP,stackpointer)
		&& machine.ReadMem((VPVOID)stackpointer,&value,sizeof(value))
		&& machine.WriteMem((VPVOID)stackpointer+stackpos,&value,sizeof(value));
		
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTCOPYTOSTACK(%d) %s\n",value,(int)stackpos,result?"succeeded":"failed");
#endif	
	return result;
}
