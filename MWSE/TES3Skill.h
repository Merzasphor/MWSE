#pragma once

#include "TES3Object.h"
#include "TES3Statistic.h"

namespace TES3 {
	namespace SkillID {
		enum Skill {
			Invalid = -1,
			Block,
			Armorer,
			MediumArmor,
			HeavyArmor,
			BluntWeapon,
			LongBlade,
			Axe,
			Spear,
			Athletics,
			Enchant,
			Destruction,
			Alteration,
			Illusion,
			Conjuration,
			Mysticism,
			Restoration,
			Alchemy,
			Unarmored,
			Security,
			Sneak,
			Acrobatics,
			LightArmor,
			ShortBlade,
			Marksman,
			Mercantile,
			Speechcraft,
			HandToHand,
			FirstSkill = Block,
			LastSkill = HandToHand
		};
	}

	namespace SkillType {
		enum SkillType {
			Major,
			Minor,
			Misc
		};
	}

	namespace SkillSpecialization {
		enum SkillSpecialization {
			Invalid = -1,
			Combat,
			Magic,
			Stealth,
			FirstSpecialization = Combat,
			LastSpecialization = Stealth
		};
	}

	struct Skill : BaseObject {
		int skill;
		int governingAttribute;
		int specialization;
		float progressActions[4];
		void * description;
		float descriptionFileOffset;
	};
	static_assert(sizeof(Skill) == 0x34, "TES3::Skill failed size validation");
}
