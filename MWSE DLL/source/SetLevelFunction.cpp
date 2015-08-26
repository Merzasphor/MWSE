#include "SetLevelFunction.h"

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool SetLevelFunction::execute()
{
	long result = 0;
	long level;
	VPVOID refr, temp;
	unsigned long ref_type;
	if (machine.pop(level) &&
		level >= 1 &&
		GetTargetData(machine, &refr, &temp, &ref_type) && 
		ref_type == NPC)
	{
		TES3REFERENCE * npc_ref = reinterpret_cast<TES3REFERENCE*>(refr);
		NPCCopyRecord * npc_copy = reinterpret_cast<NPCCopyRecord*>(npc_ref->templ);
		npc_copy->baseNPC->level = level;
		result = 1;
	}
	return machine.push(result);
}
