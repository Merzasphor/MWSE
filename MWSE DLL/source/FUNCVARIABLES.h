//FuncVariables.h
#pragma once

#include "TES3MACHINE.h"
#include "FUNCTION.h"

class FUNCGETGLOBAL : public FUNCTION
{
public:
	FUNCGETGLOBAL(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCSETGLOBAL : public FUNCTION
{
public:
	FUNCSETGLOBAL(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCFLOATSTOLONG : public FUNCTION
{
public:
	FUNCFLOATSTOLONG(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCLONGTOFLOATS : public FUNCTION
{
public:
	FUNCLONGTOFLOATS(TES3MACHINE& vm) : machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCGETLOCAL : public FUNCTION
{
	FUNCGETLOCAL(TES3MACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
	OPCODE opcode;
};

struct FUNCSETLOCAL : public FUNCTION
{
	FUNCSETLOCAL(TES3MACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
	OPCODE opcode;
};
