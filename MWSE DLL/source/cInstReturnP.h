#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

class cInstReturnP : public INSTRUCTION
{
public:
	cInstReturnP(VIRTUALMACHINE& vm) : machine(vm) { };
	virtual bool execute(void);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
private:
	VIRTUALMACHINE& machine;
	VMBYTE paramsize;
};