//FuncProperties.h
#pragma once

#include "TES3MACHINE.h"
#include "FUNCEXTENDER.h"
#include "TES3OFFSETS.h"
#include "STRINGS.h"

class FUNCDELETESPELL : public FUNCTION
{
public:
	FUNCDELETESPELL(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCCREATESPELL : public FUNCTION
{
public:
	FUNCCREATESPELL(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCSETBASEEFFECTINFO : public FUNCTION
{
public:
	FUNCSETBASEEFFECTINFO(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEEFFECTINFO : public FUNCTION
{
public:
	FUNCGETBASEEFFECTINFO(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETMAGIC : public FUNCTION
{
public:
	FUNCGETMAGIC(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETPROGRESSSKILL : public FUNCTION
{
public:
	FUNCGETPROGRESSSKILL(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCSETPROGRESSSKILL : public FUNCTION
{
public:
	FUNCSETPROGRESSSKILL(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCMODPROGRESSSKILL : public FUNCTION
{
public:
	FUNCMODPROGRESSSKILL(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASESKILL : public FUNCTION
{
public:
	FUNCGETBASESKILL(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};


class FUNCGETBASEACROBATICS : public FUNCTION
{
public:
	FUNCGETBASEACROBATICS(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEALCHEMY : public FUNCTION
{
public:
	FUNCGETBASEALCHEMY(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEALTERATION : public FUNCTION
{
public:
	FUNCGETBASEALTERATION(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEARMORER : public FUNCTION
{
public:
	FUNCGETBASEARMORER(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEATHLETICS : public FUNCTION
{
public:
	FUNCGETBASEATHLETICS(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEAXE : public FUNCTION
{
public:
	FUNCGETBASEAXE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEBLOCK : public FUNCTION
{
public:
	FUNCGETBASEBLOCK(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEBLUNTWEAPON : public FUNCTION
{
public:
	FUNCGETBASEBLUNTWEAPON(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASECONJURATION : public FUNCTION
{
public:
	FUNCGETBASECONJURATION(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEDESTRUCTION : public FUNCTION
{
public:
	FUNCGETBASEDESTRUCTION(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEENCHANT : public FUNCTION
{
public:
	FUNCGETBASEENCHANT(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEHANDTOHAND : public FUNCTION
{
public:
	FUNCGETBASEHANDTOHAND(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEHEAVYARMOR : public FUNCTION
{
public:
	FUNCGETBASEHEAVYARMOR(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEILLUSION : public FUNCTION
{
public:
	FUNCGETBASEILLUSION(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASELIGHTARMOR : public FUNCTION
{
public:
	FUNCGETBASELIGHTARMOR(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASELONGBLADE : public FUNCTION
{
public:
	FUNCGETBASELONGBLADE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEMARKSMAN : public FUNCTION
{
public:
	FUNCGETBASEMARKSMAN(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEMEDIUMARMOR : public FUNCTION
{
public:
	FUNCGETBASEMEDIUMARMOR(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEMERCANTILE : public FUNCTION
{
public:
	FUNCGETBASEMERCANTILE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEMYSTICISM : public FUNCTION
{
public:
	FUNCGETBASEMYSTICISM(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASERESTORATION : public FUNCTION
{
public:
	FUNCGETBASERESTORATION(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASESECURITY : public FUNCTION
{
public:
	FUNCGETBASESECURITY(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASESHORTBLADE : public FUNCTION
{
public:
	FUNCGETBASESHORTBLADE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASESNEAK : public FUNCTION
{
public:
	FUNCGETBASESNEAK(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASESPEAR : public FUNCTION
{
public:
	FUNCGETBASESPEAR(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASESPEECHCRAFT : public FUNCTION
{
public:
	FUNCGETBASESPEECHCRAFT(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETBASEUNARMORED : public FUNCTION
{
public:
	FUNCGETBASEUNARMORED(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETPROGRESSLEVEL : public FUNCTION
{
public:
	FUNCGETPROGRESSLEVEL(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCSETPROGRESSLEVEL : public FUNCTION
{
public:
	FUNCSETPROGRESSLEVEL(TES3MACHINE& vm): machine(vm) { };
   virtual bool execute(void);
private:
   TES3MACHINE& machine;
};

class FUNCMODPROGRESSLEVEL : public FUNCTION
{
public:
	FUNCMODPROGRESSLEVEL(TES3MACHINE& vm): machine(vm) { };
   virtual bool execute(void);
private:
   TES3MACHINE& machine;
};

class FUNCGETLOCKLEVEL : public FUNCTION
{
public:
	FUNCGETLOCKLEVEL(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETTRAP : public FUNCTION
{
public:
	FUNCGETTRAP(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCSETTRAP : public FUNCTION
{
public:
	FUNCSETTRAP(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCSPELLLIST : public FUNCTION
{
public:
	FUNCSPELLLIST(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETSPELL : public FUNCTION
{
public:
	FUNCGETSPELL(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCSETSPELLINFO : public FUNCTION
{
public:
	FUNCSETSPELLINFO(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETSPELLINFO : public FUNCTION
{
public:
	FUNCGETSPELLINFO(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCDELETEEFFECT : public FUNCTION
{
public:
	FUNCDELETEEFFECT(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCSETEFFECTINFO : public FUNCTION
{
public:
	FUNCSETEFFECTINFO(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCADDEFFECT : public FUNCTION
{
public:
	FUNCADDEFFECT(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETSPELLEFFECTINFO : public FUNCTION
{
public:
	FUNCGETSPELLEFFECTINFO(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETEFFECTINFO : public FUNCTION
{
public:
	FUNCGETEFFECTINFO(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETENCHANT : public FUNCTION
{
public:
	FUNCGETENCHANT(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCSETENCHANTINFO : public FUNCTION
{
public:
	FUNCSETENCHANTINFO(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETENCHANTINFO : public FUNCTION
{
public:
	FUNCGETENCHANTINFO(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETENCHANTEFFECTINFO : public FUNCTION
{
public:
	FUNCGETENCHANTEFFECTINFO(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETCLASS : public FUNCTION
{
public:
	FUNCGETCLASS(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

//GRM  15-01-2007 [use proper C++ class]
class FUNCSETVALUE : public FUNCTION
{
public:
	FUNCSETVALUE(TES3MACHINE& vm): machine(vm) { };
   virtual bool execute(void);
private:
   TES3MACHINE& machine;
};

// charge is unique
class FUNCSETCHARGE : public FUNCTION
{
public:
   FUNCSETCHARGE(TES3MACHINE& vm): machine(vm) { };
   virtual bool execute(void);
private:
   TES3MACHINE& machine;
};

class FUNCSETMAXCHARGE : public FUNCTION
{
public:
   FUNCSETMAXCHARGE(TES3MACHINE& vm): machine(vm) { };
   virtual bool execute(void);
private:
   TES3MACHINE& machine;
};

class FUNCSETCONDITION : public FUNCTION
{
public:
   FUNCSETCONDITION(TES3MACHINE& vm): machine(vm) { };
   virtual bool execute(void);
private:
   TES3MACHINE& machine;
};

class FUNCSETMAXCONDITION : public FUNCTION
{
public:
   FUNCSETMAXCONDITION(TES3MACHINE& vm): machine(vm) { };
   virtual bool execute(void);
private:
   TES3MACHINE& machine;
};
// Most of the <set> functions have a virtually identical structure.
// To exploit this, a base class is used.
class CommonSet : public FUNCTION
{
public:
   virtual bool execute(void);
protected:
   CommonSet(TES3MACHINE &ctor_machine, const char *ctor_name): name(ctor_name), machine(ctor_machine) {};
   const char *name;
   TES3MACHINE &machine;
   // Derived classes will define this function.
   virtual ULONG getTypeOffset(ULONG type) = 0;
   virtual bool canSet(ULONG type) = 0;
};

class FUNCSETWEIGHT : public CommonSet
{
public:
   FUNCSETWEIGHT(TES3MACHINE& vm): CommonSet(vm, "FUNCSETWEIGHT") { };
protected:
   virtual ULONG getTypeOffset(ULONG type) { return offsetOfWeight(type); }
   virtual bool canSet(ULONG type)
   {
       return (type == MISC ||
               type == CLOTHING ||
               type == WEAPON ||
               type == ARMOR ||
               type == BOOK ||
               type == ALCHEMY ||
               type == APPARATUS ||
               type == INGREDIENT ||
               type == PROBE ||
               type == LOCKPICK ||
               type == REPAIR);
   }
};

class FUNCSETQUALITY : public CommonSet
{
public:
   FUNCSETQUALITY(TES3MACHINE& vm): CommonSet(vm, "FUNCSETQUALITY") { };
protected:
   virtual ULONG getTypeOffset(ULONG type) { return offsetOfQuality(type); }
   virtual bool canSet(ULONG type)
   {
       return (type == PROBE ||
               type == LOCKPICK ||
               type == REPAIR);
   }
};



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
	virtual BYTE getid();
private:
	TES3MACHINE& machine;
	Context parent;
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

struct FUNCGETOWNERINFO : public FUNCTION
{
	FUNCGETOWNERINFO(TES3MACHINE& vm) :machine(vm) {}
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
