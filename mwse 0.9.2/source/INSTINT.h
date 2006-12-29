#ifndef _INSTINT_H_SFGHFYNADFVGNETYADFBWTYETAQGRB
#define _INSTINT_H_SFGHFYNADFVGNETYADFBWTYETAQGRB

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

struct INSTADD : public INSTRUCTION
{
	INSTADD(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTSUB : public INSTRUCTION
{
	INSTSUB(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTMUL : public INSTRUCTION
{
	INSTMUL(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTDIV : public INSTRUCTION
{
	INSTDIV(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTMOD : public INSTRUCTION
{
	INSTMOD(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

#endif
