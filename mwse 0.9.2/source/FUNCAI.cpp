#include "FUNCAI.h"
#include "TES3TYPES.h"
#include "TES3MEMMAP.h"
#include "TES3OPCODES.h"
#include "REFERENCE.h"
#include "DEBUGGING.h"

FUNCAITRAVEL::FUNCAITRAVEL(TES3MACHINE& vm) : machine(vm)
{
}

bool FUNCAITRAVEL::execute(void)
{
	bool result= false;
	VMREGTYPE stackpointer= 0;
	TES3COORDINATE coord;
#ifdef DEBUGGING	
	machine.dumpscriptstack();
#endif	
	result= (machine.GetRegister(SP,stackpointer)
			&& machine.SetRegister(SP,stackpointer+sizeof(coord))
			&& machine.ReadMem((VPVOID)stackpointer,&coord,sizeof(coord))
			&& machine.WriteMem((VPVOID)machine.reltolinear(DESTINATION_IMAGE),&coord,sizeof(coord))
			&& CallOriginalFunction(machine,ORIG_AITRAVEL));
		
#ifdef DEBUGGING
	LOG::log("FUNCAITRAVEL(%f,%f,%f) %s\n",coord.x,coord.y,coord.z,result?"succeeded":"failed");
#endif	
		
	return false; // required to make virtualmachine stop running
}

FUNCGETCOMBAT::FUNCGETCOMBAT(TES3MACHINE& vm) : machine(vm)
{
}

bool FUNCGETCOMBAT::execute(void)
{
	bool result= false;
	VPREFERENCE ref= 0;
	VPREFERENCE target= 0;
	VPMACH mach= 0;
	if(machine.ReadMem((VPVOID)machine.reltolinear(SCRIPTTARGETREF_IMAGE),&ref,sizeof(ref)))
	{
	  if(REFERENCE::GetMach(machine,(VPREFERENCE)ref,mach))
	  {
		if(mach)
		{
			if(machine.ReadMem((VPVOID)&mach->combattarget,&mach,sizeof(mach)))
			{
				if(mach)
					result= machine.ReadMem((VPVOID)&mach->ref,&target,sizeof(target));
				else
					result= true;
			}
		}
		else
			result= true;
	  }
	}
	if(result)
			result= machine.push((VMREGTYPE)target);

#ifdef DEBUGGING
	LOG::log("%lx = FUNCGETCOMBAT(%lx) %s\n",target,ref,result?"succeeded":"failed");
#endif	
			
	return result;
}

FUNCSTARTCOMBAT::FUNCSTARTCOMBAT(TES3MACHINE& vm) : machine(vm)
{
}

bool FUNCSTARTCOMBAT::execute(void)
{
	VMREGTYPE target= 0;
	
	bool result= (machine.pop(target)
		&& machine.WriteMem((VPVOID)machine.reltolinear(SECONDOBJECT_IMAGE),&target,sizeof(target))
		&& CallOriginalFunction(machine,ORIG_STARTCOMBAT));


#ifdef DEBUGGING
	LOG::log("FUNCSTARTCOMBAT(%lx) %s\n",target,result?"succeeded":"failed");
#endif	
			
	return result;
}
