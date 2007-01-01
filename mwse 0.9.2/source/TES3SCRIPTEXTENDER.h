//Tes3ScriptExtender.h
#pragma once

#include "debugger.h"
#include "TES3MACHINE.h"
#include "LOG.h"

struct TES3SCRIPTEXTENDER : public DEBUGGER
{
	TES3SCRIPTEXTENDER(void);
	virtual ~TES3SCRIPTEXTENDER(void);
	
	virtual int main(int argc, char* argv[]);

	virtual int getVersion(char* filename);

	virtual void DoCreateProc(DEBUG_EVENT& DebugEv);
	virtual void DoExitProc(DEBUG_EVENT& DebugEv);
	virtual void DoDebugString(DEBUG_EVENT& DebugEv);
	virtual void DoSingleStep(DEBUG_EVENT& DebugEv);
	virtual void DoInitialBreakpoint(DEBUG_EVENT& DebugEv);
	virtual void DoBreakpoint(DEBUG_EVENT& DebugEv);
	virtual void DoAccessViolation(DEBUG_EVENT& DebugEv);

protected:
	virtual TES3MACHINE* CreateScriptMachine(void);
	
	virtual void OnRunScript(CONTEXT& context);
	virtual void OnFixupScript(CONTEXT& context);
	virtual void OnDecode(CONTEXT& context);
	virtual void OnRunFuncIdxError(CONTEXT& context);
	virtual void OnHWBreakpoint(CONTEXT& context);
	
	virtual bool ChangeReference(VPVOID pscript);

	virtual int log(char* fmt, ...);
	virtual void logbinary(const VOID* mem, int size);

	virtual void dumpmemlist(void);
	virtual void dumpcontext(HANDLE hThread, CONTEXT& context);
	virtual void dumpcontext(HANDLE hThread);
	virtual void dumpstack(LPVOID mem);
	virtual void sprintseg(char* str, HANDLE hThread, DWORD seg);

private:
	VPVOID prevscript;
	TES3MACHINE* scriptmachine;
	HWBREAKPOINT* HWbreakpoint;
	static const char RunFunctionErrorMsg[];
	static const char WelcomeMessage[];
};
