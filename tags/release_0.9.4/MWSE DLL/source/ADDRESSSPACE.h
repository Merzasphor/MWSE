//AdressSpace.h
#pragma once

#include "VMTYPES.h"

struct ADDRESSSPACE
{
	virtual ~ADDRESSSPACE(void){};
	virtual bool Read(VPVOID addr, VOID* buf, VMSIZE size)=0;
	virtual bool Write(VPVOID addr, VOID* buf, VMSIZE size)=0;
	virtual VMSIZE size(void)=0;
};
