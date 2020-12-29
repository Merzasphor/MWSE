#pragma once

#include "TES3Defines.h"

#include "TES3HashMap.h"
#include "TES3MagicEffectInstance.h"
#include "TES3Object.h"
#include "TES3Vectors.h"

namespace TES3 {
	enum class SpellEffectState {
		PreCast = 0,
		Cast = 1,
		Beginning = 4,
		Working = 5,
		Ending = 6,
		Retired = 7,
		WorkingFortify = 8,
		EndingFortify = 9
	};

	enum class MagicSourceType : unsigned char {
		Invalid = 0,
		Spell = 1,
		Enchantment = 2,
		Alchemy = 3
	};

	struct MagicSourceCombo {
		union {
			Object * asGeneric;
			Alchemy * asAlchemy;
			Enchantment * asEnchantment;
			Spell * asSpell;
		} source; // 0xA0
		MagicSourceType sourceType;// 0xA4

		MagicSourceCombo();
		MagicSourceCombo(Object* object);

		//
		// Other related this-call functions.
		//

		Effect * getSourceEffects() const;
		nonstd::span<Effect> getEffectSpan() const;

	};
	static_assert(sizeof(MagicSourceCombo) == 0x8, "TES3::MagicSourceCombo failed size validation");

	struct MagicSourceInstance : BaseObject {
		float overrideCastChance; // 0x10
		Reference * target; // 0x14
		bool bypassResistances; // 0x18
		HashMap<const char*, MagicEffectInstance::Data> effects[8]; // 0x1C
		MobileProjectile * magicProjectile;
		MagicSourceCombo sourceCombo;
		unsigned int serialNumber;
		void * unknown_0xAC;
		float timestampCastBegin; // 0xB0
		SpellEffectState state;
		Reference * caster;
		Item * castingItem;
		ItemData * castingItemCondition;
		char castingItemID[32];
		char magicID[32];
		Sound * soundEffects[8];
		int unknown_0x124;
		float unknown_0x128;

		//
		// Other related this-call functions.
		//

		int getMagnitude(int effectIndex) const;
		void playSpellVFX(float duration, Vector3 position, Reference* attachedReference, int unknown0, PhysicalObject* effectVisual, int effectIndex = 0, int unknown1 = 0);

		//
		// Custom functions.
		//

		Object* getSourceObject() const;
		MagicSourceType getSourceType() const;
		nonstd::span<Effect> getSourceEffects() const;

		void playSpellVFX_lua(sol::table params);

	};
	static_assert(sizeof(MagicSourceInstance) == 0x12C, "TES3::MagicSourceInstance failed size validation");
}

MWSE_SOL_CUSTOMIZED_PUSHER_DECLARE_TES3(TES3::MagicSourceInstance)
