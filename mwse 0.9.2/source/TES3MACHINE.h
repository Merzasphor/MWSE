#ifndef _TES3MACHINE_H_JHTIRNHEGNSFGBAW
#define _TES3MACHINE_H_JHTIRNHEGNSFGBAW

#include "VIRTUALMACHINE.h"
#include "TES3TYPES.h"
#include "ADDRESSSPACE.h"
#include "STRINGS.h"
#include "BREAKPOINT.h"

// 22-08-2006 Tp21
#include "warnings.h"

typedef enum {INTSWITCHREFERENCE= 1} INTERRUPTS;


struct TES3MACHINE : public VIRTUALMACHINE
{
	TES3MACHINE(HANDLE process, LPVOID base);
	
	virtual void searchforscripttarget(void);
	virtual void dumpscript(void);
	virtual void dumpscriptstack(void);
	virtual void dumpobjects(void);
	virtual void dumpobject(VPREFERENCE ref);
	virtual void dumptemplate(VPTEMPLATE ptempl);
	virtual bool dumpmem(VPVOID ptr, int size);

	virtual bool Interrupt(VMINTERRUPT num);
	virtual bool GetRegister(WORD regidx, VMREGTYPE& value);
	virtual bool SetRegister(WORD regidx, VMREGTYPE value);
	virtual const char* GetScriptName(void);
	virtual const char* TES3MACHINE::GetString(VPVOID addr);

	// 2005-02-15  CDC  needed for messagefix instruction
	virtual VPSCRIPT GetScript(void) { return scriptaddr; }
	virtual bool SetScript(VPSCRIPT pscript);
	virtual const CONTEXT& GetFlow(void);
	virtual void SetFlow(const CONTEXT& newflow);
	virtual bool SetVMDebuggerBreakpoint(HWBREAKPOINT* breakpoint);
	virtual HWBREAKPOINT* GetVMDebuggerBreakpoint();

	LPVOID reltolinear(ULONG reladdr){return (LPVOID)((ULONG)procbase + (ULONG)reladdr);};
	LPVOID reltolinear(VPVOID reladdr){return (LPVOID)((ULONG)procbase + (ULONG)reladdr);};
	LPVOID reltolinear(LPVOID reladdr){return (LPVOID)((ULONG)procbase + (ULONG)reladdr);};
private:
	ADDRESSSPACE* executable;
	HANDLE hProcess;
	LPVOID procbase;
	VPSCRIPT scriptaddr;
	TES3SCRIPT script;
	CONTEXT flow;
	HWBREAKPOINT* breakpoint;
	VMREGTYPE instructionpointer;
	VMREGTYPE stackpointer;
	VMREGTYPE generalregs[GPMAX+1];
};

#endif
