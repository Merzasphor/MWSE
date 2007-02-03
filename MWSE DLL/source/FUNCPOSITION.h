//FuncPosition.h
#pragma once

#include "TES3MACHINE.h"
#include "FUNCEXTENDER.h"
#include "STRINGS.h"

struct FUNCPOSITION : public FUNCEXTENDER
{
	FUNCPOSITION(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCPOSITIONCELL : public FUNCEXTENDER
{
	FUNCPOSITIONCELL(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCDISTANCE : public FUNCEXTENDER
{
	FUNCDISTANCE(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCPCCELLID : public FUNCTION
{
	FUNCPCCELLID(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCPLACEATPART2 : public HWBREAKPOINT
{
	FUNCPLACEATPART2(TES3MACHINE& vm);
	virtual bool breakpoint();
	virtual BYTE getid();
private:
	TES3MACHINE& machine;
	CONTEXT parent;
};

struct FUNCPLACEAT : public FUNCEXTENDER, public HWBREAKPOINT
{
	FUNCPLACEAT(TES3MACHINE& vm);
	virtual bool execute(void);
	virtual bool breakpoint();
	virtual BYTE getid();
private:
	TES3MACHINE& machine;
	Context parent;
	FUNCPLACEATPART2 part2;
};
