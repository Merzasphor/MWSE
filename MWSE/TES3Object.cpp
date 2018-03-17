#include "TES3Object.h"

namespace TES3 {
	int BaseObject::setObjectModified(unsigned char modified) {
		return this->vTable->setObjectModified(this, modified);
	}

	char* BaseObject::getObjectID() {
		return this->vTable->getObjectID(this);
	}

	char* BaseObject::getName() {
		return this->vTable->getName(this);
	}

	char* BaseObject::getIconPath() {
		return this->vTable->getIconPath(this);
	}

	char* BaseObject::getModelPath() {
		return this->vTable->getModelPath(this);
	}

	Script* BaseObject::getScript() {
		return this->vTable->getScript(this);
	}

	char* BaseObject::getRaceID() {
		return this->vTable->getRaceID(this);
	}

	char* BaseObject::getClassID() {
		return this->vTable->getClassID(this);
	}

	char* BaseObject::getBirthsignID() {
		return this->vTable->getBirthsignID(this);
	}

	Race* BaseObject::getRace() {
		return this->vTable->getRace(this);
	}

	Class* BaseObject::getClass() {
		return this->vTable->getClass(this);
	}

	Faction* BaseObject::getFaction() {
		return this->vTable->getFaction(this);
	}

	bool BaseObject::isFemale() {
		return this->vTable->isFemale(this);
	}

	int BaseObject::getFactionRank() {
		return this->vTable->getFactionRank(this);
	}

	int BaseObject::getLevel() {
		return this->vTable->getLevel(this);
	}

	signed char BaseObject::setDispositionRaw(signed char value) {
		return this->vTable->setDispositionRaw(this, value);
	}

	int BaseObject::modDisposition(signed int value) {
		return this->vTable->modDisposition(this, value);
	}

	int BaseObject::getFactionIndex() {
		return this->vTable->getFactionIndex(this);
	}

	signed char BaseObject::setFactionIndex(signed char index) {
		return this->vTable->setFactionIndex(this, index);
	}

	int BaseObject::getDispositionRaw() {
		return this->vTable->getDispositionRaw(this);
	}

	signed char BaseObject::modFactionIndex(signed char value) {
		return this->vTable->modFactionIndex(this, value);
	}

	int BaseObject::getType() {
		return this->vTable->getType(this);
	}

	char* BaseObject::getTypeName() {
		return this->vTable->getTypeName(this);
	}

	float BaseObject::getWeight() {
		return this->vTable->getWeight(this);
	}

	int BaseObject::getValue() {
		return this->vTable->getValue(this);
	}

	void BaseObject::setDurability(int value) {
		return this->vTable->setDurability(this, value);
	}

	int BaseObject::getDurability() {
		return this->vTable->getDurability(this);
	}

	int BaseObject::getMagicka() {
		return this->vTable->getMagicka(this);
	}

	int BaseObject::getFatigue() {
		return this->vTable->getFatigue(this);
	}

	float BaseObject::getQuality() {
		return this->vTable->getQuality(this);
	}

	bool BaseObject::isLeftPartOfPair() {
		return this->vTable->isLeftPartOfPair(this);
	}

	bool BaseObject::isEssential() {
		return this->vTable->isEssential(this);
	}

	bool BaseObject::isRespawn() {
		return this->vTable->isRespawn(this);
	}

	int BaseObject::getUses() {
		return this->vTable->getUses(this);
	}

	Enchantment* BaseObject::getEnchantment() {
		return this->vTable->getEnchantment(this);
	}

	Enchantment* BaseObject::setEnchantment(Enchantment* enchantment) {
		return this->vTable->setEnchantment(this, enchantment);
	}

	AIConfig* BaseObject::getAIConfig() {
		return this->vTable->getAIConfig(this);
	}

	unsigned char BaseObject::getAutoCalc() {
		return this->vTable->getAutoCalc(this);
	}

	unsigned char BaseObject::setAutoCalc(unsigned char value) {
		return this->vTable->setAutoCalc(this, value);
	}

	char* BaseObject::setModelPath(char* path) {
		return this->vTable->setModelPath(this, path);
	}

	char* BaseObject::setName(char* name) {
		return this->vTable->setName(this, name);
	}

}
