//FuncLog.h
#pragma once

#include "TES3MACHINE.h"
#include "FUNCTION.h"

struct FUNCLOG : public FUNCTION
{
	FUNCLOG(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};
