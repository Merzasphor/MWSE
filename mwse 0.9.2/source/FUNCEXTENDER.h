#ifndef _FUNCEXTENDER_H_HSFYATAERHYJJUDGYNDFGASFH
#define _FUNCEXTENDER_H_HSFYATAERHYJJUDGYNDFGASFH

#include "TES3MACHINE.h"
#include "FUNCTION.h"

struct FUNCEXTENDER : public FUNCTION
{
	virtual bool CallOriginalFunction(TES3MACHINE& machine, OPCODE originalopcode);
};

#endif

