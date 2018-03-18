#include "TES3CreatureLua.h"

#include "LuaManager.h"

#include "TES3AIConfig.h"
#include "TES3Creature.h"
#include "TES3Item.h"
#include "TES3Script.h"

namespace TES3 {
	sol::object Creature::getAttributes() {
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();

		sol::table result = state.create_table();
		for (int i = 0; i < 8; i++) {
			result[i + 1] = attributes[i];
		}
		return result;
	}

	sol::object CreatureInstance::getAttributes() {
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();

		sol::table result = state.create_table();
		for (int i = 0; i < 8; i++) {
			result[i + 1] = baseCreature->attributes[i];
		}
		return result;
	}
}

namespace mwse {
	namespace lua {
		void bindTES3Creature() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Creature>("TES3Creature",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Creature::objectType,

				"id", sol::readonly_property(&TES3::Creature::getObjectID),
				"name", sol::property(&TES3::Creature::getName, &TES3::Creature::setName),

				"model", sol::readonly_property(&TES3::Creature::getModelPath),

				"type", &TES3::Creature::creatureType,

				"flags", &TES3::Creature::actorFlags,
				"cloneCount", &TES3::Creature::cloneCount,

				"level", sol::readonly_property(&TES3::Creature::getLevel),
				"health", sol::readonly_property(&TES3::Creature::getDurability),
				"magicka", sol::readonly_property(&TES3::Creature::getMagicka),
				"fatigue", sol::readonly_property(&TES3::Creature::getFatigue),
				"attributes", sol::readonly_property(&TES3::Creature::getAttributes),
				"skillCombat", &TES3::Creature::combatSkill,
				"skillMagic", &TES3::Creature::magicSkill,
				"skillStealth", &TES3::Creature::stealthSkill,
				"attack1Min", &TES3::Creature::attack1Min,
				"attack1Max", &TES3::Creature::attack1Max,
				"attack2Min", &TES3::Creature::attack2Min,
				"attack2Max", &TES3::Creature::attack2Max,
				"attack3Min", &TES3::Creature::attack3Min,
				"attack3Max", &TES3::Creature::attack3Max,

				"isEssential", sol::readonly_property(&TES3::Creature::isEssential),
				"isRespawn", sol::readonly_property(&TES3::Creature::isRespawn),
				"isAttacked", sol::readonly_property(&TES3::Creature::getIsAttacked),

				"barterGold", sol::property(&TES3::Creature::getBaseBarterGold, &TES3::Creature::setBaseBarterGold),

				"aiConfig", sol::readonly_property(&TES3::Creature::aiConfig),

				"script", sol::readonly_property(&TES3::Creature::getScript)

				);

			state.new_usertype<TES3::CreatureInstance>("TES3CreatureInstance",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::CreatureInstance::objectType,

				"id", sol::readonly_property(&TES3::CreatureInstance::getObjectID),
				"name", sol::property(&TES3::CreatureInstance::getName, &TES3::CreatureInstance::setName),

				"model", sol::readonly_property(&TES3::CreatureInstance::getModelPath),

				"flags", &TES3::CreatureInstance::actorFlags,
				"cloneCount", &TES3::CreatureInstance::cloneCount,

				"level", sol::readonly_property(&TES3::CreatureInstance::getLevel),
				"health", sol::readonly_property(&TES3::CreatureInstance::getDurability),
				"magicka", sol::readonly_property(&TES3::CreatureInstance::getMagicka),
				"fatigue", sol::readonly_property(&TES3::CreatureInstance::getFatigue),
				"attributes", sol::readonly_property(&TES3::CreatureInstance::getAttributes),
				//"skillCombat", &TES3::CreatureInstance::combatSkill,
				//"skillMagic", &TES3::CreatureInstance::magicSkill,
				//"skillStealth", &TES3::CreatureInstance::stealthSkill,
				//"attack1Min", &TES3::CreatureInstance::attack1Min,
				//"attack1Max", &TES3::CreatureInstance::attack1Max,
				//"attack2Min", &TES3::CreatureInstance::attack2Min,
				//"attack2Max", &TES3::CreatureInstance::attack2Max,
				//"attack3Min", &TES3::CreatureInstance::attack3Min,
				//"attack3Max", &TES3::CreatureInstance::attack3Max,

				"isEssential", sol::readonly_property(&TES3::CreatureInstance::isEssential),
				"isRespawn", sol::readonly_property(&TES3::CreatureInstance::isRespawn),
				"isAttacked", sol::readonly_property(&TES3::CreatureInstance::getIsAttacked),

				"barterGold", sol::property(&TES3::CreatureInstance::getBaseBarterGold, &TES3::CreatureInstance::setBaseBarterGold),

				//"aiConfig", sol::readonly_property(&TES3::CreatureInstance::aiConfig),

				"baseCreature", sol::readonly_property(&TES3::CreatureInstance::baseCreature),

				"weapon", sol::readonly_property(&TES3::CreatureInstance::weapon),

				"script", sol::readonly_property(&TES3::CreatureInstance::getScript)

				);
		}
	}
}
