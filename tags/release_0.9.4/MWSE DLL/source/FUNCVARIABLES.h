//FuncVariables.h
#pragma once

#include "TES3MACHINE.h"
#include "FUNCTION.h"

struct FUNCGETLOCAL : public FUNCTION
{
	FUNCGETLOCAL(TES3MACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
	OPCODE opcode;
};

struct FUNCSETLOCAL : public FUNCTION
{
	FUNCSETLOCAL(TES3MACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
	OPCODE opcode;
};
