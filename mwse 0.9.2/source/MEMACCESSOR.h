//MemAccessor.h
#pragma once

#include "VMTYPES.h"
#include "ADDRESSSPACE.h"

struct MEMACCESSOR
{
	virtual ~MEMACCESSOR(void){};
	virtual bool access(ADDRESSSPACE& mem,VPVOID reladdr,VOID* buf,VMSIZE size)=0;
};