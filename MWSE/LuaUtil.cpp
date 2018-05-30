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

		TES3::Vector3* getOptionalParamVector3(sol::optional<sol::table> maybeParams, const char* key) {
			if (maybeParams) {
				sol::table params = maybeParams.value();
				sol::object maybeValue = params[key];
				if (maybeValue.valid()) {
					// Were we given a real vector?
					if (maybeValue.is<TES3::Vector3*>()) {
						return maybeValue.as<TES3::Vector3*>();
					}

					// Were we given a table?
					else if (maybeValue.is<sol::table>()) {
						sol::table value = maybeValue.as<sol::table>();
						TES3::Vector3* result = tes3::malloc<TES3::Vector3>();
						result->x = value[1];
						result->y = value[2];
						result->z = value[3];
						return result;
					}
				}
			}

			return NULL;
		}

		sol::object makeLuaObject(TES3::BaseObject* object) {
			if (object == NULL) {
				return sol::nil;
			}

			LuaManager& luaManager = LuaManager::getInstance();

			// Search in cache first.
			sol::object result = luaManager.getCachedUserdata(object);
			if (result != sol::nil) {
				return result;
			}

			sol::state& state = luaManager.getState();

			switch (object->objectType) {
			case TES3::ObjectType::Activator:
				result = sol::make_object(state, reinterpret_cast<TES3::Activator*>(object));
				break;
			case TES3::ObjectType::Alchemy:
				result = sol::make_object(state, reinterpret_cast<TES3::Alchemy*>(object));
				break;
			case TES3::ObjectType::Apparatus:
				result = sol::make_object(state, reinterpret_cast<TES3::Apparatus*>(object));
				break;
			case TES3::ObjectType::Armor:
				result = sol::make_object(state, reinterpret_cast<TES3::Armor*>(object));
				break;
			case TES3::ObjectType::Book:
				result = sol::make_object(state, reinterpret_cast<TES3::Book*>(object));
				break;
			case TES3::ObjectType::Cell:
				result = sol::make_object(state, reinterpret_cast<TES3::Cell*>(object));
				break;
			case TES3::ObjectType::Class:
				result = sol::make_object(state, reinterpret_cast<TES3::Class*>(object));
				break;
			case TES3::ObjectType::Clothing:
				result = sol::make_object(state, reinterpret_cast<TES3::Clothing*>(object));
				break;
			case TES3::ObjectType::Container:
			{
				if (reinterpret_cast<TES3::Actor*>(object)->actorFlags & TES3::ActorFlag::IsBase) {
					result = sol::make_object(state, reinterpret_cast<TES3::Container*>(object));
				}
				else {
					result = sol::make_object(state, reinterpret_cast<TES3::ContainerInstance*>(object));
				}
			}
			break;
			case TES3::ObjectType::Creature:
			{
				if (reinterpret_cast<TES3::Actor*>(object)->actorFlags & TES3::ActorFlag::IsBase) {
					result = sol::make_object(state, reinterpret_cast<TES3::Creature*>(object));
				}
				else {
					result = sol::make_object(state, reinterpret_cast<TES3::CreatureInstance*>(object));
				}
			}
			break;
			case TES3::ObjectType::Door:
				result = sol::make_object(state, reinterpret_cast<TES3::Door*>(object));
				break;
			case TES3::ObjectType::Enchantment:
				result = sol::make_object(state, reinterpret_cast<TES3::Enchantment*>(object));
				break;
			case TES3::ObjectType::Faction:
				result = sol::make_object(state, reinterpret_cast<TES3::Faction*>(object));
				break;
			case TES3::ObjectType::Global:
				result = sol::make_object(state, reinterpret_cast<TES3::GlobalVariable*>(object));
				break;
			case TES3::ObjectType::GameSetting:
				result = sol::make_object(state, reinterpret_cast<TES3::GameSetting*>(object));
				break;
			case TES3::ObjectType::Ingredient:
				result = sol::make_object(state, reinterpret_cast<TES3::Ingredient*>(object));
				break;
			case TES3::ObjectType::Light:
				result = sol::make_object(state, reinterpret_cast<TES3::Light*>(object));
				break;
			case TES3::ObjectType::Lockpick:
				result = sol::make_object(state, reinterpret_cast<TES3::Lockpick*>(object));
				break;
			case TES3::ObjectType::Misc:
				result = sol::make_object(state, reinterpret_cast<TES3::Misc*>(object));
				break;
			case TES3::ObjectType::NPC:
			{
				if (reinterpret_cast<TES3::Actor*>(object)->actorFlags & TES3::ActorFlag::IsBase) {
					result = sol::make_object(state, reinterpret_cast<TES3::NPC*>(object));
				}
				else {
					result = sol::make_object(state, reinterpret_cast<TES3::NPCInstance*>(object));
				}
			}
			break;
			case TES3::ObjectType::Probe:
				result = sol::make_object(state, reinterpret_cast<TES3::Probe*>(object));
				break;
			case TES3::ObjectType::Race:
				result = sol::make_object(state, reinterpret_cast<TES3::Race*>(object));
				break;
			case TES3::ObjectType::Reference:
				result = sol::make_object(state, reinterpret_cast<TES3::Reference*>(object));
				break;
			case TES3::ObjectType::Repair:
				result = sol::make_object(state, reinterpret_cast<TES3::RepairTool*>(object));
				break;
			case TES3::ObjectType::Script:
				result = sol::make_object(state, reinterpret_cast<TES3::Script*>(object));
				break;
			case TES3::ObjectType::Skill:
				result = sol::make_object(state, reinterpret_cast<TES3::Skill*>(object));
				break;
			case TES3::ObjectType::Spell:
				result = sol::make_object(state, reinterpret_cast<TES3::Spell*>(object));
				break;
			case TES3::ObjectType::MagicSourceInstance:
				result = sol::make_object(state, reinterpret_cast<TES3::MagicSourceInstance*>(object));
				break;
			case TES3::ObjectType::Static:
				result = sol::make_object(state, reinterpret_cast<TES3::Static*>(object));
				break;
			case TES3::ObjectType::Ammo:
			case TES3::ObjectType::Weapon:
				result = sol::make_object(state, reinterpret_cast<TES3::Weapon*>(object));
				break;
			}

			// Insert the object into cache.
			if (result != sol::nil) {
				luaManager.insertUserdataIntoCache(object, result);
			}

			return result;
		}

		sol::object makeLuaObject(TES3::MobileObject* object) {
			if (object == NULL) {
				return sol::nil;
			}

			LuaManager& luaManager = LuaManager::getInstance();

			// Search in cache first.
			sol::object result = luaManager.getCachedUserdata(object);
			if (result != sol::nil) {
				return result;
			}

			sol::state& state = luaManager.getState();

			switch ((unsigned int)object->vTable.mobileObject) {
			case TES3_vTable_MobileCreature:
				result = sol::make_object(state, reinterpret_cast<TES3::MobileCreature*>(object));
				break;
			case TES3_vTable_MobileNPC:
				result = sol::make_object(state, reinterpret_cast<TES3::MobileNPC*>(object));
				break;
			case TES3_vTable_MobilePlayer:
				result = sol::make_object(state, reinterpret_cast<TES3::MobilePlayer*>(object));
				break;
			case TES3_vTable_MobileProjectile:
				result = sol::make_object(state, reinterpret_cast<TES3::MobileProjectile*>(object));
				break;
			}

			// Insert the object into cache.
			if (result != sol::nil) {
				luaManager.insertUserdataIntoCache(object, result);
			}

			return result;
		}

		sol::object makeLuaObject(NI::Object* object) {
			if (object == NULL) {
				return sol::nil;
			}

			LuaManager& luaManager = LuaManager::getInstance();

			sol::state& state = luaManager.getState();

			switch ((unsigned int)object->getRunTimeTypeInformation()) {
			case NI::RunTimeTypeInformation::AVObject:
				return sol::make_object(state, reinterpret_cast<NI::AVObject*>(object));
			case NI::RunTimeTypeInformation::Camera:
				return sol::make_object(state, reinterpret_cast<NI::Camera*>(object));
			case NI::RunTimeTypeInformation::Node:
				return sol::make_object(state, reinterpret_cast<NI::Node*>(object));
			case NI::RunTimeTypeInformation::ObjectNET:
				return sol::make_object(state, reinterpret_cast<NI::ObjectNET*>(object));
			case NI::RunTimeTypeInformation::SwitchNode:
				return sol::make_object(state, reinterpret_cast<NI::SwitchNode*>(object));
			}

			if (object->isInstanceOfType(NI::RunTimeTypeInformation::Node)) {
				return sol::make_object(state, reinterpret_cast<NI::Node*>(object));
			}
			else if (object->isInstanceOfType(NI::RunTimeTypeInformation::AVObject)) {
				return sol::make_object(state, reinterpret_cast<NI::AVObject*>(object));
			}
			else if (object->isInstanceOfType(NI::RunTimeTypeInformation::ObjectNET)) {
				return sol::make_object(state, reinterpret_cast<NI::ObjectNET*>(object));
			}

			return sol::make_object(state, object);
		}
	}
}
