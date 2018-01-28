/************************************************************************
	mwseTypes.h - Copyright (c) 2008 The MWSE Project
	http://www.sourceforge.net/projects/mwse

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#pragma once

namespace mwse
{

	typedef short mwShort_t;
	typedef long  mwLong_t;
	typedef float mwFloat_t;
	typedef char* mwString_t;

	namespace RecordTypes {
		enum recordType_t
		{
			ACTI = 'ITCA', ACTIVATOR = ACTI,
			ALCH = 'HCLA', ALCHEMY = ALCH,
			AMMO = 'OMMA',
			APPA = 'APPA', APPARATUS = APPA,
			ARMO = 'OMRA', ARMOR = ARMO,
			BOOK = 'KOOB',
			CLAS = 'SALC', CLASS = CLAS,
			CLOT = 'TOLC', CLOTHING = CLOT,
			CONT = 'TNOC', CONTAINER = CONT,
			CREA = 'AERC', CREATURE = CREA,
			DOOR = 'ROOD',
			ENCH = 'HCNE', ENCHANTMENT = ENCH,
			FACT = 'TCAF', FACTION = FACT,
			GLOB = 'BOLG', GLOBAL = GLOB,
			GMST = 'TSMG',
			INGR = 'RGNI', INGREDIENT = INGR,
			LEVC = 'CVEL', LEVELLEDCREATURE = LEVC,
			LEVI = 'IVEL', LEVELLEDITEM = LEVI,
			LIGH = 'HGIL', LIGHT = LIGH,
			LOCK = 'KCOL', LOCKPICK = LOCK,
			MACP = 'PCAM',
			MISC = 'CSIM',
			MGEF = 'FEGM', MAGICEFFECT = MGEF,
			NPC  = '_CPN',
			PROB = 'BORP', PROBE = PROB,
			REFR = 'RFER', REFERENCE = REFR,
			REPA = 'APER', REPAIR = REPA,
			SCPT = 'TPCS', SCRIPT = SCPT,
			SKIL = 'LIKS', SKILL = SKIL,
			SNDG = 'GDNS', SOUNDGENERATOR = SNDG,
			SPEL = 'LEPS', SPELL = SPEL,
			SPLL = 'LLPS',
			STAT = 'TATS', STATIC = STAT,
			WEAP = 'PAEW', WEAPON = WEAP
		};

		enum attachType_t
		{
			LOCKNODE = 3,	// Used to store lock/trap information.
			VARNODE = 6,	//attachment where 'local' variables are stored, and the size of a stack, and the owner (if it has changed i think), and the script...
			MACHNODE = 8	//PCAM
		};
	};

	namespace Effects {
		enum EffectTypes {
			NoEffect = -1,
			WaterBreathing,
			SwiftSwim,
			WaterWalking,
			Shield,
			FireShield,
			LightningShield,
			FrostShield,
			Burden,
			Feather,
			Jump,
			Levitate,
			SlowFall,
			Lock,
			Open,
			FireDamage,
			ShockDamage,
			FrostDamage,
			DrainAttribute,
			DrainHealth,
			DrainMagicka,
			DrainFatigue,
			DrainSkill,
			DamageAttribute,
			DamageHealth,
			DamageMagicka,
			DamageFatigue,
			DamageSkill,
			Poison,
			WeaknesstoFire,
			WeaknesstoFrost,
			WeaknesstoShock,
			WeaknesstoMagicka,
			WeaknesstoCommonDisease,
			WeaknesstoBlightDisease,
			WeaknesstoCorprusDisease,
			WeaknesstoPoison,
			WeaknesstoNormalWeapons,
			DisintegrateWeapon,
			DisintegrateArmor,
			Invisibility,
			Chameleon,
			Light,
			Sanctuary,
			NightEye,
			Charm,
			Paralyze,
			Silence,
			Blind,
			Sound,
			CalmHumanoid,
			CalmCreature,
			FrenzyHumanoid,
			FrenzyCreature,
			DemoralizeHumanoid,
			DemoralizeCreature,
			RallyHumanoid,
			RallyCreature,
			Dispel,
			Soultrap,
			Telekinesis,
			Mark,
			Recall,
			DivineIntervention,
			AlmsiviIntervention,
			DetectAnimal,
			DetectEnchantment,
			DetectKey,
			SpellAbsorption,
			Reflect,
			CureCommonDisease,
			CureBlightDisease,
			CureCorprusDisease,
			CurePoison,
			CureParalyzation,
			RestoreAttribute,
			RestoreHealth,
			RestoreMagicka,
			RestoreFatigue,
			RestoreSkill,
			FortifyAttribute,
			FortifyHealth,
			FortifyMagicka,
			FortifyFatigue,
			FortifySkill,
			FortifyMaximumMagicka,
			AbsorbAttribute,
			AbsorbHealth,
			AbsorbMagicka,
			AbsorbFatigue,
			AbsorbSkill,
			ResistFire,
			ResistFrost,
			ResistShock,
			ResistMagicka,
			ResistCommonDisease,
			ResistBlightDisease,
			ResistCorprusDisease,
			ResistPoison,
			ResistNormalWeapons,
			ResistParalysis,
			RemoveCurse,
			TurnUndead,
			SummonScamp,
			SummonClannfear,
			SummonDaedroth,
			SummonDremora,
			SummonAncestralGhost,
			SummonSkeletalMinion,
			SummonBonewalker,
			SummonGreaterBonewalker,
			SummonBonelord,
			SummonWingedTwilight,
			SummonHunger,
			SummonGoldenSaint,
			SummonFlameAtronach,
			SummonFrostAtronach,
			SummonStormAtronach,
			FortifyAttack,
			CommandCreature,
			CommandHumanoid,
			BoundDagger,
			BoundLongsword,
			BoundMace,
			BoundBattleAxe,
			BoundSpear,
			BoundLongbow,
			EXTRASPELL,
			BoundCuirass,
			BoundHelm,
			BoundBoots,
			BoundShield,
			BoundGloves,
			Corprus,
			Vampirism,
			SummonCenturionSphere,
			SunDamage,
			StuntedMagicka,
			SummonFabricant,
			CallWolf,
			CallBear,
			SummonBonewolf,
			sEffectSummonCreature04,
			sEffectSummonCreature05,
			FirstMagicEffect = WaterBreathing,
			LastMagicEffect = sEffectSummonCreature05
		};

		enum RangeTypes
		{
			RangeSelf = 0,
			RangeTouch,
			RangeTarget,
			FirstRangeType = RangeSelf,
			LastRangeType = RangeTarget
		};

		enum MagicEffectFlags
		{
			TargetSkill = 0x1,
			TargetAttribute = 0x2,
			NoDuration = 0x4,
			NoMagnitude = 0x8,
			Harmful = 0x10,
			ContinuousVfx = 0x20,
			CastSelf = 0x40,
			CastTouch = 0x80,
			CastTarget = 0x100,
			Spellmaking = 0x200,
			Enchanting = 0x400,
			NegativeLighting = 0x800,
			AppliedOnce = 0x1000,
			StealthEffect = 0x2000,
			NonRecastable = 0x4000,
			IllegalDaedra = 0x8000,
			Unreflectable = 0x10000,
			CasterLinked = 0x20000,
			NoMagicEffectFlags = 0,
			AllMagicEffectFlags = (TargetSkill | TargetAttribute | NoDuration | NoMagnitude |
			Harmful | ContinuousVfx | CastSelf | CastTouch | CastTarget | Spellmaking |
				Enchanting | NegativeLighting | AppliedOnce | StealthEffect | NonRecastable |
				IllegalDaedra | Unreflectable | CasterLinked)
		};

		int const MagicEffectFlagMap[] = {
			0x11c8, 0x11c0, 0x11c8, 0x11e0, 0x11e0, 0x11e0, 0x11e0, 0x11d0,
			0x11c0, 0x11c0, 0x11e0, 0x11c0, 0x11184, 0x11184, 0x1f0, 0x1f0,
			0x1f0, 0x11d2, 0x11f0, 0x11d0, 0x11d0, 0x11d1, 0x1d2, 0x1f0,
			0x01d0, 0x1d0, 0x1d1, 0x1f0, 0x11d0, 0x11d0, 0x11d0, 0x11d0,
			0x11d0, 0x11d0, 0x11d0, 0x11d0, 0x11d0, 0x1d0, 0x1d0, 0x11c8,
			0x31c0, 0x11c0, 0x11c0, 0x11c0, 0x1180, 0x11d8, 0x11d8, 0x11d0,
			0x11d0, 0x11180, 0x11180, 0x11180, 0x11180, 0x11180, 0x11180, 0x11180,
			0x11180, 0x11c4, 0x111b8, 0x1040, 0x104c, 0x104c, 0x104c, 0x104c,
			0x1040, 0x1040, 0x1040, 0x11c0, 0x11c0, 0x1cc, 0x1cc, 0x1cc,
			0x1cc, 0x1cc, 0x1c2, 0x1c0, 0x1c0, 0x1c0, 0x1c1, 0x11c2,
			0x11c0, 0x11c0, 0x11c0, 0x11c1, 0x11c0, 0x21192, 0x20190, 0x20190,
			0x20190, 0x21191, 0x11c0, 0x11c0, 0x11c0, 0x11c0, 0x11c0, 0x11c0,
			0x11c0, 0x11c0, 0x11c0, 0x11c0, 0x1c0, 0x11190, 0x9048, 0x9048,
			0x9048, 0x9048, 0x9048, 0x9048, 0x9048, 0x9048, 0x9048, 0x9048,
			0x9048, 0x9048, 0x9048, 0x9048, 0x9048, 0x11c0, 0x1180, 0x1180,
			0x5048, 0x5048, 0x5048, 0x5048, 0x5048, 0x5048, 0x1188, 0x5048,
			0x5048, 0x5048, 0x5048, 0x5048, 0x1048, 0x104c, 0x1048, 0x40,
			0x11c8, 0x1048, 0x1048, 0x1048, 0x1048, 0x1048, 0x1048
		};
	};

	enum SpellOrigins {
		Module = 1,
		Spellmaker,
		SpellOriginsFirst = Module,
		SpellOriginsLast = Spellmaker
	};

	enum SpellTypes {
		Spell,
		Ability,
		Blight,
		Disease,
		Curse,
		Power,
		FirstSpellType = Spell,
		LastSpellType = Power
	};

	enum SpellFlags {
		AutoCalculateCost = 1,
		PcStartSpell = 2,
		AlwaysSucceeds = 4,
		NoSpellFlags = 0,
		AllSpellFlags = (AutoCalculateCost | PcStartSpell | AlwaysSucceeds)
	};

	enum MagicSchools
	{
		AlterationSchool = 0,
		ConjurationSchool,
		DestructionSchool,
		IllusionSchool,
		MysticismSchool,
		RestorationSchool,
		FirstMagicSchool = AlterationSchool,
		LastMagicSchool = RestorationSchool
	};

	namespace GMST {
		enum GMSTs
		{
			fEffectCostMult = 1037,
			iLevelupTotal = 1088,
			fSpecialSkillBonus = 1161,
			fMajorSkillBonus,
			fMinorSkillBonus,
			fMiscSkillBonus
		};
	}

	struct BaseRecord_t
	{
		void * vTable;
		RecordTypes::recordType_t recordType;
	};

	struct REFRRecord_t;

	//this is the default 'template', so we can read out the type and the ID of the object behind a reference.
	//those values should always be there for 'normal' objects (like BOOKS and CLOTHING)
	struct TES3DefaultTemplate_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		mwLong_t unknown_0x08;
		mwLong_t unknown_0x0C;
		mwLong_t unknown_0x10;
		mwLong_t unknown_0x14;
		REFRRecord_t * first; // 0x18
		mwLong_t unknown_0x1C;
		mwLong_t unknown_0x20;
		mwLong_t unknown_0x24;
		mwLong_t unknown_0x28;
		char * objectId; // 0x2C
	};
	static_assert(sizeof(TES3DefaultTemplate_t) == 0x30, "TES3DefaultTemplate_t failed size validation");

	struct SCPTRecord_t
	{
		void * vTable; // 0x00 // pointer to the vTable
		RecordTypes::recordType_t recordType; // 0x04 // "SCPT"
		int recordSize; // 0x08
		char * modNamePtr; // 0x0C
		char scriptName[32]; // 0x10
		long numShorts; // 0x30
		long numLongs; // 0x34
		long numFloats; // 0x38
		long scriptDataSize; // 0x3C
		int LocalVarSize; // 0x40 // the length of the local var names concatenated (includes \0 for string endings)
		char ** shortVarNamePointers; // 0x44
		char ** longVarNamePointers; // 0x48
		char ** floatVarNamePointers; // 0x4C
		char * varNamePointers; // 0x50
		int unknown_0x54; // 0x54 // equals zero?
		void * machineCode; // 0x58
		mwShort_t * shortVarValues; // 0x5C // pointer to array of shorts, each associated with its corresponding variable
		mwLong_t * longVarValues; // 0x60
		mwFloat_t * floatVarValues; // 0x64
	};
	static_assert(sizeof(SCPTRecord_t) == 0x68, "SCPTRecord_t failed size validation");

	struct SCPTNode_t
	{
		int unknown;
		SCPTRecord_t * scptRecord;
	};
	static_assert(sizeof(SCPTNode_t) == 0x08, "SCPTNode_t failed size validation");

	struct SPELRecord_t;

	template <typename T>
	struct LinkedListNode_t
	{
		LinkedListNode_t<T> * previous;
		LinkedListNode_t<T> * next;
		T * data;
	};
	static_assert(sizeof(LinkedListNode_t<void>) == 0x0C, "LinkedListNode_t failed size validation");

	template <typename T>
	struct LinkedList_t
	{
		unsigned long size;
		T * head;
		T * tail;
	};
	static_assert(sizeof(LinkedList_t<void>) == 0x0C, "LinkedList_t failed size validation");

	struct InventoryNode_t
	{
		int itemCount;
		BaseRecord_t * recordAddress;
	};
	static_assert(sizeof(InventoryNode_t) == 0x08, "InventoryNode_t failed size validation");

	template <typename T>
	struct ListNode_t
	{
		RecordTypes::attachType_t attachType;
		ListNode_t<T> * nextNode;
		T * dataPtr;
	};
	static_assert(sizeof(ListNode_t<void>) == 0x0C, "ListNode_t failed size validation");

	template <typename T>
	struct ListIterator_t
	{
		char unknown[8];
		ListNode_t<T> * first;
		char unknown2[4];
		ListNode_t<T> * current;
	};
	static_assert(sizeof(ListIterator_t<void>) == 0x14, "ListIterator_t failed size validation");

	struct mwVariablesNode_t
	{
		mwShort_t * shortVarValues;
		mwLong_t * longVarValues;
		mwFloat_t * floatVarValues;
	};
	static_assert(sizeof(mwVariablesNode_t) == 0x0C, "mwVariablesNode_t failed size validation");

	struct mwLockNode_t {
		mwShort_t lockLevel; // 0x00
		mwShort_t unknown_0x04;
		void * owner; // 0x08 // Faction or global?
		SPELRecord_t * trapSpell; // 0x0C
		char locked; // 0x10
	};
	static_assert(sizeof(mwLockNode_t) == 0x10, "mwLockNode_t failed size validation");

	struct mwOwnerInfoNode_t {
		int unknown_0x00;
		TES3DefaultTemplate_t * owner; // 0x04
		union {
			mwLong_t rank;
			void * variable;
		} rankVar; // 0x08
	};
	static_assert(sizeof(mwOwnerInfoNode_t) == 0x0C, "mwOwnerInfoNode_t failed size validation");

	// Can alternatively be one of the above mw*Node_t types.
	struct mwVarHolderNode_t
	{
		int unknown_0x00; // For items, this is the item count (as long).
		int unknown_0x04;
		int unknown_0x08;
		int unknown_0x0C; // For LOCK/REPAIR/WEAPON/ARMOR/PROBE, this is the current condition (as long).
		int unknown_0x10; // For enchanted items, this is the current charge (as a float).
		int unknown_0x14;
		mwVariablesNode_t * vars; // 0x18
	};
	static_assert(sizeof(mwVarHolderNode_t) == 0x1C, "mwVarHolderNode_t failed size validation");

	struct REFRRecord_t;

	enum Attributes
	{
		NoAttribute = -1,
		Strength,
		Intelligence,
		Willpower,
		Agility,
		Speed,
		Endurance,
		Personality,
		Luck,
		FirstAttribute = Strength,
		LastAttribute = Luck
	};

	enum SkillTypes
	{
		Major,
		Minor,
		Misc
	};

	enum Specializations
	{
		NoSpecialization = -1,
		Combat,
		Magic,
		Stealth,
		FirstSpecialization = Combat,
		LastSpecialization = Stealth
	};

	enum Skills
	{
		NoSkill = -1,
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

	struct MACPRecord_t
	{
		struct Skill
		{
			void* vtable;
			float base;
			float current;
			SkillTypes skillType;
		};
		struct Statistic
		{
			void* vtable;
			float base;
			float current;
		};
		struct ActiveEffect
		{
			ActiveEffect* next;
			ActiveEffect* previous;
			unsigned long id; //??? matches SPLLRecord
			unsigned short flags; //??? 0x0 for spells 0x68 for potions?
			unsigned short effect_type; // see Effects enum
			unsigned short detrimental; // 1 = yes, 0 = no
			unsigned short duration; // seconds
			unsigned short magnitude;
			unsigned short attribute_skill; // 255 if N/A see Attributes/Skills enums
		};
		void * vTable; // 0x0000
		RecordTypes::attachType_t recordType; // 0x0004 // "MACP"
		int unknown_0x0008[3];
		REFRRecord_t* reference; // 0x0014
		int unknown_0x0018[53]; // 0x0018
		MACPRecord_t* combatTarget; // 0x00EC // unverified
		int unknown_0x00F0[54]; // 0x00F0
		ActiveEffect* active_effects; // 0x01C8
		long num_active_effects; // 0x01CC // Number of active spells/effects.
		MACPRecord_t* self; // 0x01D0 // Pointer back to this record?
		int unknown_0x01D4[32];  // 0x01D4
		Statistic attributes[8]; // 0x0254
		Statistic health; // 0x02B4
		Statistic magicka; // 0x02C0
		Statistic weight_limit; // 0x02CC // base = max
		Statistic fatigue; // 0x02D8 // Fatigue has a different vtable pointer than the other Statistic objects.
		Statistic unknown_statistic; // 0x02E4
		unsigned long effect_attributes[27]; // 0x02E8
		int unknown_0x035C; // 0x035C
		mwShort_t gold; // 0x0360
		mwShort_t unknown_0x0362; // 0x0362
		int unknown_0x0364[5]; // 0x0364
		BaseRecord_t * currentSpell; // 0x0378
		int unknown_0x037C[3]; // 0x037C
		void* current_weapon; // 0x0388
		int unknown_0x038C[9]; // 0x038C
		Skill skills[27]; // 0x03B0
		int unknown_0x0560[34];  // 0x0560
		long levelProgress; // 0x05E8
		int unknown_0x05EC[2];  // 0x05EC
		float skillProgress[27]; // 0x05F4
	};
	static_assert(sizeof(MACPRecord_t::Skill) == 0x10, "MACPRecord_t::Skill failed size validation");
	static_assert(sizeof(MACPRecord_t::Statistic) == 0x0C, "MACPRecord_t::Statistic failed size validation");
	static_assert(sizeof(MACPRecord_t::ActiveEffect) == 0x18, "MACPRecord_t::ActiveEffect failed size validation");
	static_assert(sizeof(MACPRecord_t) == 0x660, "MACPRecord_t failed size validation");

	struct Effect_t {
		short effectId;
		char  skillId;
		char  attributeId;
		long  rangeType;		//0=SELF, 1=TOUCH, 2=TARGET
		long  area;
		long  duration;
		long  magMin;
		long  magMax;
	};
	static_assert(sizeof(Effect_t) == 0x18, "Effect_t failed size validation");

	struct SPELRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		unsigned long origin; // 0x08 Possibly record size instead?
		char * modNamePtr; // 0x0C
		long unknown_0x10;
		LinkedList_t<SPELRecord_t> * spellsList;
		long unknown_0x18;
		SPELRecord_t * prevRecord; // 0x1C
		SPELRecord_t * nextRecord; // 0x20
		long unknown_0x24;
		char * id; // 0x28
		char * friendlyName; // 0x2C
		short type; // 0x30 // 0=SPELL, 1=ABILITY, 2=BLIGHT, 3=DISEASE, 4=CURSE, 5=POWER
		short cost; // 0x32
		Effect_t effects[8]; // 0x34
		long flags;	// 0xF4 // 1=AUTOCALC, 2=PCSTART, 4=ALWAYSSUCCEEDS
	};
	static_assert(sizeof(SPELRecord_t) == 0xF8, "SPELRecord_t failed size validation");

	struct SPLLRecord_t
	{
		struct ActiveSpell_t
		{
			char * id; // 0x00 // "PlayerSaveGame" if player.
			REFRRecord_t * reference; // 0x04
			mwFloat_t statistic; // 0x08 // Magicka Resistance if applicable.
			unsigned long magnitude; // 0x0C
			mwFloat_t time; // 0x10 // Elapsed? Start?
		};
		struct Effect_t
		{
			void * vTable; // 0x00
			unsigned long inUse; // 0x04 // Number of null-pointers in array?
			unsigned long size; // 0x08
			ActiveSpell_t ** activeSpells; // 0x0C
		};
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		long unknown_0x08;
		long unknown_0x0C;
		long unknown_0x10;
		long unknown_0x14;
		long unknown_0x18;
		Effect_t effects[8]; // 0x1C
		long unknown_0x9C;
		SPELRecord_t * spell; // 0xA0
		long unknown_0xA4;
		long unknown_0xA8; // nth active effect? In cell?
		long unknown_0xAC;
		long unknown_0xB0;
		long unknown_0xB4;
		REFRRecord_t * reference; // 0xB8
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
	static_assert(sizeof(SPLLRecord_t::ActiveSpell_t) == 0x14, "SPLLRecord_t::ActiveSpell_t failed size validation");
	static_assert(sizeof(SPLLRecord_t::Effect_t) == 0x10, "SPLLRecord_t::Effect_t failed size validation");
	static_assert(sizeof(SPLLRecord_t) == 0x0104, "SPLLRecord_t failed size validation");

	// Some kind of tree?
	struct SPLLNode_t
	{
		SPLLNode_t * first; // 0x00
		SPLLNode_t * second; // 0x04
		SPLLNode_t * third; // 0x08
		unsigned long id; // 0x0C
		SPLLRecord_t * record; // 0x10
		unsigned long flag; // 0x14
		long unknown_0x18;
		long unknown_0x1C;
	};
	static_assert(sizeof(SPLLNode_t) == 0x20, "SPLLNode_t failed size validation");

	struct ALCHRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int recordSize; // 0x08
		char * modNamePtr; // 0x0C
		int unknown_0x10;
		LinkedList_t<ALCHRecord_t> * alchemyList; // 0x14
		int unknown_0x18;
		ALCHRecord_t * prevRecord; // 0x1C
		ALCHRecord_t * nextRecord; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		char * id; // 0x2C
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		char * friendlyName; // 0x44
		int unknown_0x48;
		char * model; // 0x4C
		char * icon; // 0x50
		mwFloat_t weight; // 0x54
		mwLong_t value; // 0x58
		Effect_t effects[8]; // 0x5C
		mwLong_t flags; // 0x011C // 1 = AUTOCALC
	};
	static_assert(sizeof(ALCHRecord_t) == 0x0120, "ALCHRecord_t failed size validation");

	struct ENCHRecord_t
	{
		void * vTable;
		RecordTypes::recordType_t recordType;
		int recordSize;
		char * modNamePtr;
		int unknown1;
		int unknown2;
		int unknown3;
		ENCHRecord_t * prevRecord;
		ENCHRecord_t * nextRecord;
		int unknown4;
		char * id;

		short type;	//0=CASTONCE, 1=CASTONSTRIKE, 2=CASTONUSED, 3=CONSTANT
		short cost;
		long charge;

		Effect_t effects[8];

		long autocalc;	//0=OFF, 1=ON
	};
	static_assert(sizeof(ENCHRecord_t) == 0xF8, "ENCHRecord_t failed size validation");

	struct RACERecord_t {
		struct SkillBonus_t
		{
			Skills skill;
			unsigned long bonus;
		};
		struct BaseAttribute_t
		{
			unsigned long male;
			unsigned long female;
		};
		struct HeightWeight_t
		{
			float male;
			float female;
		};
		struct BodyParts_t
		{
			// BODY records.
			BaseRecord_t * head1;
			BaseRecord_t * hair;
			BaseRecord_t * neck;
			BaseRecord_t * chest;
			BaseRecord_t * groin;
			BaseRecord_t * hands;
			BaseRecord_t * wrist;
			BaseRecord_t * forearm;
			BaseRecord_t * upper_arm;
			BaseRecord_t * foot;
			BaseRecord_t * ankle;
			BaseRecord_t * knee;
			BaseRecord_t * upper_leg;
			BaseRecord_t * unknown1;
			BaseRecord_t * tail;
			BaseRecord_t * head2;
			int unknown2[14];
		};
		void* v_table; // 0x0000
		RecordTypes::recordType_t record_type; // 0x0004 // "RACE"
		long unknown_0x0008;
		void * module; // 0x000C // Appears to be info about the module this record comes from.
		char id[32]; // 0x0010
		char name[32]; // 0x0030
		SkillBonus_t skill_bonuses[7]; // 0x0050
		BaseAttribute_t base_attributes[8]; // 0x0088 // Index corresponds to Attributes enum.
		HeightWeight_t height; // 0x00C8
		HeightWeight_t weight; // 0x00D0
		unsigned long flags; // 0x00D8 // 1 = playable, 2 = beast, 3 = both.
		int unknown_0x00DC; // Pointer?
		int unknown_0x00E0;
		int unknown_0x00E4;
		BodyParts_t male; // 0x00E8
		BodyParts_t female; // 0x0160
	};
	static_assert(sizeof(RACERecord_t::SkillBonus_t) == 0x08, "RACERecord_t::SkillBonus_t failed size validation");
	static_assert(sizeof(RACERecord_t::BaseAttribute_t) == 0x08, "RACERecord_t::BaseAttribute_t failed size validation");
	static_assert(sizeof(RACERecord_t::HeightWeight_t) == 0x08, "RACERecord_t::HeightWeight_t failed size validation");
	static_assert(sizeof(RACERecord_t::BodyParts_t) == 0x78, "RACERecord_t::BodyParts_t failed size validation");
	static_assert(sizeof(RACERecord_t) == 0x01D8, "RACERecord_t failed size validation");

	struct CLASRecord_t {
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 // "CLAS"

		int unknown_0x08;
		int unknown_0x0C; // Pointer?

		char id[32]; // 0x10
		char name[32]; // 0x30

		// Primary attributes:
		// 0 = Strength
		// 1 = Intelligence
		// 2 = Willpower
		// 3 = Agility
		// 4 = Speed 
		// 5 = Endurance
		// 6 = Personality
		// 7 = Luck

		unsigned long attributes[2]; // 0x50

		// Specializations:
		// 0 = Combat
		// 1 = Magic
		// 2 = Stealth

		unsigned long specialization; // 0x58

		// Skills:
		//  0 = Block
		//  1 = Armorer
		//  2 = Medium Armor
		//  3 = Heavy Armor
		//  4 = Blunt Weapon
		//  5 = Long Blade
		//  6 = Axe
		//  7 = Spear
		//  8 = Athletics
		//  9 = Enchant
		//  A = Destruction
		//  B = Alteration
		//  C = Illusion
		//  D = Conjuration
		//  E = Mysticism
		//  F = Restoration
		// 10 = Alchemy
		// 11 = Unarmored
		// 12 = Security
		// 13 = Sneak
		// 14 = Acrobatics
		// 15 = Light Armor
		// 16 = Short Blade
		// 17 = Marksman
		// 18 = Mercantile
		// 19 = Speechcraft
		// 1A = Hand-To-Hand

		// Even indices [0,2,4,6,8] are minor skills and odd indices [1,3,5,7,9] are major skills.
		// The nth major skill index corresponds to the nth major skill in the CS, from the top down.
		// E.g. skills[3] is the second major skill from the top of the list in the CS.
		// Minor skills have a different mapping:
		// Index | CS Position
		//     0 | 1
		//     2 | 4
		//     4 | 5
		//     6 | 3
		//     8 | 2

		unsigned long skills[10]; // 0x5C

		unsigned long playable; // 0x84 Is this class available to PC? 0 = no, 1 = yes

		unsigned long services; // 0x88

		int unknowns[5]; // 0x8C
	};
	static_assert(sizeof(CLASRecord_t) == 0xA0, "CLASRecord_t failed size validation");

	struct NPCBaseRecord_t	//or the 'base' NPC_ record. you can access it trough the NPCC (NPC Copy) Record (baseNPC)
	{
		void * vTable; // 0x0000
		RecordTypes::recordType_t recordType; // 0x0004
		int recordSize; // 0x0008 // Should be 0x0F0 big!
		char * modNamePtr; // 0x000C
		int unknown_0x0010;
		int unknown_0x0014;
		int unknown_0x0018;
		int unknown_0x001C; // STAT
		int unknown_0x0020;	// BODY
		int unknown_0x0024;
		int unknown_0x0028;
		char * objectId; // 0x002C
		int unknown_0x0030;
		int unknown_0x0034;
		int unknown_0x0038;
		int unknown_0x003C;
		int unknown_0x0040;
		int unknown_0x0044;	// Inventory amount?
		int unknown_0x0048;	// Inventory start?
		int unknown_0x004C;	// Inventory end?
		int unknown_0x0050;
		int unknown_0x0054;
		int unknown_0x0058;
		int unknown_0x005C;
		int unknown_0x0060;
		int unknown_0x0064;
		int unknown_0x0068;
		int unknown_0x006C;
		char * name; // 0x0070
		int unknown_0x0074;
		int unknown_0x0078;
		short level; // 0x007C
		short unknown_0x007E;
		int unknown_0x0080;
		int unknown_0x0084;
		int unknown_0x0088;
		int unknown_0x008C;
		int unknown_0x0090;
		int unknown_0x0094;
		int unknown_0x0098;
		int unknown_0x009C;
		int unknown_0x00A0;
		int unknown_0x00A4;
		int unknown_0x00A8;
		mwShort_t baseGold; // 0x00AC
		mwShort_t unknown_0x00AE;
		RACERecord_t * raceRecord; // 0x00B0
		CLASRecord_t * classRecord; // 0x00B4
		int unknown_0x00B8;	// BODY (head)
		int unknown_0x00BC;	// BODY (hair)
		int unknown_0x00C0;
		int unknown_0x00C4;
		int unknown_0x00C8;
		int numberOfSpells; // 0x00CC
		LinkedListNode_t<SPELRecord_t> * spellStart; // 0x00D0 // These contain the spells! Not items with a special power.
		LinkedListNode_t<SPELRecord_t> * spellEnd; // 0x00D4
		int unknown_0x00D8;
		int unknown_0x00DC;
		int unknown_0x00E0;
		int unknown_0x00E4;
		mwLong_t servicesMask; // 0xE8
	};
	static_assert(sizeof(NPCBaseRecord_t) == 0xEC, "NPCBaseRecord_t failed size validation");

	struct NPCCopyRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int unknown_0x08; //int RecordSize; ?
		int unknown_0x0C; //char * modNamePtr; ?
		int unknown_0x10;
		int unknown_0x14;
		BaseRecord_t * reference; // 0x18
		BaseRecord_t * prevRecord; // 0x1C
		BaseRecord_t * nextRecord; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		char * objectId; // 0x2C
		int unknown_0x30;
		unsigned long flags; // 0x34
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int inventorySize; // 0x44
		LinkedList_t<TES3DefaultTemplate_t> * inventoryStart; // 0x48
		LinkedList_t<TES3DefaultTemplate_t> * inventoryEnd; // 0x4C
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58; // Pointer?
		int amountEquiped; // 0x5C
		LinkedList_t<TES3DefaultTemplate_t> * equipedStart; // 0x60
		LinkedList_t<TES3DefaultTemplate_t> * equipedEnd; // 0x64
		int unknown_0x68;
		NPCBaseRecord_t * baseNPC; // 0x6C
	};
	static_assert(sizeof(NPCCopyRecord_t) == 0x70, "NPCBaseRecord_t failed size validation");

	struct TES3Cell_t;

	struct REFRRecord_t
	{
		struct Unknown1_t {
			int unknown_0x00; // Reference?
			int unknown_0x04; // Reference?
			int unknown_0x08; // Reference?
			TES3Cell_t * cell; // 0x0C // Current cell.
		};
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 // "REFR"
		long flags; // 0x08 // 0x50 big, should this be! // 0x800 bit is isEnabled
		char* modNamePtr; // 0x0C
		int unknown_0x10;
		REFRRecord_t::Unknown1_t * unknown_0x14;
		REFRRecord_t * nextOfSameTemplate; // 0x18
		REFRRecord_t * previousRecord; // 0x1C
		REFRRecord_t * nextRecord; // 0x20
		int unknown_0x24;
		BaseRecord_t * recordPointer; // 0x28 // Points to the record for which this is a reference.
		char unknown_0x2C[12]; // 0x2C // 12 bytes?
		float x; // 0x38
		float y; // 0x3C
		float z; // 0x40
		ListNode_t<BaseRecord_t> * attachments; // 0x44
		char unknown_0x48[18]; // 0x48 // 18 bytes?
	};
	static_assert(sizeof(REFRRecord_t) == 0x5C, "REFRRecord_t failed size validation");

	struct TES3RefListHead_t {
		long size;
		REFRRecord_t * first;
		REFRRecord_t * last;
		REFRRecord_t * container;
	};
	static_assert(sizeof(TES3RefListHead_t) == 0x10, "TES3RefListHead_t failed size validation");

	// Copied from WEAPRecord - needs to be verified.
	struct ARMORecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 "ARMO"
		int recordSize; // 0x08
		char * modNamePtr; // 0x0C
		int unknown_0x10;
		int unknown_0x14;
		REFRRecord_t * nextOfSameTemplate; // 0x18
		REFRRecord_t * previousRecord; // 0x1C
		REFRRecord_t * nextRecord; // 0x20
		void * unknown_0x24;
		int unknown_0x28;
		char * objectId; // 0x2C
		void * unknownFunctionPtr; // 0x30
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		char * name; // 0x44
		int unknown_0x48; // char * scriptIDStringPtr;
		char * model; // 0x4C
		char * texture; // 0x50
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60[4];
		int unknown_0x70[4];
		int unknown_0x80[4];
		int unknown_0x90[3];
		mwShort_t maxCondition; // 0x9C
		mwShort_t unknown_0x9E;
		int unknown_0xA0[3];
		mwFloat_t weight; // 0xAC
		mwLong_t value; // 0xB0
		int unknown_0xB4[3]; // 0xB4
		ENCHRecord_t * enchantment; // 0xC0
	};
	static_assert(sizeof(ARMORecord_t) == 0xC4, "ARMO record size check failed.");

	// Copied from WEAPRecord - needs to be verified.
	struct CLOTRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 "CLOT"
		int recordSize; // 0x08
		char * modNamePtr; // 0x0C
		int unknown_0x10;
		int unknown_0x14;
		REFRRecord_t * nextOfSameTemplate; // 0x18
		REFRRecord_t * previousRecord; // 0x1C
		REFRRecord_t * nextRecord; // 0x20
		void * unknown_0x24;
		int unknown_0x28;
		char * objectId; // 0x2C
		void * unknownFunctionPtr; // 0x30
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		char * nameStringPtr; // 0x44
		int unknown_0x48;	//char * scriptIDStringPtr;
		char * nifStringPtr; // 0x4C
		char * tgaStringPtr; // 0x50
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C[19];
		int unknown_0xA4;
		mwFloat_t weight; // 0xA8
		mwShort_t value; // 0xB0
		mwShort_t unknown_0xB2;
		ENCHRecord_t * enchantment; // 0xB4
	};
	static_assert(sizeof(CLOTRecord_t) == 0xB8, "CLOTRecord_t failed size validation");

	struct WEAPRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 "WEAP"
		int recordSize; // 0x08
		char * modNamePtr; // 0x0C
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18; //REFRRecord_t * first //nextOfSameTemplate
		BaseRecord_t * previousRecord; // 0x1C
		BaseRecord_t * nextRecord; // 0x20
		void * unknown_0x24;
		int unknown_0x28;
		char * objectId; // 0x2C
		void * unknownFunctionPtr; // 0x30
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		char * nameStringPtr; // 0x44
		char * model; // 0x48
		int unknown_0x4C; // 0x4C
		char * tgaStringPtr; // 0x50
		mwFloat_t weight; // 0x54
		mwLong_t value; // 0x58
		short weaponType; // 0x5C
		short maxCondition; // 0x5E
		float speed; // 0x60
		float reach; // 0x64
		short enchantPoints; // 0x68
		char chopMin; // 0x6A
		char chopMax; // 0x6B
		char slashMin; // 0x6C
		char slashMax; // 0x6D
		char trustMin; // 0x6E
		char trustMax; // 0x6F
		long flags; // 0x70
		ENCHRecord_t * enchantment; // 0x74
	};
	static_assert(sizeof(WEAPRecord_t) == 0x78, "WEAPRecord_t failed size validation");

	struct AMMORecord_t {
		void * vtable; // 0x00
		RecordTypes::recordType_t record_type; //0x04 AMMO
		long unknown_0x08;
		void * module; // 0x0C pointer to module?
		long unknown_0x10;
		long unknown_0x14;
		long unknown_0x18;
		AMMORecord_t * next; // 0x1C
		AMMORecord_t * previous; // 0x20
		long unknown_0x24;
		long unknown_0x28;
		char * id; // 0x2C
		long unknown_0x30;
		long unknown_0x34;
		long unknown_0x38;
		long unknown_0x3C;
		long unknown_0x40;
		char * name; // 0x44
		long unknown_0x48;
		char * model; // 0x4C
		char * texture; // 0x50
		mwFloat_t weight; // 0x54
		mwLong_t value; // 0x58
		long unknown_0x5C;
		long unknown_0x60;
		long unknown_0x64;
		long unknown_0x68;
		long unknown_0x6C;
		long unknown_0x70;
		ENCHRecord_t* enchantment; // 0x74
	};
	static_assert(sizeof(AMMORecord_t) == 0x78, "AMMORecord_t failed size validation");

	struct LOCKRecord_t {
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 "LOCK"
		int recordSize; // 0x08
		char * modNamePtr; // 0x0C
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18; //REFRRecord_t * first //nextOfSameTemplate
		void * previousRecord; // 0x1C
		void * nextRecord; // 0x20
		void * unknown_0x24;
		int unknown_0x28; // 0x28
		char * objectid; // 0x2C
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		char name[32]; // 0x44
		int unknown_0x64;
		char modal[32]; // 0x68
		char texture[32]; // 0x88
		mwFloat_t weight; // 0xA8
		mwLong_t value; // 0xAC
		mwFloat_t quality; // 0xB0
		mwShort_t maxCondition; // 0xB4
		mwShort_t unknown_0xB6;
	};
	static_assert(sizeof(LOCKRecord_t) == 0xB8, "LOCKRecord_t failed size validation");

	struct PROBRecord_t {
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 "PROB"
		int recordSize; // 0x08
		char * modNamePtr; // 0x0C
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18; //REFRRecord_t * first //nextOfSameTemplate
		void * previousRecord; // 0x1C
		void * nextRecord; // 0x20
		void * unknown_0x24;
		int unknown_0x28; // 0x28
		char * objectid; // 0x2C
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		int unknown_0x48;
		int unknown_0x4C;
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60;
		int unknown_0x64;
		char model[32]; // 0x68
		char texture[32]; // 0x88
		mwFloat_t weight; // 0xA8
		mwLong_t value; // 0xAC
		mwFloat_t quality; // 0xB0
		mwShort_t maxCondition; // 0xB4
		mwShort_t unknown_0xB6;
	};
	static_assert(sizeof(PROBRecord_t) == 0xB8, "PROBRecord_t failed size validation");

	struct REPARecord_t {
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 "PROB"
		int recordSize; // 0x08
		char * modNamePtr; // 0x0C
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18; //REFRRecord_t * first //nextOfSameTemplate
		void * previousRecord; // 0x1C
		void * nextRecord; // 0x20
		void * unknown_0x24;
		int unknown_0x28; // 0x28
		char * objectid; // 0x2C
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		int unknown_0x48;
		int unknown_0x4C;
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		char model[32]; // 0x60
		char texture[32]; // 0x80
		int unknown_0xA0;
		int unknown_0xA4;
		mwFloat_t weight; // 0xA8
		mwLong_t value; // 0xAC
		mwShort_t maxCondition; // 0xB0
		mwShort_t unknown_0xB2;
		mwFloat_t quality; // 0xB4
	};
	static_assert(sizeof(REPARecord_t) == 0xB8, "REPARecord_t failed size validation");

	struct MISCRecord_t {
		void * vtable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 // "MISC"
		int unknown_0x08;
		void * module; // 0x0C // Pointer to module?
		int unknown_0x10;
		void * unknown_0x14; // Pointer to list?
		int unknown_0x18;
		MISCRecord_t * previous; // 0x1C // Previous item in list.
		MISCRecord_t * next; // 0x20 // Next item in list.
		int unknown_0x24;
		int unknown_0x28;
		char * id; // 0x2C
		void * vtable2; // 0x30 // vtable of embedded object?
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44; // 0x44
		int unknown_0x48; // 0x48
		char* model; // 0x4C
		char* texture; // 0x50
		mwFloat_t weight; // 0x54
		mwLong_t value; // 0x58
		long scroll; // 0x5C
		long skill; // 0x60
		long enchantCapacity; // 0x64
		ENCHRecord_t * enchantment; // 0x68
	};
	static_assert(sizeof(MISCRecord_t) == 0x6C, "MISCRecord_t failed size validation");

	struct BOOKRecord_t {
		void * vtable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int unknown_0x08;
		void * module; // 0x0C // Pointer to module?
		int unknown_0x10;
		void * unknown_0x14; // Pointer to list?
		int unknown_0x18;
		BOOKRecord_t * previous; // 0x1C // Previous item in list.
		BOOKRecord_t * next; // 0x20 // Next item in list.
		int unknown_0x24;
		int unknown_0x28;
		char * id; // 0x2C
		void * vtable2; // 0x30 // vtable of embedded object?
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		char * name; // 0x44
		void * script; // 0x48
		char * model; // 0x4C
		char * texture; // 0x50
		mwFloat_t weight; // 0x54
		mwLong_t value; // 0x58
		long scroll; // 0x5C
		long skill; // 0x60
		long enchantCapacity; // 0x64
		ENCHRecord_t * enchantment; // 0x68
		void* vtable3; // 0x6C // vtable of embedded object?
		int unknown_0x70;
		int unknown_0x74;
		int unknown_0x78;
		int unknown_0x7C;
		void * unknown_0x80;
		void * unknown_0x84;
	};
	static_assert(sizeof(BOOKRecord_t) == 0x88, "BOOKRecord_t failed size validation");

	struct FACTRecord_t {
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 // "FACT"
		int unknown_0x08;
		int unknown_0x0C;
		char id[32]; // 0x10
		char name[32]; // 0x30
		char ranks[10][32]; // 0x50
		int unknown2[71]; // 0x190
	};
	static_assert(sizeof(FACTRecord_t) == 0x02AC, "FACTRecord_t failed size validation");

	struct GLOBRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int recordsize; // 0x08
		char * modNamePtr; // 0x0C
		char globalName[32]; // 0x10
		char variableType; // 0x30 // Morrowind converts this to uppercase, can be 'l', 's', 'f' (long, short, float).
		char unknown[3]; // 0x31 // 3 bytes of padding.
		float data; // 0x34 // Apparently, all globals are stored as floats in morrowind (i think), at least for longs!
	};
	static_assert(sizeof(GLOBRecord_t) == 0x38, "GLOBRecord_t failed size validation");

	struct GMSTRecord_t {
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int unknown; // 0x08
		void * mod; // 0x0C // Pointer to mod?
		union values
		{
			long long_value;
			float float_value;
			char* string_value;
		} value; // 0x10
		int index; // 0x14 // Array index of this GMST
		int unknown_0x18;
		int unknown_0x1C;
	};
	static_assert(sizeof(GMSTRecord_t) == 0x20, "GMSTRecord_t failed size validation");

	struct SKILRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 // "SKIL"
		int unknown_0x08; // 0x08
		void * unknown_0x0C; // 0x0C // Pointer to first array element?
		long skill; // 0x10
		long attribute; // 0x14
		long specialization; // 0x18
		float actions[4]; // 0x1C
		int unknown_0x2C; // 0x2C
		int unknown_0x30; // 0x30
	};
	static_assert(sizeof(SKILRecord_t) == 0x34, "SKILRecord_t failed size validation");

	struct CONTRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int unknown_0x08;
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		CONTRecord_t * firstRecord; // 0x18
		CONTRecord_t * previousRecord; // 0x1C
		CONTRecord_t * nextRecord; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		int unknown_0x2C;
		char * objectId; // 0x30
		int unknown_0x34;
		int unknown_0x38;
		mwLong_t inventoryFlags; // 0x3C
		ListIterator_t<InventoryNode_t> inventory; // 0x40
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		char * name; // 0x6C
		char * model; // 0x70
		int unknown_0x74;
		mwFloat_t weight; // 0x78
	};
	static_assert(sizeof(CONTRecord_t) == 0x7C, "CONTRecord_t failed size validation");

	struct LIGHRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int unknown_0x08;
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		LIGHRecord_t * firstRecord; // 0x18
		LIGHRecord_t * previousRecord; // 0x1C
		LIGHRecord_t * nextRecord; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		int unknown_0x2C;
		char * objectId; // 0x30
		int unknown_0x34; // Empty string?
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		char * name; // 0x48
		int unknown_0x4C;
		char * model; // 0x50
		char * icon; // 0x54
		mwFloat_t weight; // 0x58
		mwLong_t value; // 0x5C
	};
	static_assert(sizeof(LIGHRecord_t) == 0x60, "LIGHRecord_t failed size validation");

	struct ACTIRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int unknown_0x08;
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		TES3DefaultTemplate_t * previousRecord; // 0x1C
		TES3DefaultTemplate_t * nextRecord; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		int unknown_0x2C;
		char * objectId; // 0x30
		char * model; // 0x34
		char * name; // 0x38
	};
	static_assert(sizeof(ACTIRecord_t) == 0x3C, "ACTIRecord_t failed size validation");

	struct STATRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int unknown_0x08;
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		TES3DefaultTemplate_t * previousRecord; // 0x1C
		TES3DefaultTemplate_t * nextRecord; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		int unknown_0x2C;
		char * model; // 0x30
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
	};
	static_assert(sizeof(STATRecord_t) == 0x40, "STATRecord_t failed size validation");

	struct DOORRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int unknown_0x08;
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		TES3DefaultTemplate_t * previousRecord; // 0x1C
		TES3DefaultTemplate_t * nextRecord; // 0x20
		char * unknown_0x24;
		char * unknown_0x28;
		char * objectId; // 0x2C
		int unknown_0x30;
		char name[32]; // 0x34
		char model[32]; // 0x54
	};
	static_assert(sizeof(DOORRecord_t) == 0x74, "DOORRecord_t failed size validation");

	struct APPARecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int unknown_0x08;
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		TES3DefaultTemplate_t * previousRecord; // 0x1C
		TES3DefaultTemplate_t * nextRecord; // 0x20
		char * unknown_0x24;
		char * unknown_0x28;
		char * objectId; // 0x2C
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		ListIterator_t<BaseRecord_t> * inventory; // 0x40
		char model[32]; // 0x44
		char name[32]; // 0x64
		char texture[32]; // 0x84
		int unknown_0xA4;
		int unknown_0xA8;
		mwFloat_t quality; // 0xAC
		mwFloat_t weight; // 0xB0
		mwLong_t value; // 0xB4
	};
	static_assert(sizeof(APPARecord_t) == 0xB8, "APPARecord_t failed size validation");

	struct INGRRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int unknown_0x08;
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		TES3DefaultTemplate_t * previousRecord; // 0x1C
		TES3DefaultTemplate_t * nextRecord; // 0x20
		char * unknown_0x24;
		char * unknown_0x28;
		char * objectId; // 0x2C
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		char name[32]; // 0x44
		char model[32]; // 0x64
		char texture[32]; // 0x84
		int unknown_0xA4;
		int unknown_0xA8;
		int unknown_0xAC;
		mwLong_t effects[4]; // 0xB0
		mwLong_t effectSkillIds[4]; // 0xC0
		mwLong_t effectAttributeIds[4]; // 0xD0
	};
	static_assert(sizeof(INGRRecord_t) == 0xE0, "INGRRecord_t failed size validation");

	struct MGEFRecord_t
	{
		void* vtable; // 0x00
		RecordTypes::recordType_t record_type; // 0x04
		int unknown_0x08;
		void * module; // 0x0C // Pointer to module?
		long index; // 0x10 // Index in array.
		int unknown_0x14;
		int unknown_0x18;
		char effect_icon[32]; // 0x1C
		char particle_texture[32]; // 0x3C
		// Only a few effects have data in their sound effect strings.
		// Maybe it's inferred from school if missing?
		char cast_sound_effect[32]; // 0x5C
		char bolt_sound_effect[32]; // 0x7C
		char hit_sound_effect[32]; // 0x9C
		char area_sound_effect[32]; // 0xBC
		void * unknown_0xDC; // Visual effect?
		void * unknown_0xE0; // Visual effect?
		void * unknown_0xE4; // Visual effect?
		void * unknown_0xE8; // Visual effect?
		MagicSchools school; // 0xEC // 0 = Alteration, 1 = Conjuration, 2 = Destruction, 3 = Illusion, 4 = Mysticism, 5 = Restoration
		float base_magicka_cost; // 0xF0
		long flags; // 0xF4 // 0x200 = spellmaking, 0x400 = enchanting, 0x800 = negative lighting effect
		long red; // 0xF8
		long green; // 0xFC
		long blue; // 0x0100
		float size_x; // 0x0104
		float speed_x; // 0x0108
		float size_cap; // 0x010C
	};
	static_assert(sizeof(MGEFRecord_t) == 0x0110, "MGEFRecord_t failed size validation");

	//this is the struct behind 'master2'
	struct TES3ViewMaster_t
	{
		char unknown[232];
		REFRRecord_t * target;
	};
	static_assert(sizeof(TES3ViewMaster_t) == 0xEC, "TES3ViewMaster_t failed size validation");

	struct CREABaseRecord_t {
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		mwLong_t unknown_0x08;
		mwLong_t unknown_0x0C;
		mwLong_t unknown_0x10;
		mwLong_t unknown_0x14;
		REFRRecord_t* first; // 0x18
		mwLong_t unknown_0x1C;
		mwLong_t unknown_0x20;
		mwLong_t unknown_0x24;
		mwLong_t unknown_0x28;
		char * objectId; // 0x2C
		mwLong_t unknown_0x30;
		mwLong_t unknown_0x34;
		mwLong_t unknown_0x38;
		mwLong_t unknown_0x3C;
		ListIterator_t<BaseRecord_t> * inventory; // 0x40
		mwLong_t unknown_0x44;
		mwLong_t unknown_0x48;
		mwLong_t unknown_0x4C;
		mwLong_t unknown_0x50;
		mwLong_t unknown_0x54;
		mwLong_t unknown_0x58;
		mwLong_t unknown_0x5C;
		mwLong_t unknown_0x60;
		mwLong_t unknown_0x64;
		mwLong_t unknown_0x68;
		mwLong_t unknown_0x6C;
		char * name; // 0x0070
		mwLong_t unknown_0x74;
		mwLong_t unknown_0x78;
		mwLong_t unknown_0x7C;
		mwLong_t unknown_0x80;
		mwLong_t unknown_0x84;
		mwLong_t unknown_0x88;
		mwLong_t unknown_0x8C;
		mwLong_t unknown_0x90;
		mwLong_t unknown_0x94;
		mwLong_t unknown_0x98;
		mwLong_t unknown_0x9C;
		mwLong_t unknown_0xA0;
		mwLong_t unknown_0xA4;
		mwLong_t unknown_0xA8;
		mwLong_t unknown_0xAC;
		mwLong_t unknown_0xB0;
		mwLong_t unknown_0xB4;
		mwLong_t unknown_0xB8;
		mwLong_t unknown_0xBC;
		mwLong_t unknown_0xC0;
		mwLong_t unknown_0xC4;
		mwLong_t unknown_0xC8;
		mwLong_t unknown_0xCC;
		mwLong_t unknown_0xD0;
		mwLong_t unknown_0xD4;
		mwShort_t baseGold; // 0xD8 -- Base barter gold.
	};
	static_assert(sizeof(CREABaseRecord_t) == 0xDC, "CREABaseRecord_t failed size validation");

	struct CREACopyRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04
		int unknown_0x08; // 0x08 // Record size?
		int unknown_0x0C; // 0x0C // char * modNamePtr; ?
		int unknown_0x10;
		int unknown_0x14;
		BaseRecord_t * reference; // 0x18
		BaseRecord_t * prevRecord; // 0x1C
		BaseRecord_t * nextRecord; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		char * objectId; // 0x2C
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int inventorySize; // 0x44
		LinkedList_t<TES3DefaultTemplate_t> * inventoryStart; // 0x48
		LinkedList_t<TES3DefaultTemplate_t> * inventoryEnd; // 0x4C
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58; // Pointer?
		int amountEquiped; // 0x5C
		LinkedList_t<TES3DefaultTemplate_t> * equipedStart; // 0x60
		LinkedList_t<TES3DefaultTemplate_t> * equipedEnd; // 0x64
		int unknown_0x68;
		CREABaseRecord_t * baseCreature; // 0x6C
	};
	static_assert(sizeof(CREACopyRecord_t) == 0x70, "CREACopyRecord_t failed size validation");

	struct RecordLists_t {
		struct UnknownStruct
		{
			void* v_table; // 0x00
			unsigned long unknown_0x04; // 0x04
			void* unknown_0x08;
			void* unknown_0x0C;
			void* unknown_0x10;
			unsigned long unknown_0x14;
			unsigned long unknown_0x18;
			unsigned long unknown_0x1C;
			unsigned long unknown_0x20;
			unsigned long unknown_0x24;
			unsigned long unknown_0x28;
			void* unknown_0x2C;
		};
		unsigned long unknown_0x00; // 
		unsigned long unknown_0x04; // always 0 ???
		BaseRecord_t * unknown_0x08; // points to info about the last loaded save
						 // list contains the following types: CREA, REPA, APPA, PROB, MISC, LEVC,
						 // ALCH, ENCH, LIGH, ACTI, LEVI, LOCK, BOOK, AMMO, ARMO, WEAP, INGR, DOOR,
						 // STAT, CONT, CLOT, BODY, NPC_
		LinkedList_t<TES3DefaultTemplate_t> * list; // 0x0C
		LinkedList_t<SPELRecord_t> * spellsList; // 0x10
		void * unknown_0x14;
		GMSTRecord_t ** GMSTs; // 0x18 // Pointer to array of GMST pointers.
		UnknownStruct* unknown5[12]; // 0x1C
		SKILRecord_t skills[27]; // 0x4C
		MGEFRecord_t magic_effects[143]; // 0x05C8
	};
	static_assert(sizeof(RecordLists_t::UnknownStruct) == 0x30, "RecordLists_t::UnknownStruct failed size validation");
	static_assert(sizeof(RecordLists_t) == 0x9DB8, "RecordLists_t failed size validation");

	struct TES3Cell_t {
		char unknown_0x00[16];
		char * cellname; // 0x10 // May be null.
		char unknown_0x14[28];
		TES3RefListHead_t npc; // 0x30
		TES3RefListHead_t statics; // 0x40
		long unknown_0x50;
		long unknown_0x54;
		TES3RefListHead_t otheritems; // 0x58
	};
	static_assert(sizeof(TES3Cell_t) == 0x68, "TES3Cell_t failed size validation");

	struct TES3CellPointer_t {
		long size;
		TES3Cell_t * first;
	};
	static_assert(sizeof(TES3CellPointer_t) == 0x08, "TES3CellPointer_t failed size validation");

	enum TES3CellGrid {
		NORTHWEST = 0,
		NORTH = 1,
		NORTHEAST = 2,
		WEST = 3,
		CENTER = 4,
		EAST = 5,
		SOUTHWEST = 6,
		SOUTH = 7,
		SOUTHEAST = 8
	};

	struct TES3Master_t {
		struct Unknown1_t {
			long unknown_0x00;
			long unknown_0x04;
			long unknown_0x08;
			SPLLNode_t * unknown_0x0C;
		};
		long unknown_0x00;
		long unknown_0x04;
		long unknown_0x08;
		long unknown_0x0C;
		long unknown_0x10;
		long unknown_0x14;
		long unknown_0x18;
		long unknown_0x1C;
		long unknown_0x20;
		long unknown_0x24;
		long unknown_0x28;
		long unknown_0x2C;
		long unknown_0x30;
		long unknown_0x34;
		long unknown_0x38;
		long unknown_0x3C;
		long unknown_0x40;
		long unknown_0x44;
		long unknown_0x48;
		long unknown_0x4C;
		long unknown_0x50;
		long unknown_0x54;
		long unknown_0x58;
		long unknown_0x5C;
		long unknown_0x60;
		long unknown_0x64;
		long unknown_0x68;
		long unknown_0x6C;
		Unknown1_t * unknown_0x70; // 
		long unknown_0x74;
		long unknown_0x78;
		long unknown_0x7C;
	};

	struct TES3CellMaster_t {
		RecordLists_t * recordLists; // 0x00
		TES3CellPointer_t * exteriorCells[9]; // 0x04
		int unknown_0x28[33]; // 0x28
		TES3Cell_t * interiorCell; // 0xAC
		int unknown_0xB0[4]; // 0xB0
	};
	static_assert(sizeof(TES3CellMaster_t) == 0xC0, "TES3CellMaster_t failed size validation");
}
