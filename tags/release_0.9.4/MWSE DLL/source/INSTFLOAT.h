//InstFloat.h
#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

struct INSTITOF : public INSTRUCTION
{
	INSTITOF(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
};

struct INSTFTOI : public INSTRUCTION
{
	INSTFTOI(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
};

struct INSTFADD : public INSTRUCTION
{
	INSTFADD(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
};

struct INSTFSUB : public INSTRUCTION
{
	INSTFSUB(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
};

struct INSTFMUL : public INSTRUCTION
{
	INSTFMUL(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
};

struct INSTFDIV : public INSTRUCTION
{
	INSTFDIV(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:
	VIRTUALMACHINE& machine;
};

struct INSTTAN : public INSTRUCTION
{
	INSTTAN(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTSIN : public INSTRUCTION
{
	INSTSIN(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTCOS : public INSTRUCTION
{
	INSTCOS(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTARCTAN : public INSTRUCTION
{
	INSTARCTAN(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTARCSIN : public INSTRUCTION
{
	INSTARCSIN(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTARCCOS : public INSTRUCTION
{
	INSTARCCOS(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTDEGRAD : public INSTRUCTION
{
	INSTDEGRAD(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTRADDEG : public INSTRUCTION
{
	INSTRADDEG(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTSQRT : public INSTRUCTION
{
	INSTSQRT(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

struct INSTHYPOT : public INSTRUCTION
{
	INSTHYPOT(VIRTUALMACHINE& vm);
	virtual bool execute(void);
private:	
	VIRTUALMACHINE& machine;
};

