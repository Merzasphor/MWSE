//Reference.cpp

#include "REFERENCE.h"
#include "DEBUGGING.h"

bool REFERENCE::GetAttachment(TES3MACHINE& machine, VPREFERENCE pref, VPVOID& attachment, AttachTypes type)
{
	bool result= true;
	
	try
	{
		VMPTR<TES3REFERENCE> ref(machine,pref);
		VMPTR<TES3LISTNODE> node(machine,ref->attachments);
		while(node && node->type!=type)
			node= node->next;
		
		if(node)
			attachment= node->dataptr;
	}
	catch(...)
	{
		result= false;
	}
	
	return result;
}

bool REFERENCE::GetMach(TES3MACHINE& machine, VPREFERENCE ref, VPMACH& mach)
{
	return GetAttachment(machine,ref,(VPVOID&)mach,MACHNODE);
}

bool REFERENCE::GetVars(TES3MACHINE& machine, VPREFERENCE ref, VPVARHOLDER& varholder)
{
	return GetAttachment(machine,ref,(VPVOID&)varholder,VARNODE);
}

bool REFERENCE::isContainer(VMPTR<TES3TEMPLATE>& templ)
{
	DWORD type= templ->type;
	return (type==NPC || type==CREA || type==CONT);
}

bool REFERENCE::GetInventory(TES3MACHINE& machine, VPREFERENCE pref, VPLISTNODE& firststack)
{
	firststack= 0;
	
	VMPTR<TES3REFERENCE> ref(machine,pref);
	VMPTR<TES3TEMPLATE> templ(machine,ref->templ);

	if(isContainer(templ))
		firststack= templ->inventory.first;
	
	return true;
}
