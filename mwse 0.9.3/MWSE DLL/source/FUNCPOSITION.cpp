//FuncPosition.cpp

#include "FUNCPOSITION.h"
#include "TES3MEMMAP.h"
#include "TES3TYPES.h"
#include "TES3OPCODES.h"
#include "cLog.h"
#include "DEBUGGING.h"
// 22-08-2006 Tp21
#include "warnings.h"

#include <math.h>

FUNCPOSITION::FUNCPOSITION(TES3MACHINE& vm) : machine(vm)
{
}

bool FUNCPOSITION::execute(void)
{
	bool result= false;
	VMREGTYPE stackpointer= 0;
	struct{TES3COORDINATE coord; TES3FLOAT zAngle;} stackparams;
	TES3ROTATION angle= {0,0,0};
	if(machine.GetRegister(SP,stackpointer)
		&& machine.ReadMem((VPVOID)stackpointer,&stackparams,sizeof(stackparams)))
	{
		angle.z= stackparams.zAngle;
		stackpointer+= sizeof(stackparams);

		result= (machine.SetRegister(SP,stackpointer)
			&& machine.WriteMem((VPVOID)reltolinear(DESTINATION_IMAGE),&stackparams.coord,sizeof(stackparams.coord))
			&& machine.WriteMem((VPVOID)reltolinear(TARGETROT_IMAGE),&angle,sizeof(angle))
			&& CallOriginalFunction(machine,ORIG_POSITION));
	}

	return false; // required to make virtualmachine stop running
}

FUNCPOSITIONCELL::FUNCPOSITIONCELL(TES3MACHINE& vm) : machine(vm)
{
}

bool FUNCPOSITIONCELL::execute(void)
{
	bool result= false;
	VMREGTYPE stackpointer= 0;
	struct{TES3COORDINATE coord; TES3FLOAT zAngle; VMREGTYPE pString;} stackparams;
	TES3ROTATION angle= {0,0,0};
	const char* string= "null";
	
	if(machine.GetRegister(SP,stackpointer)
		&& machine.ReadMem((VPVOID)stackpointer,&stackparams,sizeof(stackparams))
		&& (string=machine.GetString((VPVOID)stackparams.pString))!=0)
	{
		angle.z= stackparams.zAngle;
		VMLONG strlength= strlen((const char*)string);
		stackpointer+= sizeof(stackparams);

		result= (machine.SetRegister(SP,stackpointer)
			&& machine.WriteMem((VPVOID)reltolinear(DESTINATION_IMAGE),&stackparams.coord,sizeof(stackparams.coord))
			&& machine.WriteMem((VPVOID)reltolinear(TARGETROT_IMAGE),&angle,sizeof(angle))
			&& machine.WriteMem((VPVOID)reltolinear(TARGETCELL_IMAGE),(void*)string,strlength+1)
			&& CallOriginalFunction(machine,ORIG_POSITIONCELL));
	}

	return false; // required to make virtualmachine stop running
}

FUNCDISTANCE::FUNCDISTANCE(TES3MACHINE& vm) : machine(vm)
{
}

bool FUNCDISTANCE::execute(void)
{
	bool result= false;
	VMREGTYPE target= 0;
	VMFLOAT distance= 0;
	VMPTR<TES3REFERENCE*> pref(machine);
	VMPTR<TES3REFERENCE> thisref(machine);
	VMPTR<TES3REFERENCE> targetref(machine);
	
	try
	{
		if(machine.pop(target))
		{
			pref= (TES3REFERENCE**)reltolinear(SCRIPTTARGETREF_IMAGE);
			thisref= *pref;
			targetref= (TES3REFERENCE*)target;
			FLOAT dx= targetref->x - thisref->x;
			FLOAT dy= targetref->y - thisref->y;
			FLOAT dz= targetref->z - thisref->z;
			distance= sqrt(dx*dx+dy*dy+dz*dz);
			result= machine.push(distance);
		}
	}
	catch(...)
	{
		result= false;
	}
			
	return result;
}

FUNCPCCELLID::FUNCPCCELLID(TES3MACHINE& vm) : machine(vm)
{
}

bool FUNCPCCELLID::execute(void)
{
	bool result= false;
	VMPTR<TES3CELLMASTER*> pcellmaster(machine);
	VMPTR<TES3CELLMASTER> cellmaster(machine);
	VMPTR<TES3CELL> cell(machine);
	VMPTR<TES3IDSTRING> cellname(machine);

	const char* cellid= "Wilderness";
	
	try
	{
		pcellmaster= (TES3CELLMASTER**)reltolinear(MASTERCELL_IMAGE);
		cellmaster= *pcellmaster;
		cell= cellmaster->interiorcell;
		if(!cell)
		{
			VMPTR<TES3CELLPTR> cellptr(machine);
			cellptr= cellmaster->exteriorcells[CENTRE];
			cell= cellptr->first;
		}
		if(cell)
		{
			cellname= (VPIDSTRING)cell->cellname;
			if(cellname)
				cellid=(const char*)cellname->id;
		}
		cellid=	strings.add(cellid);
//		LOG::log("%s = PCCELLID()\n",cellid);
		result= machine.push((VMREGTYPE)cellid);
	}
	catch(...)
	{
		cLog::mLogMessage("PCCELLID() exception\n");
		result= false;
	}
			
	return result;
}

FUNCPLACEAT::FUNCPLACEAT(TES3MACHINE& vm) : machine(vm), part2(vm), HWBREAKPOINT()
{
}

bool FUNCPLACEAT::execute(void)
{
	bool result= true;
	VMREGTYPE pString= 0;
	const char* string= "null";
	if(machine.pop(pString) && (string=machine.GetString((VPVOID)pString))!=0)
	{
		VMLONG strlength= strlen((const char*)string);
		parent= machine.GetFlow();
		result= machine.WriteMem((VPVOID)reltolinear(SECONDOBJECT_LENGTH_IMAGE),&strlength,sizeof(strlength))
			&& machine.WriteMem((VPVOID)reltolinear(SECONDOBJECT_IMAGE),(void*)string,strlength+1);
		if(result)
		{
			Context Context= machine.GetFlow();
			Context.Eip= (DWORD)reltolinear(FIXUPTEMPLATE);
			machine.SetFlow(Context);
			result= machine.SetVMDebuggerBreakpoint(this);
		}
	}
	else
		result= false;

	return result;
}
BYTE FUNCPLACEAT::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool FUNCPLACEAT::breakpoint()
{
	bool result= false;
	
	Context flow= machine.GetFlow();
	machine.SetFlow(parent);
	VMREGTYPE templ= flow.Eax;
	if(templ)
	{
		VMREGTYPE count= 1;
		TES3COORDINATE relpos= { 256,1,0 };
		result=(machine.WriteMem((VPVOID)reltolinear(SECONDOBJECT_IMAGE),&templ,sizeof(templ))
			&& machine.WriteMem((VPVOID)reltolinear(VARINDEX_IMAGE),(void*)&count,sizeof(count))
			&& machine.WriteMem((VPVOID)reltolinear(DESTINATIONX_IMAGE),(void*)&relpos,sizeof(relpos))
			&& machine.SetVMDebuggerBreakpoint(&part2)
			&& CallOriginalFunction(machine,ORIG_PLACEATPC));
		
	}
	else
		result= machine.push(templ);
	
	return result;
}

FUNCPLACEATPART2::FUNCPLACEATPART2(TES3MACHINE& vm) : machine(vm), HWBREAKPOINT()
{
}

BYTE FUNCPLACEATPART2::getid()
{
	return BP_PLACEATPCRESULT;
}

bool FUNCPLACEATPART2::breakpoint()
{
	bool result= false;
	
	Context flow= machine.GetFlow();
	VMREGTYPE ref= flow.Esi;
	result= machine.push(ref);
	
	return result;
}
