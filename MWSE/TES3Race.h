#pragma once

#include "TES3Defines.h"

namespace TES3 {
	struct Race : BaseObject {
		struct SkillBonus {
			long skill;
			unsigned long bonus;
		};
		struct BaseAttribute {
			unsigned long male;
			unsigned long female;
		};
		struct HeightWeight {
			float male;
			float female;
		};
		struct BodyParts {
			BodyPart * head1;
			BodyPart * hair;
			BodyPart * neck;
			BodyPart * chest;
			BodyPart * groin;
			BodyPart * hands;
			BodyPart * wrist;
			BodyPart * forearm;
			BodyPart * upperArm;
			BodyPart * foot;
			BodyPart * ankle;
			BodyPart * knee;
			BodyPart * upperLeg;
			BodyPart * clavicle;
			BodyPart * tail;
			BodyPart * head2;
			int unknown2[14];
		};
		char id[32]; // 0x10
		char name[32]; // 0x30
		SkillBonus skillBonuses[7]; // 0x50
		BaseAttribute baseAttributes[8]; // 0x88 // Index corresponds to Attributes enum.
		HeightWeight height; // 0xC8
		HeightWeight weight; // 0xD0
		mwse::bitset32 flags; // 0xD8 // 1 = playable, 2 = beast
		int unknown_0xDC; // Pointer? Abilities list?
		char * description; // 0xE0
		unsigned int descriptionFileOffset; // 0xE4
		BodyParts maleBody; // 0xE8
		BodyParts femaleBody; // 0x0160
	};
	static_assert(sizeof(Race) == 0x1D8, "TES3::Race failed size validation");
}
