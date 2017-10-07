//Tes3Machine.h
#pragma once

#include "VIRTUALMACHINE.h"
#include "TES3TYPES.h"
#include "ADDRESSSPACE.h"
#include "STRINGS.h"
#include "BREAKPOINT.h"

// 22-08-2006 Tp21
#include "warnings.h"

#include <boost/random/mersenne_twister.hpp>

typedef enum {INTSWITCHREFERENCE= 1} INTERRUPTS;


struct TES3MACHINE : public VIRTUALMACHINE
{
	TES3MACHINE();
	
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
	virtual bool SetVMDebuggerBreakpoint(HWBREAKPOINT* breakpoint);
	virtual HWBREAKPOINT* GetVMDebuggerBreakpoint();

	// 2005-02-15  CDC  needed for messagefix instruction
	virtual VPSCRIPT GetScript(void) { return scriptaddr; }
	virtual bool SetScript(VPSCRIPT pscript);
	virtual const Context GetFlow(void);
	virtual void SetFlow(const Context newflow);

	void set_external_malloc(void* external_malloc) {
		external_malloc_ = reinterpret_cast<ExternalMalloc>(external_malloc); }
	void* Malloc(size_t size) { return external_malloc_(size); }
	void set_external_free(void* external_free) {
		external_free_ = reinterpret_cast<ExternalFree>(external_free); }
	void Free(void* to_free) { external_free_(to_free); }
	void set_external_realloc(void* external_realloc) {
		external_realloc_ =
			reinterpret_cast<ExternalRealloc>(external_realloc); }
	void* Realloc(void* to_realloc, size_t size) {
		return external_realloc_(to_realloc, size); }
	void CheckForSkillUp(long skill_id);
	MACPRecord* GetMacpRecord();
	long GetRandomLong(long min, long max);
	float GetRandomFloat(float min, float max);

private:
	typedef void* (__cdecl *ExternalMalloc)(size_t);
	typedef void (__cdecl *ExternalFree)(void*);
	typedef void* (__cdecl *ExternalRealloc)(void*, size_t);
	ADDRESSSPACE* executable;
	VPSCRIPT scriptaddr;
	TES3SCRIPT script;
	Context flow;
	HWBREAKPOINT* breakpoint;
	VMREGTYPE instructionpointer;
	VMREGTYPE stackpointer;
	VMREGTYPE generalregs[GPMAX+1];
	ExternalMalloc external_malloc_;
	ExternalFree external_free_;
	ExternalRealloc external_realloc_;
	boost::random::mt19937 rng_;
};
