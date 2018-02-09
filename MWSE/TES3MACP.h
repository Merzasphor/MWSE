#pragma once

#include "TES3Skill.h"

#include "TES3Reference.h"

namespace TES3 {
	struct MACP {
		struct Skill
		{
			void* vtable;
			float base;
			float current;
			SkillType skillType;
		};
		struct Statistic
		{
			void* vtable;
			float base;
			float current;
		};
		struct ActiveEffect
		{
			ActiveEffect * next;
			ActiveEffect * previous;
			unsigned long id; //??? matches SPLLRecord
			unsigned short flags; //??? 0x0 for spells 0x68 for potions?
			unsigned short TES3::Effectype; // see Effects enum
			unsigned short detrimental; // 1 = yes, 0 = no
			unsigned short duration; // seconds
			unsigned short magnitude;
			unsigned short attribute_skill; // 255 if N/A see Attributes/Skills enums
		};
		void * vTable; // 0x0000
		ObjectType::ObjectType objectType; // 0x0004 // "MACP"
		int unknown_0x0008[3];
		TES3::Reference * reference; // 0x0014
		int unknown_0x0018[53]; // 0x0018
		MACP * combatTarget; // 0x00EC // unverified
		int unknown_0x00F0[54]; // 0x00F0
		ActiveEffect * activeEffects; // 0x01C8
		long num_active_effects; // 0x01CC // Number of active spells/effects.
		MACP * self; // 0x01D0 // Pointer back to this record?
		int unknown_0x01D4[32];  // 0x01D4
		Statistic attributes[8]; // 0x0254
		Statistic health; // 0x02B4
		Statistic magicka; // 0x02C0
		Statistic weight_limit; // 0x02CC // base = max
		Statistic fatigue; // 0x02D8 // Fatigue has a different vtable pointer than the other Statistic objects.
		Statistic unknown_statistic; // 0x02E4
		unsigned long effect_attributes[27]; // 0x02E8
		int unknown_0x035C; // 0x035C
		mwShort gold; // 0x0360
		mwShort unknown_0x0362; // 0x0362
		int unknown_0x0364[5]; // 0x0364
		BaseObject * currentSpell; // 0x0378
		int unknown_0x037C[3]; // 0x037C
		void* current_weapon; // 0x0388
		int unknown_0x038C[9]; // 0x038C
		Skill skills[27]; // 0x03B0
		int unknown_0x0560[34];  // 0x0560
		long levelProgress; // 0x05E8
		int unknown_0x05EC[2];  // 0x05EC
		float skillProgress[27]; // 0x05F4
	};
	static_assert(sizeof(MACP::Skill) == 0x10, "TES3::MACP::Skill failed size validation");
	static_assert(sizeof(MACP::Statistic) == 0x0C, "TES3::MACP::Statistic failed size validation");
	static_assert(sizeof(MACP::ActiveEffect) == 0x18, "TES3::MACP::ActiveEffect failed size validation");
	static_assert(sizeof(MACP) == 0x660, "TES3::MACP failed size validation");
}
