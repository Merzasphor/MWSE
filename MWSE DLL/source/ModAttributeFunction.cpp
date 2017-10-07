#include "ModAttributeFunction.h"

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool ModAttributeFunction::execute(void)
{
	long attribute_index;
	long result = 0;
	float value;
	unsigned long type;
	VPVOID refr, temp;
	if (GetTargetData(machine, &refr, &temp, &type) && type == NPC) {
		MACPRecord* macp =
			reinterpret_cast<MACPRecord*>(GetAttachPointer(machine, refr, MACHNODE));
		if (macp && machine.pop(attribute_index) && machine.pop(value)
			&& attribute_index >= kFirstAttribute 
			&& attribute_index <= kLastAttribute) {
			float new_current = macp->attributes[attribute_index].current + value;
			if (new_current < 0) new_current = 0;
			macp->attributes[attribute_index].current = new_current;
			float new_base = macp->attributes[attribute_index].base + value;
			if (new_base < 0) new_base = 0;
			macp->attributes[attribute_index].base = new_base;
			result = 1;
		}
	}
	return (machine.push(result));
}
