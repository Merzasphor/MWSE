//InstPush.cpp

#include "INSTPUSH.h"
#include "DEBUGGING.h"

INSTPUSH::INSTPUSH(VIRTUALMACHINE& vm) : machine(vm)
{
}

int INSTPUSH::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	if(machine.ReadMem(operanddata,&value,sizeof(value)))
		result= sizeof(value);
	else
		result= -1;
		
	return result;
}

bool INSTPUSH::execute(void)
{
	bool result= machine.push(value);
	
#ifdef DEBUGGING
	cLog::mLogMessage("INSTPUSH(%lx or %f) %s\n",value,*(float*)&value,result?"succeeded":"failed");
#endif	
	return result;
}

INSTPUSHB::INSTPUSHB(VIRTUALMACHINE& vm) : machine(vm)
{
}

int INSTPUSHB::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	if(machine.ReadMem(operanddata,&value,sizeof(value)))
		result= sizeof(value);
	else
		result= -1;
		
	return result;
}

bool INSTPUSHB::execute(void)
{
	VMREGTYPE val= value;
	bool result= machine.push(val);
	
#ifdef DEBUGGING
	cLog::mLogMessage("INSTPUSHB(%lx or %f) %s\n",val,*(float*)&val,result?"succeeded":"failed");
#endif	
	return result;
}

INSTPUSHS::INSTPUSHS(VIRTUALMACHINE& vm) : machine(vm)
{
}

int INSTPUSHS::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	if(machine.ReadMem(operanddata,&value,sizeof(value)))
		result= sizeof(value);
	else
		result= -1;
		
	return result;
}

bool INSTPUSHS::execute(void)
{
	VMREGTYPE val= value;
	bool result= machine.push(val);
#ifdef DEBUGGING
	cLog::mLogMessage("INSTPUSHS(%lx or %f) %s\n",val,*(float*)&val,result?"succeeded":"failed");
#endif	
	return result;
}

INSTPUSHREG::INSTPUSHREG(VIRTUALMACHINE& vm) : machine(vm)
{
}

int INSTPUSHREG::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	if(machine.ReadMem(operanddata,&regidx,sizeof(regidx)))
		result= sizeof(regidx);
	else
		result= -1;
		
	return result;
}

bool INSTPUSHREG::execute(void)
{
	bool result= false;
	
	VMREGTYPE value= 0;
	if(machine.GetRegister(GP+regidx,value))
		result= machine.push(value);
		
#ifdef DEBUGGING
	cLog::mLogMessage("%lx or %f = INSTPUSHREG(REG%d) %s\n",
		value,*(float*)&value,GP+regidx,result?"succeeded":"failed");
#endif	
	return result;
}

INSTDECLARELOCAL::INSTDECLARELOCAL(VIRTUALMACHINE& vm) : machine(vm)
{
}

int INSTDECLARELOCAL::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	if(machine.ReadMem(operanddata,&localsize,sizeof(localsize)))
		result= sizeof(localsize);
	else
		result= -1;
		
	return result;
}

bool INSTDECLARELOCAL::execute(void)
{
	bool result= false;
	
	VMREGTYPE sp= 0;
	VMREGTYPE value= 0;
	if(machine.GetRegister(SP,sp))
	{
		sp-= localsize;
		result= machine.SetRegister(SP,sp);
		if(result && localsize>0)
		{
			VMBYTE buf[VMBYTE_MAX]={0};
			machine.WriteMem((VPVOID)sp,buf,localsize);
		}
	}
		
#ifdef DEBUGGING
	TES3MACHINE* vm= (TES3MACHINE*)(&machine);
	vm->dumpscriptstack();
	cLog::mLogMessage("INSTDECLARELOCAL(%d) %s\n",(int)localsize,result?"succeeded":"failed");
#endif	
	return result;
}
