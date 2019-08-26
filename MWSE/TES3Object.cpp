#include "TES3Object.h"

#include "TES3Actor.h"
#include "TES3Reference.h"

#include "TES3Util.h"

namespace TES3 {
	void * BaseObject::operator new(size_t size) {
		return mwse::tes3::_new(size);
	}
	void BaseObject::operator delete(void * address) {
		mwse::tes3::_delete(address);
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

	signed char Object::setDispositionRaw(signed char value) {
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
}
