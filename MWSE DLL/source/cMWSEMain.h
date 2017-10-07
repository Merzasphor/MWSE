#pragma once

#include "Breakpoint.h"
#include "TES3MACHINE.h"
#include "cLog.h"
#include "TES3MemMap.h"

class cMWSEMain
{
private:
	static TES3MACHINE* vScriptMachine;
	static VPVOID vPrevScript;
	static HWBREAKPOINT* vHWBreakpoint;
public:
	static void mStartMWSE();

	static void mOnDecode(Context* context);
	static void mOnRunFuncIdxError(Context* context);
	static void mOnRunScript(Context* context);
	static void mOnFixupScript(Context* context);
	static void mOnOtherBreakpoint(Context* context);

	static bool mChangeReference(VPVOID pscript);
	static TES3MACHINE* mGetVM();
};

// MGE XE exports
extern "C"
{
	__declspec( dllexport ) TES3MACHINE* MWSEGetVM();
	__declspec( dllexport ) bool MWSEAddInstruction(OPCODE op, INSTRUCTION *ins);
}
