#include "TES3Object.h"

#include "TES3Util.h"

#include "TES3Activator.h"
#include "TES3Alchemy.h"
#include "TES3AnimationGroup.h"
#include "TES3Apparatus.h"
#include "TES3Armor.h"
#include "TES3BodyPart.h"
#include "TES3Book.h"
#include "TES3Cell.h"
#include "TES3Class.h"
#include "TES3Clothing.h"
#include "TES3Container.h"
#include "TES3Creature.h"
#include "TES3Dialogue.h"
#include "TES3DialogueInfo.h"
#include "TES3Door.h"
#include "TES3Enchantment.h"
#include "TES3Faction.h"
#include "TES3GameSetting.h"
#include "TES3GlobalVariable.h"
#include "TES3Ingredient.h"
#include "TES3Land.h"
#include "TES3LeveledList.h"
#include "TES3Light.h"
#include "TES3Lockpick.h"
#include "TES3MagicEffect.h"
#include "TES3MagicSourceInstance.h"
#include "TES3Misc.h"
#include "TES3NPC.h"
#include "TES3Probe.h"
#include "TES3Quest.h"
#include "TES3Race.h"
#include "TES3Reference.h"
#include "TES3Region.h"
#include "TES3RepairTool.h"
#include "TES3Script.h"
#include "TES3Skill.h"
#include "TES3Sound.h"
#include "TES3SoundGenerator.h"
#include "TES3Spell.h"
#include "TES3Static.h"
#include "TES3Weapon.h"

#include "MemoryUtil.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaObjectInvalidatedEvent.h"

namespace TES3 {
	void * BaseObject::operator new(size_t size) {
		return mwse::tes3::_new(size);
	}

	void BaseObject::operator delete(void * address) {
		mwse::tes3::_delete(address);
	}

	const auto BaseObject_dtor = reinterpret_cast<TES3::BaseObject * (__thiscall*)(TES3::BaseObject*)>(0x4F0CA0);
	void BaseObject::dtor() {
		clearCachedLuaObject(this);
		BaseObject_dtor(this);
	}

	bool BaseObject::getObjectModified() {
		return (objectFlags & TES3::ObjectFlag::Modified);
	}

	void BaseObject::setObjectModified(bool modified) {
		vTable.base->setObjectModified(this, modified);
	}

	char* BaseObject::getObjectID() {
		return vTable.base->getObjectID(this);
	}

	BaseObject * BaseObject::getBaseObject() {
		BaseObject * object = this;

		if (object->objectType == ObjectType::Reference) {
			object = static_cast<Reference*>(object)->baseObject;
		}

		if (object->isActor() && static_cast<Actor*>(object)->isClone()) {
			object = static_cast<Actor*>(object)->getBaseActor();
		}

		return object;
	}

	bool BaseObject::isActor() {
		switch (objectType) {
		case TES3::ObjectType::Container:
		case TES3::ObjectType::Creature:
		case TES3::ObjectType::NPC:
			return true;
		default:
			return false;
		}
	}

	std::unordered_set<BaseObject*> sourcelessObjects;

	const auto TES3_isSourcelessObject = reinterpret_cast<bool(__stdcall*)(BaseObject*)>(0x4C1980);
	bool __stdcall BaseObject::isSourcelessObject(BaseObject* object) {
		return TES3_isSourcelessObject(object) || sourcelessObjects.find(object) != sourcelessObjects.end();
	}

	void BaseObject::setSourcelessObject(BaseObject* object) {
		sourcelessObjects.insert(object);
	}

	static std::unordered_map<const BaseObject*, sol::object> baseObjectCache;
	static std::mutex baseObjectCacheMutex;

	sol::object BaseObject::getOrCreateLuaObject(lua_State* L, const BaseObject* object) {
		if (object == nullptr) {
			return sol::nil;
		}

		baseObjectCacheMutex.lock();

		auto cacheHit = baseObjectCache.find(object);
		if (cacheHit != baseObjectCache.end()) {
			auto result = cacheHit->second;
			baseObjectCacheMutex.unlock();
			return result;
		}

		sol::object ref = sol::nil;
		switch ((uint32_t)object->vTable.object) {
		case TES3::VirtualTableAddress::Activator:
			ref = sol::make_object(L, static_cast<const TES3::Activator*>(object));
			break;
		case TES3::VirtualTableAddress::Alchemy:
			ref = sol::make_object(L, static_cast<const TES3::Alchemy*>(object));
			break;
		case TES3::VirtualTableAddress::AnimationGroup:
			ref = sol::make_object(L, static_cast<const TES3::AnimationGroup*>(object));
			break;
		case TES3::VirtualTableAddress::Apparatus:
			ref = sol::make_object(L, static_cast<const TES3::Apparatus*>(object));
			break;
		case TES3::VirtualTableAddress::Armor:
			ref = sol::make_object(L, static_cast<const TES3::Armor*>(object));
			break;
		case TES3::VirtualTableAddress::BodyPart:
			ref = sol::make_object(L, static_cast<const TES3::BodyPart*>(object));
			break;
		case TES3::VirtualTableAddress::Book:
			ref = sol::make_object(L, static_cast<const TES3::Book*>(object));
			break;
		case TES3::VirtualTableAddress::Cell:
			ref = sol::make_object(L, static_cast<const TES3::Cell*>(object));
			break;
		case TES3::VirtualTableAddress::Class:
			ref = sol::make_object(L, static_cast<const TES3::Class*>(object));
			break;
		case TES3::VirtualTableAddress::Clothing:
			ref = sol::make_object(L, static_cast<const TES3::Clothing*>(object));
			break;
		case TES3::VirtualTableAddress::ContainerBase:
			ref = sol::make_object(L, static_cast<const TES3::Container*>(object));
			break;
		case TES3::VirtualTableAddress::ContainerInstance:
			ref = sol::make_object(L, static_cast<const TES3::ContainerInstance*>(object));
			break;
		case TES3::VirtualTableAddress::CreatureBase:
			ref = sol::make_object(L, static_cast<const TES3::Creature*>(object));
			break;
		case TES3::VirtualTableAddress::CreatureInstance:
			ref = sol::make_object(L, static_cast<const TES3::CreatureInstance*>(object));
			break;
		case TES3::VirtualTableAddress::Dialogue:
			ref = sol::make_object(L, static_cast<const TES3::Dialogue*>(object));
			break;
		case TES3::VirtualTableAddress::DialogueInfo:
			ref = sol::make_object(L, static_cast<const TES3::DialogueInfo*>(object));
			break;
		case TES3::VirtualTableAddress::Door:
			ref = sol::make_object(L, static_cast<const TES3::Door*>(object));
			break;
		case TES3::VirtualTableAddress::Enchantment:
			ref = sol::make_object(L, static_cast<const TES3::Enchantment*>(object));
			break;
		case TES3::VirtualTableAddress::Faction:
			ref = sol::make_object(L, static_cast<const TES3::Faction*>(object));
			break;
		case TES3::VirtualTableAddress::GlobalVariable:
			ref = sol::make_object(L, static_cast<const TES3::GlobalVariable*>(object));
			break;
		case TES3::VirtualTableAddress::GameSetting:
			ref = sol::make_object(L, static_cast<const TES3::GameSetting*>(object));
			break;
		case TES3::VirtualTableAddress::Ingredient:
			ref = sol::make_object(L, static_cast<const TES3::Ingredient*>(object));
			break;
		case TES3::VirtualTableAddress::Land:
			ref = sol::make_object(L, static_cast<const TES3::Land*>(object));
			break;
		case TES3::VirtualTableAddress::LeveledCreature:
			ref = sol::make_object(L, static_cast<const TES3::LeveledCreature*>(object));
			break;
		case TES3::VirtualTableAddress::LeveledItem:
			ref = sol::make_object(L, static_cast<const TES3::LeveledItem*>(object));
			break;
		case TES3::VirtualTableAddress::Light:
			ref = sol::make_object(L, static_cast<const TES3::Light*>(object));
			break;
		case TES3::VirtualTableAddress::Lockpick:
			ref = sol::make_object(L, static_cast<const TES3::Lockpick*>(object));
			break;
		case TES3::VirtualTableAddress::MagicEffect:
			ref = sol::make_object(L, static_cast<const TES3::MagicEffect*>(object));
			break;
		case TES3::VirtualTableAddress::Miscellaneous:
			ref = sol::make_object(L, static_cast<const TES3::Misc*>(object));
			break;
		case TES3::VirtualTableAddress::NPCBase:
			ref = sol::make_object(L, static_cast<const TES3::NPC*>(object));
			break;
		case TES3::VirtualTableAddress::NPCInstance:
			ref = sol::make_object(L, static_cast<const TES3::NPCInstance*>(object));
			break;
		case TES3::VirtualTableAddress::Probe:
			ref = sol::make_object(L, static_cast<const TES3::Probe*>(object));
			break;
		case TES3::VirtualTableAddress::Quest:
			ref = sol::make_object(L, static_cast<const TES3::Quest*>(object));
			break;
		case TES3::VirtualTableAddress::Race:
			ref = sol::make_object(L, static_cast<const TES3::Race*>(object));
			break;
		case TES3::VirtualTableAddress::Reference:
			ref = sol::make_object(L, static_cast<const TES3::Reference*>(object));
			break;
		case TES3::VirtualTableAddress::Region:
			ref = sol::make_object(L, static_cast<const TES3::Region*>(object));
			break;
		case TES3::VirtualTableAddress::RepairTool:
			ref = sol::make_object(L, static_cast<const TES3::RepairTool*>(object));
			break;
		case TES3::VirtualTableAddress::Script:
			ref = sol::make_object(L, static_cast<const TES3::Script*>(object));
			break;
		case TES3::VirtualTableAddress::Skill:
			ref = sol::make_object(L, static_cast<const TES3::Skill*>(object));
			break;
		case TES3::VirtualTableAddress::Sound:
			ref = sol::make_object(L, static_cast<const TES3::Sound*>(object));
			break;
		case TES3::VirtualTableAddress::SoundGenerator:
			ref = sol::make_object(L, static_cast<const TES3::SoundGenerator*>(object));
			break;
		case TES3::VirtualTableAddress::Spell:
			ref = sol::make_object(L, static_cast<const TES3::Spell*>(object));
			break;
		case TES3::VirtualTableAddress::MagicSourceInstance:
			ref = sol::make_object(L, static_cast<const TES3::MagicSourceInstance*>(object));
			break;
		case TES3::VirtualTableAddress::Static:
			ref = sol::make_object(L, static_cast<const TES3::Static*>(object));
			break;
		case TES3::VirtualTableAddress::Weapon:
			ref = sol::make_object(L, static_cast<const TES3::Weapon*>(object));
			break;
		default:
			ref = sol::make_object(L, object);
			break;
		}

		if (ref != sol::nil) {
			baseObjectCache[object] = ref;
		}

		baseObjectCacheMutex.unlock();

		return ref;
	}

	int BaseObject::pushCachedLuaObject(lua_State* L, const BaseObject* object) {
		return getOrCreateLuaObject(L, object).push(L);
	}

	void BaseObject::clearCachedLuaObject(const BaseObject* object) {
		if (!baseObjectCache.empty()) {
			baseObjectCacheMutex.lock();

			// Clear any events that make use of this object.
			auto it = baseObjectCache.find(object);
			if (it != baseObjectCache.end()) {
				// Let people know that this object is invalidated.
				mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::ObjectInvalidatedEvent(it->second));

				// Clear any events that make use of this object.
				mwse::lua::event::clearObjectFilter(it->second);

				// Remove it from the cache.
				baseObjectCache.erase(it);
			}

			baseObjectCacheMutex.unlock();
		}
	}

	void BaseObject::clearCachedLuaObjects() {
		baseObjectCacheMutex.lock();
		baseObjectCache.clear();
		baseObjectCacheMutex.unlock();
	}

	void Object::setID(const char* id) {
		vTable.object->setID(this, id);
	}

	char* Object::getName() {
		return vTable.object->getName(this);
	}

	char* Object::getIconPath() {
		return vTable.object->getIconPath(this);
	}

	char* Object::getModelPath() {
		return vTable.object->getModelPath(this);
	}

	Script* Object::getScript() {
		return vTable.object->getScript(this);
	}

	Sound* Object::getSound() {
		return vTable.object->getSound(this);
	}

	char* Object::getRaceID() {
		return vTable.object->getRaceID(this);
	}

	char* Object::getClassID() {
		return vTable.object->getClassID(this);
	}

	char* Object::getBirthsignID() {
		return vTable.object->getBirthsignID(this);
	}

	Race* Object::getRace() {
		return vTable.object->getRace(this);
	}

	Class* Object::getClass() {
		return vTable.object->getClass(this);
	}

	Faction* Object::getFaction() {
		return vTable.object->getFaction(this);
	}

	bool Object::isFemale() {
		return vTable.object->isFemale(this);
	}

	int Object::getFactionRank() {
		return vTable.object->getFactionRank(this);
	}

	int Object::getLevel() {
		return vTable.object->getLevel(this);
	}

	void Object::setDispositionRaw(signed char value) {
		return vTable.object->setDispositionRaw(this, value);
	}

	int Object::modDisposition(signed int value) {
		return vTable.object->modDisposition(this, value);
	}

	int Object::getFactionIndex() {
		return vTable.object->getFactionIndex(this);
	}

	signed char Object::setFactionIndex(signed char index) {
		return vTable.object->setFactionIndex(this, index);
	}

	int Object::getDispositionRaw() {
		return vTable.object->getDispositionRaw(this);
	}

	signed char Object::modFactionIndex(signed char value) {
		return vTable.object->modFactionIndex(this, value);
	}

	int Object::getType() {
		return vTable.object->getType(this);
	}

	char* Object::getTypeName() {
		return vTable.object->getTypeName(this);
	}

	float Object::getWeight() {
		return vTable.object->getWeight(this);
	}

	int Object::getValue() {
		return vTable.object->getValue(this);
	}

	void Object::setDurability(int value) {
		return vTable.object->setDurability(this, value);
	}

	int Object::getDurability() {
		return vTable.object->getDurability(this);
	}

	int Object::getMagicka() {
		return vTable.object->getMagicka(this);
	}

	int Object::getFatigue() {
		return vTable.object->getFatigue(this);
	}

	float Object::getQuality() {
		return vTable.object->getQuality(this);
	}

	bool Object::isLeftPartOfPair() {
		return vTable.object->isLeftPartOfPair(this);
	}

	bool Object::isEssential() {
		return vTable.object->isEssential(this);
	}

	bool Object::isRespawn() {
		return vTable.object->isRespawn(this);
	}

	int Object::getUses() {
		return vTable.object->getUses(this);
	}

	Enchantment* Object::getEnchantment() {
		return vTable.object->getEnchantment(this);
	}

	Enchantment* Object::setEnchantment(Enchantment* enchantment) {
		return vTable.object->setEnchantment(this, enchantment);
	}

	AIConfig* Object::getAIConfig() {
		return vTable.object->getAIConfig(this);
	}

	bool Object::getAutoCalc() {
		return vTable.object->getAutoCalc(this);
	}

	void Object::setAutoCalc(bool value) {
		vTable.object->setAutoCalc(this, value);
	}

	void Object::setModelPath(const char* path) {
		vTable.object->setModelPath(this, path);
	}

	void Object::setName(const char* name) {
		vTable.object->setName(this, name);
	}

	void Object::reevaluateEquipment() {
		vTable.object->reevaluateEquipment(this);
	}

	void Object::resetVisualNode(NI::Node* node) {
		vTable.object->resetVisualNode(this, node);
	}

	float Object::getScale() {
		return vTable.object->getScale(this);
	}

	void Object::setScale(float value, bool cap) {
		vTable.object->setScale(this, value, cap);
	}

	NI::Node * Object::getSceneGraphNode() {
		return vTable.object->getSceneGraphNode(this);
	}

	Object * Object::skipDeletedObjects() {
		TES3::Object * object = this;
		while (object && (object->objectFlags & TES3::ObjectFlag::Delete) == TES3::ObjectFlag::Delete)
		{
			object = object->nextInCollection;
		}
		return object;
	}

	//
	// PhysicalObject
	//

	Iterator<BaseObject> * PhysicalObject::getStolenList() {
		return vTable.physical->getStolenList(this);
	}

	const auto TES3_PhysicalObject_addStolenFlag = reinterpret_cast<void(__thiscall*)(PhysicalObject*, BaseObject*)>(0x4EFEE0);
	void PhysicalObject::addStolenFlag(BaseObject* stolenFrom) {
		TES3_PhysicalObject_addStolenFlag(this, stolenFrom);
	}

	const auto TES3_PhysicalObject_removeStolenFlag = reinterpret_cast<void(__thiscall*)(PhysicalObject*, BaseObject*)>(0x4EFF10);
	void PhysicalObject::removeStolenFlag(BaseObject* stolenFrom) {
		TES3_PhysicalObject_removeStolenFlag(this, stolenFrom);
	}

	const auto TES3_PhysicalObject_getStolenFlag = reinterpret_cast<bool(__thiscall*)(PhysicalObject*, BaseObject*)>(0x4EFEB0);
	bool PhysicalObject::getStolenFlag(BaseObject* stolenFrom) {
		return TES3_PhysicalObject_getStolenFlag(this, stolenFrom);
	}
}

MWSE_SOL_CACHE_TYPE_BODY(TES3::Activator);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Actor);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Alchemy);
MWSE_SOL_CACHE_TYPE_BODY(TES3::AnimationGroup);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Apparatus);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Armor);
MWSE_SOL_CACHE_TYPE_BODY(TES3::BaseObject);
MWSE_SOL_CACHE_TYPE_BODY(TES3::BodyPart);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Book);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Cell);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Class);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Clothing);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Container);
MWSE_SOL_CACHE_TYPE_BODY(TES3::ContainerInstance);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Creature);
MWSE_SOL_CACHE_TYPE_BODY(TES3::CreatureInstance);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Dialogue);
MWSE_SOL_CACHE_TYPE_BODY(TES3::DialogueInfo);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Door);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Enchantment);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Faction);
MWSE_SOL_CACHE_TYPE_BODY(TES3::GameSetting);
MWSE_SOL_CACHE_TYPE_BODY(TES3::GlobalVariable);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Ingredient);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Item);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Land);
MWSE_SOL_CACHE_TYPE_BODY(TES3::LeveledCreature);
MWSE_SOL_CACHE_TYPE_BODY(TES3::LeveledItem);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Light);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Lockpick);
MWSE_SOL_CACHE_TYPE_BODY(TES3::MagicEffect);
MWSE_SOL_CACHE_TYPE_BODY(TES3::MagicSourceInstance);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Misc);
MWSE_SOL_CACHE_TYPE_BODY(TES3::NPC);
MWSE_SOL_CACHE_TYPE_BODY(TES3::NPCBase);
MWSE_SOL_CACHE_TYPE_BODY(TES3::NPCInstance);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Object);
MWSE_SOL_CACHE_TYPE_BODY(TES3::PhysicalObject);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Probe);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Quest);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Race);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Reference);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Region);
MWSE_SOL_CACHE_TYPE_BODY(TES3::RepairTool);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Script);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Skill);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Sound);
MWSE_SOL_CACHE_TYPE_BODY(TES3::SoundGenerator);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Spell);
MWSE_SOL_CACHE_TYPE_BODY(TES3::StartScript);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Static);
MWSE_SOL_CACHE_TYPE_BODY(TES3::Weapon);

