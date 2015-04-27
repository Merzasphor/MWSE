// Based on funcgmst.cpp from MGE XE by Hrnchamd.
#include "FUNCGMST.h"
#include "TES3MemMap.h"
#include "cLog.h"

VMREGTYPE* GetGMSTPointer(TES3MACHINE & machine, VMLONG const id)
{
	VPVOID addr = reinterpret_cast<VPVOID>(reltolinear(MASTER_IMAGE + 0x4));
	machine.ReadMem(addr, &addr, sizeof(addr));
	machine.ReadMem(addr, &addr, sizeof(addr));
	machine.ReadMem(addr + 0x18, &addr, sizeof(addr));
	machine.ReadMem(addr + 4 * id, &addr, sizeof(addr));
	addr += 0x10;
	return reinterpret_cast<VMREGTYPE*>(addr);
}

bool FUNCGETGS::execute(void)
{
	VMLONG id;
    VMREGTYPE ret;

	if (!machine.pop(static_cast<VMREGTYPE&>(id)))
	{
		return false;
	}

	ret = *(GetGMSTPointer(machine, id));
	return machine.push(ret);
}

bool FUNCSETGS::execute(void)
{
	VMLONG id;
    VMLONG value;

	if (!machine.pop(static_cast<VMREGTYPE&>(id)))
	{
		return false;
	}

	if (!machine.pop(static_cast<VMREGTYPE&>(value)))
	{
		return false;
	}
    
	*(GetGMSTPointer(machine, id)) = value;
	return true;
}