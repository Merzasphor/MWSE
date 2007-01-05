//FuncFile.h
#pragma once

#include "TES3MACHINE.h"
#include "FUNCTION.h"
#include "FILECACHE.h"
#include "STRINGS.h"

struct FUNCFILEREADTWOBYTES : public FUNCTION
{
	FUNCFILEREADTWOBYTES(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCFILEREADFOURBYTES : public FUNCTION
{
	FUNCFILEREADFOURBYTES(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCFILEREADSTRING : public FUNCTION
{
	FUNCFILEREADSTRING(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCFILEREWIND : public FUNCTION
{
	FUNCFILEREWIND(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCFILESEEK : public FUNCTION
{
	FUNCFILESEEK(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCFILEWRITETWOBYTES : public FUNCTION
{
	FUNCFILEWRITETWOBYTES(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCFILEWRITEFOURBYTES : public FUNCTION
{
	FUNCFILEWRITEFOURBYTES(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCFILEWRITESTRING : public FUNCTION
{
	FUNCFILEWRITESTRING(TES3MACHINE& vm);
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

// 2005-07-10  CDC  Separate the new text reading functions from normal string processing
struct FUNCFILEREADTEXT : public FUNCTION
{
	FUNCFILEREADTEXT(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

struct FUNCFILEWRITETEXT : public FUNCTION
{
	FUNCFILEWRITETEXT(TES3MACHINE& vm) :machine(vm) {}
	virtual bool execute(void);
private:
	TES3MACHINE& machine;
};

