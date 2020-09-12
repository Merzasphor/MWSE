#include "TES3Creature.h"

#include "BitUtil.h"

namespace TES3 {
	bool CreatureBase::getIsBiped() const {
		return BIT_TEST(actorFlags, ActorFlagCreature::BipedBit);
	}

	void CreatureBase::setIsBiped(bool value) {
		BIT_SET(actorFlags, ActorFlagCreature::BipedBit, value);
	}

	bool CreatureBase::getIsEssential() const {
		return BIT_TEST(actorFlags, ActorFlagCreature::EssentialBit);
	}

	void CreatureBase::setIsEssential(bool value) {
		BIT_SET(actorFlags, ActorFlagCreature::EssentialBit, value);
	}

	bool CreatureBase::getRespawns() const {
		return BIT_TEST(actorFlags, ActorFlagCreature::RespawnBit);
	}

	void CreatureBase::setRespawns(bool value) {
		BIT_SET(actorFlags, ActorFlagCreature::RespawnBit, value);
	}

	bool CreatureBase::getUsesEquipment() const {
		return BIT_TEST(actorFlags, ActorFlagCreature::WeaponAndShieldBit);
	}

	void CreatureBase::setUsesEquipment(bool value) {
		BIT_SET(actorFlags, ActorFlagCreature::WeaponAndShieldBit, value);
	}

	bool CreatureBase::getSwims() const {
		return BIT_TEST(actorFlags, ActorFlagCreature::SwimsBit);
	}

	void CreatureBase::setSwims(bool value) {
		BIT_SET(actorFlags, ActorFlagCreature::SwimsBit, value);
	}

	bool CreatureBase::getFlies() const {
		return BIT_TEST(actorFlags, ActorFlagCreature::FliesBit);
	}

	void CreatureBase::setFlies(bool value) {
		BIT_SET(actorFlags, ActorFlagCreature::FliesBit, value);
	}

	bool CreatureBase::getWalks() const {
		return BIT_TEST(actorFlags, ActorFlagCreature::WalksBit);
	}

	void CreatureBase::setWalks(bool value) {
		BIT_SET(actorFlags, ActorFlagCreature::WalksBit, value);
	}

	std::reference_wrapper<int[8]> Creature::getAttributes() {
		return std::ref(attributes);
	}

	std::reference_wrapper<int[3]> Creature::getSkills() {
		return std::ref(skills);
	}

	std::reference_wrapper<Range<int>[3]> Creature::getAttacks() {
		return std::ref(attacks);
	}

	AIConfig* CreatureInstance::getBaseAIConfig() const {
		return baseCreature->aiConfig;
	}

	std::reference_wrapper<int[8]> CreatureInstance::getBaseAttributes() const {
		return baseCreature->getAttributes();
	}

	std::reference_wrapper<int[3]> CreatureInstance::getBaseSkills() const {
		return baseCreature->getSkills();
	}

	std::reference_wrapper<Range<int>[3]> CreatureInstance::getBaseAttacks() const {
		return baseCreature->getAttacks();
	}

	Creature* CreatureInstance::getBaseSoundGenerator() const {
		return baseCreature->soundGenerator;
	}

	int CreatureInstance::getBaseCreatureType() const {
		return baseCreature->creatureType;
	}

	SpellList* CreatureInstance::getBaseSpells() const {
		return baseCreature->spellList;
	}

	int CreatureInstance::getBaseSoulValue() const {
		return baseCreature->soul;
	}

	void CreatureInstance::setBaseSoulValue(int value) {
		baseCreature->soul = value;
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::CreatureBase)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::Creature)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::CreatureInstance)
