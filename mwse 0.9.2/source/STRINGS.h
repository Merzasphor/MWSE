//Strings.h
#pragma once

#include <string>
#include "function.h"

typedef std::string STRING;

struct STRINGS
{
	void clear();
	const char* add(const char* str);
};

extern STRINGS strings;

struct TES3MACHINE;

struct FUNCSTRCMP : FUNCTION
{
	FUNCSTRCMP(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};
