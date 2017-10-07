#include "GetSkillInfoFunction.h"

#include <algorithm>

#include "TES3MemMap.h"
#include "TES3TYPES.h"

bool GetSkillInfoFunction::execute()
{
	long skill_id;
	long attribute_id = kNoAttribute;
	long specialization_id = kNoSpecialization;
	float actions[4] = { -1.0, -1.0, -1.0, -1.0 };
	if (machine.pop(skill_id) &&
		kFirstSkill <= skill_id && skill_id <= kLastSkill) {
		TES3CELLMASTER* cell_master =
			*(reinterpret_cast<TES3CELLMASTER**>reltolinear(MASTERCELL_IMAGE));
		SKILRecord const& skill_record = 
			cell_master->recordLists->skills[skill_id];
		attribute_id = skill_record.attribute;
		specialization_id = skill_record.specialization;
		std::copy(skill_record.actions, skill_record.actions + 
			sizeof(skill_record.actions) / sizeof(skill_record.actions[0]), 
			actions);
	}
	return machine.push(actions[3]) && machine.push(actions[2]) && 
		machine.push(actions[1]) && machine.push(actions[0]) &&
		machine.push(specialization_id) && machine.push(attribute_id);
}