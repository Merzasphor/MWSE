#include "GetSkillFunction.h"

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool GetSkillFunction::execute(void)
{
	long skill_index;
	float skill_value = -1.0;
	unsigned long record_type;
	VPVOID reference, temp;
	if (GetTargetData(machine, &reference, &temp, &record_type) &&
		(record_type == NPC || record_type == CREATURE)) {
		MACPRecord* macp = 
			reinterpret_cast<MACPRecord*>(GetAttachPointer(
			machine, reference, MACHNODE));
		if (macp != NULL && machine.pop(skill_index) &&
			skill_index >= kFirstSkill && skill_index <= kLastSkill) {
			skill_value = macp->skills[skill_index].current;
		}
	}
	return (machine.push(skill_value));
}
