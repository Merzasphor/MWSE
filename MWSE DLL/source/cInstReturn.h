#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

class cInstReturn : public INSTRUCTION
{
public:
	cInstReturn(VIRTUALMACHINE& vm) : machine(vm) { };
	virtual bool execute(void);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
private:
	VIRTUALMACHINE& machine;
	VPVOID function;
};