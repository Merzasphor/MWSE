#ifndef MWSE_ARRAYFUNCTIONS_H_
#define MWSE_ARRAYFUNCTIONS_H_

#include "FUNCTION.h"
#include "TES3MACHINE.h"

class CreateArrayFunction : public FUNCTION
{
public:
	CreateArrayFunction(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

class GetArrayValueFunction : public FUNCTION
{
public:
	GetArrayValueFunction(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute();
private:
	TES3MACHINE& machine;
};

class SetArrayValueFunction : public FUNCTION
{
public:
	SetArrayValueFunction(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

#endif // MWSE_ARRAYFUNCTIONS_H_
