//InstNop.h
#pragma once

#include "INSTRUCTION.h"
#include "DEBUGGING.h"

struct INSTNOP : public INSTRUCTION
{
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata)
	{
		return 1;
	}
	virtual bool execute(void)
	{
	#ifdef DEBUGGING
		LOG::log("NOP() succeeded\n");
	#endif
		return true;
	}
};
