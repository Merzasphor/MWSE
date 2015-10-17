//FuncText.h
#pragma once

#include "TES3OFFSETS.h"

#include <string>

//int interpolate(TES3MACHINE& machine, const char* src, char *buffer, int &size);
int interpolate(TES3MACHINE& machine, std::string const& format, std::string& result);
int secernate(const char* format, const char *string, VMREGTYPE* resultset, int resultmax);
bool enumerate(const char *format, int& substitutions, bool& eolmode);


struct FUNCMESSAGEFIX : public FUNCTION
{

	FUNCMESSAGEFIX(TES3MACHINE& vm) :machine(vm) {}
	virtual int GetOperands(OPCODE opcode, VPVOID operanddata);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
	VPVOID scriptoffset;
};

// 2005-07-09  CDC  Keyboard input, in two functions one checks raw key presses the other reads string data
struct FUNCKEYPRESSED : public FUNCTION
{
	FUNCKEYPRESSED(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCTEXTINPUT : public FUNCTION
{
	FUNCTEXTINPUT(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

// 2005-07-12  CDC  Alternative version if text input that doesn't block the game for long
struct FUNCTEXTINPUTALT : public FUNCTION
{
	FUNCTEXTINPUTALT(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

// 2005-07-10  CDC  Separate the string read/write from the file functions
struct FUNCSTRINGLENGTH : public FUNCTION
{
	FUNCSTRINGLENGTH(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCSTRINGBUILD : public FUNCTION
{
	FUNCSTRINGBUILD(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCSTRINGPARSE : public FUNCTION
{
	FUNCSTRINGPARSE(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

class FUNCSTRINGMATCH : public FUNCTION
{
public:
	FUNCSTRINGMATCH(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};


