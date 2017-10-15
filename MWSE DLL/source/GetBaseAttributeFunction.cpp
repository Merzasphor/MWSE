#include "GetBaseAttributeFunction.h"

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool GetBaseAttributeFunction::execute(void)
{
	long attribute_index;
	float attribute_value = -1.0;
	unsigned long record_type;
	VPVOID reference, temp;
	if (GetTargetData(machine, &reference, &temp, &record_type) &&
		(record_type == NPC || record_type == CREATURE)) {
		MACPRecord const* const macp =
			reinterpret_cast<MACPRecord*>(GetAttachPointer(machine, reference, MACHNODE));
		if (macp != NULL && machine.pop(attribute_index) &&
			attribute_index >= kFirstAttribute &&
			attribute_index <= kLastAttribute) {
			attribute_value = macp->attributes[attribute_index].base;
		}
	}
	return (machine.push(attribute_value));
}
