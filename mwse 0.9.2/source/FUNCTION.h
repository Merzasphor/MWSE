#ifndef _FUNCTION_H_DFHJNWRAVSDFGSFNM
#define _FUNCTION_H_DFHJNWRAVSDFGSFNM

#include "INSTRUCTION.h"

struct FUNCTION : public INSTRUCTION
{
	virtual ~FUNCTION(void){};
	virtual bool execute(void)=0;
};

#endif
