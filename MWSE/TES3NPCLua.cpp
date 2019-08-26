#include "TES3NPCLua.h"

#include "LuaManager.h"
#include "TES3ActorLua.h"

#include "TES3NPC.h"
#include "TES3BodyPart.h"
#include "TES3Race.h"
#include "TES3Class.h"
#include "TES3Faction.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3NPC() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::NPC
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::NPC>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
				setUserdataForActor(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("baseDisposition", &TES3::NPC::baseDisposition);
				usertypeDefinition.set("factionIndex", &TES3::NPC::factionIndex);
				usertypeDefinition.set("factionRank", &TES3::NPC::factionRank);
				usertypeDefinition.set("fatigue", &TES3::NPC::fatigue);
				usertypeDefinition.set("hair", &TES3::NPC::hair);
				usertypeDefinition.set("head", &TES3::NPC::head);
				usertypeDefinition.set("health", &TES3::NPC::health);
				usertypeDefinition.set("level", &TES3::NPC::level);
				usertypeDefinition.set("magicka", &TES3::NPC::magicka);
				usertypeDefinition.set("reputation", &TES3::NPC::reputation);

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("attributes", sol::property([](TES3::NPC& self) { return std::ref(self.attributes); }));
				usertypeDefinition.set("skills", sol::property([](TES3::NPC& self) { return std::ref(self.skills); }));

				// Constants.
				usertypeDefinition.set("isInstance", sol::var(false));

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("class", sol::readonly_property([](TES3::NPC& self) { return makeLuaObject(self.class_); }));
				usertypeDefinition.set("faction", sol::readonly_property([](TES3::NPC& self) { return makeLuaObject(self.faction); }));
				usertypeDefinition.set("race", sol::readonly_property([](TES3::NPC& self) { return makeLuaObject(self.race); }));
				usertypeDefinition.set("script", sol::readonly_property([](TES3::NPC& self) { return makeLuaObject(self.getScript()); }));

				// Functions exposed as properties.
				usertypeDefinition.set("aiConfig", sol::readonly_property(&TES3::NPC::getAIConfig));
				usertypeDefinition.set("isGuard", sol::readonly_property(&TES3::NPC::isGuard));
				usertypeDefinition.set("isEssential", sol::readonly_property(&TES3::NPC::isEssential));
				usertypeDefinition.set("isRespawn", sol::readonly_property(&TES3::NPC::isRespawn));
				usertypeDefinition.set("mesh", sol::property(&TES3::NPC::getModelPath, &TES3::NPC::setModelPath));
				usertypeDefinition.set("name", sol::property(&TES3::NPC::getName, &TES3::NPC::setName));
				usertypeDefinition.set("spells", sol::readonly_property([](TES3::NPC& self) { return &self.spellList; }));

				// Easy access to actor flags.
				usertypeDefinition.set("female", sol::property(
					[](TES3::NPC& self) { return self.actorFlags.test(TES3::ActorFlagNPC::FemaleBit); },
					[](TES3::NPC& self, bool state) { return self.actorFlags.set(TES3::ActorFlagNPC::FemaleBit, state); }
				));
				usertypeDefinition.set("autoCalc", sol::property(
					[](TES3::NPC& self) { return self.actorFlags.test(TES3::ActorFlagNPC::AutoCalcBit); },
					[](TES3::NPC& self, bool state) { return self.actorFlags.set(TES3::ActorFlagNPC::AutoCalcBit, state); }
				));

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition.set("model", sol::property(&TES3::NPC::getModelPath, &TES3::NPC::setModelPath));
				usertypeDefinition.set("essential", sol::property(
					[](TES3::NPC& self) { return self.actorFlags.test(TES3::ActorFlagNPC::EssentialBit); },
					[](TES3::NPC& self, bool state) { return self.actorFlags.set(TES3::ActorFlagNPC::EssentialBit, state); }
				));
				usertypeDefinition.set("respawns", sol::property(
					[](TES3::NPC& self) { return self.actorFlags.test(TES3::ActorFlagNPC::RespawnBit); },
					[](TES3::NPC& self, bool state) { return self.actorFlags.set(TES3::ActorFlagNPC::RespawnBit, state); }
				));

				// Finish up our usertype.
				state.set_usertype("tes3npc", usertypeDefinition);
			}

			// Binding for TES3::NPCInstance
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::NPCInstance>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
				setUserdataForActor(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("disposition", sol::property([](TES3::NPCInstance& self) { return self.getDisposition(false); }));
				usertypeDefinition.set("baseDisposition", sol::property(&TES3::NPCInstance::getBaseDisposition, &TES3::NPCInstance::setBaseDisposition));
				usertypeDefinition.set("factionIndex", &TES3::NPCInstance::factionIndex);

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("attributes", sol::property([](TES3::NPCInstance& self) { return std::ref(self.baseNPC->attributes); }));
				usertypeDefinition.set("skills", sol::property([](TES3::NPCInstance& self) { return std::ref(self.baseNPC->skills); }));

				// Constants.
				usertypeDefinition.set("isInstance", sol::var(true));

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("baseObject", sol::readonly_property([](TES3::NPCInstance& self) { return makeLuaObject(self.baseNPC); }));
				usertypeDefinition.set("class", sol::readonly_property([](TES3::NPCInstance& self) { return makeLuaObject(self.baseNPC->class_); }));
				usertypeDefinition.set("faction", sol::readonly_property([](TES3::NPCInstance& self) { return makeLuaObject(self.baseNPC->faction); }));
				usertypeDefinition.set("race", sol::readonly_property([](TES3::NPCInstance& self) { return makeLuaObject(self.baseNPC->race); }));
				usertypeDefinition.set("script", sol::readonly_property([](TES3::NPCInstance& self) { return makeLuaObject(self.getScript()); }));

				// Functions exposed as properties.
				usertypeDefinition.set("aiConfig", sol::readonly_property(&TES3::NPCInstance::getAIConfig));
				usertypeDefinition.set("barterGold", sol::property(&TES3::NPCInstance::getBaseBarterGold, &TES3::NPCInstance::setBaseBarterGold));
				usertypeDefinition.set("health", sol::readonly_property(&TES3::NPCInstance::getDurability));
				usertypeDefinition.set("magicka", sol::readonly_property(&TES3::NPCInstance::getMagicka));
				usertypeDefinition.set("fatigue", sol::readonly_property(&TES3::NPCInstance::getFatigue));
				usertypeDefinition.set("isGuard", sol::readonly_property(&TES3::NPCInstance::isGuard));
				usertypeDefinition.set("isEssential", sol::readonly_property(&TES3::NPCInstance::isEssential));
				usertypeDefinition.set("isRespawn", sol::readonly_property(&TES3::NPCInstance::isRespawn));
				usertypeDefinition.set("level", sol::readonly_property(&TES3::NPCInstance::getLevel));
				usertypeDefinition.set("mesh", sol::property(&TES3::NPCInstance::getModelPath, &TES3::NPCInstance::setModelPath));
				usertypeDefinition.set("name", sol::property(&TES3::NPCInstance::getName, &TES3::NPCInstance::setName));
				usertypeDefinition.set("spells", sol::readonly_property([](TES3::NPCInstance& self) { return &self.baseNPC->spellList; }));

				// Easy access to actor flags.
				usertypeDefinition.set("female", sol::property(
					[](TES3::NPCInstance& self) { return self.actorFlags.test(TES3::ActorFlagNPC::FemaleBit); },
					[](TES3::NPCInstance& self, bool state) { return self.actorFlags.set(TES3::ActorFlagNPC::FemaleBit, state); }
				));
				usertypeDefinition.set("autoCalc", sol::property(
					[](TES3::NPCInstance& self) { return self.actorFlags.test(TES3::ActorFlagNPC::AutoCalcBit); },
					[](TES3::NPCInstance& self, bool state) { return self.actorFlags.set(TES3::ActorFlagNPC::AutoCalcBit, state); }
				));

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition.set("model", sol::property(&TES3::NPCInstance::getModelPath, &TES3::NPCInstance::setModelPath));
				usertypeDefinition.set("essential", sol::property(
					[](TES3::NPCInstance& self) { return self.actorFlags.test(TES3::ActorFlagNPC::EssentialBit); },
					[](TES3::NPCInstance& self, bool state) { return self.actorFlags.set(TES3::ActorFlagNPC::EssentialBit, state); }
				));
				usertypeDefinition.set("respawns", sol::property(
					[](TES3::NPCInstance& self) { return self.actorFlags.test(TES3::ActorFlagNPC::Respawn); },
					[](TES3::NPCInstance& self, bool state) { return self.actorFlags.set(TES3::ActorFlagNPC::RespawnBit, state); }
				));

				// Finish up our usertype.
				state.set_usertype("tes3npcInstance", usertypeDefinition);
			}
		}
	}
}
