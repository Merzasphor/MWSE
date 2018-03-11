#pragma once

#include "TES3Object.h"

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
			BaseObject * head1;
			BaseObject * hair;
			BaseObject * neck;
			BaseObject * chest;
			BaseObject * groin;
			BaseObject * hands;
			BaseObject * wrist;
			BaseObject * forearm;
			BaseObject * upper_arm;
			BaseObject * foot;
			BaseObject * ankle;
			BaseObject * knee;
			BaseObject * upper_leg;
			BaseObject * unknown1;
			BaseObject * tail;
			BaseObject * head2;
			int unknown2[14];
		};
		char id[32]; // 0x10
		char name[32]; // 0x30
		SkillBonus skillBonuses[7]; // 0x50
		BaseAttribute baseAttributes[8]; // 0x88 // Index corresponds to Attributes enum.
		HeightWeight height; // 0xC8
		HeightWeight weight; // 0xD0
		unsigned long flags; // 0xD8 // 1 = playable, 2 = beast, 3 = both.
		int unknown_0xDC; // Pointer?
		int unknown_0xE0;
		int unknown_0xE4;
		BodyParts maleBody; // 0xE8
		BodyParts femaleBody; // 0x0160
	};
}
