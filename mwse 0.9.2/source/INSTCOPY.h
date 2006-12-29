#ifndef _INSTCOPY_H_SFGNFRTGBAETBGHMUSTHAEDRHSFGYNRYU
#define _INSTCOPY_H_SFGNFRTGBAETBGHMUSTHAEDRHSFGYNRYU

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

struct INSTCOPYREG : public INSTRUCTION
{
	INSTCOPYREG(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMBYTE registers;
};

struct INSTCOPYFROMSTACK : public INSTRUCTION
{
	INSTCOPYFROMSTACK(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMBYTE stackpos;
};

struct INSTCOPYTOSTACK : public INSTRUCTION
{
	INSTCOPYTOSTACK(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
	VMBYTE stackpos;
};

#endif

