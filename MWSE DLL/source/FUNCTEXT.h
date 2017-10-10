//FuncText.h
#pragma once

#include "TES3OFFSETS.h"

#include <string>

// Returns a string with substitutions performed, similar to printf().
// Recognized format codes (all codes are case insensitive):
// %% = %
// %n = \r\n
// %q = "
// %d = decimal integer
// %h = hexadecimal integr
// %f = floating point number - can specify precision: %.3f
// %s = string - can skip leading character: %2.s - or only insert n
//      characters: %.3s - or combine both: %2.3s
// % at the end of the string indicates that the null terminator should not be
// printed.
// format - a string containing zero or more format codes and/or other text.
// machine - read arguments for substitution from this machine.
// suppress_null - set to true when null suppression flag is detected.
std::string interpolate(std::string const& format, TES3MACHINE* machine,
						bool* suppress_null, std::string* bad_codes);
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


