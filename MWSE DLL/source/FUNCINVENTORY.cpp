//FuncInventory.cpp

#include <string.h>
#include "FUNCINVENTORY.h"
#include "TES3MEMMAP.h"
#include "TES3OPCODES.h"
#include "DEBUGGING.h"
#include "REFERENCE.h"
#include "cLog.h"
#include "TES3OFFSETS.h"

// 22-08-2006 Tp21
#include "warnings.h"

bool FUNCEXPLODESPELL::execute(void) 
{ 
     bool result = true; 
     VMREGTYPE pString = 0; 
     const char* string = "null"; 
 
     if(machine.pop(pString)
		 && (string = machine.GetString(reinterpret_cast<VPVOID>(pString))) != 0) 
     { 
          VMLONG strlength = strlen(string); 
          parent = machine.GetFlow(); 
          result = machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_LENGTH_IMAGE)), &strlength, sizeof(strlength)) 
               && machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)), (void*)string, strlength+1); 
          if(result) 
          { 
               Context context = machine.GetFlow(); 
               context.Eip = (DWORD)reltolinear(FIXUPTEMPLATE); 
                machine.SetFlow(context); 
               result = machine.SetVMDebuggerBreakpoint(this); 
          } 
     } 
     else 
		 result= false; 
 
	#ifdef DEBUGGING 
     cLog::mLogMessage("FUNCEXPLODESPELL(%s) %s\n",string,result?"succeeded":"failed"); 
	#endif
	 
	 return result; 
}


BYTE FUNCEXPLODESPELL::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool FUNCEXPLODESPELL::breakpoint()
{
	bool result = false;
	Context flow = machine.GetFlow();
	if(machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)), &flow.Eax, sizeof(flow.Eax)))
	{
		machine.SetFlow(parent);
		result = CallOriginalFunction(machine,ORIG_EXPLODESPELL);
	}
	
	#ifdef DEBUGGING
	cLog::mLogMessage("FUNCADDSPELLb() %s\n",result?"succeeded":"failed");
	#endif

	return result;
}


//Fliggerty 12-27-06
FUNCADDSPELL::FUNCADDSPELL(TES3MACHINE& vm) : machine(vm), HWBREAKPOINT()
{
}

bool FUNCADDSPELL::execute(void) 
{ 
     bool result = true; 
     VMREGTYPE pString = 0; 
     const char* string = "null"; 
 
     if(machine.pop(pString)
		 && (string = machine.GetString(reinterpret_cast<VPVOID>(pString))) != 0) 
     { 
          VMLONG strlength = strlen(string); 
          parent = machine.GetFlow(); 
          result = machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_LENGTH_IMAGE)), &strlength, sizeof(strlength)) 
               && machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)), (void*)string, strlength+1); 
          if(result) 
          { 
               Context context = machine.GetFlow(); 
               context.Eip = (DWORD)reltolinear(FIXUPTEMPLATE); 
                machine.SetFlow(context); 
               result = machine.SetVMDebuggerBreakpoint(this); 
          } 
     } 
     else 
		 result= false; 
 
	#ifdef DEBUGGING 
     cLog::mLogMessage("FUNCADDSPELL(%s) %s\n",string,result?"succeeded":"failed"); 
	#endif
	 
	 return result; 
}


BYTE FUNCADDSPELL::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool FUNCADDSPELL::breakpoint()
{
	bool result = false;
	Context flow = machine.GetFlow();
	if(machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)), &flow.Eax, sizeof(flow.Eax)))
	{
		machine.SetFlow(parent);
		result = CallOriginalFunction(machine,ORIG_ADDSPELL);
	}
	
	#ifdef DEBUGGING
	cLog::mLogMessage("FUNCADDSPELLb() %s\n",result?"succeeded":"failed");
	#endif

	return result;
}
//Fliggerty 12-29-06
FUNCREMOVESPELL::FUNCREMOVESPELL(TES3MACHINE& vm) : machine(vm), HWBREAKPOINT()
{
}

bool FUNCREMOVESPELL::execute(void) 
{ 
     bool result = true; 
     VMREGTYPE pString = 0; 
     const char* string = "null"; 
 
     if(machine.pop(pString)
		 && (string = machine.GetString(reinterpret_cast<VPVOID>(pString))) != 0) 
     { 
          VMLONG strlength = strlen(string); 
          parent = machine.GetFlow(); 
          result = machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_LENGTH_IMAGE)), &strlength, sizeof(strlength)) 
               && machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)), (void*)string, strlength+1); 
          if(result) 
          { 
               Context context = machine.GetFlow(); 
               context.Eip = (DWORD)reltolinear(FIXUPTEMPLATE); 
                machine.SetFlow(context); 
               result = machine.SetVMDebuggerBreakpoint(this); 
          } 
     } 
     else 
		 result= false; 
 
	#ifdef DEBUGGING 
     cLog::mLogMessage("FUNCREMOVESPELL(%s) %s\n",string,result?"succeeded":"failed"); 
	#endif
	 
	 return result; 
}


BYTE FUNCREMOVESPELL::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool FUNCREMOVESPELL::breakpoint()
{
	bool result = false;
	Context flow = machine.GetFlow();
	if(machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)), &flow.Eax, sizeof(flow.Eax)))
	{
		machine.SetFlow(parent);
		result = CallOriginalFunction(machine,ORIG_REMOVESPELL);
	}
	
	#ifdef DEBUGGING
	cLog::mLogMessage("FUNCREMOVESPELLb() %s\n",result?"succeeded":"failed");
	#endif

	return result;
}

//Tp21 22-08-2006: xDrop
FUNCDROPITEM::FUNCDROPITEM(TES3MACHINE& vm) : machine(vm), HWBREAKPOINT()
{
}

bool FUNCDROPITEM::execute(void)
{
	bool result = true;
	VMREGTYPE pString = 0;
	const char* string = "null";
	VMREGTYPE count = 0;

	if(machine.pop(pString) 
		&& machine.pop(count) 
		&& (string=machine.GetString(reinterpret_cast<VPVOID>(pString))) != 0)
	{
		VMLONG strlength = strlen((const char*)string);
		parent = machine.GetFlow();
		result = machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_LENGTH_IMAGE)), &strlength, sizeof(strlength))
			&& machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)), (void*)string, strlength+1)
			&& machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(VARINDEX_IMAGE)), (void*)&count, sizeof(count));
		if(result)
		{
			Context context = machine.GetFlow();
			context.Eip = (DWORD)reltolinear(FIXUPTEMPLATE);
			machine.SetFlow(context);
			result = machine.SetVMDebuggerBreakpoint(this);
		}
	}
	else
		result = false;

	return result;
}

BYTE FUNCDROPITEM::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool FUNCDROPITEM::breakpoint()
{
	bool result= false;
	Context flow= machine.GetFlow();
	if(machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)),&flow.Eax,sizeof(flow.Eax)))
	{
		machine.SetFlow(parent);
		result= CallOriginalFunction(machine,ORIG_DROPITEM);
	}

	return result;
}

//TP21 27-12-2006: xCast
FUNCCAST::FUNCCAST(TES3MACHINE& vm) :machine(vm), HWBREAKPOINT()
{
}

bool FUNCCAST::execute(void)
{
	bool result = true;
	VMREGTYPE pString = 0;
	const char* string = "null";

	if (machine.pop(pString) && (string = machine.GetString(reinterpret_cast<VPVOID>(pString))) != 0)
	{
		VMLONG strlength = strlen((const char*)string);
		parent = machine.GetFlow();
		result = machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_LENGTH_IMAGE)), &strlength, sizeof(strlength))
			&& machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)), (void*)string, strlength+1);
		if(result)
		{
			Context context= machine.GetFlow();
			context.Eip= (DWORD)reltolinear(FIXUPTEMPLATE);
			machine.SetFlow(context);
			result= machine.SetVMDebuggerBreakpoint(this);
		}
	}
	else
		result = false;

	return result;
}

BYTE FUNCCAST::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool FUNCCAST::breakpoint()
{
	bool result= false;
	Context flow= machine.GetFlow();
	if(machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)),&flow.Eax,sizeof(flow.Eax)))
	{
		machine.SetFlow(parent);
		result= CallOriginalFunction(machine,ORIG_CAST);
	}
	return result;
}

//Tp21 22-08-2006: xEquip
FUNCEQUIPITEM::FUNCEQUIPITEM(TES3MACHINE& vm) : machine(vm), HWBREAKPOINT()
{
}

bool FUNCEQUIPITEM::execute(void)
{
	bool result= true;
	VMREGTYPE pString= 0;
	const char* string= "null";

	if(machine.pop(pString) && (string=machine.GetString(reinterpret_cast<VPVOID>(pString)))!=0)
	{
		VMLONG strlength= strlen((const char*)string);
		parent= machine.GetFlow();
		result= machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_LENGTH_IMAGE)),&strlength,sizeof(strlength))
			&& machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)),(void*)string,strlength+1);
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

BYTE FUNCEQUIPITEM::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool FUNCEQUIPITEM::breakpoint()
{
	bool result= false;
	Context flow= machine.GetFlow();
	if(machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)),&flow.Eax,sizeof(flow.Eax)))
	{
		machine.SetFlow(parent);
		result= CallOriginalFunction(machine,ORIG_EQUIPITEM);
	}

	return result;
}

FUNCADDITEM::FUNCADDITEM(TES3MACHINE& vm)
	:machine(vm)
	,HWBREAKPOINT()
{
}

bool FUNCADDITEM::execute(void)
{
	bool result= true;
	VMREGTYPE pString= 0;
	const char* string= "null";
	VMREGTYPE count= 0;

	if(machine.pop(pString) && machine.pop(count) && (string=machine.GetString(reinterpret_cast<VPVOID>(pString)))!=0)
	{
		VMLONG strlength= strlen((const char*)string);
		parent= machine.GetFlow();
		result= machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_LENGTH_IMAGE)),&strlength,sizeof(strlength))
			&& machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)),(void*)string,strlength+1)
			&& machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(VARINDEX_IMAGE)),(void*)&count,sizeof(count));
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

BYTE FUNCADDITEM::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool FUNCADDITEM::breakpoint()
{
	bool result= false;
	Context flow= machine.GetFlow();
	if(machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)),&flow.Eax,sizeof(flow.Eax)))
	{
		machine.SetFlow(parent);
		result= CallOriginalFunction(machine,ORIG_ADDITEM);
	}

	return result;
}


FUNCREMOVEITEM::FUNCREMOVEITEM(TES3MACHINE& vm)
	:machine(vm)
	,HWBREAKPOINT()
{
}

bool FUNCREMOVEITEM::execute(void)
{
	bool result= true;
	VMREGTYPE pString= 0;
	const char* string= "null";
	VMREGTYPE count= 0;

	if(machine.pop(pString) && machine.pop(count) && (string=machine.GetString(reinterpret_cast<VPVOID>(pString)))!=0)
	{
		VMLONG strlength= strlen((const char*)string);
		parent= machine.GetFlow();
		result= machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_LENGTH_IMAGE)),&strlength,sizeof(strlength))
			&& machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)),(void*)string,strlength+1)
			&& machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(VARINDEX_IMAGE)),(void*)&count,sizeof(count));
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

BYTE FUNCREMOVEITEM::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool FUNCREMOVEITEM::breakpoint()
{
	bool result= false;
	Context flow= machine.GetFlow();
	if(machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)),&flow.Eax,sizeof(flow.Eax)))
	{
		machine.SetFlow(parent);
		result= CallOriginalFunction(machine,ORIG_REMOVEITEM);
	}

	return result;
}

FUNCINVENTORY::FUNCINVENTORY(TES3MACHINE& vm)
	:machine(vm)
{
}

bool FUNCINVENTORY::execute(void)
{
	bool result= true;
	VMREGTYPE ref= 0;
	VMREGTYPE stackpointer= 0;
	
	struct{VMREGTYPE id, count, next;} stackresults={(VMREGTYPE)"null",0,0};
	if(machine.GetRegister(SP,stackpointer))
	{
		machine.SetFlags((VMREGTYPE)0);
		VMPTR<TES3REFERENCE*> pref(machine,(TES3REFERENCE**)reltolinear(SCRIPTTARGETREF_IMAGE));
		VPLISTNODE pstacknode= 0;
		if(REFERENCE::GetInventory(machine,*pref,pstacknode))
		{
			if(pstacknode)
			{
				VMPTR<TES3LISTNODE> stacknode(machine,pstacknode);
				if(stacknode->dataptr)
				{
					VMPTR<TES3STACK> firststack(machine,(VPSTACK)stacknode->dataptr);
					if(firststack->templ)
					{
						VMPTR<TES3TEMPLATE> templ(machine,firststack->templ);
						if(templ->objectid)
						{
							VMPTR<TES3IDSTRING> id(machine,(VPIDSTRING)templ->objectid);
							if(id->id)
							{
								stackresults.id=(VMREGTYPE)strings.add((const char*)id->id);
								stackresults.count=firststack->count;
								stackresults.next=(VMREGTYPE)((VPLISTNODE)stacknode->next);
								machine.SetFlags((VMREGTYPE)1);
							}
						}
					}
				}
			}
		}
		stackpointer-= sizeof(stackresults);
		result= (machine.SetRegister(SP,stackpointer)
			&& machine.WriteMem(reinterpret_cast<VPVOID>(stackpointer),&stackresults,sizeof(stackresults)));

	}
	else
		result= false;

	return result;
}

FUNCNEXTSTACK::FUNCNEXTSTACK(TES3MACHINE& vm)
	:machine(vm)
{
}

bool FUNCNEXTSTACK::execute(void)
{
	bool result= true;
	VMREGTYPE ref= 0;
	VMREGTYPE stackpointer= 0;
	VMREGTYPE pstacknode= 0;
	struct{VMREGTYPE id, count, next;} stackresults={(VMREGTYPE)"null",0,0};
	if(machine.GetRegister(SP,stackpointer)
		&& machine.ReadMem(reinterpret_cast<VPVOID>(stackpointer),&pstacknode,sizeof(pstacknode)))
	{
		machine.SetFlags((VMREGTYPE)0);
		if(pstacknode)
		{
			VMPTR<TES3LISTNODE> stacknode(machine,(VPLISTNODE)pstacknode);
			if(stacknode->dataptr)
			{
				VMPTR<TES3STACK> firststack(machine,(VPSTACK)stacknode->dataptr);
				if(firststack->templ)
				{
					VMPTR<TES3TEMPLATE> templ(machine,firststack->templ);
					if(templ->objectid)
					{
						VMPTR<TES3IDSTRING> id(machine,(VPIDSTRING)templ->objectid);
						if(id->id)
						{
							stackresults.id=(VMREGTYPE)strings.add((const char*)id->id);
							stackresults.count=firststack->count;
							stackresults.next=(VMREGTYPE)((VPLISTNODE)stacknode->next);
							machine.SetFlags((VMREGTYPE)1);
						}
					}
				}
			}
		}
		// 2005-06-29  CDC	// major error here, producing two extra elements on the stack each call!
		stackpointer = stackpointer - sizeof(stackresults) + sizeof(pstacknode);
		result= (machine.SetRegister(SP,stackpointer)
			&& machine.WriteMem(reinterpret_cast<VPVOID>(stackpointer),&stackresults,sizeof(stackresults)));

	}
	else
		result = false;

	return result;
}

FUNCHASEQUIPED::FUNCHASEQUIPED(TES3MACHINE& vm)
	:machine(vm)
	,part2(vm)
	,HWBREAKPOINT()
{
}

bool FUNCHASEQUIPED::execute(void)
{
	bool result= true;
	VMREGTYPE pString= 0;
	const char* string= "null";
	if(machine.pop(pString) && (string=machine.GetString(reinterpret_cast<VPVOID>(pString)))!=0)
	{
		VMLONG strlength= strlen((const char*)string);
		parent= machine.GetFlow();
		result= machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_LENGTH_IMAGE)),&strlength,sizeof(strlength))
			&& machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)),(void*)string,strlength+1);
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

BYTE FUNCHASEQUIPED::getid()
{
	return BP_FIXUPTEMPLATE;
}
bool FUNCHASEQUIPED::breakpoint()
{
	bool result= false;
	
	Context flow= machine.GetFlow();
	machine.SetFlow(parent);
	VMREGTYPE templ= flow.Eax;
	if(templ)
	{
		result=(machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)),&templ,sizeof(templ))
			&& machine.SetVMDebuggerBreakpoint(&part2)
			&& CallOriginalFunction(machine,ORIG_HASEQUIPED));
		
	}
	else
		result= machine.push(templ);
	
	return result;
}

FUNCHASEQUIPEDPART2::FUNCHASEQUIPEDPART2(TES3MACHINE& vm) : machine(vm), HWBREAKPOINT()
{
}

BYTE FUNCHASEQUIPEDPART2::getid()
{
	return BP_HASITEMEQUIPPEDRESULT;
}

bool FUNCHASEQUIPEDPART2::breakpoint()
{
	bool result= false;
	
	Context flow= machine.GetFlow();
	VMREGTYPE equipped= flow.Esi && flow.Eax; // maybe more acurate to test esp->c
	result= machine.push(equipped);
	
	return result;
}

// 2005-07-10  CDC  More detailed information about inventory items, including a rudimentary random item selector
// 2005-06-29  CDC  NextStack won't be used with the new form and there are many more values returned

bool FUNCCONTENTLIST::execute(void)
{
	bool result= true;
	VPVOID refr;
	VMREGTYPE stackpointer= 0;
	VPLISTNODE pnode= 0;
	VPSTACK pstack= 0;
	VPVOID ptempl= 0;
	VMREGTYPE data= 0;
	VMREGTYPE offset = 0;
	char idstr[129] = "null";
	idstr[128]=0;
	struct{VMREGTYPE id, count, type, value, weight, name, next;} invresults={0,0,0,0,0,0,0};

	machine.SetFlags((VMREGTYPE)0);

	machine.pop((VMREGTYPE&)pnode);	// New form for inventory, try to get a reference from the stack
	
	if ( !pnode )	// Parameter null (or missing), so get first item using object reference instead
		GetTargetData(machine, &refr) && REFERENCE::GetInventory(machine,(VPREFERENCE)refr,pnode);

	if ( pnode && GetOffsetData(machine,reinterpret_cast<VPVOID>(pnode),0x2,(ULONG*)&pstack)
		&& pstack && GetOffsetData(machine,reinterpret_cast<VPVOID>(pstack),0x1,(ULONG*)&ptempl) && ptempl )
	{
		GetIdString(machine,ptempl,idstr);
		invresults.id = (VMREGTYPE)strings.add((const char*)idstr);
		GetOffsetData(machine,reinterpret_cast<VPVOID>(pstack),0x0,(ULONG*)&data);
		invresults.count = data;

		GetOffsetData(machine,ptempl,0x1,(ULONG*)&data);
		invresults.type = data;
		offset = offsetOfValue(invresults.type);
		if ( offset && GetOffsetData(machine,ptempl,offset,(ULONG*)&data) ) 
		{
			if ( invresults.type == 'TOLC' ) data %= 65536;
			if ( invresults.type == 'CSIM' && !strncmp(idstr,"Gold_",5) ) data = 1;
			invresults.value = data;
		}
		offset = offsetOfWeight(invresults.type);
		if ( offset && GetOffsetData(machine,ptempl,offset,(ULONG*)&data) )
			invresults.weight = data;

		// Name will be a random ID for a levelled item (value and weight will be 0 though)
		if ( invresults.type == 'IVEL' )
			invresults.name = (ULONG)randomselect(ptempl);
		else if ( data = (VMREGTYPE)GetNameString(machine,ptempl,invresults.type,0) )
			invresults.name = data;

		GetOffsetData(machine,reinterpret_cast<VPVOID>(pnode),0x1,(ULONG*)&data);
		invresults.next = data;
		machine.SetFlags((VMREGTYPE)1);
	}

	machine.GetRegister(SP,stackpointer);
	stackpointer-= sizeof(invresults);
	result= (machine.SetRegister(SP,stackpointer)
		&& machine.WriteMem(reinterpret_cast<VPVOID>(stackpointer),&invresults,sizeof(invresults)));

	return result;
}


// Choose one of the random items from a levelled item list. 
// Unfortunately, getting the player level is hard, so it is ignored right now.
// Any of the items might be selected, but low level ones are more likely.
const char *FUNCCONTENTLIST::randomselect(VPVOID templ)
{
	VPVOID p;
    const char *string;
	VPVOID node;
	VPVOID item;		// item template pointer
	ULONG chance;		// chance of none or pc level value (They are really short values though.)
	ULONG count = 0;	// used to create a fair probability for each item
	char buf[129];

	buf[0] = buf[128] = 0;
    //Timeslip: time doesn't seem to be defined anywhere, so I'll replace it with GetTickCount()
    srand(GetTickCount());
	// Honor the chance for none option
	GetOffsetData(machine, templ, 0xf, &chance);
	if ( (unsigned)(rand() % 100) < (chance & 0xFFFF) ) return 0; //fixed error 4018
	// Find the head of the list
	GetOffsetData(machine, templ, 0xC, (ULONG*)&p);
	if (!p) return 0;	// empty list
	GetOffsetData(machine, p, 0x2, (ULONG*)&node);

	while ( node )
	{
		GetOffsetData(machine, node, 0x2, (ULONG*)&p);
		GetOffsetData(machine, p, 0x0, (ULONG*)&item);
		GetOffsetData(machine, p, 0x1, (ULONG*)&chance);
		chance = chance & 0xFFFF;
		if ( chance >= 80 ) chance = 99;
		else if ( chance >= 40 ) chance = chance / 2 + 60;
		else if ( chance >= 20 ) chance += 20;
		else if ( chance >= 7 ) chance = chance * 2 + 1;
		else chance = chance * 3 - 3;
		count++;
		if ( item && ( (rand() % 1000) < ((1000.0-chance*10)/count) ) )
		{
			GetOffsetData(machine,item,0x1,&chance);	// check for nested levelled lists
			if (chance != 'IVEL') 
				GetIdString(machine, item, buf);
            else if ( string = randomselect(item) ) {
				strncpy(buf,string,sizeof buf-1);
                buf[sizeof buf-1] = '\0';
            }
		}
		GetOffsetData(machine, node, 0x1, (ULONG*)&node);
		fflush(stdout);
	}

	if ( buf[0] )
		return strings.add(buf);
	else
		return 0;
}
