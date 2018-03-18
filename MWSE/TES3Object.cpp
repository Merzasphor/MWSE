#include "TES3Object.h"

namespace TES3 {
	int BaseObject::setObjectModified(unsigned char modified) {
		return this->vTable->setObjectModified(this, modified);
	}

	char* BaseObject::getObjectID() {
		return this->vTable->getObjectID(this);
	}

	char* Object::getName() {
		return this->vTable->getName(this);
	}

	char* Object::getIconPath() {
		return this->vTable->getIconPath(this);
	}

	char* Object::getModelPath() {
		return this->vTable->getModelPath(this);
	}

	Script* Object::getScript() {
		return this->vTable->getScript(this);
	}

	char* Object::getRaceID() {
		return this->vTable->getRaceID(this);
	}

	char* Object::getClassID() {
		return this->vTable->getClassID(this);
	}

	char* Object::getBirthsignID() {
		return this->vTable->getBirthsignID(this);
	}

	Race* Object::getRace() {
		return this->vTable->getRace(this);
	}

	Class* Object::getClass() {
		return this->vTable->getClass(this);
	}

	Faction* Object::getFaction() {
		return this->vTable->getFaction(this);
	}

	bool Object::isFemale() {
		return this->vTable->isFemale(this);
	}

	int Object::getFactionRank() {
		return this->vTable->getFactionRank(this);
	}

	int Object::getLevel() {
		return this->vTable->getLevel(this);
	}

	signed char Object::setDispositionRaw(signed char value) {
		return this->vTable->setDispositionRaw(this, value);
	}

	int Object::modDisposition(signed int value) {
		return this->vTable->modDisposition(this, value);
	}

	int Object::getFactionIndex() {
		return this->vTable->getFactionIndex(this);
	}

	signed char Object::setFactionIndex(signed char index) {
		return this->vTable->setFactionIndex(this, index);
	}

	int Object::getDispositionRaw() {
		return this->vTable->getDispositionRaw(this);
	}

	signed char Object::modFactionIndex(signed char value) {
		return this->vTable->modFactionIndex(this, value);
	}

	int Object::getType() {
		return this->vTable->getType(this);
	}

	char* Object::getTypeName() {
		return this->vTable->getTypeName(this);
	}

	float Object::getWeight() {
		return this->vTable->getWeight(this);
	}

	int Object::getValue() {
		return this->vTable->getValue(this);
	}

	void Object::setDurability(int value) {
		return this->vTable->setDurability(this, value);
	}

	int Object::getDurability() {
		return this->vTable->getDurability(this);
	}

	int Object::getMagicka() {
		return this->vTable->getMagicka(this);
	}

	int Object::getFatigue() {
		return this->vTable->getFatigue(this);
	}

	float Object::getQuality() {
		return this->vTable->getQuality(this);
	}

	bool Object::isLeftPartOfPair() {
		return this->vTable->isLeftPartOfPair(this);
	}

	bool Object::isEssential() {
		return this->vTable->isEssential(this);
	}

	bool Object::isRespawn() {
		return this->vTable->isRespawn(this);
	}

	int Object::getUses() {
		return this->vTable->getUses(this);
	}

	Enchantment* Object::getEnchantment() {
		return this->vTable->getEnchantment(this);
	}

	Enchantment* Object::setEnchantment(Enchantment* enchantment) {
		return this->vTable->setEnchantment(this, enchantment);
	}

	AIConfig* Object::getAIConfig() {
		return this->vTable->getAIConfig(this);
	}

	unsigned char Object::getAutoCalc() {
		return this->vTable->getAutoCalc(this);
	}

	unsigned char Object::setAutoCalc(unsigned char value) {
		return this->vTable->setAutoCalc(this, value);
	}

	char* Object::setModelPath(char* path) {
		return this->vTable->setModelPath(this, path);
	}

	char* Object::setName(char* name) {
		return this->vTable->setName(this, name);
	}

}
