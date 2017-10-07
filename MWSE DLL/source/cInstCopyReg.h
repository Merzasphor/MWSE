#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

class cInstCopyReg : public INSTRUCTION
{
public:
	cInstCopyReg(VIRTUALMACHINE& vm) : machine(vm) { };
	virtual bool execute(void);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
private:
	VIRTUALMACHINE& machine;
	VMBYTE registers;
};