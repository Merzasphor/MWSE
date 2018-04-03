#include "TES3Object.h"

namespace TES3 {
	int BaseObject::setObjectModified(unsigned char modified) {
		return vTable.base->setObjectModified(this, modified);
	}

	char* BaseObject::getObjectID() {
		return vTable.base->getObjectID(this);
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

	unsigned char Object::getAutoCalc() {
		return vTable.object->getAutoCalc(this);
	}

	unsigned char Object::setAutoCalc(unsigned char value) {
		return vTable.object->setAutoCalc(this, value);
	}

	char* Object::setModelPath(char* path) {
		return vTable.object->setModelPath(this, path);
	}

	char* Object::setName(const char* name) {
		return vTable.object->setName(this, name);
	}

}
