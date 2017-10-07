#include "GetMaxHealthFunction.h"

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool GetMaxHealthFunction::execute(void)
{
	float value = -1.0;
	unsigned long type;
	VPVOID refr, temp;
	if (GetTargetData(machine, &refr, &temp, &type) && type == NPC) {
		MACPRecord* macp = 
			reinterpret_cast<MACPRecord*>(GetAttachPointer(machine, refr, MACHNODE));
		if (macp) {
			value = macp->health.base;
		}
	}
	return (machine.push(value));
}
