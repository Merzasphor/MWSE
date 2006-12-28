#include "INSTINT.h"
#include "DEBUGGING.h"

INSTADD::INSTADD(VIRTUALMACHINE& vm)
:	machine(vm)
{
}

bool INSTADD::execute(void)
{
	bool result= false;
	VMREGTYPE val= 0,val2= 0, sum= 0;
	if(machine.pop(val)
		&&machine.pop(val2))
	{
		sum= val+val2;
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	LOG::log("%ld= INSTADD(%ld,%ld) %s\n",sum,val,val2,result?"succeeded":"failed");
#endif	
	return result;
}

INSTSUB::INSTSUB(VIRTUALMACHINE& vm)
:	machine(vm)
{
}

bool INSTSUB::execute(void)
{
	bool result= false;
	VMREGTYPE val= 0,val2= 0, sum= 0;
	if(machine.pop(val)
		&&machine.pop(val2))
	{
		sum= val-val2;
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	LOG::log("%ld= INSTSUB(%ld,%ld) %s\n",sum,val,val2,result?"succeeded":"failed");
#endif	
	return result;
}

INSTMUL::INSTMUL(VIRTUALMACHINE& vm)
:	machine(vm)
{
}

bool INSTMUL::execute(void)
{
	bool result= false;
	VMREGTYPE val= 0,val2= 0, sum= 0;
	if(machine.pop(val)
		&&machine.pop(val2))
	{
		sum= val*val2;
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	LOG::log("%ld= INSTMUL(%ld,%ld) %s\n",sum,val,val2,result?"succeeded":"failed");
#endif	
	return result;
}

INSTDIV::INSTDIV(VIRTUALMACHINE& vm)
:	machine(vm)
{
}

bool INSTDIV::execute(void)
{
	bool result= false;
	VMREGTYPE val= 0,val2= 0, sum= 0;
	if(machine.pop(val)
		&&machine.pop(val2))
	{
		sum= val/val2;
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	LOG::log("%ld= INSTDIV(%ld,%ld) %s\n",sum,val,val2,result?"succeeded":"failed");
#endif	
	return result;
}

INSTMOD::INSTMOD(VIRTUALMACHINE& vm)
:	machine(vm)
{
}

bool INSTMOD::execute(void)
{
	bool result= false;
	VMREGTYPE val= 0,val2= 0, sum= 0;
	if(machine.pop(val)
		&&machine.pop(val2))
	{
		sum= val % val2;
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	LOG::log("%ld= INSTMOD(%ld,%ld) %s\n",sum,val,val2,result?"succeeded":"failed");
#endif	
	return result;
}
