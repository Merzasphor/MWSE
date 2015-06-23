//InstInt.cpp

#include "INSTINT.h"
#include "DEBUGGING.h"

INSTADD::INSTADD(VIRTUALMACHINE& vm) : machine(vm)
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
	cLog::mLogMessage("%ld= INSTADD(%ld,%ld) %s\n",sum,val,val2,result?"succeeded":"failed");
#endif	
	return result;
}

INSTSUB::INSTSUB(VIRTUALMACHINE& vm) : machine(vm)
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
	cLog::mLogMessage("%ld= INSTSUB(%ld,%ld) %s\n",sum,val,val2,result?"succeeded":"failed");
#endif	
	return result;
}

INSTMUL::INSTMUL(VIRTUALMACHINE& vm) : machine(vm)
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
	cLog::mLogMessage("%ld= INSTMUL(%ld,%ld) %s\n",sum,val,val2,result?"succeeded":"failed");
#endif	
	return result;
}

INSTDIV::INSTDIV(VIRTUALMACHINE& vm) : machine(vm)
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
	cLog::mLogMessage("%ld= INSTDIV(%ld,%ld) %s\n",sum,val,val2,result?"succeeded":"failed");
#endif	
	return result;
}

INSTMOD::INSTMOD(VIRTUALMACHINE& vm) : machine(vm)
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
	cLog::mLogMessage("%ld= INSTMOD(%ld,%ld) %s\n",sum,val,val2,result?"succeeded":"failed");
#endif	
	return result;
}

bool INSTSHIFT::execute(void)
{
	VMLONG value, magnitude;
	VMLONG result = 0;
	if(machine.pop(value) && machine.pop(magnitude))
	{
		if (magnitude < 0)
		{
			result = value >> abs(magnitude);
		}
		else
		{
			result = value << magnitude;
		}
	}
	
	return machine.push(result);
}

bool INSTBITAND::execute(void)
{
	VMLONG a, b;
	VMLONG result = 0;

	if(machine.pop(a) && machine.pop(b))
	{
		result = a & b;
	}
	
	return machine.push(result);
}

bool INSTBITOR::execute(void)
{
	VMLONG a, b;
	VMLONG result = 0;

	if(machine.pop(a) && machine.pop(b))
	{
		result = a | b;
	}
	
	return machine.push(result);
}

bool INSTBITXOR::execute(void)
{
	VMLONG a, b;
	VMLONG result = 0;

	if(machine.pop(a) && machine.pop(b))
	{
		result = a ^ b;
	}
	
	return machine.push(result);
}

bool INSTBITNOT::execute(void)
{
	VMLONG a;
	VMLONG result = 0;

	if(machine.pop(a))
	{
		result = ~a;
	}
	
	return machine.push(result);
}

bool INSTAND::execute(void)
{
	VMLONG a, b;
	VMLONG result = 0;

	if(machine.pop(a) && machine.pop(b))
	{
		result = a && b;
	}
	
	return machine.push(result);
}

bool INSTOR::execute(void)
{
	VMLONG a, b;
	VMLONG result = 0;

	if(machine.pop(a) && machine.pop(b))
	{
		result = a || b;
	}
	
	return machine.push(result);
}

bool INSTXOR::execute(void)
{
	VMLONG a, b;
	VMLONG result = 0;

	if(machine.pop(a) && machine.pop(b))
	{
		result = (a || b) && !(a && b);
	}
	
	return machine.push(result);
}

bool INSTNOT::execute(void)
{
	VMLONG a;
	VMLONG result = 0;

	if(machine.pop(a))
	{
		result = !a;
	}
	
	return machine.push(result);
}
