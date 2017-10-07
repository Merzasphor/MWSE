#include "SetLevelFunction.h"

#include "Breakpoint.h"
#include "Tes3MemMap.h"
#include "TES3OFFSETS.h"
#include "TES3OPCODES.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool SetLevelFunction::execute()
{
	bool result = false;
	long level;
	if (machine.pop(level)) {
		parent = machine.GetFlow();
		result =
			machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(VARINDEX_IMAGE)),
			static_cast<void*>(&level),sizeof(level));
		if (result) {
			Context context = machine.GetFlow();
			context.Eip = (DWORD)reltolinear(FIXUPTEMPLATE);
			machine.SetFlow(context);
			result = machine.SetVMDebuggerBreakpoint(this);
		}
	}
	return result;
}

BYTE SetLevelFunction::getid()
{
	return BP_FIXUPTEMPLATE;
}

bool SetLevelFunction::breakpoint()
{
	bool result = false;
	Context flow = machine.GetFlow();
	if (machine.WriteMem(reinterpret_cast<VPVOID>(reltolinear(SECONDOBJECT_IMAGE)),
		&flow.Eax, sizeof(flow.Eax))) {
		machine.SetFlow(parent);
		result = CallOriginalFunction(machine, ORIG_SETLEVEL);
	}
	return result;
}
