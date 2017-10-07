#include "SetSkillInfoFunction.h"

#include <algorithm>

#include "TES3MemMap.h"
#include "TES3TYPES.h"

bool SetSkillInfoFunction::execute()
{
	long skill_id, attribute_id, specialization_id;
	float actions[4];
	long result = 0;
	if (machine.pop(skill_id) && machine.pop(attribute_id) && 
		machine.pop(specialization_id) && machine.pop(actions[0]) &&
		machine.pop(actions[1]) && machine.pop(actions[2]) &&
		machine.pop(actions[3]) &&
		kFirstSkill <= skill_id && skill_id <= kLastSkill &&
		kFirstAttribute <= attribute_id && attribute_id <= kLastAttribute &&
		kFirstSpecialization <= specialization_id && 
		specialization_id <= kLastSpecialization) {
		TES3CELLMASTER* cell_master =
			*(reinterpret_cast<TES3CELLMASTER**>reltolinear(MASTERCELL_IMAGE));
		SKILRecord& skill_record = 
			cell_master->recordLists->skills[skill_id];
		skill_record.attribute = attribute_id;
		std::copy(actions, actions + sizeof(actions) / sizeof(actions[0]), 
			skill_record.actions);
		if (skill_record.specialization != specialization_id) {
			skill_record.specialization = specialization_id;
			machine.CheckForSkillUp(skill_id);
		}
		result = 1;
	}
	return machine.push(result);
}