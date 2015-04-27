// Provides functions to get and set GMSTs.
// Based on funcgmst.h from MGE XE by Hrnchamd.

#pragma once

#include "FUNCEXTENDER.h"

struct FUNCGETGS : public FUNCEXTENDER
{
	FUNCGETGS(TES3MACHINE& vm): machine(vm){}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCSETGS : public FUNCEXTENDER
{
	FUNCSETGS(TES3MACHINE& vm): machine(vm){}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};