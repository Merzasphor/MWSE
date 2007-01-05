#include "MWSEmain.h"
#include "Breakpoint.h"

static void OnDecode(Context* context);
static void OnRunFuncIdxError(Context* context);
static void OnRunScript(Context* context);
static void OnFixupScript(Context* context);

static void OnDecode(Context* context) {

}

static void OnRunFuncIdxError(Context* context) {

}

static void OnRunScript(Context* context) {
	AddBreakpoint(BP_FIXUPSCRIPT, OnFixupScript);
	RemoveBreakpoint(BP_RUNSCRIPT);

	AddBreakpoint(BP_RUNFUNCIDXERR, OnRunFuncIdxError);
	RemoveBreakpoint(BP_DECODEWITHINFO);
}

static void OnFixupScript(Context* context) {
	AddBreakpoint(BP_RUNSCRIPT, OnRunScript);
	RemoveBreakpoint(BP_FIXUPSCRIPT);

	AddBreakpoint(BP_DECODEWITHINFO, OnDecode);
	RemoveBreakpoint(BP_RUNFUNCIDXERR);
}

void MWSEOnProcessStart() {
	AddBreakpoint(BP_RUNSCRIPT, OnRunScript);
	AddBreakpoint(BP_FIXUPSCRIPT, OnFixupScript);
}
