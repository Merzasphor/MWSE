#include "GetRaceFunction.h"

#include "TES3OFFSETS.h"
#include "TES3TYPES.h"
#include "VMTYPES.h"

bool GetRaceFunction::execute()
{
	long id = 0;
	long return_array;
	unsigned long record_type;
	unsigned char* reference;
	unsigned char* temp;
	if (GetTargetData(machine, &reference, &temp, &record_type)	
		&& record_type == NPC && machine.pop(return_array)) {
		TES3REFERENCE const* const npc_reference =
			reinterpret_cast<TES3REFERENCE const* const>(reference);
		NPCCopyRecord const* const npc_copy =
			reinterpret_cast<NPCCopyRecord*>(npc_reference->templ);
		RACERecord const* const race = npc_copy->baseNPC->race;
		if (return_array == 0) {
			id = reinterpret_cast<long>(strings.add(race->name));
		} else if (return_array == 1) {
			id = machine.CreateArray("xGetRace");
			if (id != 0) {
				long skill_id = machine.CreateArray("xGetRace");
				if (skill_id != 0) {
					std::vector<long>& skill_array = 
						machine.arrays()[skill_id - 1];
					skill_array.push_back(7);
					for (int i = 0; i < 7; i++) {
						if (race->skill_bonuses[i].skill != kNoSkill) {
							skill_array.push_back(race->skill_bonuses[i].skill);
							skill_array.push_back(race->skill_bonuses[i].bonus);
						} else {
							skill_array[0] = i;
							break;
						}
					}
				}
				long attribute_id = machine.CreateArray("xGetRace");
				if (attribute_id != 0) {
					std::vector<long>& attribute_array = 
						machine.arrays()[attribute_id - 1];
					for (int i = 0; i < 8; i++) {
						attribute_array.push_back(race->base_attributes[i].male);
						attribute_array.push_back(race->base_attributes[i].female);
					}
				}
				std::vector<long>& main_array = machine.arrays()[id - 1];
				main_array.push_back(reinterpret_cast<long>(strings.add(race->id)));
				main_array.push_back(reinterpret_cast<long>(strings.add(race->name)));
				main_array.push_back(skill_id);
				main_array.push_back(attribute_id);
				main_array.push_back(*reinterpret_cast<long const*>(&race->height.male));
				main_array.push_back(*reinterpret_cast<long const*>(&race->height.female));
				main_array.push_back(*reinterpret_cast<long const*>(&race->weight.male));
				main_array.push_back(*reinterpret_cast<long const*>(&race->weight.female));
				main_array.push_back(race->flags & 1);
				main_array.push_back(race->flags >> 1);
			}
		}
	}
	return (machine.push(id));
}
