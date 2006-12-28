#ifndef _INSTRUCTION_H_SFGWTBQERYUMJERYTUNWSB
#define _INSTRUCTION_H_SFGWTBQERYUMJERYTUNWSB

#include "VMTYPES.h"

struct INSTRUCTION
{
	virtual ~INSTRUCTION(void){};
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata)
	{
		return 0;
	}
	virtual bool execute(void)=0;
};

#endif
