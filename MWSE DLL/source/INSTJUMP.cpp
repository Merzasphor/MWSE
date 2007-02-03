//InstJump.cpp

#include "INSTJUMP.h"
#include "DEBUGGING.h"
// 22-08-2006 Tp21
#include "warnings.h"

INSTJUMP::INSTJUMP(VIRTUALMACHINE& vm) : machine(vm)
{
}

int INSTJUMP::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	if(machine.ReadMem(operanddata,&position,sizeof(position)))
		result= sizeof(position);
	else
		result= -1;
		
	return result;
}

bool INSTJUMP::execute(void)
{
	bool result= machine.SetRegister(IP,(VMREGTYPE)position);
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTJUMP() %s\n",(long)position,result?"succeeded":"failed");
#endif	
	return result;
}

VIRTUALMACHINE& INSTJUMP::GetMachine(void)
{
	return machine;
}

INSTJUMPZERO::INSTJUMPZERO(VIRTUALMACHINE& vm) : INSTJUMP(vm)
{
}

bool INSTJUMPZERO::execute(void)
{
	bool result= false;
	if(GetMachine().GetFlags()&FZERO)
		result= INSTJUMP::execute();
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTJUMPZERO(%s) %s\n",(long)position,
	(GetMachine().GetFlags()&FZERO)?"ZERO":"NOTZERO",
	result?"succeeded":"failed");
#endif	
	return result;
}


INSTJUMPNOTZERO::INSTJUMPNOTZERO(VIRTUALMACHINE& vm) : INSTJUMP(vm)
{
}

bool INSTJUMPNOTZERO::execute(void)
{
	bool result= false;
	if(!(GetMachine().GetFlags()&FZERO))
		result= INSTJUMP::execute();
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTJUMPNOTZERO(%s) %s\n",(long)position,
	(GetMachine().GetFlags()&FZERO)?"ZERO":"NOTZERO",
	result?"succeeded":"failed");
#endif	
	return result;
}

INSTJUMPPOSITIVE::INSTJUMPPOSITIVE(VIRTUALMACHINE& vm) : INSTJUMP(vm)
{
}

bool INSTJUMPPOSITIVE::execute(void)
{
	bool result= false;
	if((GetMachine().GetFlags()&FPOS))
		result= INSTJUMP::execute();
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTJUMPPOSITIVE(%s) %s\n",(long)position,
	(GetMachine().GetFlags()&FPOS)?"POS":"NEG",
	result?"succeeded":"failed");
#endif	
	return result;
}

INSTJUMPNEGATIVE::INSTJUMPNEGATIVE(VIRTUALMACHINE& vm) : INSTJUMP(vm)
{
}

bool INSTJUMPNEGATIVE::execute(void)
{
	bool result= false;
	if(!(GetMachine().GetFlags()&FPOS))
		result= INSTJUMP::execute();
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTJUMPNEGATIVE(%s) %s\n",(long)position,
	(GetMachine().GetFlags()&FPOS)?"POS":"NEG",
	result?"succeeded":"failed");
#endif	
	return result;
}

INSTJUMPSHORT::INSTJUMPSHORT(VIRTUALMACHINE& vm) : INSTJUMP(vm)
{
}

int INSTJUMPSHORT::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	int result= -1;
	VMSHORT pos= 0;
	if(GetMachine().ReadMem(operanddata,&pos,sizeof(pos)))
	{
		result= sizeof(pos);
// 2005-06-29  CDC  kill the warning about pointer conversion
		position= (VPVOID)((int)pos);
	}
	else
		result= -1;
		
	return result;
}

INSTJUMPSHORTZERO::INSTJUMPSHORTZERO(VIRTUALMACHINE& vm) : INSTJUMPSHORT(vm)
{
}

bool INSTJUMPSHORTZERO::execute(void)
{
	bool result= true;
	if(GetMachine().GetFlags()&FZERO)
		result= INSTJUMP::execute();
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTJUMPSHORTZERO(%s) %s\n",(long)position,
	(GetMachine().GetFlags()&FZERO)?"ZERO":"NOTZERO",
	result?"succeeded":"failed");
#endif	
	return result;
}


INSTJUMPSHORTNOTZERO::INSTJUMPSHORTNOTZERO(VIRTUALMACHINE& vm) : INSTJUMPSHORT(vm)
{
}

bool INSTJUMPSHORTNOTZERO::execute(void)
{
	bool result= true;
	if(!(GetMachine().GetFlags()&FZERO))
		result= INSTJUMP::execute();
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTJUMPSHORTNOTZERO(%s) %s\n",(long)position,
	(GetMachine().GetFlags()&FZERO)?"ZERO":"NOTZERO",
	result?"succeeded":"failed");
#endif	
	return result;
}

INSTJUMPSHORTPOSITIVE::INSTJUMPSHORTPOSITIVE(VIRTUALMACHINE& vm) : INSTJUMPSHORT(vm)
{
}

bool INSTJUMPSHORTPOSITIVE::execute(void)
{
	bool result= true;
	if((GetMachine().GetFlags()&FPOS))
		result= INSTJUMP::execute();
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTJUMPSHORTPOSITIVE(%s) %s\n",(long)position,
	(GetMachine().GetFlags()&FPOS)?"POS":"NEG",
	result?"succeeded":"failed");
#endif	
	return result;
}

INSTJUMPSHORTNEGATIVE::INSTJUMPSHORTNEGATIVE(VIRTUALMACHINE& vm) : INSTJUMPSHORT(vm)
{
}

bool INSTJUMPSHORTNEGATIVE::execute(void)
{
	bool result= true;
	if(!(GetMachine().GetFlags()&FPOS))
		result= INSTJUMP::execute();
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= INSTJUMPSHORTNEGATIVE(%s) %s\n",(long)position,
	(GetMachine().GetFlags()&FPOS)?"POS":"NEG",
	result?"succeeded":"failed");
#endif	
	return result;
}
