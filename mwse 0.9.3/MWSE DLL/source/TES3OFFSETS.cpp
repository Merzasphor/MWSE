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
		case 'CSIM':
		case 'KOOB':
		case 'HCLA':
		case 'PAEW': return 0x16;
		case 'HGIL': return 0x17;
		case 'RGNI':
		case 'KCOL':
		case 'BORP':
		case 'REPA': return 0x2b;
		case 'OMRA':
		case 'TOLC': return 0x2c;
		case 'APPA': return 0x2d;
	}
	return 0;
}
	
// offset of weight in carriable item templates
ULONG offsetOfWeight(ULONG type) {
	ULONG i = offsetOfValue(type) - 1;
	if (type == 'TNOC') i = 0x1e;
	if ( i < 0 ) i = 0;
	return i;
}

ULONG offsetOfCondition(ULONG type) {
	switch ( type ) {
		case 'KCOL':
		case 'BORP':
		case 'OMRA': return 0x2d;
		case 'APER': return 0x2c;
		case 'PAEW': return 0x17;
	}
	return 0;
}

ULONG offsetOfQuality(ULONG type) {
	switch ( type ) {
		case 'APPA': return 0x2b;
		case 'KCOL':
		case 'BORP': return 0x2c;
		case 'APER': return 0x2d;
	}
	return 0;
}


const char *GetNameString(TES3MACHINE& vm, VPVOID temp, ULONG type, VPVOID base)
{
	VPVOID addr = 0;
	char namestr[129];
	namestr[128] = 0;

	if (type == '_CPN' || type == 'AERC')
		GetOffsetData(vm,base?base:temp,0x1c,(ULONG*)&addr);
	else if (type == 'TNOC')
		GetOffsetData(vm,temp,0x1b,(ULONG*)&addr);
	else if (type == 'HGIL')
		GetOffsetData(vm,temp,0x12,(ULONG*)&addr);
	else if (type == 'TOLC' || type == 'OMRA' || type == 'PAEW' 
		|| type == 'CSIM' || type == 'KOOB' || type == 'HCLA')
		GetOffsetData(vm,temp,0x11,(ULONG*)&addr);
	else if (type == 'ITCA')
		GetOffsetData(vm,temp,0xe,(ULONG*)&addr);
	else if (type == 'ROOD')
		addr = LONGOFFSET(temp,0x0d);
	else if (type == 'APPA')
		addr = LONGOFFSET(temp,0x19);
	else if (type == 'RGNI' || type == 'APER' || type == 'BORP' || type == 'KCIP')
		addr = LONGOFFSET(temp,0x11);

	if (addr && vm.ReadMem((VPVOID)addr, namestr, 128))
		return strings.add(namestr);
	else
		return 0;
}

	
bool GetOffsetData(TES3MACHINE& vm, VPVOID base, ULONG offset, ULONG* data) 
{
	return vm.ReadMem(LONGOFFSET(base,offset),data,sizeof(ULONG));
}
	
bool SetOffsetData(TES3MACHINE& vm, VPVOID base, ULONG offset, ULONG data) 
{
	return vm.WriteMem(LONGOFFSET(base,offset),(VPVOID)&data,sizeof(ULONG));
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

bool GetAttachData(TES3MACHINE& vm, VPVOID ref, ULONG type, ULONG offset, ULONG* data) 
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
			return GetOffsetData(vm,node.dataptr,offset,data);
	}
	return false;
}

bool SetAttachData(TES3MACHINE& vm, VPVOID ref, ULONG type, ULONG offset, ULONG data) 
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
			return SetOffsetData(vm,node.dataptr,offset,data);
	}
	return false;
}



