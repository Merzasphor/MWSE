//InstCall.h
#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

struct INSTCALL : public INSTRUCTION
{
	INSTCALL(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VPVOID function;
};

struct INSTCALLSHORT : public INSTRUCTION
{
	INSTCALLSHORT(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VPVOID function;
};

struct INSTRETURN : public INSTRUCTION
{
	INSTRETURN(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
};

struct INSTRETURNP : public INSTRUCTION
{
	INSTRETURNP(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMBYTE paramsize;
};

struct INSTRETURNVP : public INSTRUCTION
{
	INSTRETURNVP(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMBYTE paramsize;
};

