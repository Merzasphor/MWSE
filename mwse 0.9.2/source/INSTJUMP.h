//InstJump.h
#pragma once

#include "VIRTUALMACHINE.h"
#include "INSTRUCTION.h"

struct INSTJUMP : public INSTRUCTION
{
	INSTJUMP(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
protected:
	virtual VIRTUALMACHINE& GetMachine(void);
protected:
	VIRTUALMACHINE& machine;
	VPVOID position;
};

struct INSTJUMPZERO : public INSTJUMP
{
	INSTJUMPZERO(VIRTUALMACHINE& vm);
	virtual bool execute(void);
};

struct INSTJUMPNOTZERO : public INSTJUMP
{
	INSTJUMPNOTZERO(VIRTUALMACHINE& vm);
	virtual bool execute(void);
};

struct INSTJUMPPOSITIVE : public INSTJUMP
{
	INSTJUMPPOSITIVE(VIRTUALMACHINE& vm);
	virtual bool execute(void);
};

struct INSTJUMPNEGATIVE : public INSTJUMP
{
	INSTJUMPNEGATIVE(VIRTUALMACHINE& vm);
	virtual bool execute(void);
};

struct INSTJUMPSHORT : public INSTJUMP
{
	INSTJUMPSHORT(VIRTUALMACHINE& vm);
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
};

struct INSTJUMPSHORTZERO : public INSTJUMPSHORT
{
	INSTJUMPSHORTZERO(VIRTUALMACHINE& vm);
	virtual bool execute(void);
};

struct INSTJUMPSHORTNOTZERO : public INSTJUMPSHORT
{
	INSTJUMPSHORTNOTZERO(VIRTUALMACHINE& vm);
	virtual bool execute(void);
};

struct INSTJUMPSHORTPOSITIVE : public INSTJUMPSHORT
{
	INSTJUMPSHORTPOSITIVE(VIRTUALMACHINE& vm);
	virtual bool execute(void);
};

struct INSTJUMPSHORTNEGATIVE : public INSTJUMPSHORT
{
	INSTJUMPSHORTNEGATIVE(VIRTUALMACHINE& vm);
	virtual bool execute(void);
};

