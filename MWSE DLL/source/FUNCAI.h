//FuncAi.h
#pragma once

#include "FUNCEXTENDER.h"

struct FUNCAITRAVEL : public FUNCEXTENDER
{
	FUNCAITRAVEL(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCSTARTCOMBAT : public FUNCEXTENDER
{
	FUNCSTARTCOMBAT(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCGETCOMBAT : public FUNCTION
{
	FUNCGETCOMBAT(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

