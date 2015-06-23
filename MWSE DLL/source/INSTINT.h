//InstInt.h
#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

struct INSTADD : public INSTRUCTION
{
	INSTADD(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTSUB : public INSTRUCTION
{
	INSTSUB(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTMUL : public INSTRUCTION
{
	INSTMUL(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTDIV : public INSTRUCTION
{
	INSTDIV(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTMOD : public INSTRUCTION
{
	INSTMOD(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

class INSTSHIFT : public INSTRUCTION
{
public:
	INSTSHIFT(VIRTUALMACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

class INSTBITAND : public INSTRUCTION
{
public:
	INSTBITAND(VIRTUALMACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

class INSTBITOR : public INSTRUCTION
{
public:
	INSTBITOR(VIRTUALMACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

class INSTBITXOR : public INSTRUCTION
{
public:
	INSTBITXOR(VIRTUALMACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

class INSTBITNOT : public INSTRUCTION
{
public:
	INSTBITNOT(VIRTUALMACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

class INSTAND : public INSTRUCTION
{
public:
	INSTAND(VIRTUALMACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

class INSTOR : public INSTRUCTION
{
public:
	INSTOR(VIRTUALMACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

class INSTXOR : public INSTRUCTION
{
public:
	INSTXOR(VIRTUALMACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

class INSTNOT : public INSTRUCTION
{
public:
	INSTNOT(VIRTUALMACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};
