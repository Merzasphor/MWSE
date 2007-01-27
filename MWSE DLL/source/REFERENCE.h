//Reference.h
#pragma once //TODO: need here?

#include "TES3MACHINE.h"

struct REFERENCE
{
	static bool GetMach(TES3MACHINE& machine, VPREFERENCE ref, VPMACH& mach);
	static bool GetVars(TES3MACHINE& machine, VPREFERENCE ref, VPVARHOLDER& varholder);
	static bool GetInventory(TES3MACHINE& machine, VPREFERENCE pref, VPLISTNODE& firststack);
private:
	static bool GetAttachment(TES3MACHINE& machine, VPREFERENCE pref, VPVOID& attachment, TES3ATTACHTYPE type);
	static bool isContainer(VMPTR<TES3TEMPLATE>& templ);
};

