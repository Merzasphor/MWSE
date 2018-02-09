#pragma once

/*
	Objects in Morrowind have a 4-byte 
*/

typedef short mwShort;
typedef long  mwLong;
typedef float mwFloat;
typedef char* mwString;

namespace TES3 {
	namespace ObjectType {
		enum ObjectType
		{
			Activator = 'ITCA',
			Alchemy = 'HCLA',
			Ammo = 'OMMA',
			Apparatus = 'APPA',
			Armor = 'OMRA',
			Book = 'KOOB',
			Bodypart = 'YDOB',
			Birthsign = 'NGSB',
			Cell = 'LLEC',
			Class = 'SALC',
			Clothing = 'TOLC',
			Container = 'TNOC',
			Creature = 'AERC',
			Dialog = 'GAID',
			Door = 'ROOD',
			Enchantment = 'HCNE',
			Faction = 'TCAF',
			Global = 'BOLG',
			GameSetting = 'TSMG',
			DialogInfo = 'OFNI',
			Ingredient = 'RGNI',
			Land = 'DNAL',
			LevelledCreature = 'CVEL',
			LevelledItem = 'IVEL',
			Light = 'HGIL',
			Lockpick = 'KCOL',
			LandTexture = 'XETL',
			Macp = 'PCAM',
			Misc = 'CSIM',
			MagicEffect = 'FEGM',
			NPC = '_CPN',
			PathGrid = 'DRGP',
			Probe = 'BORP',
			Race = 'ECAR',
			Reference = 'RFER',
			Region = 'NGER',
			Repair = 'APER',
			Script = 'TPCS',
			Skill = 'LIKS',
			SoundGenerator = 'GDNS',
			Sound = 'NUOS',
			Spell = 'LEPS',
			Spll = 'LLPS',
			Static = 'TATS',
			TES3 = '3SET',
			Weapon = 'PAEW',
		};
	}

	struct Ammo;
	struct Activator;
	struct Alchemy;
	struct Apparatus;
	struct Armor;
	struct Book;
	struct Cell;
	struct CellMaster;
	struct Class;
	struct Clothing;
	struct Container;
	struct Door;
	struct Effect;
	struct Enchantment;
	struct GameSetting;
	struct GlobalVariable;
	struct Ingredient;
	struct Light;
	struct Lockpick;
	struct MACP;
	struct MagicEffect;
	struct Master;
	struct Misc;
	struct NPC;
	struct NPCInstance;
	struct Probe;
	struct Race;
	struct Reference;
	struct Region;
	struct Repair;
	struct Script;
	struct Skill;
	struct Sound;
	struct Spell;
	struct Static;
	struct ViewMaster;
	struct Weapon;

	struct BaseObject_vTable {

	};

	struct BaseObject {
		BaseObject_vTable * vTable;
		ObjectType::ObjectType objectType;
		mwLong unknown_0x08;
		mwLong unknown_0x0C;
		mwLong unknown_0x10;
		mwLong unknown_0x14;
		mwLong unknown_0x18;
		BaseObject * previousRecord; // 0x1C
		BaseObject * nextRecord; // 0x20
		mwLong unknown_0x24;
		mwLong unknown_0x28;
		mwString objectID; // 0x2C
	};

	// TODO: Move this to its own TES3Attribute thing? Do attributes have an object/record?enum Attributes
	enum Attributes {
		AttributeInvalid = -1,
		AttributeStrength,
		AttributeIntelligence,
		AttributeWillpower,
		AttributeAgility,
		AttributeSpeed,
		AttributeEndurance,
		AttributePersonality,
		AttributeLuck,
		FirstAttribute = AttributeStrength,
		LastAttribute = AttributeLuck
	};
}
