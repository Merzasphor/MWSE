#include "TES3CreatureLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3Creature.h"
#include "TES3Item.h"
#include "TES3Script.h"

namespace TES3 {
	sol::object CreatureInstance::getAttributes() {
		return sol::make_object(mwse::lua::LuaManager::getInstance().getState(), &baseCreature->attributes);
	}

	sol::object CreatureInstance::getSkills() {
		return sol::make_object(mwse::lua::LuaManager::getInstance().getState(), &baseCreature->skills);
	}

	sol::object Creature::getAttacks() {
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();

		sol::table result = state.create_table();
		for (int i = 0; i < 3; i++) {
			result[i+1] = sol::make_object(state, &attacks[i]);
		}
		return result;
	}

	sol::object CreatureInstance::getAttacks() {
		return baseCreature->getAttacks();
	}
}

namespace mwse {
	namespace lua {
		void bindTES3Creature() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Creature::Attributes>("TES3CreatureAttributes",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"strength", &TES3::Creature::Attributes::strength,
				"intelligence", &TES3::Creature::Attributes::intelligence,
				"willpower", &TES3::Creature::Attributes::willpower,
				"agility", &TES3::Creature::Attributes::agility,
				"speed", &TES3::Creature::Attributes::speed,
				"endurance", &TES3::Creature::Attributes::endurance,
				"personality", &TES3::Creature::Attributes::personality,
				"luck", &TES3::Creature::Attributes::luck

				);

			state.new_usertype<TES3::Creature::Skills>("TES3CreatureSkills",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"combat", &TES3::Creature::Skills::combat,
				"magic", &TES3::Creature::Skills::magic,
				"stealth", &TES3::Creature::Skills::stealth

				);

			state.new_usertype<TES3::Creature::Attack>("TES3CreatureAttack",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"min", &TES3::Creature::Attack::min,
				"max", &TES3::Creature::Attack::max

				);

			state.new_usertype<TES3::Creature>("TES3Creature",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::Actor, TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::Creature::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Creature::objectType,

				"boundingBox", &TES3::Creature::boundingBox,

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
				"attributes", sol::readonly_property(&TES3::Creature::attributes),
				"skills", sol::readonly_property(&TES3::Creature::skills),
				"attacks", sol::readonly_property(&TES3::Creature::getAttacks),

				"isEssential", sol::readonly_property(&TES3::Creature::isEssential),
				"isRespawn", sol::readonly_property(&TES3::Creature::isRespawn),
				"isAttacked", sol::readonly_property(&TES3::Creature::getIsAttacked),
				"isInstance", sol::var(false),

				"inventory", sol::readonly_property(&TES3::Creature::inventory),
				"equipment", sol::readonly_property(&TES3::Creature::equipment),
				"barterGold", sol::property(&TES3::Creature::getBaseBarterGold, &TES3::Creature::setBaseBarterGold),

				"spells", sol::readonly_property(&TES3::Creature::spellList),

				"soul", &TES3::Creature::soul,

				"aiConfig", sol::readonly_property(&TES3::Creature::aiConfig),

				"script", sol::readonly_property(&TES3::Creature::getScript),

				"soundCreature", &TES3::Creature::soundGenerator

				);

			state.new_usertype<TES3::CreatureInstance>("TES3CreatureInstance",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::Actor, TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::CreatureInstance::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::CreatureInstance::objectType,

				"boundingBox", &TES3::CreatureInstance::boundingBox,

				"id", sol::readonly_property(&TES3::CreatureInstance::getObjectID),
				"name", sol::property(&TES3::CreatureInstance::getName, &TES3::CreatureInstance::setName),

				"baseObject", &TES3::CreatureInstance::baseCreature,

				"model", sol::readonly_property(&TES3::CreatureInstance::getModelPath),

				"flags", &TES3::CreatureInstance::actorFlags,
				"cloneCount", &TES3::CreatureInstance::cloneCount,

				"level", sol::readonly_property(&TES3::CreatureInstance::getLevel),
				"health", sol::readonly_property(&TES3::CreatureInstance::getDurability),
				"magicka", sol::readonly_property(&TES3::CreatureInstance::getMagicka),
				"fatigue", sol::readonly_property(&TES3::CreatureInstance::getFatigue),
				"attributes", sol::readonly_property(&TES3::CreatureInstance::getAttributes),
				"skills", sol::readonly_property(&TES3::CreatureInstance::getSkills),
				"attacks", sol::readonly_property(&TES3::CreatureInstance::getAttacks),

				"isEssential", sol::readonly_property(&TES3::CreatureInstance::isEssential),
				"isRespawn", sol::readonly_property(&TES3::CreatureInstance::isRespawn),
				"isAttacked", sol::readonly_property(&TES3::CreatureInstance::getIsAttacked),
				"isInstance", sol::var(true),

				"inventory", sol::readonly_property(&TES3::CreatureInstance::inventory),
				"equipment", sol::readonly_property(&TES3::CreatureInstance::equipment),
				"barterGold", sol::property(&TES3::CreatureInstance::getBaseBarterGold, &TES3::CreatureInstance::setBaseBarterGold),

				"spells", sol::readonly_property([](TES3::CreatureInstance& self) { return self.baseCreature->spellList; }),

				//"aiConfig", sol::readonly_property(&TES3::CreatureInstance::aiConfig),

				"baseCreature", sol::readonly_property(&TES3::CreatureInstance::baseCreature),

				"weapon", sol::readonly_property(&TES3::CreatureInstance::weapon),

				"script", sol::readonly_property(&TES3::CreatureInstance::getScript)

				);
		}
	}
}
