//FuncReference.cpp

#include "FUNCREFERENCE.h"
#include "TES3MEMMAP.h"
#include "TES3OPCODES.h"
#include "DEBUGGING.h"
#include "cLog.h"
#include <string.h>
// 22-08-2006 Tp21
#include "warnings.h"


static VPREFERENCE exteriors[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static VPREFERENCE SkipRemovedRefs(TES3MACHINE &machine, VPREFERENCE ref);

FUNCREF::FUNCREF(TES3MACHINE& vm) : machine(vm)
{
}

bool FUNCREF::setref(VPREFERENCE target)
{
	TES3REFERENCE ref;
	OPCODE deref= ORIG_DEREF;
	BYTE inref= 1;
	const Context context( machine.GetFlow() );
	machine.SetFlags((VMREGTYPE)target);
	return (!target
		|| (machine.ReadMem((VPVOID)target,&ref,sizeof(ref))
			&& machine.WriteMem((VPVOID)reltolinear(TES3OP_IMAGE),&deref,sizeof(deref))
			&& machine.WriteMem((VPVOID)reltolinear(SCRIPTTARGETREF_IMAGE),&target,sizeof(target))
			&& machine.WriteMem((VPVOID)reltolinear(SCRIPTTARGETTEMPL_IMAGE),&ref.templ,sizeof(ref.templ))
			&& machine.WriteMem((VPVOID)context.Ebp+RUNSCRIPT_INREFOFFSET,&inref,sizeof(inref))));
}

bool FUNCREF::execute(void)
{
	VMREGTYPE pref= 0;
	bool result= (getMachine().pop(pref)
		&& setref((VPREFERENCE)pref));

#ifdef DEBUGGING
	cLog::mLogMessage("%s= FUNCREF(%lx) %s\n",pref?"true":"false",pref,result?"succeeded":"failed");
//	if(pref)
//		machine.dumpobject((VPREFERENCE)pref);
#endif

	return result;
}

FUNCREFTYPE::FUNCREFTYPE(TES3MACHINE& vm) : machine(vm)
{
}

bool FUNCREFTYPE::execute(void)
{
	bool result= false;
	VMPTR<TES3REFERENCE*> pref(machine);
	VMPTR<TES3REFERENCE> ref(machine);
	VMPTR<TES3TEMPLATE> templ(machine);
	try
	{
		pref= (TES3REFERENCE**)reltolinear(SCRIPTTARGETREF_IMAGE);
		ref= *pref;
		templ= ref->templ;
		result= machine.push((VMREGTYPE)templ->type);
	}
	catch(...)
	{
		result= false;
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lx= FUNCREFTYPE() %s\n",templ->type,result?"succeeded":"failed");
#endif	
		
	return result;
}

FUNCREFID::FUNCREFID(TES3MACHINE& vm) : machine(vm)
{
}

bool FUNCREFID::execute(void)
{
	bool result= false;
	VMPTR<TES3REFERENCE*> pref(machine);
	VMPTR<TES3REFERENCE> ref(machine);
	VMPTR<TES3TEMPLATE> templ(machine);
	VMPTR<TES3IDSTRING> id(machine);
	const char* idstring= "null";
	try
	{
		pref= (TES3REFERENCE**)reltolinear(SCRIPTTARGETREF_IMAGE);
		ref= *pref;
		templ= ref->templ;
		id= (VPIDSTRING)templ->objectid;
		idstring= strings.add((const char*)id->id);
		result= machine.push((VMREGTYPE)idstring);
	}
	catch(...)
	{
		result= false;
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%s= FUNCREFID() %s\n",idstring,result?"succeeded":"failed");
#endif	
		
	return result;
}

FUNCFIRSTNPC::FUNCFIRSTNPC(TES3MACHINE& vm) : FUNCREF(vm)
{
}

bool FUNCFIRSTNPC::execute(void)
{
	bool result= false;
	static VPCELLMASTER cellmaster= 0;
	VPCELLPTR pcellptr;
	TES3CELLPTR cellptr;
	VPCELL intcell= 0;
	VPREFERENCE ref= 0;
// 2005-06-18  CDC
	int i;	
	exteriors[0] = 0;
	if((cellmaster || getMachine().ReadMem((VPVOID)reltolinear(MASTERCELL_IMAGE),&cellmaster,sizeof(cellmaster)))
		&& getMachine().ReadMem((VPVOID)&cellmaster->interiorcell,&intcell,sizeof(intcell)))
	{
		if(intcell)
		{
			result= getMachine().ReadMem((VPVOID)&intcell->npc.first,&ref,sizeof(ref));
			ref = SkipRemovedRefs(getMachine(), ref);
		}
		else
		{
			if(getMachine().ReadMem((VPVOID)&cellmaster->exteriorcells[CENTRE],&pcellptr,sizeof(pcellptr))
				&& getMachine().ReadMem((VPVOID)pcellptr,&cellptr,sizeof(cellptr)))
			{
				if(cellptr.size==1)
				{
					// get the start of the list for the center cell. we'll check that it's valid later.
					result= getMachine().ReadMem((VPVOID)&cellptr.first->npc.first,&ref,sizeof(ref));
					int extCount = 0;
					// check the other exterior cells for lists
					for (i = 0; i < 9; ++i)
					{
						if (i == CENTRE)
							continue;
						if(getMachine().ReadMem((VPVOID)&cellmaster->exteriorcells[i],&pcellptr,sizeof(pcellptr))
							&& getMachine().ReadMem((VPVOID)pcellptr,&cellptr,sizeof(cellptr))
							&& cellptr.size == 1)
						{
							VPREFERENCE temp = 0;
							getMachine().ReadMem((VPVOID)&cellptr.first->npc.first,&temp,sizeof(VPREFERENCE));
							temp = SkipRemovedRefs(getMachine(), temp);
							if (temp != 0)
							{
								// If we've made it here, temp is a valid reference.
								exteriors[extCount] = temp;
								++extCount;
							}
						}
					}
					exteriors[extCount] = 0;
					
					// Find the first reference in the center (player's) cell that hasn't been removed.
					ref = SkipRemovedRefs(getMachine(), ref);

					// make sure the reference in the center cell is valid
					// if not, use the reference from another exterior cell.
					if (ref == 0 && extCount > 0)
					{
						--extCount;
						ref = exteriors[extCount];
						exteriors[extCount] = 0;
					}
				}
				else
					result= true;
			}
		}
	}
	result= getMachine().push((VMREGTYPE)ref) && result;

#ifdef DEBUGGING
	cLog::mLogMessage("%lx = FUNCFIRSTNPC() %s\n",ref,result?"succeeded":"failed");
	if(ref)
		getMachine().dumpobject((VPREFERENCE)ref);
#endif

	return result;
}

FUNCFIRSTITEM::FUNCFIRSTITEM(TES3MACHINE& vm) : FUNCREF(vm)
{
}

bool FUNCFIRSTITEM::execute(void)
{
	bool result= false;
	static VPCELLMASTER cellmaster= 0;
	VPCELLPTR pcellptr;
	TES3CELLPTR cellptr;
	VPCELL intcell= 0;
	VPREFERENCE ref= 0;

// 2005-07-02  CDC
	int i;	
	exteriors[0] = 0;
	if((cellmaster || getMachine().ReadMem((VPVOID)reltolinear(MASTERCELL_IMAGE),&cellmaster,sizeof(cellmaster)))
		&& getMachine().ReadMem((VPVOID)&cellmaster->interiorcell,&intcell,sizeof(intcell)))
	{
		if(intcell)
		{
			result= getMachine().ReadMem((VPVOID)&intcell->otheritems.first,&ref,sizeof(ref));
			ref = SkipRemovedRefs(getMachine(), ref);
		}
		else
		{
			if(getMachine().ReadMem((VPVOID)&cellmaster->exteriorcells[CENTRE],&pcellptr,sizeof(pcellptr))
				&& getMachine().ReadMem((VPVOID)pcellptr,&cellptr,sizeof(cellptr)))
			{
				if(cellptr.size==1)
				{
					// get the start of the list for the center cell. we'll check that it's valid later.
					result= getMachine().ReadMem((VPVOID)&cellptr.first->otheritems.first,&ref,sizeof(ref));
					int extCount = 0;
					// check the other exterior cells for lists
					for (i = 0; i < 9; ++i)
					{
						if (i == CENTRE)
							continue;
						if(getMachine().ReadMem((VPVOID)&cellmaster->exteriorcells[i],&pcellptr,sizeof(pcellptr))
							&& getMachine().ReadMem((VPVOID)pcellptr,&cellptr,sizeof(cellptr))
							&& cellptr.size == 1)
						{
							VPREFERENCE temp = 0;
							getMachine().ReadMem((VPVOID)&cellptr.first->otheritems.first,&temp,sizeof(VPREFERENCE));
							temp = SkipRemovedRefs(getMachine(), temp);
							if (temp != 0)
							{
								// If we've made it here, temp is a valid reference.
								exteriors[extCount] = temp;
								++extCount;
							}
						}
					}
					exteriors[extCount] = 0;
					
					// Find the first reference in the center (player's) cell that's hasn't been removed.
					ref = SkipRemovedRefs(getMachine(), ref);

					// make sure the reference in the center cell is valid
					// if not, use the reference from another exterior cell.
					if (ref == 0 && extCount > 0)
					{
						--extCount;
						ref = exteriors[extCount];
						exteriors[extCount] = 0;
					}
				}
				else
					result= true;
			}
		}
	}
	result= getMachine().push((VMREGTYPE)ref) && result;

#ifdef DEBUGGING
	cLog::mLogMessage("%lx = FUNCFIRSTITEM() %s\n",ref,result?"succeeded":"failed");
	if(ref)
		getMachine().dumpobject((VPREFERENCE)ref);
#endif

	return result;
}

FUNCFIRSTSTATIC::FUNCFIRSTSTATIC(TES3MACHINE& vm) : FUNCREF(vm)
{
}

bool FUNCFIRSTSTATIC::execute(void)
{
	bool result = false;
	static VPCELLMASTER cellmaster= 0;
	VPCELLPTR pcellptr;
	TES3CELLPTR cellptr;
	VPCELL intcell= 0;
	VPREFERENCE ref= 0;
	int i;
	exteriors[0] = 0;

	if((cellmaster || getMachine().ReadMem((VPVOID)reltolinear(MASTERCELL_IMAGE),&cellmaster,sizeof(cellmaster)))
		&& getMachine().ReadMem((VPVOID)&cellmaster->interiorcell,&intcell,sizeof(intcell)))
	{
		if(intcell)
		{
			result= getMachine().ReadMem((VPVOID)&intcell->statics.first,&ref,sizeof(ref));
			ref = SkipRemovedRefs(getMachine(), ref);
		}
		else
		{
			if(getMachine().ReadMem((VPVOID)&cellmaster->exteriorcells[CENTRE],&pcellptr,sizeof(pcellptr))
				&& getMachine().ReadMem((VPVOID)pcellptr,&cellptr,sizeof(cellptr)))
			{
				if(cellptr.size==1)
				{
					// get the start of the list for the center cell. we'll check that it's valid later.
					result= getMachine().ReadMem((VPVOID)&cellptr.first->statics.first,&ref,sizeof(ref));
					int extCount = 0;
					// check the other exterior cells for lists
					for (i = 0; i < 9; ++i)
					{
						if (i == CENTRE)
							continue;
						if(getMachine().ReadMem((VPVOID)&cellmaster->exteriorcells[i],&pcellptr,sizeof(pcellptr))
							&& getMachine().ReadMem((VPVOID)pcellptr,&cellptr,sizeof(cellptr))
							&& cellptr.size == 1)
						{
							VPREFERENCE temp = 0;
							getMachine().ReadMem((VPVOID)&cellptr.first->statics.first,&temp,sizeof(VPREFERENCE));
							temp = SkipRemovedRefs(getMachine(), temp);
							if (temp != 0)
							{
								// If we've made it here, temp is a valid reference.
								exteriors[extCount] = temp;
								++extCount;
							}
						}
					}
					exteriors[extCount] = 0;
					
					// Find the first reference in the center (player's) cell that's hasn't been removed.
					ref = SkipRemovedRefs(getMachine(), ref);

					// make sure the reference in the center cell is valid
					// if not, use the reference from another exterior cell.
					if (ref == 0 && extCount > 0)
					{
						--extCount;
						ref = exteriors[extCount];
						exteriors[extCount] = 0;
					}
				}
				else
					result= true;
			}
		}
	}
	result= getMachine().push((VMREGTYPE)ref) && result;

#ifdef DEBUGGING
	cLog::mLogMessage("%lx = FUNCFIRSTSTATIC() %s\n",ref,result?"succeeded":"failed");
	if(ref)
		getMachine().dumpobject((VPREFERENCE)ref);
#endif

	return result;
}

FUNCNEXTREF::FUNCNEXTREF(TES3MACHINE& vm) : FUNCREF(vm)
{
}

bool FUNCNEXTREF::execute(void)
{
	bool result= false;

	VMREGTYPE pref;
	VPREFERENCE next= 0;
	if(getMachine().pop(pref))
	{
		VPREFERENCE ref= (VPREFERENCE)pref;
		int i;
		getMachine().ReadMem((VPVOID)&ref->next,&next,sizeof(next));
		next = SkipRemovedRefs(getMachine(), next);
		if (next == 0 && exteriors[0] != 0)
		{
			next = exteriors[0];
			for ( i=0; i<8; i++ )
				exteriors[i] = exteriors[i+1];
		}
		result= getMachine().push((VMREGTYPE)next);
	}

#ifdef DEBUGGING
	cLog::mLogMessage("%lx= FUNCNEXTREF(%lx) %s\n",next,pref,result?"succeeded":"failed");
	if(next)
		getMachine().dumpobject((VPREFERENCE)next);
#endif

	return result;
}


FUNCGETPCTARGET::FUNCGETPCTARGET(TES3MACHINE& vm) : FUNCREF(vm)
{
}

bool FUNCGETPCTARGET::execute(void)
{
	bool result= false;
	static VPVIEWMASTER viewmaster= 0;
	VPREFERENCE target= 0;

	result= ((viewmaster || getMachine().ReadMem((VPVOID)reltolinear(MASTER2_IMAGE),&viewmaster,sizeof(viewmaster)))
		&& getMachine().ReadMem((VPVOID)&viewmaster->target,&target,sizeof(target))
		&& getMachine().push((VMREGTYPE)target));

#ifdef DEBUGGING
	cLog::mLogMessage("%lx= FUNCGETTARGET() %s\n",target,result?"succeeded":"failed");
	if(target)
		getMachine().dumpobject((VPREFERENCE)target);
#endif

	return result;
}

FUNCREFPCTARGET::FUNCREFPCTARGET(TES3MACHINE& vm) : FUNCREF(vm)
{
}

bool FUNCREFPCTARGET::execute(void)
{
	bool result= false;
	static VPVIEWMASTER viewmaster= 0;
	VPREFERENCE target= 0;

	result= ((viewmaster || getMachine().ReadMem((VPVOID)reltolinear(MASTER2_IMAGE),&viewmaster,sizeof(viewmaster)))
		&& getMachine().ReadMem((VPVOID)&viewmaster->target,&target,sizeof(target))
		&& setref(target));

#ifdef DEBUGGING
	cLog::mLogMessage("%lx= FUNCREFTARGET() %s\n",target,result?"succeeded":"failed");
	if(target)
		getMachine().dumpobject((VPREFERENCE)target);
#endif

	return result;
}

FUNCGETREF::FUNCGETREF(TES3MACHINE& vm) : machine(vm), HWBREAKPOINT()
{
}

bool FUNCGETREF::execute(void)
{
	bool result= true;
	VMREGTYPE pString= 0;
	const char* string= "null";
	VMREGTYPE count= 0;

	if(machine.pop(pString) && (string=machine.GetString((VPVOID)pString))!=0)
	{
		VMLONG strlength= strlen((const char*)string);
		parent= machine.GetFlow();
		result= machine.WriteMem((VPVOID)reltolinear(SECONDOBJECT_LENGTH_IMAGE),&strlength,sizeof(strlength))
			&& machine.WriteMem((VPVOID)reltolinear(SECONDOBJECT_IMAGE),(void*)string,strlength+1);
		if(result)
		{
		
			Context context= machine.GetFlow();
			isplayer= !_stricmp(string,"player") || !_stricmp(string,"playersavegame");
			if(isplayer)
				context.Eip= (DWORD)reltolinear(FIXUPPLAYER);
			else
				context.Eip= (DWORD)reltolinear(FIXUPINSTANCE);
			machine.SetFlow(context);
			result= machine.SetVMDebuggerBreakpoint(this);
		}
	}
	else
		result= false;

	return result;
}		

BYTE FUNCGETREF::getid()
{
	if(!isplayer) return BP_FIXUPINSTANCE;
	else return BP_FIXUPPLAYER;
}

bool FUNCGETREF::breakpoint()
{
	bool result= false;
	Context flow= machine.GetFlow();
	VMREGTYPE ref= (VMREGTYPE)flow.Edx;
	
	result= machine.push(ref);
	machine.SetFlow(parent);
	
	return result;
}

static VPREFERENCE SkipRemovedRefs(TES3MACHINE &machine, VPREFERENCE ref)
{
	while (ref != 0 && (ref->flags & 0x20) == 0x20)
	{
		VPREFERENCE next;
		machine.ReadMem((VPVOID)&ref->next, &next, sizeof(next));
		ref = next;
	}
	return ref;
}