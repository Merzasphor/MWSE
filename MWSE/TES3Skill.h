#pragma once

#include "ObjectTypes.h"

namespace TES3 {
	enum Skills {
		SkillInvalid = -1,
		SkillBlock,
		SkillArmorer,
		SkillMediumArmor,
		SkillHeavyArmor,
		SkillBluntWeapon,
		SkillLongBlade,
		SkillAxe,
		SkillSpear,
		SkillAthletics,
		SkillEnchant,
		SkillDestruction,
		SkillAlteration,
		SkillIllusion,
		SkillConjuration,
		SkillMysticism,
		SkillRestoration,
		SkillAlchemy,
		SkillUnarmored,
		SkillSecurity,
		SkillSneak,
		SkillAcrobatics,
		SkillLightArmor,
		SkillShortBlade,
		SkillMarksman,
		SkillMercantile,
		SkillSpeechcraft,
		SkillHandToHand,
		FirstSkill = SkillBlock,
		LastSkill = SkillHandToHand
	};

	enum SkillType {
		SkillTypeMajor,
		SkillTypeMinor,
		SkillTypeMisc
	};

	enum SkillSpecialization {
		SpecializationInvalid = -1,
		SpecializationCombat,
		SpecializationMagic,
		SpecializationStealth,
		FirstSpecialization = SpecializationCombat,
		LastSpecialization = SpecializationStealth
	};

	struct Skill_vTable {

	};

	struct Skill {
		void * vTable; // 0x00
		ObjectType::ObjectType objectType; // 0x04 // "SKIL"
		int baseFlags; // 0x08
		void * unknown_0x0C; // 0x0C // Pointer to first array element?
		mwLong skill; // 0x10
		mwLong attribute; // 0x14
		mwLong specialization; // 0x18
		mwFloat actions[4]; // 0x1C
		int unknown_0x2C; // 0x2C
		int unknown_0x30; // 0x30
	};
	static_assert(sizeof(Skill) == 0x34, "TES3::Skill failed size validation");
}
