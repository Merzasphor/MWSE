//InstPush.h
#pragma once

#include "TES3MACHINE.h"
#include "INSTRUCTION.h"

struct INSTPUSH : public INSTRUCTION
{
	INSTPUSH(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMREGTYPE value;
};

struct INSTPUSHB : public INSTRUCTION
{
	INSTPUSHB(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMBYTE value;
};

struct INSTPUSHS : public INSTRUCTION
{
	INSTPUSHS(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMSHORT value;
};

struct INSTPUSHREG : public INSTRUCTION
{
	INSTPUSHREG(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMBYTE regidx;
};

struct INSTDECLARELOCAL : public INSTRUCTION
{
	INSTDECLARELOCAL(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMBYTE localsize;
};
