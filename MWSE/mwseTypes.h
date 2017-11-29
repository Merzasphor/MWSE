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
	typedef unsigned short mwOpcode_t; //same as old MWSE (WORD == unsigned short) should be big enough

	namespace RecordTypes {
		enum recordType_t
		{
			NPC = '_CPN',
			CREA = 'AERC', CREATURE = CREA,
			CONT = 'TNOC', CONTAINER = CONT,
			LIGH = 'HGIL', LIGHT = LIGH,
			MISC = 'CSIM',
			CLOT = 'TOLC', CLOTHING = CLOT,
			WEAP = 'PAEW', WEAPON = WEAP,
			ARMO = 'OMRA', ARMOR = ARMO,
			BOOK = 'KOOB',
			ALCH = 'HCLA', ALCHEMY = ALCH,
			ACTI = 'ITCA', ACTIVATOR = ACTI,
			DOOR = 'ROOD',
			APPA = 'APPA', APPARATUS = APPA,
			INGR = 'RGNI', INGREDIENT = INGR,
			PROB = 'BORP', PROBE = PROB,
			PICK = 'KCIP', // Is this record used?
			REPA = 'APER', REPAIR = REPA,
			CLAS = 'SALC', CLASS = CLAS,
			LOCK = 'KCOL', LOCKPICK = LOCK,
			GLOB = 'BOLG', GLOBAL = GLOB,
			REFR = 'RFER', REFERENCE = REFR,
			MACP = 'PCAM'
		};

		enum attachType_t
		{
			VARNODE = 6,	//attachment where 'local' variables are stored, and the size of a stack, and the owner (if it has changed i think), and the script...
			MACHNODE = 8	//PCAM
		};
	};

	struct BaseRecord_t
	{
		void * vTable;
		RecordTypes::recordType_t recordType;
	};

	struct SCPTRecord_t
	{
		void * vTable; //pointer to the vTable
		RecordTypes::recordType_t recordType; // "SCPT"
		int recordSize;
		char * modNamePtr;
		char scriptName[32];
		long numShorts;
		long numLongs;
		long numFloats;
		long scriptDataSize;
		int LocalVarSize; //the length of the local var names concatenated (includes \0 for string endings)
		char ** shortVarNamePointers;
		char ** longVarNamePointers;
		char ** floatVarNamePointers;
		char * varNamePointers;
		int unknownData;	//equals zero
		void * machineCode;
		mwShort_t * shortVarValues; //pointer to array of shorts, each associated with its corresponding variable
		mwLong_t * longVarValues;
		mwFloat_t * floatVarValues;
	};

	struct SCPTNode_t
	{
		int unknown;
		SCPTRecord_t * scptRecord;
	};

	struct LinkedList_t
	{
		LinkedList_t * previousNode;
		LinkedList_t * nextNode;
		void * dataNode;
	};

	struct InventoryNode_t
	{
		int itemCount;
		void * recordAddress;
	};

	struct ListNode_t
	{
		RecordTypes::attachType_t attachType;
		ListNode_t * nextNode;
		void * dataPtr;
	};

	struct ListIterator_t
	{
		char unknown[8];
		ListNode_t * first;
		char unknown2[4];
		ListNode_t * current;
	};

	struct mwVariablesNode_t
	{
		mwShort_t * shortVarValues;
		mwLong_t * longVarValues;
		mwFloat_t * floatVarValues;
	};

	struct mwVarHolderNode_t
	{
		int unknown_0x00;
		int unknown_0x04;
		int unknown_0x08;
		int unknown_0x0C; // For LOCK/REPAIR/WEAPON/ARMOR/PROBE, this is the current condition (as long).
		int unknown_0x10; // For enchanted items, this is the current charge (as a float).
		int unknown_0x14;
		mwVariablesNode_t * vars; // 0x18
	};

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
		void * vTable; // 0
		RecordTypes::attachType_t recordType; // "MACP" // 4
		int unknown1[3]; //8
		REFRRecord_t* reference; //20
		int unknown2[53]; //24
		MACPRecord_t* combatTarget; // unverified // 236
		int unknown3[54]; // 240
		ActiveEffect* active_effects; // 454
		long num_active_effects; // 460 // number of active spells / effects
		MACPRecord_t* self; // 464 // pointer back to this record?
		int unknown[32];  // 468
		Statistic attributes[8]; // 596
		Statistic health; // 692
		Statistic magicka; // 704
		Statistic weight_limit; // 716 // base = max
		Statistic fatigue; // 728 // fatigue has a different vtable pointer than the other Statistic objects.
		Statistic unknown_statistic; // 740
		unsigned long effect_attributes[27]; // 752
		int unknown4[7]; // 860
		void * currentSpell; // 888
		int unknown5[3]; // 892
		void* current_weapon; // 904
		int unknown6[9]; // 908
		Skill skills[27]; // 944
		int unknown7[34];  // 1376
		long levelProgress; // 1512
		int unknown8[2];  // 1516
		float skillProgress[27]; // 1524
	};

	struct SPELRecord_t
	{
		void * vTable;
		RecordTypes::recordType_t recordType;
		int recordSize;
		char * modNamePtr;
		int unknown1;
		int unknown2;
		int unknown3;
		SPELRecord_t * prevRecord;
		SPELRecord_t * nextRecord;
		int unknown4;
		char * idPtr;
		char * friendlyName;
		short type; //0=SPELL, 1=ABILITY, 2=BLIGHT, 3=DISEASE, 4=CURSE, 5=POWER
		short cost;

		//effect
		struct Effect
		{
			short effectId;
			char  skillId;
			char  AttributeId;
			long  RangeType;		//0=SELF, 1=TOUCH, 2=TARGET
			long  Area;
			long  Duration;
			long  MagMin;
			long  MagMax;
		} effects[8];

		long flags;	//1=AUTOCALC, 2=PCSTART, 4=ALWAYSSUCCEEDS
	};

	struct ALCHRecord_t
	{
		void * vTable;
		RecordTypes::recordType_t recordType;
		int recordSize;
		char * modNamePtr;
		int unknown1;
		LinkedList_t * alchemyList;
		int unknown3;
		ALCHRecord_t * prevRecord;
		ALCHRecord_t * nextRecord;
		int unknown4;
		int unknown5;
		char * idPtr;
		int unknown6;
		int unknown7;
		int unknown8;
		int unknown9;
		int unknown10;
		char * friendlyName;
		int unknown11;
		char * model;
		char * icon;

		float weight;
		long value;

		//effect
		struct Effect
		{
			short effectId;
			char  skillId;
			char  AttributeId;
			long  RangeType;		//0=SELF, 1=TOUCH, 2=TARGET
			long  Area;
			long  Duration;
			long  MagMin;
			long  MagMax;
		} effects[8];

		long flags; //1=AUTOCALC
	};

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
		char * idPtr;

		short type;	//0=CASTONCE, 1=CASTONSTRIKE, 2=CASTONUSED, 3=CONSTANT
		short cost;
		long charge;

		//effect
		struct Effect
		{
			short effectId;
			char  skillId;
			char  AttributeId;
			long  RangeType;		//0=SELF, 1=TOUCH, 2=TARGET
			long  Area;
			long  Duration;
			long  MagMin;
			long  MagMax;
		} effects[8];

		long autocalc;	//0=OFF, 1=ON
	};

	struct CLASRecord_t {
		void * vTable;
		RecordTypes::recordType_t recordType; // CLAS

		int unknown1;
		int unknown2; // pointer?

		char id[32];
		char name[32];

		// Primary attributes:
		// 0 = Strength
		// 1 = Intelligence
		// 2 = Willpower
		// 3 = Agility
		// 4 = Speed 
		// 5 = Endurance
		// 6 = Personality
		// 7 = Luck

		unsigned long attributes[2];

		// Specializations:
		// 0 = Combat
		// 1 = Magic
		// 2 = Stealth

		unsigned long specialization;

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

		unsigned long skills[10];

		unsigned long playable; // is this class available to PC? 0 = no, 1 = yes

		unsigned long services;

		int unknowns[5];
	};

	struct NPCBaseRecord_t	//or the 'base' NPC_ record. you can access it trough the NPCC (NPC Copy) Record (baseNPC)
	{
		void * vTable;
		RecordTypes::recordType_t recordType;
		int recordSize;		//should be 0x0F0 big!
		char * modNamePtr;
		int unknown1;
		int unknown2;
		int unknown3;
		int unknown4;	//STAT
		int unknown5;	//BODY
		int unknown6;
		int unknown7;
		char * objectId;
		int unknown8;
		int unknown9;
		int unknown10;
		int unknown11;
		int unknown12;
		int unknown13;	//inventory? (amount)
		int unknown14;	//inventory? (start)
		int unknown15;	//inventory? (end)
		int unknown16;
		int unknown17;
		int unknown18;
		int unknown19;
		int unknown20;
		int unknown21;
		int unknown22;
		int unknown23;
		int unknown24;
		int unknown25;
		int unknown26;
		short level;
		short unknown27;
		int unknown28;
		int unknown29;
		int unknown30;
		int unknown31;
		int unknown32;
		int unknown33;
		int unknown34;
		int unknown35;
		int unknown36;
		int unknown37;
		int unknown38;
		mwShort_t baseGold;
		mwShort_t unknown45;
		int unknown39; //RACE
		CLASRecord_t * classRecord; //CLASS
		int unknown41;	//BODY (head)
		int unknown42;	//BODY (hair)
		int unknown43;
		int unknown44;
		int numberOfSpells;
		LinkedList_t * spellStart;	//these contain the spells! not items with a special power.
		LinkedList_t * spellEnd;
	};

	struct NPCCopyRecord_t
	{
		void * vTable;
		RecordTypes::recordType_t recordType;
		int unknown1; //int RecordSize; ?
		int unknown2; //char * modNamePtr; ?
		int unknown3;
		int unknown4;
		void * reference;
		void * prevRecord;
		void * nextRecord;
		int unknown5;
		int unknown6;
		char * objectId;
		int unknown7;
		int unknown8;
		int unknown9;
		int unknown10;
		int unknown11;
		int AmountInventory;
		LinkedList_t * inventoryStart;
		LinkedList_t * inventoryEnd;
		int unknown13;
		int unknown14;
		int unknown15;	//some pointer
		int amountEquiped;
		LinkedList_t * equipedStart;
		LinkedList_t * equipedEnd;
		int unknown16;
		NPCBaseRecord_t * baseNPC;
	};

	struct REFRRecord_t
	{
		void * vTable;
		RecordTypes::recordType_t recordType; // "REFR"
		long flags;			//0x50 big, should this be!
		char* modNamePtr;
		int unknown1;
		int unknown2;
		REFRRecord_t * nextOfSameTemplate;
		REFRRecord_t * previousRecord;
		REFRRecord_t * nextRecord;
		int unknown3;
		BaseRecord_t * recordPointer; //points to the record for which this is a reference;
		char unknown4[12];	//12 bytes
		float x;
		float y;
		float z;
		ListNode_t * attachments;
		char unknown5[18];	//18 bytes
	};

	struct TES3RefListHead_t {
		long size;
		REFRRecord_t * first;
		REFRRecord_t * last;
		REFRRecord_t * container;
	};

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
		char * nameStringPtr; // 0x44
		int unknown_0x48;	// char * scriptIDStringPtr;
		char * nifStringPtr; // 0x4C
		char * tgaStringPtr; // 0x50
		float weight; // 0x54
		int value; // 0x58
		int unknown_0x5C[16];
		mwShort_t maxCondition; // 0xB4
		mwShort_t unknown_0xB6;
		int unknown_0xB8[8];
		ENCHRecord_t * enchantment; // 0xF0
	};

	// Copied from WEAPRecord - needs to be verified.
	struct CLOTRecord
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
		char * nifStringPtr;
		char * tgaStringPtr;
		float weight;
		int value;
		int unknown_0x5C[22];
		ENCHRecord_t * enchantment; // 0xB8
	};

	struct WEAPRecord_t
	{
		void * vTable; // 0x00
		RecordTypes::recordType_t recordType; // 0x04 "WEAP"
		int recordSize; // 0x08
		char * modNamePtr; // 0x0C
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18; //REFRRecord_t * first //nextOfSameTemplate
		void * previousRecord; // 0x1C
		void * nextRecord; // 0x20
		void * unknown_0x24;
		int unknown_0x28;
		char * objectId; // 0x2C
		void * unknownFunctionPtr; // 0x30
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		char * nameStringPtr; // 0x44
		int unknown_0x48; // char * scriptIDStringPtr;
		char * nifStringPtr; // 0x4C
		char * tgaStringPtr; // 0x50
		float weight; // 0x54
		int value; // 0x58
		short weaponType; // 0x5C
		short maxCondition; // 0x5E
		float speed; // 0x60
		float reach; // 0x64
		short enchantPoints; // 0x68
		char chopMin; // 0x60
		char chopMax; // 0x61
		char slashMin; // 0x62
		char slashMax; // 0x63
		char trustMin; // 0x64
		char trustMax; // 0x65
		long flags; // 0x66
		ENCHRecord_t * enchantment; // 0x7A
	};

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
		int unknown_0x44;
		int unknown_0x48;
		int unknown_0x4C;
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		int unknown_0x6C;
		int unknown_0x70;
		int unknown_0x74;
		int unknown_0x78;
		int unknown_0x7C;
		int unknown_0x80;
		int unknown_0x84;
		int unknown_0x88;
		int unknown_0x8C;
		int unknown_0x90;
		int unknown_0x94;
		int unknown_0x98;
		int unknown_0x9C;
		int unknown_0xA0;
		int unknown_0xA4;
		int unknown_0xA8;
		int unknown_0xAC;
		int unknown_0xB0;
		mwShort_t maxCondition; // 0xB4
		mwShort_t unknown_0xB6;
	};

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
		int unknown_0x68;
		int unknown_0x6C;
		int unknown_0x70;
		int unknown_0x74;
		int unknown_0x78;
		int unknown_0x7C;
		int unknown_0x80;
		int unknown_0x84;
		int unknown_0x88;
		int unknown_0x8C;
		int unknown_0x90;
		int unknown_0x94;
		int unknown_0x98;
		int unknown_0x9C;
		int unknown_0xA0;
		int unknown_0xA4;
		int unknown_0xA8;
		int unknown_0xAC;
		int unknown_0xB0;
		mwShort_t maxCondition; // 0xB4
		mwShort_t unknown_0xB6;
	};

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
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		int unknown_0x6C;
		int unknown_0x70;
		int unknown_0x74;
		int unknown_0x78;
		int unknown_0x7C;
		int unknown_0x80;
		int unknown_0x84;
		int unknown_0x88;
		int unknown_0x8C;
		int unknown_0x90;
		int unknown_0x94;
		int unknown_0x98;
		int unknown_0x9C;
		int unknown_0xA0;
		int unknown_0xA4;
		int unknown_0xA8;
		int unknown_0xAC;
		mwShort_t maxCondition; // 0xB0
		mwShort_t unknown_0xB2;
	};

	struct GLOBRecord_t
	{
		void * vTable;
		RecordTypes::recordType_t recordType;
		int recordsize;
		char * modNamePtr;
		char globalName[32];
		char variableType; //morrowind converts this to uppercase (i don't know why), can be 'l', 's', 'f' (long, short, float)
		char unknown[3]; //3 bytes of nothing usefull apparently
		float data; //apparently, all globals are stored as floats in morrowind (i think), at least for longs!
	};

	struct GMSTRecord_t {
		void * vTable;
		RecordTypes::recordType_t recordType;
		int unknown;
		void * mod; // pointer to mod?
		union values
		{
			long long_value;
			float float_value;
			char* string_value;
		} value;
		int index; // array index of this GMST
		int unknown2[2];
	};

	struct SKILRecord_t
	{
		void * vTable;
		RecordTypes::recordType_t recordType; // SKIL
		int unknown1;
		void * ptr1; // pointer to first array element?
		long skill;
		long attribute;
		long specialization;
		float actions[4];
		int unknown2;
		int unknown3;
	};

	struct MGEFRecord_t
	{
		void* vtable;
		RecordTypes::recordType_t record_type;
		int unknown1;
		void* module; // pointer to module?
		long index; // index in array
		int unknown3;
		int unknown4;
		char effect_icon[32];
		char particle_texture[32];
		// Only a few effects have data in their sound effect strings.
		// Maybe it's inferred from school if missing?
		char cast_sound_effect[32];
		char bolt_sound_effect[32];
		char hit_sound_effect[32];
		char area_sound_effect[32];
		void* unknown5; // visual effect?
		void* unknown6; // visual effect?
		void* unknown7; // visual effect?
		void* unknown8; // visual effect?
		long school; // 0 = Alteration, 1 = Conjuration, 2 = Destruction, 3 = Illusion, 4 = Mysticism, 5 = Restoration
		float base_magicka_cost;
		long flags; //0x200 = spellmaking 0x400 = enchanting 0x800 = negative lighting effect
		long red;
		long green;
		long blue;
		float size_x;
		float speed_x;
		float size_cap;
	};

	//this is the struct behind 'master2'
	struct TES3ViewMaster_t
	{
		char unknown[232];
		REFRRecord_t * target;
	};

	//this is the default 'template', so we can read out the type and the ID of the object behind a reference.
	//those values should always be there for 'normal' objects (like BOOKS and CLOTHING)
	struct TES3DefaultTemplate_t
	{
		void * vTable;
		RecordTypes::recordType_t recordType;
		mwLong_t unknown_0x08;
		mwLong_t unknown_0x0C;
		mwLong_t unknown_0x10;
		mwLong_t unknown_0x14;
		REFRRecord_t * first;
		mwLong_t unknown_0x1C;
		mwLong_t unknown_0x20;
		mwLong_t unknown_0x24;
		mwLong_t unknown_0x28;
		char * objectId;
	};

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
		ListIterator_t * inventory; // 0x40
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
		mwLong_t unknown_0x70;
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

	struct CREACopyRecord_t
	{
		void * vTable;
		RecordTypes::recordType_t recordType;
		int unknown1; //int RecordSize; ?
		int unknown2; //char * modNamePtr; ?
		int unknown3;
		int unknown4;
		void * reference;
		void * prevRecord;
		void * nextRecord;
		int unknown5;
		int unknown6;
		char * objectId;
		int unknown7;
		int unknown8;
		int unknown9;
		int unknown10;
		int unknown11;
		int AmountInventory;
		LinkedList_t * inventoryStart;
		LinkedList_t * inventoryEnd;
		int unknown13;
		int unknown14;
		int unknown15;	//some pointer
		int amountEquiped;
		LinkedList_t * equipedStart;
		LinkedList_t * equipedEnd;
		int unknown16;
		CREABaseRecord_t * baseCreature;
	};

	struct RecordLists_t {
		struct UnknownStruct
		{
			void* v_table;
			unsigned long unknown1;
			void* unknown2;
			void* unknown3;
			void* unknown4;
			unsigned long unknown5[6];
			void* unknown6;
		};
		unsigned long unknown1; // 
		unsigned long unknown2; // always 0 ???
		void * unknown3; // points to info about the last loaded save
						 // list contains the following types: CREA, REPA, APPA, PROB, MISC, LEVC,
						 // ALCH, ENCH, LIGH, ACTI, LEVI, LOCK, BOOK, AMMO, ARMO, WEAP, INGR, DOOR,
						 // STAT, CONT, CLOT, BODY, NPC_
		LinkedList_t * list;
		LinkedList_t * spellsList;
		void * unknown4;
		GMSTRecord_t ** GMSTs; // pointer to array of GMST pointers
		UnknownStruct* unknown5[12];
		SKILRecord_t skills[27];
		MGEFRecord_t magic_effects[143];
	};

	struct TES3Cell_t {
		char unknown[0x10];
		char* cellname; // may be null
		char unknown2[0x30 - 0x10 - sizeof(char*)];
		TES3RefListHead_t npc;
		TES3RefListHead_t statics;
		char unknown3[0x58 - 0x30 - 2 * sizeof(TES3RefListHead_t)];
		TES3RefListHead_t otheritems;
	};

	struct TES3CellPointer_t {
		long size;
		TES3Cell_t * first;
	};

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

	struct TES3CellMaster_t {
		RecordLists_t * recordLists;
		TES3CellPointer_t * exteriorCells[9];
		int unknown[33];
		TES3Cell_t * interiorCell;
		int unknown2[4];
	};
}
