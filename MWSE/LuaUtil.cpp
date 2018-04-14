#include "LuaUtil.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
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
			case TES3::ObjectType::Ammo:
			case TES3::ObjectType::Weapon:
				return sol::make_object(state, reinterpret_cast<TES3::Weapon*>(object));
			}

			return sol::nil;
		}

		sol::object makeLuaObject(TES3::MobileActor* actor) {
			sol::state& state = LuaManager::getInstance().getState();

			switch (actor->objectType) {
			case TES3::ObjectType::MobileCreature:
				return sol::make_object(state, reinterpret_cast<TES3::MobileCreature*>(actor));
			case TES3::ObjectType::MobileNPC:
				return sol::make_object(state, reinterpret_cast<TES3::MobileNPC*>(actor));
			case TES3::ObjectType::MobilePlayer:
				return sol::make_object(state, reinterpret_cast<TES3::MobilePlayer*>(actor));
			}

			return sol::nil;
		}
	}
}
