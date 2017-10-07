#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

class cInstCall : public INSTRUCTION
{
public:
	cInstCall(VIRTUALMACHINE& vm) : machine(vm) { };
	virtual bool execute(void);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
private:
	VIRTUALMACHINE& machine;
	VPVOID function;
};