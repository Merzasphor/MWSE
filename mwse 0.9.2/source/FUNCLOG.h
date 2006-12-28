#ifndef _FUNCLOG_H_SFGBRwevtynetywrtHDFTYNETYNA
#define _FUNCLOG_H_SFGBRwevtynetywrtHDFTYNETYNA

#include "TES3MACHINE.h"
#include "FUNCTION.h"

struct FUNCLOG : public FUNCTION
{
	FUNCLOG(TES3MACHINE& vm);
	virtual bool execute(void);
	private:
	TES3MACHINE& machine;
};

#endif
