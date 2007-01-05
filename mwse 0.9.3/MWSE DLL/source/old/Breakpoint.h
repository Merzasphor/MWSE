#pragma once

#include "WinHeader.h"

struct Context {
	DWORD eax;
	DWORD ebx;
	DWORD ecx;
	DWORD edx;
	DWORD edi;
	DWORD esi;
	DWORD ebp;
	DWORD esp;
	DWORD eip;

	DWORD flags;
};

enum BreakpointIDs {
	BP_FIXUPSCRIPT    = 0,
	BP_RUNSCRIPT      = 1,
	BP_DECODEWITHINFO = 2,
	
	BP_RUNFUNCIDXERR  = 3,

	BP_FIXUPTEMPLATE  = 4,
	BP_FIXUPPLAYER    = 5,
	BP_FIXUPINSTANCE  = 6
};

typedef void (BreakpointFunc)(Context*);

void AddBreakpoint(BYTE ID, BreakpointFunc func);
void RemoveBreakpoint(BYTE ID);