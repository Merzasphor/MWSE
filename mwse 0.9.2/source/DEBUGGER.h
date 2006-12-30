//Debugger.h
#pragma once

#include <map>
#include <wtypes.h>
#include "application.h"

// 22-08-2006 Tp21
#include "warnings.h"

#define BREAKPOINT	((BYTE)0xCC)
#define RETURN	((BYTE)0xC3)

#define EFLAGS_SINGLE_STEP ((DWORD)0x00000100)

#ifndef NELEMS
#define NELEMS(a) (sizeof(a)/sizeof(a[0]))
#endif

typedef std::map<LPVOID,BYTE> BREAKPOINTMAP;
typedef std::map<DWORD,HANDLE> THREADHANDLEMAP;

struct DEBUGGER : public application
{
	DEBUGGER(void);
	virtual ~DEBUGGER(void);
	
	virtual int main(int argc, char* argv[]);
	
	virtual void DoCreateProc(DEBUG_EVENT& DebugEv);
	virtual void DoExitProc(DEBUG_EVENT& DebugEv);
	virtual void DoCreateThread(DEBUG_EVENT& DebugEv);
	virtual void DoExitThread(DEBUG_EVENT& DebugEv);
	virtual void DoDebugString(DEBUG_EVENT& DebugEv);
	virtual void DoInitialBreakpoint(DEBUG_EVENT& DebugEv);
	virtual void DoBreakpoint(DEBUG_EVENT& DebugEv);
	virtual void DoPageGuard(DEBUG_EVENT& DebugEv);
	virtual void DoSingleStep(DEBUG_EVENT& DebugEv);
	virtual void DoAccessViolation(DEBUG_EVENT& DebugEv);

	LPVOID reltolinear(LPVOID reladdr){return (LPVOID)((BYTE*)reladdr + (long)procbase);};

	protected:
	virtual int log(char* fmt, ...);
	virtual void logerror(char* fmt);

	virtual int debug(char* commandline);
//	virtual int debugattach(/*const */char* commandline);
	virtual int debug(DWORD processID);
	virtual int debug(const PROCESS_INFORMATION& procinfo);
	
	virtual void closethreadhandles(void);

	virtual bool setpageguard(LPVOID addr);
	virtual bool setbreakpoint(LPVOID addr);
	virtual bool clearbreakpoints(void);
	virtual bool clearbreakpoint(LPVOID addr);
	virtual bool runbreakpoint(CONTEXT& context);

	virtual bool setsinglestep(HANDLE hThread);
	virtual bool clearsinglestep(HANDLE hThread);
	
	protected:
	PROCESS_INFORMATION procinfo;
	LPVOID procbase;
	BREAKPOINTMAP breakpoints;
	THREADHANDLEMAP threadhandles;
	LPVOID stepbreakpoint;
	
	static char emptystring[];
	static SECURITY_ATTRIBUTES security;
	static STARTUPINFO startup;
};
