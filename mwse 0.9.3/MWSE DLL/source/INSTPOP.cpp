//InstPop.cpp

#include "INSTPOP.h"
#include "DEBUGGING.h"

INSTPOP::INSTPOP(VIRTUALMACHINE& vm) : machine(vm)
{
}

int INSTPOP::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	
	if(machine.ReadMem(operanddata,&stackincrease,sizeof(stackincrease)))
		result= sizeof(stackincrease);
	else
		result= -1;
		
	return result;
}

bool INSTPOP::execute(void)
{
	VMREGTYPE stackpointer= 0;
	
	bool result= machine.GetRegister(SP,stackpointer)
		&& machine.SetRegister(SP,stackpointer+stackincrease);
		
#ifdef DEBUGGING
	cLog::mLogMessage("INSTPOP(%d) %s\n",(int)stackincrease,result?"succeeded":"failed");
#endif	
	return result;
}

INSTPOPREG::INSTPOPREG(VIRTUALMACHINE& vm) : machine(vm)
{
}

int INSTPOPREG::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	
	if(machine.ReadMem(operanddata,&regidx,sizeof(regidx)))
		result= sizeof(regidx);
	else
		result= -1;
		
	return result;
}

bool INSTPOPREG::execute(void)
{
	VMREGTYPE val= 0;
	
	bool result= machine.pop(val) && machine.SetRegister(GP+regidx,val);
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTPOPREG(REG%d) %s\n",val,(int)GP+regidx,result?"succeeded":"failed");
#endif	
	return result;
}
