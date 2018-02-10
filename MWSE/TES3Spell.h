#pragma once

#include "ObjectTypes.h"
#include "TES3Collections.h"

#include "TES3Effect.h"

namespace TES3 {
	enum SpellOrigins {
		Module = 1,
		Spellmaker,
		SpellOriginsFirst = Module,
		SpellOriginsLast = Spellmaker
	};

	enum SpellTypes {
		SpellTypeSpell,
		SpellTypeAbility,
		SpellTypeBlight,
		SpellTypeDisease,
		SpellTypeCurse,
		SpellTypePower,
		FirstSpellType = SpellTypeSpell,
		LastSpellType = SpellTypePower
	};

	enum SpellFlags {
		AutoCalculateCost = 1,
		PcStartSpell = 2,
		AlwaysSucceeds = 4,
		NoSpellFlags = 0,
		AllSpellFlags = (AutoCalculateCost | PcStartSpell | AlwaysSucceeds)
	};

	// TODO: Rename this.
	struct SPLL {
		struct ActiveSpell {
			char * id; // 0x00 // "PlayerSaveGame" if player.
			Reference * reference; // 0x04
			mwFloat statistic; // 0x08 // Magicka Resistance if applicable.
			unsigned long magnitude; // 0x0C
			mwFloat time; // 0x10 // Elapsed? Start?
		};
		struct SPLLEffect {
			void * vTable; // 0x00
			unsigned long inUse; // 0x04 // Number of null-pointers in array?
			unsigned long size; // 0x08
			ActiveSpell ** activeSpells; // 0x0C
		};
		void * vTable; // 0x00
		ObjectType::ObjectType objectType; // 0x04
		long unknown_0x08;
		long unknown_0x0C;
		long unknown_0x10;
		long unknown_0x14;
		long unknown_0x18;
		SPLLEffect effects[8]; // 0x1C
		long unknown_0x9C;
		Spell * spell; // 0xA0
		long unknown_0xA4;
		long unknown_0xA8; // nth active effect? In cell?
		long unknown_0xAC;
		long unknown_0xB0;
		long unknown_0xB4;
		Reference * reference; // 0xB8
		unsigned long flags; // 0xBC
		long unknown_0xC0;
		long unknown_0xC4;
		long unknown_0xC8;
		long unknown_0xCC;
		long unknown_0xD0;
		long unknown_0xD4;
		long unknown_0xD8;
		long unknown_0xDC;
		long unknown_0xE0;
		char id[32]; // 0xE4 // Matches spell.id?
	};
	static_assert(sizeof(TES3::SPLL::ActiveSpell) == 0x14, "TES3::SPLL::ActiveSpell failed size validation");
	static_assert(sizeof(TES3::SPLL::SPLLEffect) == 0x10, "TES3::SPLL::SPLLEffect failed size validation");
	static_assert(sizeof(TES3::SPLL) == 0x0104, "TES3::SPLL failed size validation");

	// TODO: Some kind of tree?
	struct SPLLNode
	{
		SPLLNode * first; // 0x00
		SPLLNode * second; // 0x04
		SPLLNode * third; // 0x08
		unsigned long id; // 0x0C
		SPLL * object; // 0x10
		unsigned long flag; // 0x14
		long unknown_0x18;
		long unknown_0x1C;
	};
	static_assert(sizeof(TES3::SPLLNode) == 0x20, "TES3::SPLLNode failed size validation");

	struct Spell_vTable {

	};

	struct Spell {
		Spell_vTable * vTable;
		ObjectType::ObjectType objectType;
		mwLong origin; // 0x08
		int unknown_0x0C;
		int unknown_0x10;
		LinkedList<Spell> * spellsList;
		int unknown_0x18;
		Spell * previousSpell; // 0x1C
		Spell * nextSpell; // 0x20
		int unknown_0x24;
		mwString objectID; // 0x28
		mwString name; // 0x2C
		short type; // 0x30 // 0=SPELL, 1=ABILITY, 2=BLIGHT, 3=DISEASE, 4=CURSE, 5=POWER
		short cost; // 0x32
		Effect effects[8]; // 0x34
		long flags;	// 0xF4 // 1=AUTOCALC, 2=PCSTART, 4=ALWAYSSUCCEEDS
	};
	static_assert(sizeof(Spell) == 0xF8, "TES3::Spell failed size validation");
}
