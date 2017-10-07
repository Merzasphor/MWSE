#include "GetAttributeFunction.h"

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool GetAttributeFunction::execute(void)
{
	long attribute_index;
	float value = -1.0;
	unsigned long type;
	VPVOID refr, temp;
	if (GetTargetData(machine, &refr, &temp, &type) && type == NPC) {
		MACPRecord* macp =
			reinterpret_cast<MACPRecord*>(GetAttachPointer(machine, refr, MACHNODE));
		if (macp && machine.pop(attribute_index) && attribute_index >= kFirstAttribute
			&& attribute_index <= kLastAttribute) {
			value = macp->attributes[attribute_index].current;
		}
	}
	return (machine.push(value));
}
