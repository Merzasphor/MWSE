#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

class cInstCallShort : public INSTRUCTION
{
public:
	cInstCallShort(VIRTUALMACHINE& vm) : machine(vm) { };
	virtual bool execute(void);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
private:
	VIRTUALMACHINE& machine;
	VPVOID function;
};