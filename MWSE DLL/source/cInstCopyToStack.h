#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

class cInstCopyToStack : public INSTRUCTION
{
public:
	cInstCopyToStack(VIRTUALMACHINE& vm) : machine(vm) { };
	virtual bool execute(void);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
private:
	VIRTUALMACHINE& machine;
	VMBYTE stackpos;
};