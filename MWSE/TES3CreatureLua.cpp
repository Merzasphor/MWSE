#include "TES3CreatureLua.h"

#include "LuaManager.h"
#include "TES3ActorLua.h"

#include "TES3AIConfig.h"
#include "TES3Creature.h"
#include "TES3Item.h"
#include "TES3Script.h"
#include "TES3SpellList.h"

#include "BitUtil.h"

namespace mwse {
	namespace lua {
		void bindTES3Creature() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::Creature
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Creature>("tes3creature");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>();
				setUserdataForActor(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["aiConfig"] = sol::readonly_property(&TES3::Creature::aiConfig);
				usertypeDefinition["isInstance"] = sol::var(false);
				usertypeDefinition["soul"] = &TES3::Creature::soul;
				usertypeDefinition["soundCreature"] = &TES3::Creature::soundGenerator;
				usertypeDefinition["spells"] = sol::readonly_property(&TES3::Creature::spellList);
				usertypeDefinition["type"] = &TES3::Creature::creatureType;

				// Indirect bindings to unions and arrays.
				usertypeDefinition["attacks"] = sol::readonly_property([](TES3::Creature& self) { return std::ref(self.attacks); });
				usertypeDefinition["attributes"] = sol::readonly_property([](TES3::Creature& self) { return std::ref(self.attributes); });
				usertypeDefinition["skills"] = sol::readonly_property([](TES3::Creature& self) { return std::ref(self.skills); });

				// Functions exposed as properties.
				usertypeDefinition["fatigue"] = sol::readonly_property(&TES3::Creature::getFatigue);
				usertypeDefinition["health"] = sol::readonly_property(&TES3::Creature::getDurability);
				usertypeDefinition["isEssential"] = sol::readonly_property(&TES3::Creature::isEssential);
				usertypeDefinition["isRespawn"] = sol::readonly_property(&TES3::Creature::isRespawn);
				usertypeDefinition["level"] = sol::readonly_property(&TES3::Creature::getLevel);
				usertypeDefinition["magicka"] = sol::readonly_property(&TES3::Creature::getMagicka);
				usertypeDefinition["mesh"] = sol::property(&TES3::Creature::getModelPath, &TES3::Creature::setModelPath);
				usertypeDefinition["name"] = sol::property(&TES3::Creature::getName, &TES3::Creature::setName);
				usertypeDefinition["script"] = sol::readonly_property(&TES3::Creature::getScript);

				// Easy access to actor flags.
				usertypeDefinition["biped"] = sol::property(
					[](TES3::Creature& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::BipedBit); },
					[](TES3::Creature& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::BipedBit, state); }
				);
				usertypeDefinition["respawns"] = sol::property(
					[](TES3::Creature& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::RespawnBit); },
					[](TES3::Creature& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::RespawnBit, state); }
				);
				usertypeDefinition["usesEquipment"] = sol::property(
					[](TES3::Creature& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::WeaponAndShieldBit); },
					[](TES3::Creature& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::WeaponAndShieldBit, state); }
				);
				usertypeDefinition["swims"] = sol::property(
					[](TES3::Creature& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::SwimsBit); },
					[](TES3::Creature& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::SwimsBit, state); }
				);
				usertypeDefinition["flies"] = sol::property(
					[](TES3::Creature& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::FliesBit); },
					[](TES3::Creature& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::FliesBit, state); }
				);
				usertypeDefinition["walks"] = sol::property(
					[](TES3::Creature& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::WalksBit); },
					[](TES3::Creature& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::WalksBit, state); }
				);

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition["model"] = sol::property(&TES3::Creature::getModelPath, &TES3::Creature::setModelPath);
			}

			// Binding for TES3::CreatureInstance
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::CreatureInstance>("tes3creatureInstance");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>();
				setUserdataForActor(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["equipment"] = sol::readonly_property(&TES3::CreatureInstance::equipment);
				usertypeDefinition["fatigue"] = sol::readonly_property(&TES3::CreatureInstance::getFatigue);
				usertypeDefinition["health"] = sol::readonly_property(&TES3::CreatureInstance::getDurability);
				usertypeDefinition["inventory"] = sol::readonly_property(&TES3::CreatureInstance::inventory);
				usertypeDefinition["isInstance"] = sol::var(true);
				usertypeDefinition["weapon"] = sol::readonly_property([](TES3::CreatureInstance& self) { return makeLuaObject(self.weapon); });

				// Properties that directly point to the base creature.
				usertypeDefinition["aiConfig"] = sol::readonly_property([](TES3::CreatureInstance& self) { return self.baseCreature->aiConfig; });
				usertypeDefinition["attacks"] = sol::readonly_property([](TES3::CreatureInstance& self) { return std::ref(self.baseCreature->attacks); });
				usertypeDefinition["attributes"] = sol::readonly_property([](TES3::CreatureInstance& self) { return std::ref(self.baseCreature->attributes); });
				usertypeDefinition["baseObject"] = sol::readonly_property([](TES3::CreatureInstance& self) { return makeLuaObject(self.baseCreature); });
				usertypeDefinition["soul"] = sol::property(
					[](TES3::CreatureInstance& self) { return self.baseCreature->soul; },
					[](TES3::CreatureInstance& self, int value) { self.baseCreature->soul = value; }
				);
				usertypeDefinition["soundCreatureInstance"] = sol::readonly_property([](TES3::CreatureInstance& self) { return self.baseCreature->soundGenerator; });
				usertypeDefinition["skills"] = sol::readonly_property([](TES3::CreatureInstance& self) { return std::ref(self.baseCreature->skills); });
				usertypeDefinition["type"] = sol::readonly_property([](TES3::CreatureInstance& self) { return self.baseCreature->creatureType; });
				usertypeDefinition["spells"] = sol::readonly_property([](TES3::CreatureInstance& self) { return self.baseCreature->spellList; });

				// Functions exposed as properties.
				usertypeDefinition["barterGold"] = sol::property(&TES3::CreatureInstance::getBaseBarterGold, &TES3::CreatureInstance::setBaseBarterGold);
				usertypeDefinition["isEssential"] = sol::readonly_property(&TES3::CreatureInstance::isEssential);
				usertypeDefinition["isRespawn"] = sol::readonly_property(&TES3::CreatureInstance::isRespawn);
				usertypeDefinition["level"] = sol::readonly_property(&TES3::CreatureInstance::getLevel);
				usertypeDefinition["magicka"] = sol::readonly_property(&TES3::CreatureInstance::getMagicka);
				usertypeDefinition["mesh"] = sol::property(&TES3::CreatureInstance::getModelPath, &TES3::CreatureInstance::setModelPath);
				usertypeDefinition["name"] = sol::property(&TES3::CreatureInstance::getName, &TES3::CreatureInstance::setName);
				usertypeDefinition["script"] = sol::readonly_property(&TES3::CreatureInstance::getScript);

				// Easy access to actor flags.
				usertypeDefinition["biped"] = sol::property(
					[](TES3::CreatureInstance& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::BipedBit); },
					[](TES3::CreatureInstance& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::BipedBit, state); }
				);
				usertypeDefinition["respawns"] = sol::property(
					[](TES3::CreatureInstance& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::RespawnBit); },
					[](TES3::CreatureInstance& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::RespawnBit, state); }
				);
				usertypeDefinition["usesEquipment"] = sol::property(
					[](TES3::CreatureInstance& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::WeaponAndShieldBit); },
					[](TES3::CreatureInstance& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::WeaponAndShieldBit, state); }
				);
				usertypeDefinition["swims"] = sol::property(
					[](TES3::CreatureInstance& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::SwimsBit); },
					[](TES3::CreatureInstance& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::SwimsBit, state); }
				);
				usertypeDefinition["flies"] = sol::property(
					[](TES3::CreatureInstance& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::FliesBit); },
					[](TES3::CreatureInstance& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::FliesBit, state); }
				);
				usertypeDefinition["walks"] = sol::property(
					[](TES3::CreatureInstance& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagCreature::WalksBit); },
					[](TES3::CreatureInstance& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagCreature::WalksBit, state); }
				);

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition["baseCreature"] = sol::readonly_property([](TES3::CreatureInstance& self) { return makeLuaObject(self.baseCreature); });
				usertypeDefinition["model"] = sol::property(&TES3::CreatureInstance::getModelPath, &TES3::CreatureInstance::setModelPath);
			}
		}
	}
}
