//InstPop.h
#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

struct INSTPOP : public INSTRUCTION
{
	INSTPOP(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMSHORT stackincrease;
};

struct INSTPOPREG : public INSTRUCTION
{
	INSTPOPREG(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMBYTE regidx;
};
