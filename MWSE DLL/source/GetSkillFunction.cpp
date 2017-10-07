#include "GetSkillFunction.h"

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool GetSkillFunction::execute(void)
{
	long skill_index;
	float value = -1.0;
	unsigned long type;
	VPVOID refr, temp;
	if (GetTargetData(machine, &refr, &temp, &type) && type == NPC) {
		MACPRecord* macp = 
			reinterpret_cast<MACPRecord*>(GetAttachPointer(machine, refr, MACHNODE));
		if (macp && machine.pop(skill_index) && skill_index >= kFirstSkill
			&& skill_index <= kLastSkill) {
			value = macp->skills[skill_index].current;
		}
	}
	return (machine.push(value));
}
