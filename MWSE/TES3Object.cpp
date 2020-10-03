#include "TES3Object.h"

#include "TES3Util.h"

#include "TES3Activator.h"
#include "TES3Alchemy.h"
#include "TES3AnimationGroup.h"
#include "TES3Apparatus.h"
#include "TES3Armor.h"
#include "TES3Birthsign.h"
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
#include "TES3GameFile.h"
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

#include "BitUtil.h"
#include "MemoryUtil.h"

#include "LuaManager.h"
#include "LuaObjectInvalidatedEvent.h"

#include "Log.h"

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

	bool BaseObject::getObjectModified() const {
		return (objectFlags & TES3::ObjectFlag::Modified);
	}

	void BaseObject::setObjectModified(bool modified) {
		vTable.base->setObjectModified(this, modified);
	}

	const char* BaseObject::getObjectID() const {
		return vTable.base->getObjectID(this);
	}

	const auto BaseObject_writeFileHeader = reinterpret_cast<bool(__thiscall*)(const BaseObject*, GameFile*)>(0x4EEE60);
	bool BaseObject::writeFileHeader(GameFile* file) const {
		return BaseObject_writeFileHeader(this, file);
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

	const char* BaseObject::getSourceFilename() {
		if (sourceMod) {
			return sourceMod->filename;
		}
		return nullptr;
	}

	bool BaseObject::getDisabled() const {
		return BIT_TEST(objectFlags, TES3::ObjectFlag::DisabledBit);
	}

	bool BaseObject::getDeleted() const {
		return BIT_TEST(objectFlags, TES3::ObjectFlag::DeleteBit);
	}

	bool BaseObject::getPersistent() const {
		return BIT_TEST(objectFlags, TES3::ObjectFlag::PersistentBit);
	}

	void BaseObject::setPersistent(bool value) {
		BIT_SET(objectFlags, TES3::ObjectFlag::PersistentBit, value);
	}

	bool BaseObject::getBlocked() const {
		return BIT_TEST(objectFlags, TES3::ObjectFlag::BlockedBit);
	}

	void BaseObject::setBlocked(bool value) {
		BIT_SET(objectFlags, TES3::ObjectFlag::BlockedBit, value);
	}

	std::string BaseObject::toJson() {
		std::ostringstream ss;
		ss << "\"tes3baseObject:" << getObjectID() << "\"";
		return std::move(ss.str());
	}

	std::unordered_set<const BaseObject*> sourcelessObjects;

	bool BaseObject::getSourceless() const {
		return isSourcelessObject(this);
	}

	void BaseObject::setSourceless(bool sourceless) const {
		if (sourceless) {
			setSourcelessObject(this);
		}
		else {
			sourcelessObjects.erase(this);
		}
	}

	const auto TES3_isSourcelessObject = reinterpret_cast<bool(__stdcall*)(const BaseObject*)>(0x4C1980);
	bool __stdcall BaseObject::isSourcelessObject(const BaseObject* object) {
		return TES3_isSourcelessObject(object) || sourcelessObjects.find(object) != sourcelessObjects.end();
	}

	void BaseObject::setSourcelessObject(const BaseObject* object) {
		if (!TES3_isSourcelessObject(object)) {
			sourcelessObjects.insert(object);
		}
	}

	static std::unordered_map<const BaseObject*, sol::object> baseObjectCache;

	sol::object BaseObject::getOrCreateLuaObject(lua_State* L) const {
		if (this == nullptr) {
			return sol::nil;
		}

		auto stateHandle = mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle();

		auto cacheHit = baseObjectCache.find(this);
		if (cacheHit != baseObjectCache.end()) {
			auto result = cacheHit->second;
			return result;
		}

		// Make sure we're looking at the main state.
		L = stateHandle.state;

		sol::object ref = sol::nil;
		switch (objectType) {
		case ObjectType::Activator:
			ref = sol::make_object_userdata(L, static_cast<const Activator*>(this));
			break;
		case ObjectType::Alchemy:
			ref = sol::make_object_userdata(L, static_cast<const Alchemy*>(this));
			break;
		case ObjectType::AnimationGroup:
			ref = sol::make_object_userdata(L, static_cast<const AnimationGroup*>(this));
			break;
		case ObjectType::Apparatus:
			ref = sol::make_object_userdata(L, static_cast<const Apparatus*>(this));
			break;
		case ObjectType::Armor:
			ref = sol::make_object_userdata(L, static_cast<const Armor*>(this));
			break;
		case ObjectType::Birthsign:
			ref = sol::make_object_userdata(L, static_cast<const Birthsign*>(this));
			break;
		case ObjectType::Bodypart:
			ref = sol::make_object_userdata(L, static_cast<const BodyPart*>(this));
			break;
		case ObjectType::Book:
			ref = sol::make_object_userdata(L, static_cast<const Book*>(this));
			break;
		case ObjectType::Cell:
			ref = sol::make_object_userdata(L, static_cast<const Cell*>(this));
			break;
		case ObjectType::Class:
			ref = sol::make_object_userdata(L, static_cast<const Class*>(this));
			break;
		case ObjectType::Clothing:
			ref = sol::make_object_userdata(L, static_cast<const Clothing*>(this));
			break;
		case ObjectType::Container:
			if (static_cast<const Actor*>(this)->isClone()) {
				ref = sol::make_object_userdata(L, static_cast<const ContainerInstance*>(this));
			}
			else {
				ref = sol::make_object_userdata(L, static_cast<const Container*>(this));
			}
			break;
		case ObjectType::Creature:
			if (static_cast<const Actor*>(this)->isClone()) {
				ref = sol::make_object_userdata(L, static_cast<const CreatureInstance*>(this));
			}
			else {
				ref = sol::make_object_userdata(L, static_cast<const Creature*>(this));
			}
			break;
		case ObjectType::Dialogue:
			ref = sol::make_object_userdata(L, static_cast<const Dialogue*>(this));
			break;
		case ObjectType::DialogueInfo:
			ref = sol::make_object_userdata(L, static_cast<const DialogueInfo*>(this));
			break;
		case ObjectType::Door:
			ref = sol::make_object_userdata(L, static_cast<const Door*>(this));
			break;
		case ObjectType::Enchantment:
			ref = sol::make_object_userdata(L, static_cast<const Enchantment*>(this));
			break;
		case ObjectType::Faction:
			ref = sol::make_object_userdata(L, static_cast<const Faction*>(this));
			break;
		case ObjectType::Global:
			ref = sol::make_object_userdata(L, static_cast<const GlobalVariable*>(this));
			break;
		case ObjectType::GameSetting:
			ref = sol::make_object_userdata(L, static_cast<const GameSetting*>(this));
			break;
		case ObjectType::Ingredient:
			ref = sol::make_object_userdata(L, static_cast<const Ingredient*>(this));
			break;
		case ObjectType::Land:
			ref = sol::make_object_userdata(L, static_cast<const Land*>(this));
			break;
		case ObjectType::LeveledCreature:
			ref = sol::make_object_userdata(L, static_cast<const LeveledCreature*>(this));
			break;
		case ObjectType::LeveledItem:
			ref = sol::make_object_userdata(L, static_cast<const LeveledItem*>(this));
			break;
		case ObjectType::Light:
			ref = sol::make_object_userdata(L, static_cast<const Light*>(this));
			break;
		case ObjectType::Lockpick:
			ref = sol::make_object_userdata(L, static_cast<const Lockpick*>(this));
			break;
		case ObjectType::MagicEffect:
			ref = sol::make_object_userdata(L, static_cast<const MagicEffect*>(this));
			break;
		case ObjectType::Misc:
			ref = sol::make_object_userdata(L, static_cast<const Misc*>(this));
			break;
		case ObjectType::NPC:
			if (static_cast<const Actor*>(this)->isClone()) {
				ref = sol::make_object_userdata(L, static_cast<const NPCInstance*>(this));
			}
			else {
				ref = sol::make_object_userdata(L, static_cast<const NPC*>(this));
			}
			break;
		case ObjectType::Probe:
			ref = sol::make_object_userdata(L, static_cast<const Probe*>(this));
			break;
		case ObjectType::Quest:
			ref = sol::make_object_userdata(L, static_cast<const Quest*>(this));
			break;
		case ObjectType::Race:
			ref = sol::make_object_userdata(L, static_cast<const Race*>(this));
			break;
		case ObjectType::Reference:
			ref = sol::make_object_userdata(L, static_cast<const Reference*>(this));
			break;
		case ObjectType::Region:
			ref = sol::make_object_userdata(L, static_cast<const Region*>(this));
			break;
		case ObjectType::Repair:
			ref = sol::make_object_userdata(L, static_cast<const RepairTool*>(this));
			break;
		case ObjectType::Script:
			ref = sol::make_object_userdata(L, static_cast<const Script*>(this));
			break;
		case ObjectType::Skill:
			ref = sol::make_object_userdata(L, static_cast<const Skill*>(this));
			break;
		case ObjectType::Sound:
			ref = sol::make_object_userdata(L, static_cast<const Sound*>(this));
			break;
		case ObjectType::SoundGenerator:
			ref = sol::make_object_userdata(L, static_cast<const SoundGenerator*>(this));
			break;
		case ObjectType::Spell:
			ref = sol::make_object_userdata(L, static_cast<const Spell*>(this));
			break;
		case ObjectType::MagicSourceInstance:
			ref = sol::make_object_userdata(L, static_cast<const MagicSourceInstance*>(this));
			break;
		case ObjectType::Static:
			ref = sol::make_object_userdata(L, static_cast<const Static*>(this));
			break;
		case ObjectType::Ammo:
		case ObjectType::Weapon:
			ref = sol::make_object_userdata(L, static_cast<const Weapon*>(this));
			break;
		default:
			mwse::log::getLog() << "[MWSE] Invalidated object pushed. vtable is: 0x" << std::hex << uint32_t(vTable.object) << std::endl;
			break;
		}

		// Don't cache misses or objects that are invalidated.
		if (ref != sol::nil && uint32_t(vTable.object) != VirtualTableAddress::BaseObject) {
			baseObjectCache[this] = ref;
		}

		return ref;
	}

	void BaseObject::clearCachedLuaObject(const BaseObject* object) {
		auto stateHandle = mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle();
		if (!baseObjectCache.empty()) {
			// Clear any events that make use of this object.
			auto it = baseObjectCache.find(object);
			if (it != baseObjectCache.end()) {
				// Let people know that this object is invalidated.
				stateHandle.triggerEvent(new mwse::lua::event::ObjectInvalidatedEvent(it->second));

				// Clear any events that make use of this object.
				mwse::lua::event::clearObjectFilter(it->second);

				// Remove it from the cache.
				baseObjectCache.erase(it);
			}
		}
	}

	void BaseObject::clearCachedLuaObjects() {
		auto stateHandle = mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle();
		baseObjectCache.clear();
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

	ReferenceList* Object::getOwningCollection() {
		return owningCollection.asReferenceList;
	}

	void Object::setScale_lua(float scale) {
		setScale(scale);
	}

	//
	// PhysicalObject
	//

	IteratedList<BaseObject*> * PhysicalObject::getStolenList() {
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

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::BaseObject)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::Object)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::PhysicalObject)
