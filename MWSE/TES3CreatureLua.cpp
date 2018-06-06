#include "TES3CreatureLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3AIConfig.h"
#include "TES3Creature.h"
#include "TES3Item.h"
#include "TES3Script.h"
#include "TES3SpellList.h"

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
			result[i + 1] = sol::make_object(state, &attacks[i]);
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
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::Creature::Attributes
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Creature::Attributes>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("agility", &TES3::Creature::Attributes::agility);
				usertypeDefinition.set("endurance", &TES3::Creature::Attributes::endurance);
				usertypeDefinition.set("intelligence", &TES3::Creature::Attributes::intelligence);
				usertypeDefinition.set("luck", &TES3::Creature::Attributes::luck);
				usertypeDefinition.set("personality", &TES3::Creature::Attributes::personality);
				usertypeDefinition.set("speed", &TES3::Creature::Attributes::speed);
				usertypeDefinition.set("strength", &TES3::Creature::Attributes::strength);
				usertypeDefinition.set("willpower", &TES3::Creature::Attributes::willpower);

				// Finish up our usertype.
				state.set_usertype("tes3creatureAttributes", usertypeDefinition);
			}

			// Binding for TES3::Creature::Skills
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Creature::Skills>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("combat", &TES3::Creature::Skills::combat);
				usertypeDefinition.set("magic", &TES3::Creature::Skills::magic);
				usertypeDefinition.set("stealth", &TES3::Creature::Skills::stealth);

				// Finish up our usertype.
				state.set_usertype("tes3creatureSkills", usertypeDefinition);
			}

			// Binding for TES3::Creature::Attack
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Creature::Attack>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("min", &TES3::Creature::Attack::min);
				usertypeDefinition.set("max", &TES3::Creature::Attack::max);

				// Finish up our usertype.
				state.set_usertype("tes3creatureAttack", usertypeDefinition);
			}

			// Binding for TES3::Creature
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Creature>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());

				// Basic property binding.
				usertypeDefinition.set("aiConfig", sol::readonly_property(&TES3::Creature::aiConfig));
				usertypeDefinition.set("attributes", sol::readonly_property(&TES3::Creature::attributes));
				usertypeDefinition.set("equipment", sol::readonly_property(&TES3::Creature::equipment));
				usertypeDefinition.set("inventory", sol::readonly_property(&TES3::Creature::inventory));
				usertypeDefinition.set("isInstance", sol::var(false));
				usertypeDefinition.set("skills", sol::readonly_property(&TES3::Creature::skills));
				usertypeDefinition.set("soul", &TES3::Creature::soul);
				usertypeDefinition.set("soundCreature", &TES3::Creature::soundGenerator);
				usertypeDefinition.set("spells", sol::readonly_property(&TES3::Creature::spellList));
				usertypeDefinition.set("type", sol::readonly_property(&TES3::Creature::creatureType));

				// Functions exposed as properties.
				usertypeDefinition.set("attacks", sol::readonly_property(&TES3::Creature::getAttacks));
				usertypeDefinition.set("barterGold", sol::property(&TES3::Creature::getBaseBarterGold, &TES3::Creature::setBaseBarterGold));
				usertypeDefinition.set("fatigue", sol::readonly_property(&TES3::Creature::getFatigue));
				usertypeDefinition.set("health", sol::readonly_property(&TES3::Creature::getDurability));
				usertypeDefinition.set("isAttacked", sol::readonly_property(&TES3::Creature::getIsAttacked));
				usertypeDefinition.set("isEssential", sol::readonly_property(&TES3::Creature::isEssential));
				usertypeDefinition.set("isRespawn", sol::readonly_property(&TES3::Creature::isRespawn));
				usertypeDefinition.set("level", sol::readonly_property(&TES3::Creature::getLevel));
				usertypeDefinition.set("magicka", sol::readonly_property(&TES3::Creature::getMagicka));
				usertypeDefinition.set("model", sol::property(&TES3::Creature::getModelPath, &TES3::Creature::setModelPath));
				usertypeDefinition.set("name", sol::property(&TES3::Creature::getName, &TES3::Creature::setName));
				usertypeDefinition.set("script", sol::readonly_property(&TES3::Creature::getScript));

				// Finish up our usertype.
				state.set_usertype("tes3creature", usertypeDefinition);
			}

			// Binding for TES3::CreatureInstance
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::CreatureInstance>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());

				// Basic property binding.
				usertypeDefinition.set("equipment", sol::readonly_property(&TES3::CreatureInstance::equipment));
				usertypeDefinition.set("fatigue", sol::readonly_property(&TES3::CreatureInstance::getFatigue));
				usertypeDefinition.set("health", sol::readonly_property(&TES3::CreatureInstance::getDurability));
				usertypeDefinition.set("inventory", sol::readonly_property(&TES3::CreatureInstance::inventory));
				usertypeDefinition.set("isInstance", sol::var(true));
				usertypeDefinition.set("weapon", sol::readonly_property([](TES3::CreatureInstance& self) { return makeLuaObject(self.weapon); }));

				// Properties that directly point to the base creature.
				usertypeDefinition.set("aiConfig", sol::readonly_property([](TES3::CreatureInstance& self) { return self.baseCreature->aiConfig; }));
				usertypeDefinition.set("baseCreature", sol::readonly_property([](TES3::CreatureInstance& self) { return makeLuaObject(self.baseCreature); }));
				usertypeDefinition.set("skills", sol::readonly_property([](TES3::CreatureInstance& self) { return &self.baseCreature->skills; }));
				usertypeDefinition.set("soul", sol::property(
					[](TES3::CreatureInstance& self) { return self.baseCreature->soul; },
					[](TES3::CreatureInstance& self, int value) { self.baseCreature->soul = value; }
				));
				usertypeDefinition.set("soundCreatureInstance", sol::readonly_property([](TES3::CreatureInstance& self) { return self.baseCreature->soundGenerator; }));
				usertypeDefinition.set("type", sol::readonly_property([](TES3::CreatureInstance& self) { return self.baseCreature->creatureType; }));
				usertypeDefinition.set("spells", sol::readonly_property([](TES3::CreatureInstance& self) { return self.baseCreature->spellList; }));

				// Functions exposed as properties.
				usertypeDefinition.set("attacks", sol::readonly_property(&TES3::CreatureInstance::getAttacks));
				usertypeDefinition.set("attributes", sol::readonly_property(&TES3::CreatureInstance::getAttributes));
				usertypeDefinition.set("barterGold", sol::property(&TES3::CreatureInstance::getBaseBarterGold, &TES3::CreatureInstance::setBaseBarterGold));
				usertypeDefinition.set("isAttacked", sol::readonly_property(&TES3::CreatureInstance::getIsAttacked));
				usertypeDefinition.set("isEssential", sol::readonly_property(&TES3::CreatureInstance::isEssential));
				usertypeDefinition.set("isRespawn", sol::readonly_property(&TES3::CreatureInstance::isRespawn));
				usertypeDefinition.set("level", sol::readonly_property(&TES3::CreatureInstance::getLevel));
				usertypeDefinition.set("magicka", sol::readonly_property(&TES3::CreatureInstance::getMagicka));
				usertypeDefinition.set("model", sol::property(&TES3::CreatureInstance::getModelPath, &TES3::CreatureInstance::setModelPath));
				usertypeDefinition.set("name", sol::property(&TES3::CreatureInstance::getName, &TES3::CreatureInstance::setName));
				usertypeDefinition.set("script", sol::readonly_property(&TES3::CreatureInstance::getScript));

				// Finish up our usertype.
				state.set_usertype("tes3creatureInstance", usertypeDefinition);
			}
		}
	}
}
