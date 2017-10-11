#include "GetEncumbranceFunction.h"

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool GetEncumbranceFunction::execute(void)
{
	enum Encumbrance
	{
		kCurrent = 0,
		kMax = 1,
		kBase = 2
	};
	long encumbrance_type;
	float encumbrance = -1.0;
	unsigned long record_type;
	VPVOID reference, temp;
	if (GetTargetData(machine, &reference, &temp, &record_type) 
		&& record_type == NPC) {
		MACPRecord* macp = 
			reinterpret_cast<MACPRecord*>(GetAttachPointer(
			machine, reference, MACHNODE));
		machine.pop(encumbrance_type);
		if (macp != NULL) {
			if (encumbrance_type == kCurrent) {
				encumbrance = macp->weight_limit.current;
			} else if (encumbrance_type == kMax) {
				encumbrance = macp->weight_limit.base;
			}
		}
	}
	return (machine.push(encumbrance));
}
