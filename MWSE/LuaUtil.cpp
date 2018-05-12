#include "LuaUtil.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

#include "TES3Util.h"
#include "Log.h"

#define TES3_vTable_MobileCreature 0x74AFA4
#define TES3_vTable_MobileNPC 0x74AE6C
#define TES3_vTable_MobilePlayer 0x74B174
#define TES3_vTable_MobileProjectile 0x74b2b4

namespace mwse {
	namespace lua {
		TES3::Script* getOptionalParamExecutionScript(sol::optional<sol::table> maybeParams) {
			if (maybeParams) {
				sol::table params = maybeParams.value();
				sol::object maybeScript = params["_script"];
				if (maybeScript.valid()) {
					if (maybeScript.is<std::string>()) {
						return tes3::getDataHandler()->nonDynamicData->findScriptByName(maybeScript.as<std::string>().c_str());
					}
					else if (maybeScript.is<TES3::Script*>()) {
						return maybeScript.as<TES3::Script*>();
					}
				}
			}

			// Fall back to the currently executing script.
			return LuaManager::getInstance().getCurrentScript();
		}

		TES3::Reference* getOptionalParamExecutionReference(sol::optional<sol::table> maybeParams) {
			TES3::Reference* reference = NULL;

			if (maybeParams) {
				sol::table params = maybeParams.value();
				sol::object maybeScript = params["reference"];
				if (maybeScript.valid()) {
					if (maybeScript.is<std::string>()) {
						reference = tes3::getReference(maybeScript.as<std::string>());
					}
					else if (maybeScript.is<TES3::Reference*>()) {
						reference = maybeScript.as<TES3::Reference*>();
					}
				}
			}

			if (reference == NULL) {
				reference = LuaManager::getInstance().getCurrentReference();
			}

			return reference;
		}

		TES3::Script* getOptionalParamScript(sol::optional<sol::table> maybeParams, const char* key) {
			if (maybeParams) {
				sol::table params = maybeParams.value();
				sol::object maybeValue = params[key];
				if (maybeValue.valid()) {
					if (maybeValue.is<std::string>()) {
						return tes3::getDataHandler()->nonDynamicData->findScriptByName(maybeValue.as<std::string>().c_str());
					}
					else if (maybeValue.is<TES3::Script*>()) {
						return maybeValue.as<TES3::Script*>();
					}
				}
			}

			return NULL;
		}

		TES3::Reference* getOptionalParamReference(sol::optional<sol::table> maybeParams, const char* key) {
			TES3::Reference* value = NULL;

			if (maybeParams) {
				sol::table params = maybeParams.value();
				sol::object maybeValue = params[key];
				if (maybeValue.valid()) {
					if (maybeValue.is<std::string>()) {
						value = tes3::getReference(maybeValue.as<std::string>());
					}
					else if (maybeValue.is<TES3::Reference*>()) {
						value = maybeValue.as<TES3::Reference*>();
					}
				}
			}

			return value;
		}

		TES3::Spell* getOptionalParamSpell(sol::optional<sol::table> maybeParams, const char* key) {
			TES3::Spell* value = NULL;

			if (maybeParams) {
				sol::table params = maybeParams.value();
				sol::object maybeValue = params[key];
				if (maybeValue.valid()) {
					if (maybeValue.is<std::string>()) {
						value = tes3::getSpellById(maybeValue.as<std::string>().c_str());
					}
					else if (maybeValue.is<TES3::Spell*>()) {
						value = maybeValue.as<TES3::Spell*>();
					}
				}
			}

			return value;
		}

		TES3::DialogueInfo* getOptionalParamTopic(sol::optional<sol::table> maybeParams, const char* key) {
			TES3::DialogueInfo* value = NULL;

			if (maybeParams) {
				sol::table params = maybeParams.value();
				sol::object maybeValue = params[key];
				if (maybeValue.valid()) {
					if (maybeValue.is<std::string>()) {
						value = tes3::getDataHandler()->nonDynamicData->findDialogInfo(maybeValue.as<std::string>().c_str());
					}
					else if (maybeValue.is<TES3::DialogueInfo*>()) {
						value = maybeValue.as<TES3::DialogueInfo*>();
					}
				}
			}

			return value;
		}

		TES3::Sound* getOptionalParamSound(sol::optional<sol::table> maybeParams, const char* key) {
			TES3::Sound* value = NULL;

			if (maybeParams) {
				sol::table params = maybeParams.value();
				sol::object maybeValue = params[key];
				if (maybeValue.valid()) {
					if (maybeValue.is<std::string>()) {
						value = tes3::getDataHandler()->nonDynamicData->findSound(maybeValue.as<std::string>().c_str());
					}
					else if (maybeValue.is<TES3::Sound*>()) {
						value = maybeValue.as<TES3::Sound*>();
					}
				}
			}

			return value;
		}

		sol::object makeLuaObject(TES3::BaseObject* object) {
			if (object == NULL) {
				return sol::nil;
			}

			sol::state& state = LuaManager::getInstance().getState();

			switch (object->objectType) {
			case TES3::ObjectType::Activator:
				return sol::make_object(state, reinterpret_cast<TES3::Activator*>(object));
			case TES3::ObjectType::Alchemy:
				return sol::make_object(state, reinterpret_cast<TES3::Alchemy*>(object));
			case TES3::ObjectType::Apparatus:
				return sol::make_object(state, reinterpret_cast<TES3::Apparatus*>(object));
			case TES3::ObjectType::Armor:
				return sol::make_object(state, reinterpret_cast<TES3::Armor*>(object));
			case TES3::ObjectType::Book:
				return sol::make_object(state, reinterpret_cast<TES3::Book*>(object));
			case TES3::ObjectType::Cell:
				return sol::make_object(state, reinterpret_cast<TES3::Cell*>(object));
			case TES3::ObjectType::Class:
				return sol::make_object(state, reinterpret_cast<TES3::Class*>(object));
			case TES3::ObjectType::Clothing:
				return sol::make_object(state, reinterpret_cast<TES3::Clothing*>(object));
			case TES3::ObjectType::Container:
				if (reinterpret_cast<TES3::Actor*>(object)->actorFlags & TES3::ActorFlag::IsBase) {
					return sol::make_object(state, reinterpret_cast<TES3::Container*>(object));
				}
				else {
					return sol::make_object(state, reinterpret_cast<TES3::ContainerInstance*>(object));
				}
			case TES3::ObjectType::Creature:
				if (reinterpret_cast<TES3::Actor*>(object)->actorFlags & TES3::ActorFlag::IsBase) {
					return sol::make_object(state, reinterpret_cast<TES3::Creature*>(object));
				}
				else {
					return sol::make_object(state, reinterpret_cast<TES3::CreatureInstance*>(object));
				}
			case TES3::ObjectType::Door:
				return sol::make_object(state, reinterpret_cast<TES3::Door*>(object));
			case TES3::ObjectType::Enchantment:
				return sol::make_object(state, reinterpret_cast<TES3::Enchantment*>(object));
			case TES3::ObjectType::Faction:
				return sol::make_object(state, reinterpret_cast<TES3::Faction*>(object));
			case TES3::ObjectType::Global:
				return sol::make_object(state, reinterpret_cast<TES3::GlobalVariable*>(object));
			case TES3::ObjectType::GameSetting:
				return sol::make_object(state, reinterpret_cast<TES3::GameSetting*>(object));
			case TES3::ObjectType::Ingredient:
				return sol::make_object(state, reinterpret_cast<TES3::Ingredient*>(object));
			case TES3::ObjectType::Light:
				return sol::make_object(state, reinterpret_cast<TES3::Light*>(object));
			case TES3::ObjectType::Lockpick:
				return sol::make_object(state, reinterpret_cast<TES3::Lockpick*>(object));
			case TES3::ObjectType::Misc:
				return sol::make_object(state, reinterpret_cast<TES3::Misc*>(object));
			case TES3::ObjectType::NPC:
				if (reinterpret_cast<TES3::Actor*>(object)->actorFlags & TES3::ActorFlag::IsBase) {
					return sol::make_object(state, reinterpret_cast<TES3::NPC*>(object));
				}
				else {
					return sol::make_object(state, reinterpret_cast<TES3::NPCInstance*>(object));
				}
			case TES3::ObjectType::Probe:
				return sol::make_object(state, reinterpret_cast<TES3::Probe*>(object));
			case TES3::ObjectType::Race:
				return sol::make_object(state, reinterpret_cast<TES3::Race*>(object));
			case TES3::ObjectType::Reference:
				return sol::make_object(state, reinterpret_cast<TES3::Reference*>(object));
			case TES3::ObjectType::Repair:
				return sol::make_object(state, reinterpret_cast<TES3::RepairTool*>(object));
			case TES3::ObjectType::Script:
				return sol::make_object(state, reinterpret_cast<TES3::Script*>(object));
			case TES3::ObjectType::Skill:
				return sol::make_object(state, reinterpret_cast<TES3::Skill*>(object));
			case TES3::ObjectType::Spell:
				return sol::make_object(state, reinterpret_cast<TES3::Spell*>(object));
			case TES3::ObjectType::Static:
				return sol::make_object(state, reinterpret_cast<TES3::Static*>(object));
			case TES3::ObjectType::Ammo:
			case TES3::ObjectType::Weapon:
				return sol::make_object(state, reinterpret_cast<TES3::Weapon*>(object));
			}

			return sol::make_object(state, object);
		}

		sol::object makeLuaObject(TES3::MobileObject* object) {
			if (object == NULL) {
				return sol::nil;
			}

			sol::state& state = LuaManager::getInstance().getState();

			unsigned int vTable = (unsigned int)object->vTable.mobileObject;
			switch (vTable) {
			case TES3_vTable_MobileCreature:
				return sol::make_object(state, reinterpret_cast<TES3::MobileCreature*>(object));
			case TES3_vTable_MobileNPC:
				return sol::make_object(state, reinterpret_cast<TES3::MobileNPC*>(object));
			case TES3_vTable_MobilePlayer:
				return sol::make_object(state, reinterpret_cast<TES3::MobilePlayer*>(object));
			case TES3_vTable_MobileProjectile:
				return sol::make_object(state, reinterpret_cast<TES3::MobileProjectile*>(object));
			}

			return sol::make_object(state, object);
		}

		namespace event {
			sol::object trigger(const char* eventType, sol::table eventData) {
				sol::state& state = LuaManager::getInstance().getState();

				// Trigger the function, check for lua errors.
				sol::protected_function trigger = state["event"]["trigger"];
				auto result = trigger(eventType, eventData);
				if (!result.valid()) {
					sol::error error = result;
					log::getLog() << "Lua error encountered when raising " << eventType << " event:" << std::endl << error.what() << std::endl;
				}

				return result;
			}
		}
	}
}
