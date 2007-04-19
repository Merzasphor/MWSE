//FuncReference.h
#pragma once

#include "TES3MACHINE.h"
#include "FUNCEXTENDER.h"
#include "STRINGS.h"

struct FUNCREF : public FUNCTION
{
	FUNCREF(TES3MACHINE& vm);
	virtual bool execute(void);
	virtual bool setref(VPREFERENCE ref);
	TES3MACHINE& getMachine(void)
	{
		return machine;
	}

private:
	TES3MACHINE& machine;
};

struct FUNCREFTYPE : public FUNCTION
{
	FUNCREFTYPE(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCREFID : public FUNCTION
{
	FUNCREFID(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCFIRSTNPC : public FUNCREF
{
	FUNCFIRSTNPC(TES3MACHINE& vm);
	virtual bool execute(void);
};

struct FUNCFIRSTITEM : public FUNCREF
{
	FUNCFIRSTITEM(TES3MACHINE& vm);
	virtual bool execute(void);
};

struct FUNCFIRSTSTATIC : public FUNCREF
{
	FUNCFIRSTSTATIC(TES3MACHINE& vm);
	virtual bool execute(void);
};

struct FUNCNEXTREF : public FUNCREF
{
	FUNCNEXTREF(TES3MACHINE& vm);
	virtual bool execute(void);
};

struct FUNCGETPCTARGET : public FUNCREF
{
	FUNCGETPCTARGET(TES3MACHINE& vm);
	virtual bool execute(void);
};

struct FUNCREFPCTARGET : public FUNCREF
{
	FUNCREFPCTARGET(TES3MACHINE& vm);
	virtual bool execute(void);
};

struct FUNCGETREF : public FUNCEXTENDER, public HWBREAKPOINT
{
	FUNCGETREF(TES3MACHINE& vm);
	virtual bool execute(void);
	virtual bool breakpoint();
	virtual BYTE getid();
private:
	TES3MACHINE& machine;
	Context parent;
	bool isplayer;
};
