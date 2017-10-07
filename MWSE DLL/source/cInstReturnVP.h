#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

class cInstReturnVP : public INSTRUCTION
{
public:
	cInstReturnVP(VIRTUALMACHINE& vm) : machine(vm) { };
	virtual bool execute(void);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
private:
	VIRTUALMACHINE& machine;
	VMBYTE paramsize;
};