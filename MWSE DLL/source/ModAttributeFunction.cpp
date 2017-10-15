#include "ModAttributeFunction.h"

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool ModAttributeFunction::execute(void)
{
	long attribute_index;
	long result = 0;
	float mod_value;
	unsigned long record_type;
	VPVOID reference, temp;
	if (GetTargetData(machine, &reference, &temp, &record_type) &&
		(record_type == NPC || record_type == CREATURE)) {
		MACPRecord* const macp =
			reinterpret_cast<MACPRecord*>(GetAttachPointer(machine, reference, MACHNODE));
		if (macp != NULL && machine.pop(attribute_index) && machine.pop(mod_value)
			&& attribute_index >= kFirstAttribute 
			&& attribute_index <= kLastAttribute) {
			float new_current = macp->attributes[attribute_index].current + mod_value;
			if (new_current < 0) new_current = 0;
			macp->attributes[attribute_index].current = new_current;
			float new_base = macp->attributes[attribute_index].base + mod_value;
			if (new_base < 0) new_base = 0;
			macp->attributes[attribute_index].base = new_base;
			result = 1;
		}
	}
	return (machine.push(result));
}
