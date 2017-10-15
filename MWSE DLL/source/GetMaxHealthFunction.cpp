#include "GetMaxHealthFunction.h"

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool GetMaxHealthFunction::execute(void)
{
	float health = -1.0;
	unsigned long record_type;
	VPVOID reference, temp;
	if (GetTargetData(machine, &reference, &temp, &record_type) &&
		(record_type == NPC || record_type == CREATURE)) {
		MACPRecord const* const macp =
			reinterpret_cast<MACPRecord*>(GetAttachPointer(
			machine, reference, MACHNODE));
		if (macp != NULL) health = macp->health.base;
	}
	return (machine.push(health));
}
