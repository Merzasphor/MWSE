#pragma once

#include "MgeVmtypes.h"

struct INSTRUCTION {
	virtual ~INSTRUCTION() {};
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata) {
		return 0;
	}
	virtual bool execute() = 0;
};
