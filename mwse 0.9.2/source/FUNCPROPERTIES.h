// 2005-02-14  CDC
#ifndef _FUNCPROPERTIES_H_SDFBGNWARVBFNTYUSRTBADFRBDYSTEAQGB
#define _FUNCPROPERTIES_H_SDFBGNWARVBFNTYUSRTBADFRBDYSTEAQGB

#include "TES3MACHINE.h"
#include "FUNCEXTENDER.h"
#include "STRINGS.h"

//Tp21 22-08-2006
struct FUNCSETNAME : public FUNCTION
{
	FUNCSETNAME(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
	STRINGS strings;
};

//Tp21 22-08-2006
struct FUNCGETSPELLEFFECTS : public FUNCEXTENDER, public HWBREAKPOINT
{
	FUNCGETSPELLEFFECTS(TES3MACHINE& vm);
	virtual bool execute(void);
	virtual bool breakpoint();
	virtual LPVOID getaddress();
	private:
	TES3MACHINE& machine;
	CONTEXT parent;
};

struct FUNCGETVALUE : public FUNCTION
{
	FUNCGETVALUE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETOWNER : public FUNCTION
{
	FUNCGETOWNER(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETWEIGHT : public FUNCTION
{
	FUNCGETWEIGHT(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETENCUMB : public FUNCTION
{
	FUNCGETENCUMB(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETCONDITION : public FUNCTION
{
	FUNCGETCONDITION(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETMAXCOND : public FUNCTION
{
	FUNCGETMAXCOND(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETCHARGE : public FUNCTION
{
	FUNCGETCHARGE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETMAXCHARGE : public FUNCTION
{
	FUNCGETMAXCHARGE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETQUALITY : public FUNCTION
{
	FUNCGETQUALITY(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETNAME : public FUNCTION
{
	FUNCGETNAME(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETBASEID : public FUNCTION
{
	FUNCGETBASEID(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETBASESTR : public FUNCTION
{
	FUNCGETBASESTR(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETBASEINT : public FUNCTION
{
	FUNCGETBASEINT(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETBASEWIL : public FUNCTION
{
	FUNCGETBASEWIL(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETBASEAGI : public FUNCTION
{
	FUNCGETBASEAGI(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETBASESPE : public FUNCTION
{
	FUNCGETBASESPE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETBASEEND : public FUNCTION
{
	FUNCGETBASEEND(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETBASEPER : public FUNCTION
{
	FUNCGETBASEPER(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETBASELUC : public FUNCTION
{
	FUNCGETBASELUC(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCISFEMALE : public FUNCTION
{
	FUNCISFEMALE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCMYCELLID : public FUNCTION
{
	FUNCMYCELLID(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETBASEGOLD : public FUNCTION
{
	FUNCGETBASEGOLD(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCGETGOLD : public FUNCTION
{
	FUNCGETGOLD(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCSETBASEGOLD : public FUNCTION
{
	FUNCSETBASEGOLD(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCSETGOLD : public FUNCTION
{
	FUNCSETGOLD(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCISTRADER : public FUNCTION
{
	FUNCISTRADER(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCISTRAINER : public FUNCTION
{
	FUNCISTRAINER(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCISPROVIDER : public FUNCTION
{
	FUNCISPROVIDER(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

// 2005-07-12  CDC  More powerful alternatives to the IsTrader/Trainer/Provider functions
struct FUNCGETSERVICE : public FUNCTION
{
	FUNCGETSERVICE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCSETSERVICE : public FUNCTION
{
	FUNCSETSERVICE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

struct FUNCMODSERVICE : public FUNCTION
{
	FUNCMODSERVICE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

#endif
