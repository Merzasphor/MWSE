#include "TES3NPCLua.h"

#include "LuaManager.h"
#include "TES3ActorLua.h"

#include "TES3NPC.h"
#include "TES3BodyPart.h"
#include "TES3Race.h"
#include "TES3Class.h"
#include "TES3Faction.h"
#include "TES3Script.h"

#include "BitUtil.h"

namespace mwse {
	namespace lua {
		void bindTES3NPC() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::NPC
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::NPC>("tes3npc");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>();
				setUserdataForActor(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["baseDisposition"] = &TES3::NPC::baseDisposition;
				usertypeDefinition["factionIndex"] = &TES3::NPC::factionIndex;
				usertypeDefinition["factionRank"] = &TES3::NPC::factionRank;
				usertypeDefinition["fatigue"] = &TES3::NPC::fatigue;
				usertypeDefinition["hair"] = &TES3::NPC::hair;
				usertypeDefinition["head"] = &TES3::NPC::head;
				usertypeDefinition["health"] = &TES3::NPC::health;
				usertypeDefinition["level"] = &TES3::NPC::level;
				usertypeDefinition["magicka"] = &TES3::NPC::magicka;
				usertypeDefinition["reputation"] = &TES3::NPC::reputation;

				// Indirect bindings to unions and arrays.
				usertypeDefinition["attributes"] = sol::property([](TES3::NPC& self) { return std::ref(self.attributes); });
				usertypeDefinition["skills"] = sol::property([](TES3::NPC& self) { return std::ref(self.skills); });

				// Constants.
				usertypeDefinition["isInstance"] = sol::var(false);

				// Access to other objects that need to be packaged.
				usertypeDefinition["class"] = sol::readonly_property([](TES3::NPC& self) { return makeLuaObject(self.class_); });
				usertypeDefinition["faction"] = sol::readonly_property([](TES3::NPC& self) { return makeLuaObject(self.faction); });
				usertypeDefinition["race"] = sol::readonly_property([](TES3::NPC& self) { return makeLuaObject(self.race); });
				usertypeDefinition["script"] = sol::readonly_property([](TES3::NPC& self) { return makeLuaObject(self.getScript()); });

				// Functions exposed as properties.
				usertypeDefinition["aiConfig"] = sol::readonly_property(&TES3::NPC::getAIConfig);
				usertypeDefinition["isGuard"] = sol::readonly_property(&TES3::NPC::isGuard);
				usertypeDefinition["isEssential"] = sol::readonly_property(&TES3::NPC::isEssential);
				usertypeDefinition["isRespawn"] = sol::readonly_property(&TES3::NPC::isRespawn);
				usertypeDefinition["mesh"] = sol::property(&TES3::NPC::getModelPath, &TES3::NPC::setModelPath);
				usertypeDefinition["name"] = sol::property(&TES3::NPC::getName, &TES3::NPC::setName);
				usertypeDefinition["spells"] = sol::readonly_property([](TES3::NPC& self) { return &self.spellList; });

				// Easy access to actor flags.
				usertypeDefinition["female"] = sol::property(
					[](TES3::NPC& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagNPC::FemaleBit); },
					[](TES3::NPC& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagNPC::FemaleBit, state); }
				);
				usertypeDefinition["autoCalc"] = sol::property(
					[](TES3::NPC& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagNPC::AutoCalcBit); },
					[](TES3::NPC& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagNPC::AutoCalcBit, state); }
				);

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition["model"] = sol::property(&TES3::NPC::getModelPath, &TES3::NPC::setModelPath);
				usertypeDefinition["essential"] = sol::property(
					[](TES3::NPC& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagNPC::EssentialBit); },
					[](TES3::NPC& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagNPC::EssentialBit, state); }
				);
				usertypeDefinition["respawns"] = sol::property(
					[](TES3::NPC& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagNPC::RespawnBit); },
					[](TES3::NPC& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagNPC::RespawnBit, state); }
				);
			}

			// Binding for TES3::NPCInstance
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::NPCInstance>("tes3npcInstance");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>();
				setUserdataForActor(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["disposition"] = sol::property([](TES3::NPCInstance& self) { return self.getDisposition(false); });
				usertypeDefinition["baseDisposition"] = sol::property(&TES3::NPCInstance::getBaseDisposition, &TES3::NPCInstance::setBaseDisposition);
				usertypeDefinition["factionIndex"] = &TES3::NPCInstance::factionIndex;

				// Indirect bindings to unions and arrays.
				usertypeDefinition["attributes"] = sol::property([](TES3::NPCInstance& self) { return std::ref(self.baseNPC->attributes); });
				usertypeDefinition["skills"] = sol::property([](TES3::NPCInstance& self) { return std::ref(self.baseNPC->skills); });

				// Constants.
				usertypeDefinition["isInstance"] = sol::var(true);

				// Access to other objects that need to be packaged.
				usertypeDefinition["baseObject"] = sol::readonly_property([](TES3::NPCInstance& self) { return makeLuaObject(self.baseNPC); });
				usertypeDefinition["class"] = sol::readonly_property([](TES3::NPCInstance& self) { return makeLuaObject(self.baseNPC->class_); });
				usertypeDefinition["faction"] = sol::readonly_property([](TES3::NPCInstance& self) { return makeLuaObject(self.baseNPC->faction); });
				usertypeDefinition["race"] = sol::readonly_property([](TES3::NPCInstance& self) { return makeLuaObject(self.baseNPC->race); });
				usertypeDefinition["script"] = sol::readonly_property([](TES3::NPCInstance& self) { return makeLuaObject(self.getScript()); });

				// Functions exposed as properties.
				usertypeDefinition["aiConfig"] = sol::readonly_property(&TES3::NPCInstance::getAIConfig);
				usertypeDefinition["barterGold"] = sol::property(&TES3::NPCInstance::getBaseBarterGold, &TES3::NPCInstance::setBaseBarterGold);
				usertypeDefinition["health"] = sol::readonly_property(&TES3::NPCInstance::getDurability);
				usertypeDefinition["magicka"] = sol::readonly_property(&TES3::NPCInstance::getMagicka);
				usertypeDefinition["fatigue"] = sol::readonly_property(&TES3::NPCInstance::getFatigue);
				usertypeDefinition["isGuard"] = sol::readonly_property(&TES3::NPCInstance::isGuard);
				usertypeDefinition["isEssential"] = sol::readonly_property(&TES3::NPCInstance::isEssential);
				usertypeDefinition["isRespawn"] = sol::readonly_property(&TES3::NPCInstance::isRespawn);
				usertypeDefinition["level"] = sol::readonly_property(&TES3::NPCInstance::getLevel);
				usertypeDefinition["mesh"] = sol::property(&TES3::NPCInstance::getModelPath, &TES3::NPCInstance::setModelPath);
				usertypeDefinition["name"] = sol::property(&TES3::NPCInstance::getName, &TES3::NPCInstance::setName);
				usertypeDefinition["spells"] = sol::readonly_property([](TES3::NPCInstance& self) { return &self.baseNPC->spellList; });

				// Easy access to actor flags.
				usertypeDefinition["female"] = sol::property(
					[](TES3::NPCInstance& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagNPC::FemaleBit); },
					[](TES3::NPCInstance& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagNPC::FemaleBit, state); }
				);
				usertypeDefinition["autoCalc"] = sol::property(
					[](TES3::NPCInstance& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagNPC::AutoCalcBit); },
					[](TES3::NPCInstance& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagNPC::AutoCalcBit, state); }
				);

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition["model"] = sol::property(&TES3::NPCInstance::getModelPath, &TES3::NPCInstance::setModelPath);
				usertypeDefinition["essential"] = sol::property(
					[](TES3::NPCInstance& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagNPC::EssentialBit); },
					[](TES3::NPCInstance& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagNPC::EssentialBit, state); }
				);
				usertypeDefinition["respawns"] = sol::property(
					[](TES3::NPCInstance& self) { return BIT_TEST(self.actorFlags, TES3::ActorFlagNPC::RespawnBit); },
					[](TES3::NPCInstance& self, bool state) { BIT_SET(self.actorFlags, TES3::ActorFlagNPC::RespawnBit, state); }
				);
			}
		}
	}
}
