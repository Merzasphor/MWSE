#ifndef _INSTPOP_H_FGNJUMRYYAWRsdvgnyhswg
#define _INSTPOP_H_FGNJUMRYYAWRsdvgnyhswg

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

struct INSTPOP : public INSTRUCTION
{
	INSTPOP(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
	private:
	VIRTUALMACHINE& machine;
	VMSHORT stackincrease;
};

struct INSTPOPREG : public INSTRUCTION
{
	INSTPOPREG(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
	private:
	VIRTUALMACHINE& machine;
	VMBYTE regidx;
};

#endif
