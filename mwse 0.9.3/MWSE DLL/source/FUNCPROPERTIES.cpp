//FuncProperties.cpp

#include "FUNCPROPERTIES.h"
#include "REFERENCE.h"
#include "TES3MEMMAP.h"
#include "TES3OPCODES.h"
#include "DEBUGGING.h"
#include "cLog.h"
#include "TES3OFFSETS.h"
#include <string.h>
// 22-08-2006 Tp21
#include "warnings.h"
	

//Tp21 22-08-2006: xGetSpellEffects
//TODO i don't think it works... (we don't get the return results... have to find that breakpoint)
FUNCGETSPELLEFFECTS::FUNCGETSPELLEFFECTS(TES3MACHINE& vm) : machine(vm), HWBREAKPOINT()
{
}

bool FUNCGETSPELLEFFECTS::execute(void)
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
			context.Eip= (DWORD)reltolinear(FIXUPTEMPLATE);
			machine.SetFlow(context);
			result= machine.SetVMDebuggerBreakpoint(this);
		}
	}
	else
		result= false;

	return result;
}

BYTE FUNCGETSPELLEFFECTS::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool FUNCGETSPELLEFFECTS::breakpoint()
{
	bool result= false;
	Context flow= machine.GetFlow();
	if(machine.WriteMem((VPVOID)reltolinear(SECONDOBJECT_IMAGE),&flow.Eax,sizeof(flow.Eax)))
	{
		machine.SetFlow(parent);
		result= CallOriginalFunction(machine,ORIG_GETSPELLEFFECTS);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("FUNCGETSPELLEFFECTSb() %s\n",result?"succeeded":"failed");
#endif

	return result;
}

bool FUNCGETVALUE::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG offset = 0;
	ULONG count = 0;
	ULONG value = 0;
	char idstr[129];
	idstr[128] = 0;
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		offset = offsetOfValue(type);
		if (offset && GetOffsetData(machine, temp, offset, &value))
		{
			// clothing value is stored in a short not long like all others
			if (type == 'TOLC')
				value %= 65536;
	
			// gold is special (it's always worth one, but not in the CS)
			if ( type == 'CSIM' && GetIdString(machine, temp, idstr))
				if (!strncmp(idstr,"Gold_",5 )) 
					value = 1;
	
			if (GetAttachData(machine, refr, VARNODE, 0, &count))
				value *= count;
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCGETVALUE()\n",value);
#endif	
	return machine.push((VMREGTYPE)value);
}

bool FUNCGETOWNER::execute(void)
{
	VPVOID refr;
	ULONG data;
	ULONG id = 0;
	char idstr[129];
	idstr[128] = 0;
	if (GetTargetData(machine, &refr))
	{
		if (GetAttachData(machine, refr, VARNODE, 1, &data) && data)
		{
			if (GetIdString(machine, (VPVOID)data, idstr))
				id= (ULONG)strings.add((const char*)idstr);
			else
				id= (ULONG)strings.add("unknown");
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lx %s= FUNCGETOWNER()\n",id, (id?(char*)id:"(null)"));
#endif	
		
	return machine.push((VMREGTYPE)id);
}


bool FUNCGETWEIGHT::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG offset = 0;
	ULONG count = 0;
	VMFLOAT weight = 0.0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		if ( offset = offsetOfWeight(type) )
			GetOffsetData(machine,temp,offset,(ULONG*)&weight);
		
		if ( GetAttachData(machine, refr, VARNODE, 0, &count) )
			weight *= count;
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETWEIGHT()\n",weight);
#endif	
	return machine.push((VMFLOAT)weight);
}


bool FUNCGETENCUMB::execute(void)
{
	bool result= false;
	VMPTR<TES3REFERENCE*> pref(machine);
	VMPTR<TES3REFERENCE> ref(machine);
	VMPTR<TES3LISTNODE> stacknode(machine);
	VMPTR<TES3STACK> thisstack(machine);
	VMPTR<TES3TEMPLATE> templ(machine);
	VPLISTNODE pstacknode= 0;
	
	bool leveled = false;
	VMFLOAT totalweight = 0.0;
	VMFLOAT weight = 0.0;
	int i;
	try
	{
		pref= (TES3REFERENCE**)reltolinear(SCRIPTTARGETREF_IMAGE);
		if (!*pref) throw 0;
	
		ref= *pref;
		if ( REFERENCE::GetInventory(machine,*pref,pstacknode) )
		{
			while ( pstacknode )
			{
				stacknode = pstacknode;
				if (stacknode->dataptr)
				{
					thisstack = (VPSTACK)stacknode->dataptr;
					if (thisstack->templ)
					{
						templ = thisstack->templ;
						if ( i = offsetOfWeight(templ->type) ) 
						{
							machine.ReadMem(LONGOFFSET(thisstack->templ,i),&weight,sizeof(weight));
							totalweight += (weight * abs((int)thisstack->count));
						}
						else if ( templ->type == 'IVEL' )
						{
							totalweight += 0.000001;
							leveled = true;
						}
					}
				}
				pstacknode = stacknode->next;
			}
		}
		if ( leveled )
			totalweight *= -1;
		result= machine.push((VMFLOAT)totalweight);
	}
	catch(...)
	{
		result= machine.push((VMFLOAT)totalweight);
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETENCUMB() %s\n",totalweight,result?"succeeded":"failed");
#endif	
	return result;
}


bool FUNCGETCONDITION::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG value = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		if (!GetAttachData(machine, refr, VARNODE, 3, &value))
		{
			ULONG offset = offsetOfCondition(type);
			if ( offset )
				GetOffsetData(machine, temp, offset, &value);
			if ( type == 'PAEW' ) 
				value /= 65536;   // weapon uses short stored in upper half
		}
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCGETCONDITION()\n",value);
#endif	
	return machine.push((VMREGTYPE)value);
}

bool FUNCGETMAXCOND::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG value = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		ULONG offset = offsetOfCondition(type);
		if ( offset )
			GetOffsetData(machine, temp, offset, &value);
		if ( type == 'PAEW' ) 
			value /= 65536;   // weapon uses short stored in upper half
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCGETMAXCOND()\n",value);
#endif	
	return machine.push((VMREGTYPE)value);
}

bool FUNCGETCHARGE::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG ench = 0;
	ULONG value = 0;
	VMFLOAT charge = 0.0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		if (!GetAttachData(machine, refr, VARNODE, 4, (ULONG*)&charge))
		{ 		//	charge = *((VMFLOAT*)(&data));
			if ( type == 'OMRA' )
				GetOffsetData(machine, temp, 0x30, &ench);
			else if ( type == 'TOLC' )
				GetOffsetData(machine, temp, 0x2d, &ench);
			else if ( type == 'PAEW' ) 
				GetOffsetData(machine, temp, 0x1d, &ench);
		
			if (ench)  // found enchantment record
				GetOffsetData(machine,(VPVOID)ench,0x10,&value);
			value %= 4;	// type of enchantment
			if ( value == 1 || value == 2) // uses charges
				GetOffsetData(machine,(VPVOID)ench,0xc,&value);
			if (value)
				charge = value;  // want float format to match current charge
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETCHARGE()\n",charge);
#endif	
	return machine.push((VMFLOAT)charge);
}

bool FUNCGETMAXCHARGE::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG ench = 0;
	ULONG value = 0;
	VMFLOAT maxcharge = 0.0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		if ( type == 'OMRA' )
			GetOffsetData(machine, temp, 0x30, &ench);
		else if ( type == 'TOLC' )
			GetOffsetData(machine, temp, 0x2d, &ench);
		else if ( type == 'PAEW' ) 
			GetOffsetData(machine, temp, 0x1d, &ench);
		
		if (ench)  // found enchantment record
			GetOffsetData(machine,(VPVOID)ench,0x10,&value);
		value %= 4;	// type of enchantment
		if ( value == 1 || value == 2 ) // uses charges
			GetOffsetData(machine,(VPVOID)ench,0xc,&value);
		if (value)
			maxcharge = value;  // want float format to match current charge
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETMAXCHARGE()\n",maxcharge);
#endif	
	return machine.push((VMFLOAT)maxcharge);
}

bool FUNCGETQUALITY::execute(void)
{
	VPVOID refr, temp;
	ULONG type;
	ULONG offset;
	ULONG count = 0;
	VMFLOAT quality = 0.0;
	
	if (GetTargetData(machine, &refr, &temp, &type))
	{
		offset = offsetOfQuality(type);
		if (offset)
			GetOffsetData(machine,temp,offset,(ULONG*)&quality);
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETQUALITY()\n",quality);
#endif	
	return machine.push((VMFLOAT)quality);
}

bool FUNCGETNAME::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	VPVOID addr = 0;
	ULONG str = 0;
	char namestr[129];
	namestr[128] = 0;
	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
		if (type == '_CPN' || type == 'AERC')
			GetOffsetData(machine,base?base:temp,0x1c,(ULONG*)&addr);
		else if (type == 'TNOC')
			GetOffsetData(machine,temp,0x1b,(ULONG*)&addr);
		else if (type == 'HGIL')
			GetOffsetData(machine,temp,0x12,(ULONG*)&addr);
		else if (type == 'TOLC' || type == 'OMRA' || type == 'PAEW' 
			|| type == 'CSIM' || type == 'KOOB' || type == 'HCLA')
			GetOffsetData(machine,temp,0x11,(ULONG*)&addr);
		else if (type == 'ITCA')
			GetOffsetData(machine,temp,0xe,(ULONG*)&addr);
		else if (type == 'ROOD')
			addr = LONGOFFSET(temp,0x0d);
		else if (type == 'APPA')
			addr = LONGOFFSET(temp,0x19);
		else if (type == 'RGNI' || type == 'APER' || type == 'BORP' || type == 'KCIP')
			addr = LONGOFFSET(temp,0x11);

		if (addr && machine.ReadMem((VPVOID)addr, namestr, 128))
				str = (ULONG)strings.add((const char*)namestr);
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lx %s= FUNCGETNAME()\n",str, (str?(char*)str:"(null)"));
#endif	
		
	return machine.push((VMREGTYPE)str);
}

//Tp21 22-08-2006: xSetName
//TODO xSetName, very buggy
bool FUNCSETNAME::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	VPVOID addr = 0;
	ULONG str = 0;

	VMREGTYPE newname = 0;
	const char* string= "null";
	

	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
		if(machine.pop(newname) && (string=machine.GetString((VPVOID)newname))!=0)
		{
			//if the type is npc_ or crea
		if (type == '_CPN' || type == 'AERC')
			GetOffsetData(machine,base?base:temp,0x1c,(ULONG*)&addr);
		else if (type == 'TNOC')
			GetOffsetData(machine,temp,0x1b,(ULONG*)&addr);
		else if (type == 'HGIL')
			GetOffsetData(machine,temp,0x12,(ULONG*)&addr);
		else if (type == 'TOLC' || type == 'OMRA' || type == 'PAEW' 
			|| type == 'CSIM' || type == 'KOOB' || type == 'HCLA')
			GetOffsetData(machine,temp,0x11,(ULONG*)&addr);
		else if (type == 'ITCA')
			GetOffsetData(machine,temp,0xe,(ULONG*)&addr);
		else if (type == 'ROOD')
			addr = LONGOFFSET(temp,0x0d);
		else if (type == 'APPA')
			addr = LONGOFFSET(temp,0x19);
		else if (type == 'RGNI' || type == 'APER' || type == 'BORP' || type == 'KCIP')
			addr = LONGOFFSET(temp,0x11);

			//this writes the string (max char= 128!)
			//no check for maximum characters
			if ( addr )
				machine.WriteMem((VPVOID)addr, string, 128);

//			if addr is true, read the name from memory
//			if (addr && machine.ReadMem((VPVOID)addr, namestr, 128))
//					str = (ULONG)strings.add((const char*)namestr);
//					machine.WriteMem((VPVOID)addr, namestr, 128);
		}
	}
#ifdef DEBUGGING
//	cLog::mLogMessage("%lx %s %s= FUNCSETNAME()\n",str, (str?(char*)str:"(null)"), string);
#endif	

	return true;
}

bool FUNCGETBASEID::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG id = 0;
	char idstr[129];
	idstr[128] = 0;
	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
		if (base && GetIdString(machine, (VPVOID)base, idstr))
			id= (ULONG)strings.add((const char*)idstr);
		else if (temp && GetIdString(machine, (VPVOID)temp, idstr))
			id= (ULONG)strings.add((const char*)idstr);
		else
			id= (ULONG)strings.add("unknown");
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lx %s= FUNCGETBASEID()\n",id, (id?(char*)id:"(null)"));
#endif	
		
	return machine.push((VMREGTYPE)id);
}



bool FUNCGETBASESTR::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x96, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASESTR()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASEINT::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x99, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEINT()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASEWIL::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x9c, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEWIL()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASEAGI::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0x9f, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEAGI()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASESPE::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xa2, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASESPE()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASEEND::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xa5, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEEND()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASEPER::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xa8, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASEPER()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}

bool FUNCGETBASELUC::execute(void)
{
	VPVOID refr;
	VMFLOAT value = -1.0;
	
	if (GetTargetData(machine, &refr))
		GetAttachData(machine, refr, 8, 0xab, (ULONG*)&value);
#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCGETBASELUC()\n",value);
#endif	
	return machine.push((VMFLOAT)value);
}



bool FUNCISFEMALE::execute(void)
{
	VPVOID refr, temp;
	ULONG value = 0;
	
	if (GetTargetData(machine, &refr, &temp))
		if (GetOffsetData(machine, temp, OFFSET_NPCFLAGS, &value))
			value %= 2;	// lowest bit
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCISFEMALE()\n",value);
#endif	
	return machine.push((VMREGTYPE)value);
}

bool FUNCMYCELLID::execute(void)
{
	VPVOID refr, addr;
	ULONG data;
	ULONG id = 0;
	char idstr[129];
	idstr[128] = 0;
	if (GetTargetData(machine, &refr))
	{
		if (GetOffsetData(machine, refr, 5, &data) && data)
			if (GetOffsetData(machine, (VPVOID)data, 3, (ULONG*)&addr) && addr)
				if (GetOffsetData(machine, addr, 4, &data) && data)
					if (machine.ReadMem((VPVOID)data, (VPVOID)idstr, 128))
						id= (ULONG)strings.add((const char*)idstr);
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lx %s= FUNCMYCELLID()\n",id, (id?(char*)id:"(null)"));
#endif	
		
	return machine.push((VMREGTYPE)id);
}




bool FUNCGETBASEGOLD::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG value = 0;
	ULONG gold = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
		if (!base)
			base = temp;
		if ( type == '_CPN' )
			GetOffsetData(machine, base, OFFSET_NPCBASEGOLD, &gold);
		else if ( type == 'AERC' )
			GetOffsetData(machine, base, OFFSET_CREBASEGOLD, &gold);
		gold %= 65536; // it's a short here, so lower half only
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCGETBASEGOLD()\n",gold);
#endif	
	return machine.push((VMREGTYPE)gold);
}

bool FUNCGETGOLD::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG value = 0;
	ULONG gold = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
		if (!GetAttachData(machine, refr, 8, OFFSET_GOLD, &gold))
		{
			if (!base)
				base = temp;
			if ( type == '_CPN' )
				GetOffsetData(machine, base, OFFSET_NPCBASEGOLD, &gold);
			else if ( type == 'AERC' )
				GetOffsetData(machine, base, OFFSET_CREBASEGOLD, &gold);
			gold %= 65536; // it's a short here, so lower half only
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCGETGOLD()\n",gold);
#endif	
	return machine.push((VMREGTYPE)gold);
}

bool FUNCSETBASEGOLD::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG value = 0;
	VMREGTYPE gold = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base))
	{
        	if (machine.pop(gold))
		{
			if (!base)
				base = temp;
			if ( type == '_CPN' )
				if (GetOffsetData(machine, base, OFFSET_NPCBASEGOLD, &value))
				{
					value /= 65536;
					gold %= 65536;  // gold is hold the lower half here
					gold = gold + value * 65536;
					SetOffsetData(machine, base, OFFSET_NPCBASEGOLD, gold);
				}
			else if ( type == 'AERC' )
				if (GetOffsetData(machine, base, OFFSET_CREBASEGOLD, &value))
				{
					value /= 65536;
					gold %= 65536;  // gold is hold the lower half here
					gold = gold + value * 65536;
					SetOffsetData(machine, base, OFFSET_CREBASEGOLD, gold);
				}
		}
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCSETBASEGOLD()\n",gold);
#endif	
	return machine.push((VMREGTYPE)gold);
}

bool FUNCSETGOLD::execute(void)
{
	bool result = false;
	VPVOID refr;
	ULONG value = 0;
	VMREGTYPE gold = 0;
	
	if (GetTargetData(machine, &refr))
	{
        	if (machine.pop(gold))
			result = SetAttachData(machine, refr, 8, OFFSET_GOLD, (ULONG)gold);
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCSETGOLD()\n",gold);
#endif	
	return result;
}



bool FUNCISTRADER::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	ULONG value = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == '_CPN')
	{
		if (!base || !GetOffsetData(machine, base, 1, &value) || value != '_CPN')
			base = temp;  // in case npc isn't currently loaded
		
		GetOffsetData(machine,base,OFFSET_NPCSERVICES,&flags);
		flags &= 0x000037FF;
	
		if (GetOffsetData(machine,base,OFFSET_NPCCLASS,(ULONG*)&temp) && temp) // class info
		{
			if (GetOffsetData(machine,temp,1,&value) && value == 'SALC') 
			{
				GetOffsetData(machine,temp,OFFSET_CLASSSERVICES,&cflags);
				cflags &= 0x000037FF;
			}
		}
		
		flags |= cflags; 
	}
	
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCISTRADER()\n",flags);
#endif	
	return machine.push((VMREGTYPE)flags);
}

bool FUNCISTRAINER::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	ULONG value = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == '_CPN')
	{
		if (!base || !GetOffsetData(machine, base, 1, &value) || value != '_CPN')
			base = temp;  // in case npc isn't currently loaded
		
		GetOffsetData(machine,base,OFFSET_NPCSERVICES,&flags);
		flags &= 0x00004000;
	
		if (GetOffsetData(machine,base,OFFSET_NPCCLASS,(ULONG*)&temp) && temp) // class info
		{
			if (GetOffsetData(machine,temp,1,&value) && value == 'SALC') 
			{
				GetOffsetData(machine,temp,OFFSET_CLASSSERVICES,&cflags);
				cflags &= 0x00004000;
			}
		}
		if ( flags | cflags ) 
			flags = 1;
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCISTRAINER()\n",flags);
#endif	
	return machine.push((VMREGTYPE)flags);
}

bool FUNCISPROVIDER::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	ULONG value = 0;
	
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == '_CPN')
	{
		if (!base || !GetOffsetData(machine, base, 1, &value) || value != '_CPN')
			base = temp;  // in case npc isn't currently loaded
		
		GetOffsetData(machine,base,OFFSET_NPCSERVICES,&flags);
		flags &= 0x00038800;
	
		if (GetOffsetData(machine,base,OFFSET_NPCCLASS,(ULONG*)&temp) && temp) // class info
		{
			if (GetOffsetData(machine,temp,1,&value) && value == 'SALC') 
			{
				GetOffsetData(machine,temp,OFFSET_CLASSSERVICES,&cflags);
				cflags &= 0x00038800;
			}
		}
		flags |= cflags;
	}
#ifdef DEBUGGING
	cLog::mLogMessage("%lu= FUNCISPROVIDER()\n",flags);
#endif	
	return machine.push((VMREGTYPE)flags);
}



// 2005-07-12  CDC  More powerful alternatives to the IsTrader/Trainer/Provider functions
bool FUNCGETSERVICE::execute(void)
{
	VPVOID refr, temp, base;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	ULONG mask = 0x0003FFFF;
	
	if (machine.pop((VMREGTYPE&)mask)) 
		mask &= 0x0003FFFF;
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == '_CPN')
	{
		if (!base || !GetOffsetData(machine, base, 1, &type) || type != '_CPN')
			base = temp;  // in case npc isn't currently loaded
		
		GetOffsetData(machine,base,OFFSET_NPCSERVICES,&flags);		// the npc data
		//if (GetOffsetData(machine,base,OFFSET_NPCCLASS,(ULONG*)&temp) 	// class info if available?
		//	&& temp && GetOffsetData(machine,temp,1,&type) && type == 'SALC')
		//	GetOffsetData(machine,temp,OFFSET_CLASSSERVICES,&cflags);
		flags |= cflags; 
		flags &= mask;
	}
	return machine.push((VMREGTYPE)flags);
}

bool FUNCSETSERVICE::execute(void)
{
	VPVOID refr, temp, base;
	VMREGTYPE data;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	
	if (!machine.pop(data)) return false;

	flags = data & 0x0003FFFF;
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == '_CPN')
	{
		if (!base || !GetOffsetData(machine, base, 1, &type) || type != '_CPN')
			base = temp;  // in case npc isn't currently loaded
		
		return SetOffsetData(machine,base,OFFSET_NPCSERVICES,flags);
	}
	return false;
}

bool FUNCMODSERVICE::execute(void)
{
	VPVOID refr, temp, base;
	VMREGTYPE data;
	ULONG type;
	ULONG flags = 0;
	ULONG cflags = 0;
	
	if (!machine.pop(data)) return false;
	if (GetTargetData(machine, &refr, &temp, &type, &base) && type == '_CPN')
	{
		if (!base || !GetOffsetData(machine, base, 1, &type) || type != '_CPN')
			base = temp;  // in case npc isn't currently loaded
		
		GetOffsetData(machine,base,OFFSET_NPCSERVICES,&flags);		// the npc data
		if (GetOffsetData(machine,base,OFFSET_NPCCLASS,(ULONG*)&temp) 	// class info if available?
			&& temp && GetOffsetData(machine,temp,1,&type) && type == 'SALC')
			GetOffsetData(machine,temp,OFFSET_CLASSSERVICES,&cflags);
		flags |= cflags; 

	if ( ((signed long)data) < 0 )	// Want to remove services
		flags = flags & (~((ULONG)(0-(signed long)data)));
	else				// Want to add services
		flags = flags | (data & 0x0003FFFF);
		return SetOffsetData(machine,base,OFFSET_NPCSERVICES,flags);
	}
	return false;
}
