//Function.h
#pragma once

#include "INSTRUCTION.h"

struct FUNCTION : public INSTRUCTION
{
	virtual ~FUNCTION(void){};
	virtual bool execute(void)=0;
};
