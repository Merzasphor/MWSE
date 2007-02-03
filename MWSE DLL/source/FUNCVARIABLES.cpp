//FuncVariables.cpp

#include "FUNCVARIABLES.h"
#include "TES3MEMMAP.h"
#include "TES3OPCODES.h"
#include "DEBUGGING.h"

bool GetLocalVars(TES3MACHINE& machine, TES3VARIABLES* vars)
{
	VPVARIABLES pvars= 0;
	return machine.ReadMem((VPVOID)reltolinear(LOCALVARIABLES_IMAGE),&pvars,sizeof(pvars))
		&& pvars
		&& machine.ReadMem((VPVOID)pvars,vars,sizeof(TES3VARIABLES));
}

bool GetRefVars(TES3MACHINE& machine, VPREFERENCE pref, TES3VARIABLES* vars)
{
	bool result= false;
	if(pref)
	{
		TES3REFERENCE ref;
		if(machine.ReadMem((VPVOID)pref,&ref,sizeof(ref)))
		{
			bool found= false;
			VPLISTNODE pnode= ref.attachments;
			TES3LISTNODE node;
			result= true;
			while(result && pnode && !found)
			{
				result= machine.ReadMem((VPVOID)pnode,&node,sizeof(node));
				if(result)
				{
					if(node.type==VARNODE)
						found= true;
					else
						pnode= (VPLISTNODE)node.next;
				}
			}
			if(result && found)
			{
				TES3VARHOLDER vh;
				result= machine.ReadMem((VPVOID)node.dataptr,&vh,sizeof(vh))
					&& machine.ReadMem((VPVOID)vh.vars,vars,sizeof(TES3VARIABLES));
			}
		}
	}
	else
		result= GetLocalVars(machine,vars);
	
	return result;
}

FUNCGETLOCAL::FUNCGETLOCAL(TES3MACHINE& vm) : machine(vm)
{
}

int FUNCGETLOCAL::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	this->opcode= opcode;
	return 0;
}

bool FUNCGETLOCAL::execute(void)
{
	bool result= false;
	VMREGTYPE stackpointer= 0, value= 0;
	struct{VMREGTYPE type, index;} stackparams;
	if(machine.GetRegister(SP,stackpointer))
	{
		VPREFERENCE pref= 0;
		TES3VARIABLES vars;
		if(    machine.ReadMem((VPVOID)stackpointer,&stackparams,sizeof(stackparams))
			&& machine.ReadMem((VPVOID)reltolinear(SCRIPTTARGETREF_IMAGE),&pref,sizeof(pref))
			&& opcode==GETFOREIGN?GetRefVars(machine,pref,&vars):GetLocalVars(machine,&vars))
		{
			switch(stackparams.type)
			{
			case 's':
				{
					TES3SHORT val;
					TES3SHORT* addr= &vars.shorts[stackparams.index];
					result= machine.ReadMem((VPVOID)addr,&val,sizeof(val));
					value= val;
				}
				break;
			case 'l':
				{
					TES3LONG* addr= &vars.longs[stackparams.index];
					result= machine.ReadMem((VPVOID)addr,&value,sizeof(value));
				}
				break;
			case 'f':
				{
					TES3FLOAT* addr= &vars.floats[stackparams.index];
					result= machine.ReadMem((VPVOID)addr,&value,sizeof(value));
				}
				break;
			}
// 2005-06-30  CDC  Clearing the stack isn't optional, we used them even if we couldn't finish the read
			stackpointer+= sizeof(stackparams);
			machine.SetRegister(SP,stackpointer);
			result= machine.push(value);
		}
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lx or %f = FUNCGETLOCAL(%lx,%lx) %s\n",
		value,*(VMFLOAT*)&value,stackparams.type,stackparams.index,result?"succeeded":"failed");
#endif	
	
	return result;
}

FUNCSETLOCAL::FUNCSETLOCAL(TES3MACHINE& vm) : machine(vm)
{
}

int FUNCSETLOCAL::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	this->opcode= opcode;
	return 0;
}

bool FUNCSETLOCAL::execute(void)
{
	bool result= false;
	VMREGTYPE stackpointer= 0;
	struct{VMREGTYPE type, index, value;} stackparams;
// 2005-06-30  CDC  If there is at least one item on the stack, make sure there are three
	if(machine.GetRegister(SP,stackpointer) && stackpointer)
	{
		if ( !(stackpointer + sizeof(VMREGTYPE)) && machine.push((VMREGTYPE)0) )
			stackpointer-= 2 * sizeof(VMREGTYPE);
		else if ( !(stackpointer + 2 * sizeof(VMREGTYPE)) 
				&& machine.push((VMREGTYPE)0) && machine.push((VMREGTYPE)0) )
			stackpointer-= sizeof(VMREGTYPE);
		VPREFERENCE pref= 0;
		TES3VARIABLES vars;
		if(    machine.ReadMem((VPVOID)stackpointer,&stackparams,sizeof(stackparams))
			&& machine.ReadMem((VPVOID)reltolinear(SCRIPTTARGETREF_IMAGE),&pref,sizeof(pref))
			&& opcode==SETFOREIGN?GetRefVars(machine,pref,&vars):GetLocalVars(machine,&vars))
		{
			switch(stackparams.type)
			{
			case 's':
				{
					TES3SHORT val= (TES3SHORT)stackparams.value;
					TES3SHORT* addr= &vars.shorts[stackparams.index];
					result= machine.WriteMem((VPVOID)addr,&val,sizeof(val));
				}
				break;
			case 'l':
				{
					TES3LONG val= (TES3LONG)stackparams.value;
					TES3LONG* addr= &vars.longs[stackparams.index];
					result= machine.WriteMem((VPVOID)addr,&val,sizeof(val));
				}
				break;
			case 'f':
				{
					TES3FLOAT val= *((TES3FLOAT*)&stackparams.value);
					TES3FLOAT* addr= &vars.floats[stackparams.index];
					result= machine.WriteMem((VPVOID)addr,&val,sizeof(val));
				}
				break;
			}
			{
				stackpointer+= sizeof(stackparams);
				result= machine.SetRegister(SP,stackpointer);
			}
		}
	}

#ifdef DEBUGGING
	cLog::mLogMessage("FUNCSETLOCAL(%lx,%lx,%lx or %f) %s\n",
		stackparams.type,stackparams.index,stackparams.value,*(VMFLOAT*)&stackparams.value,
		result?"succeeded":"failed");
#endif	
	
	return result;
}
