#ifndef MWSE_SETLEVELFUNCTION_H_
#define MWSE_SETLEVELFUNCTION_H_

#include "Breakpoint.h"
#include "FUNCEXTENDER.h"
#include "TES3MACHINE.h"

class SetLevelFunction : public FUNCEXTENDER, public HWBREAKPOINT
{
public:
	SetLevelFunction(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute();
	virtual bool breakpoint();
	virtual BYTE getid();
private:
	TES3MACHINE& machine;
	Context parent;
};

#endif // MWSE_SETLEVELFUNCTION_H_
