//InstFloat.cpp

#include "INSTFLOAT.h"
#include "DEBUGGING.h"
#include "math.h"
// 22-08-2006 Tp21
#include "warnings.h"

#ifndef M_PI
#define M_PI 3.141592653
#endif
//#if sizeof(VMREGTYPE) <> sizeof(VMFLOAT)
//#error "VMREGTYPE and VMFLOAT must be the same size!"
//#endif

VMREGTYPE ifromf(VMFLOAT f)
{
	return *(VMREGTYPE*)&f;
}

VMFLOAT ffromi(VMREGTYPE i)
{
	return *(VMFLOAT*)&i;
}

INSTITOF::INSTITOF(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTITOF::execute(void)
{
	bool result= false;
	VMREGTYPE val= 0,sum= 0;
	if(machine.pop(val))
	{
		VMFLOAT f= val;
		sum= ifromf(f);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTITOF(%ld) %s\n",ffromi(sum),val,result?"succeeded":"failed");
#endif	
	return result;
}

INSTFTOI::INSTFTOI(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTFTOI::execute(void)
{
	bool result= false;
	VMREGTYPE val= 0,sum= 0;
	if(machine.pop(val))
	{
		VMFLOAT f= ffromi(val);
		sum= (VMREGTYPE)f;
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%ld= INSTFTOI(%f) %s\n",sum,ffromi(val),result?"succeeded":"failed");
#endif	
	return result;
}

INSTFADD::INSTFADD(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTFADD::execute(void)
{
	bool result= false;
	VMREGTYPE val1,val2,sum= 0;
	if(machine.pop(val1)
		&& machine.pop(val2))
	{
		VMFLOAT f1= ffromi(val1);
		VMFLOAT f2= ffromi(val2);
		f1= f1 + f2;
		sum= ifromf(f1);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTFADD(%f,%f) %s\n",
		ffromi(sum),ffromi(val1),ffromi(val2),result?"succeeded":"failed");
#endif	
	return result;
}

INSTFSUB::INSTFSUB(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTFSUB::execute(void)
{
	bool result= false;
	VMREGTYPE val1,val2,sum= 0;
	if(machine.pop(val1)
		&& machine.pop(val2))
	{
		VMFLOAT f1= ffromi(val1);
		VMFLOAT f2= ffromi(val2);
		f1= f1 - f2;
		sum= ifromf(f1);
		result= machine.push(sum);
	}

#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTFSUB(%f,%f) %s\n",
		ffromi(sum),ffromi(val1),ffromi(val2),result?"succeeded":"failed");
#endif	
	return result;
}

INSTFMUL::INSTFMUL(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTFMUL::execute(void)
{
	bool result= false;
	VMREGTYPE val1,val2,sum= 0;
	if(machine.pop(val1)
		&& machine.pop(val2))
	{
		VMFLOAT f1= ffromi(val1);
		VMFLOAT f2= ffromi(val2);
		f1= f1 * f2;
		sum= ifromf(f1);
		result= machine.push(sum);
	}

#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTFMUL(%f,%f) %s\n",
		ffromi(sum),ffromi(val1),ffromi(val2),result?"succeeded":"failed");
#endif	
	return result;
}

INSTFDIV::INSTFDIV(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTFDIV::execute(void)
{
	bool result= false;
	VMREGTYPE val1,val2,sum= 0;
	if(machine.pop(val1)
		&& machine.pop(val2))
	{
		VMFLOAT f1= ffromi(val1);
		VMFLOAT f2= ffromi(val2);
		f1= f1 / f2;
		sum= ifromf(f1);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTFDIV(%f,%f) %s\n",
		ffromi(sum),ffromi(val1),ffromi(val2),result?"succeeded":"failed");
#endif	
	return result;
}

INSTTAN::INSTTAN(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTTAN::execute(void)
{
	bool result= false;
	VMREGTYPE val,sum= 0;
	if(machine.pop(val))
	{
		VMFLOAT f= ffromi(val);
		f= tan(f);
		sum= ifromf(f);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTTAN(%f) %s\n",ffromi(sum),ffromi(val),result?"succeeded":"failed");
#endif	
	return result;
}

INSTSIN::INSTSIN(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTSIN::execute(void)
{
	bool result= false;
	VMREGTYPE val,sum= 0;
	if(machine.pop(val))
	{
		VMFLOAT f= ffromi(val);
		f= sin(f);
		sum= ifromf(f);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTSIN(%f) %s\n",ffromi(sum),ffromi(val),result?"succeeded":"failed");
#endif	
	return result;
}

INSTCOS::INSTCOS(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTCOS::execute(void)
{
	bool result= false;
	VMREGTYPE val,sum= 0;
	if(machine.pop(val))
	{
		VMFLOAT f= ffromi(val);
		f= cos(f);
		sum= ifromf(f);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTCOS(%f) %s\n",ffromi(sum),ffromi(val),result?"succeeded":"failed");
#endif	
	return result;
}


INSTARCTAN::INSTARCTAN(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTARCTAN::execute(void)
{
	bool result= false;
	VMREGTYPE val,sum= 0;
	if(machine.pop(val))
	{
		VMFLOAT f= ffromi(val);
		f= atan(f);
		sum= ifromf(f);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTARCTAN(%f) %s\n",ffromi(sum),ffromi(val),result?"succeeded":"failed");
#endif	
	return result;
}

INSTARCSIN::INSTARCSIN(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTARCSIN::execute(void)
{
	bool result= false;
	VMREGTYPE val,sum= 0;
	if(machine.pop(val))
	{
		VMFLOAT f= ffromi(val);
		f= asin(f);
		sum= ifromf(f);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTARCSIN(%f) %s\n",ffromi(sum),ffromi(val),result?"succeeded":"failed");
#endif	
	return result;
}

INSTARCCOS::INSTARCCOS(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTARCCOS::execute(void)
{
	bool result= false;
	VMREGTYPE val,sum= 0;
	if(machine.pop(val))
	{
		VMFLOAT f= ffromi(val);
		f= acos(f);
		sum= ifromf(f);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTARCCOS(%f) %s\n",ffromi(sum),ffromi(val),result?"succeeded":"failed");
#endif	
	return result;
}

INSTDEGRAD::INSTDEGRAD(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTDEGRAD::execute(void)
{
	bool result= false;
	VMREGTYPE val,sum= 0;
	if(machine.pop(val))
	{
		VMFLOAT f= ffromi(val);
		f= f*M_PI/180;
		sum= ifromf(f);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTDEGRAD(%f) %s\n",ffromi(sum),ffromi(val),result?"succeeded":"failed");
#endif	
	return result;
}

INSTRADDEG::INSTRADDEG(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTRADDEG::execute(void)
{
	bool result= false;
	VMREGTYPE val,sum= 0;
	if(machine.pop(val))
	{
		VMFLOAT f= ffromi(val);
		f= f/M_PI*180;
		sum= ifromf(f);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTRADDEG(%f) %s\n",ffromi(sum),ffromi(val),result?"succeeded":"failed");
#endif	
	return result;
}

INSTSQRT::INSTSQRT(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTSQRT::execute(void)
{
	bool result= false;
	VMREGTYPE val,sum= 0;
	if(machine.pop(val))
	{
		VMFLOAT f= ffromi(val);
		f= sqrt(f);
		sum= ifromf(f);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTSQRT(%f) %s\n",ffromi(sum),ffromi(val),result?"succeeded":"failed");
#endif	
	return result;
}

INSTHYPOT::INSTHYPOT(VIRTUALMACHINE& vm) : machine(vm)
{
}

bool INSTHYPOT::execute(void)
{
	bool result= false;
	VMREGTYPE val1,val2,sum= 0;
	if(machine.pop(val1)
		&& machine.pop(val2))
	{
		VMFLOAT f1= ffromi(val1);
		VMFLOAT f2= ffromi(val2);
		f1= _hypot(f1,f2);
		sum= ifromf(f1);
		result= machine.push(sum);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= INSTHYPOT(%f,%f) %s\n",
		ffromi(sum),ffromi(val1),ffromi(val2),result?"succeeded":"failed");
#endif	
	return result;
}

bool INSTPOW::execute(void)
{
	VMFLOAT base, exponent;
	VMFLOAT result = 0;

	if (machine.pop(base) && machine.pop(exponent))
	{
		result = powf(base, exponent);
	}

	return machine.push(result);
}