//BufSpace.h
#pragma once

#include <string.h>
#include "ADDRESSSPACE.h"

struct BUFSPACE : public ADDRESSSPACE
{
	BUFSPACE(VMSIZE size);
	~BUFSPACE(void);
	virtual bool Read(VPVOID addr, VOID* buf, VMSIZE size);
	virtual bool Write(VPVOID addr, VOID* buf, VMSIZE size);
	virtual VMSIZE size(void);

	private:
	VMSIZE memsize;
	BYTE* mem;
};
