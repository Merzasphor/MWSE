//Tes3Offsets.cpp

#include "TES3OFFSETS.h"
#include "REFERENCE.h"
#include "TES3MEMMAP.h"
#include "TES3OPCODES.h"
#include "DEBUGGING.h"
#include "cLog.h"
#include <string.h>
	
// offset of value in carriable item templates
ULONG offsetOfValue(ULONG type) {
	switch ( type ) {
		case MISC:
		case BOOK:
		case ALCHEMY:
		case AMMO:
		case WEAPON: return 0x16;
		case LIGHT: return 0x17;
		case INGREDIENT:
		case LOCK:
		case PROBE:
		case REPAIR: return 0x2b;
		case ARMOR:
		case CLOTHING: return 0x2c;
		case APPARATUS: return 0x2d;
	}
	return 0;
}
	
// offset of weight in carriable item templates
ULONG offsetOfWeight(ULONG type) {
	ULONG i = offsetOfValue(type) - 1;
	if (type == CONT) i = 0x1e;
	if ( i < 0 ) i = 0;
	return i;
}

ULONG offsetOfCondition(ULONG type) {
	switch ( type ) {
		case LOCK:
		case PROBE:
		case ARMOR: return 0x2d;
		case REPAIR: return 0x2c;
		case WEAPON: return 0x17;
	}
	return 0;
}

ULONG offsetOfQuality(ULONG type) {
	switch ( type ) {
		case APPARATUS: return 0x2b;
		case LOCK:
		case PROBE: return 0x2c;
		case REPAIR: return 0x2d;
	}
	return 0;
}


const char *GetNameString(TES3MACHINE& vm, VPVOID temp, ULONG type, VPVOID base)
{
	VPVOID addr = 0;
	char namestr[129];
	namestr[128] = 0;

	if (type == NPC || type == CREATURE)
		GetOffsetData(vm,base?base:temp,0x1c,(ULONG*)&addr);
	else if (type == CONTAINER)
		GetOffsetData(vm,temp,0x1b,(ULONG*)&addr);
	else if (type == LIGHT)
		GetOffsetData(vm,temp,0x12,(ULONG*)&addr);
	else if (type == CLOTHING || type == ARMOR || type == WEAPON 
		|| type == MISC || type == BOOK || type == ALCHEMY || type == AMMO)
		GetOffsetData(vm,temp,0x11,(ULONG*)&addr);
	else if (type == ACTIVATOR)
		GetOffsetData(vm,temp,0xe,(ULONG*)&addr);
	else if (type == DOOR)
		addr = LONGOFFSET(temp,0x0d);
	else if (type == APPARATUS)
		addr = LONGOFFSET(temp,0x19);
	else if (type == INGREDIENT || type == REPAIR || type == PROBE || type == LOCKPICK)
		addr = LONGOFFSET(temp,0x11);

	if (addr && vm.ReadMem((VPVOID)addr, namestr, 128))
		return strings.add(namestr);
	else
		return 0;
}

	
bool GetOffsetData(TES3MACHINE& vm, VPVOID base, ULONG offset, void* data, size_t size)
{
	//cLog::mLogMessage("base: %i offset: %i size: %i\n", base, offset, size);
	return vm.ReadMem(LONGOFFSET(base,offset),data,size);
}

bool SetOffsetData(TES3MACHINE& vm, VPVOID base, ULONG offset, void *data, size_t size)
{
	return vm.WriteMem(LONGOFFSET(base,offset),data, size);
}


bool GetIdString(TES3MACHINE& vm, VPVOID temp, char *id)
{
	ULONG pid = 0;
	if (!temp) return false;
	if (!GetOffsetData(vm, temp, 0xb, &pid)) return false;
	if (!pid) return false;
	if (!vm.ReadMem((VPVOID)pid, id, 128)) return false;
	return true;
}

bool GetTargetData(TES3MACHINE& vm, VPVOID* refr, VPVOID* temp, ULONG* type, VPVOID* base) 
{
	ULONG basetype = 0;
	if (!refr) return false;  // nothing to do, pointer invalid
	// pointer to reference for script's target
	if (!(*refr = (VPVOID)reltolinear(SCRIPTTARGETREF_IMAGE))) return false;
	// address of the reference data
	if (!vm.ReadMem(*refr,refr,sizeof(VPVOID))) return false;
	if (!*refr) return false;  // should never be empty

	if (!temp) return true;  // good enough, just wanted refr addr
	// address of the template data
	if (!vm.ReadMem(LONGOFFSET(*refr,0xa),temp,sizeof(VPVOID))) return false;
	if (!*temp) return false;  // should never be empty

	if (!type) return true; // type is optional, but can't get base without it
	GetOffsetData(vm,*temp,1,type);

	if (!base) return true;   // this rarely needed, but if wanted it must exist
	// loaded characters (and other objects) may have a second "template" area
	if (!vm.ReadMem(LONGOFFSET(*temp,0x1b),base,sizeof(VPVOID))) return false;
	GetOffsetData(vm,*base,1,&basetype);
	if ( basetype != *type ) *base = 0;   // not really a base
	return true;
}

bool GetAttachData(TES3MACHINE& vm, VPVOID ref, ULONG type, ULONG offset, void* data, size_t size)
{
	VPVOID pnode = 0;
	TES3LISTNODE node;
	
	GetOffsetData(vm, ref, 0x11, (ULONG*)&pnode); // attachments
	while (pnode)
	{
		if (!vm.ReadMem(pnode,&node,sizeof(node)))
			return false;
		if (node.type != type)
			pnode = (VPVOID)node.next;
		else
		{
			/*if (type == 8)
			{
				char dump[2048];
				bool ret = GetOffsetData(vm, node.dataptr, 0, dump, 2048);
				if (ret)
				{
					cLog::mLogMessage("Type 8 dump.\n");
					cLog::mLogBinaryMessage(dump, 2048);
				}
				else
					cLog::mLogMessage("Error dumping type 8.\n");
			}*/
			return GetOffsetData(vm,node.dataptr,offset,data,size);
		}
	}
	return false;
}

void* GetAttachPointer(TES3MACHINE& vm, VPVOID ref, ULONG type)
{
	VPVOID pnode = 0;
	TES3LISTNODE node;
	
	GetOffsetData(vm, ref, 0x11, (ULONG*)&pnode); // attachments
	while (pnode)
	{
		if (!vm.ReadMem(pnode,&node,sizeof(node)))
			return 0;
		if (node.type != type)
			pnode = (VPVOID)node.next;
		else
		{
			return node.dataptr;
		}
	}
	return 0;
}


bool SetAttachData(TES3MACHINE& vm, VPVOID ref, ULONG type, ULONG offset, void *data, size_t size)
{
	VPVOID pnode = 0;
	TES3LISTNODE node;
	
	GetOffsetData(vm, ref, 0x11, (ULONG*)&pnode); // attachments
	while (pnode)
	{
		if (!vm.ReadMem(pnode,&node,sizeof(node)))
			return false;
		if (node.type != type)
			pnode = (VPVOID)node.next;
		else
			return SetOffsetData(vm,node.dataptr,offset,data,size);
	}
	return false;
}



