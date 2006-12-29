#ifndef _FUNCITEM_H_NDFGBADFBYNYUMMDFGYBADFBTN
#define _FUNCITEM_H_NDFGBADFBYNYUMMDFGYBADFBTN

#include "TES3MACHINE.h"
#include "FUNCEXTENDER.h"
#include "STRINGS.h"

//Fliggerty 12-27-06

struct FUNCADDSPELL : public FUNCEXTENDER, public HWBREAKPOINT
{
	FUNCADDSPELL(TES3MACHINE& vm);
	virtual bool execute(void);
	virtual bool breakpoint();
	virtual LPVOID getaddress();
private:
	TES3MACHINE& machine;
	CONTEXT parent;
};

//Tp21 22-08-2006
struct FUNCDROPITEM : public FUNCEXTENDER, public HWBREAKPOINT
{
	FUNCDROPITEM(TES3MACHINE& vm);
	virtual bool execute(void);
	virtual bool breakpoint();
	virtual LPVOID getaddress();
private:
	TES3MACHINE& machine;
	CONTEXT parent;
};

//Tp21 22-08-2006
struct FUNCEQUIPITEM : public FUNCEXTENDER, public HWBREAKPOINT
{
	FUNCEQUIPITEM(TES3MACHINE& vm);
	virtual bool execute(void);
	virtual bool breakpoint();
	virtual LPVOID getaddress();
private:
	TES3MACHINE& machine;
	CONTEXT parent;
};

//Tp21 27-12-2006
struct FUNCCAST : public FUNCEXTENDER, public HWBREAKPOINT
{
	FUNCCAST(TES3MACHINE& vm);
	virtual bool execute(void);
	virtual bool breakpoint();
	virtual LPVOID getaddress();
private:
	TES3MACHINE& machine;
	CONTEXT parent;
};

struct FUNCADDITEM : public FUNCEXTENDER, public HWBREAKPOINT
{
	FUNCADDITEM(TES3MACHINE& vm);
	virtual bool execute(void);
	virtual bool breakpoint();
	virtual LPVOID getaddress();
private:
	TES3MACHINE& machine;
	CONTEXT parent;
};

struct FUNCREMOVEITEM : public FUNCEXTENDER, public HWBREAKPOINT
{
	FUNCREMOVEITEM(TES3MACHINE& vm);
	virtual bool execute(void);
	virtual bool breakpoint();
	virtual LPVOID getaddress();
private:
	TES3MACHINE& machine;
	CONTEXT parent;
};

struct FUNCINVENTORY : public FUNCTION
{
	FUNCINVENTORY(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCNEXTSTACK : public FUNCTION
{
	FUNCNEXTSTACK(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCHASEQUIPEDPART2 : public HWBREAKPOINT
{
	FUNCHASEQUIPEDPART2(TES3MACHINE& vm);
	virtual bool breakpoint();
	virtual LPVOID getaddress();
private:
	TES3MACHINE& machine;
	CONTEXT parent;
};

struct FUNCHASEQUIPED : public FUNCEXTENDER, public HWBREAKPOINT
{
	FUNCHASEQUIPED(TES3MACHINE& vm);
	virtual bool execute(void);
	virtual bool breakpoint();
	virtual LPVOID getaddress();
private:
	TES3MACHINE& machine;
	CONTEXT parent;
	FUNCHASEQUIPEDPART2 part2;
};

// 2005-07-02  CDC
struct FUNCCONTENTLIST : public FUNCTION
{
	FUNCCONTENTLIST(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
	const char *randomselect(VPVOID temp);
};

#endif
