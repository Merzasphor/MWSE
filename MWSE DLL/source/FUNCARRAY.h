#ifndef MWSE_FUNCARRAY_H_
#define MWSE_FUNCARRAY_H_

#include "TES3MACHINE.h"

class FUNCCREATEARRAY : public FUNCTION
{
public:
	FUNCCREATEARRAY(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCGETARRAYVALUE : public FUNCTION
{
public:
	FUNCGETARRAYVALUE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCSETARRAYVALUE : public FUNCTION
{
public:
	FUNCSETARRAYVALUE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

#endif // MWSE_FUNCARRAY_H_
