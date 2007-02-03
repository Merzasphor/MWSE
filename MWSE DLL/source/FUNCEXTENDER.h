//FuncExtender.h
#pragma once

#include "TES3MACHINE.h"
#include "FUNCTION.h"

struct FUNCEXTENDER : public FUNCTION
{
	virtual bool CallOriginalFunction(TES3MACHINE& machine, OPCODE originalopcode);
};

