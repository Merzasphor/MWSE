#pragma once

#include "WinHeader.h"

struct Context {
	DWORD Eax;
	DWORD Ebx;
	DWORD Ecx;
	DWORD Edx;
	DWORD Edi;
	DWORD Esi;
	DWORD Ebp;
	DWORD Esp;
	DWORD Eip;

	DWORD flags;
};

enum BreakpointIDs {
	BP_FIXUPSCRIPT = 0,
	BP_RUNSCRIPT   = 1,

	BP_DECODEWITHINFO = 2,
	BP_RUNFUNCIDXERR  = 3,

	BP_FIXUPTEMPLATE = 4,
	BP_FIXUPPLAYER   = 5,
	BP_FIXUPINSTANCE = 6,

	BP_PLACEATPCRESULT       = 7,
	BP_HASITEMEQUIPPEDRESULT = 8
};

typedef void (BreakpointFunc)(Context*);

void AddBreakpoint(BYTE ID, BreakpointFunc func);
void RemoveBreakpoint(BYTE ID);

struct HWBREAKPOINT
{
	virtual BYTE getid() = 0;
	virtual bool breakpoint() = 0;
};
