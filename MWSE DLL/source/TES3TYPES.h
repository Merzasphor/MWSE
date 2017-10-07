//Tes3Types.h
#pragma once

#include "VMTYPES.h"

typedef short	TES3SHORT;
typedef long	TES3LONG;
typedef float	TES3FLOAT;

typedef enum{NORTHWEST=0,NORTH=1,NORTHEAST=2,WEST=3,CENTRE=4,EAST=5,SOUTHWEST=6,SOUTH=7,SOUTHEAST=8} TES3CELLGRID;

typedef BYTE* VPSTR;

// 2005-06-27  CDC
struct TES3HEADER
{
	VPVOID	vtable;
	DWORD	type;
};

struct TES3IDSTRING
{
	char id[128];
};
typedef TES3IDSTRING* VPIDSTRING;

struct TES3VARIABLES
{
	TES3SHORT*	shorts;
	TES3LONG*	longs;
	TES3FLOAT*	floats;
};
typedef TES3VARIABLES* VPVARIABLES;

struct TES3SCRIPT
{
	VPVOID	vtable;
	DWORD	type;
	BYTE	unknown[8];
	BYTE	name[0x20];
	DWORD	numshorts;
	DWORD	numlongs;
	DWORD	numfloats;
	DWORD	scdtlength;
	BYTE	unknown2[0x58-0x3c-sizeof(DWORD)];
	VPVOID	scdt;
};
typedef TES3SCRIPT* VPSCRIPT;

struct TES3LISTNODE
{
	DWORD type;
	TES3LISTNODE* next;
	VPVOID dataptr;
};
typedef TES3LISTNODE* VPLISTNODE;

struct TES3LISTITERATOR
{
	BYTE unknown[8];
	VPLISTNODE first;
	BYTE unknown2[4];
	VPLISTNODE current;
};
typedef TES3LISTITERATOR* VPLISTITERATOR;

struct TES3REFERENCE;

struct TES3TEMPLATE
{
	VPVOID vtable;
	DWORD type; // , CREA NPC_, MISC, things like that
	BYTE unknown[0x18-sizeof(VPVOID)-sizeof(DWORD)];
	TES3REFERENCE* first;
	BYTE unknown2[0x2C-0x18-sizeof(TES3REFERENCE*)];
	VPSTR objectid;
	BYTE unknown3[0x3c-0x2c-sizeof(BYTE*)];
	DWORD invflags;
	TES3LISTITERATOR inventory;
};
typedef TES3TEMPLATE* VPTEMPLATE;

struct TES3STACK
{
	DWORD	count;
	VPTEMPLATE templ;
};
typedef TES3STACK* VPSTACK;

struct TES3REFERENCE
{
	VPVOID vtable;
	DWORD type;	// "REFR"
	DWORD flags;
	BYTE	unknown[0x18 - sizeof(VPVOID) - 2 * sizeof(DWORD)];
	TES3REFERENCE* nextofsametempl;
	TES3REFERENCE* prev;
	TES3REFERENCE* next;
	BYTE	unknown2[0x28-0x18-3*sizeof(TES3REFERENCE*)];
	VPTEMPLATE templ;
	BYTE	unknown3[0x38-0x28-sizeof(VPTEMPLATE)];
	FLOAT	x,y,z;
	VPLISTNODE attachments;
	BYTE unknown4[0x60-0x38-3*sizeof(FLOAT)-sizeof(VPLISTNODE)];
};
typedef TES3REFERENCE* VPREFERENCE;

struct TES3VARHOLDER
{
	BYTE unknown[0x18];
	VPVARIABLES vars;
};
typedef TES3VARHOLDER* VPVARHOLDER;

struct TES3MACH
{
	BYTE unknown[0x14];
	VPREFERENCE	ref;
	BYTE unknown2[0xcc+0x20 - 0x14-sizeof(VPREFERENCE)];
	TES3MACH* combattarget;
};
typedef TES3MACH* VPMACH;

struct TES3COORDINATE
{
	TES3FLOAT x,y,z;
};
typedef TES3COORDINATE* VPCOORDINATE;

struct TES3ROTATION
{
	TES3FLOAT x,y,z;
};
typedef TES3ROTATION* VPROTATION;

struct TES3ARMOUR
{
	TES3TEMPLATE common;
	BYTE unknown[0x110-sizeof(TES3TEMPLATE)];
	DWORD septims;
};

struct TES3WEAPON
{
	TES3TEMPLATE common;
	BYTE unknown[0x58-sizeof(TES3TEMPLATE)];
	DWORD septims;
};

struct TES3REFLISTHEAD
{
	LONG	size;
	VPREFERENCE first;
	VPREFERENCE last;
	VPREFERENCE container;
};

struct TES3CELL
{
	BYTE unknown[0x10];
	VPSTR cellname; // may be null
	BYTE unknown2[0x30-0x10-sizeof(VPSTR)];
	TES3REFLISTHEAD npc;
	TES3REFLISTHEAD statics;
	BYTE unknown3[0x58-0x30-2*sizeof(TES3REFLISTHEAD)];
	TES3REFLISTHEAD otheritems;
};
typedef TES3CELL* VPCELL;

struct TES3CELLPTR
{
	LONG size;
	VPCELL	first;
};
typedef TES3CELLPTR* VPCELLPTR;

struct TES3VIEWMASTER
{
	BYTE unknown[0x4c];
	BYTE unknown2[0x9c];
	VPREFERENCE target;
};
typedef TES3VIEWMASTER* VPVIEWMASTER;

enum MagicEffectFlags
{
	kTargetSkill      = 0x1,
	kTargetAttribute  = 0x2,
	kNoDuration       = 0x4,
	kNoMagnitude      = 0x8,
	kHarmful          = 0x10,
	kContinuousVfx    = 0x20,
	kCastSelf         = 0x40,
	kCastTouch        = 0x80,
	kCastTarget       = 0x100,
	kSpellmaking      = 0x200,
	kEnchanting       = 0x400,
	kNegativeLighting = 0x800,
	kAppliedOnce      = 0x1000,
	kStealthEffect    = 0x2000,
	kNonRecastable    = 0x4000,
	kIllegalDaedra    = 0x8000,
	kUnreflectable    = 0x10000,
	kCasterLinked     = 0x20000,
	kNoMagicEffectFlags = 0,
	kAllMagicEffectFlags = (kTargetSkill | kTargetAttribute | kNoDuration | kNoMagnitude |
		kHarmful | kContinuousVfx | kCastSelf | kCastTouch | kCastTarget | kSpellmaking |
		kEnchanting | kNegativeLighting | kAppliedOnce | kStealthEffect | kNonRecastable |
		kIllegalDaedra | kUnreflectable | kCasterLinked)
};

// From https://wiki.openmw.org/index.php?title=Research:Magic#Effect_flags
// TODO Expand these out into combinations of the above flags.
// TODO Read these from memory instead of hardcoding them.
int const kMagicEffectFlags[] = {
    0x11c8, 0x11c0, 0x11c8, 0x11e0, 0x11e0, 0x11e0, 0x11e0, 0x11d0,
    0x11c0, 0x11c0, 0x11e0, 0x11c0, 0x11184, 0x11184, 0x1f0, 0x1f0,
    0x1f0, 0x11d2, 0x11f0, 0x11d0, 0x11d0, 0x11d1, 0x1d2, 0x1f0,
    0x1d0, 0x1d0, 0x1d1, 0x1f0, 0x11d0, 0x11d0, 0x11d0, 0x11d0,
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

enum SpellFlags 
{
	kAutoCalculateCost = 1,
	kPcStartSpell = 2,
	kAlwaysSucceeds = 4,
	kNoSpellFlags = 0,
	kAllSpellFlags = (kAutoCalculateCost | kPcStartSpell | kAlwaysSucceeds)
};


enum RecordTypes
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
	NPC = '_CPN',
	PROB = 'BORP', PROBE = PROB,
	REFR = 'RFER', REFERENCE = REFR,
	REPA = 'APER', REPAIR = REPA,
	SCPT = 'TPCS', SCRIPT = SCPT,
	SKIL = 'LIKS', SKILL = SKIL,
	SNDG = 'GDNS', SOUNDGENERATOR = SNDG,
	SPEL = 'LEPS', SPELL = SPEL,
	STAT = 'TATS', STATIC = STAT,
	WEAP = 'PAEW', WEAPON = WEAP
};

enum AttachTypes
{
	VARNODE = 6,	//attachment where 'local' variables are stored, and the size of a stack, and the owner (if it has changed i think), and the script...
	MACHNODE = 8	//PCAM
};


enum GMSTs
{
	fEffectCostMult = 1037,
	iLevelupTotal = 1088,
	fSpecialSkillBonus = 1161,
	fMajorSkillBonus,
	fMinorSkillBonus,
	fMiscSkillBonus
};

enum Attributes
{
	kNoAttribute = -1,
	kStrength,
	kIntelligence,
	kWillpower,
	kAgility,
	kSpeed,
	kEndurance,
	kPersonality,
	kLuck,
	kFirstAttribute = kStrength,
	kLastAttribute = kLuck
};

enum SkillTypes
{
	Major,
	Minor,
	Misc
};

enum Specializations
{
	kNoSpecialization = -1,
	kCombat,
	kMagic,
	kStealth,
	kFirstSpecialization = kCombat,
	kLastSpecialization = kStealth
};

enum Skills
{
	kNoSkill = -1,
	kBlock,
	kArmorer,
	kMediumArmor,
	kHeavyArmor,
	kBluntWeapon,
	kLongBlade,
	kAxe,
	kSpear,
	kAthletics,
	kEnchant,
	kDestruction,
	kAlteration,
	kIllusion,
	kConjuration,
	kMysticism,
	kRestoration,
	kAlchemy,
	kUnarmored,
	kSecurity,
	kSneak,
	kAcrobatics,
	kLightArmor,
	kShortBlade,
	kMarksman,
	kMercantile,
	kSpeechcraft,
	kHandToHand,
	kFirstSkill = kBlock,
	kLastSkill = kHandToHand
};

enum Effects
{
	kNoEffect = -1,
	kWaterBreathing,
	kSwiftSwim,
	kWaterWalking,
	kShield,
	kFireShield,
	kLightningShield,
	kFrostShield,
	kBurden,
	kFeather,
	kJump,
	kLevitate,
	kSlowFall,
	kLock,
	kOpen,
	kFireDamage,
	kShockDamage,
	kFrostDamage,
	kDrainAttribute,
	kDrainHealth,
	kDrainMagicka,
	kDrainFatigue,
	kDrainSkill,
	kDamageAttribute,
	kDamageHealth,
	kDamageMagicka,
	kDamageFatigue,
	kDamageSkill,
	kPoison,
	kWeaknesstoFire,
	kWeaknesstoFrost,
	kWeaknesstoShock,
	kWeaknesstoMagicka,
	kWeaknesstoCommonDisease,
	kWeaknesstoBlightDisease,
	kWeaknesstoCorprusDisease,
	kWeaknesstoPoison,
	kWeaknesstoNormalWeapons,
	kDisintegrateWeapon,
	kDisintegrateArmor,
	kInvisibility,
	kChameleon,
	kLight,
	kSanctuary,
	kNightEye,
	kCharm,
	kParalyze,
	kSilence,
	kBlind,
	kSound,
	kCalmHumanoid,
	kCalmCreature,
	kFrenzyHumanoid,
	kFrenzyCreature,
	kDemoralizeHumanoid,
	kDemoralizeCreature,
	kRallyHumanoid,
	kRallyCreature,
	kDispel,
	kSoultrap,
	kTelekinesis,
	kMark,
	kRecall,
	kDivineIntervention,
	kAlmsiviIntervention,
	kDetectAnimal,
	kDetectEnchantment,
	kDetectKey,
	kSpellAbsorption,
	kReflect,
	kCureCommonDisease,
	kCureBlightDisease,
	kCureCorprusDisease,
	kCurePoison,
	kCureParalyzation,
	kRestoreAttribute,
	kRestoreHealth,
	kRestoreMagicka,
	kRestoreFatigue,
	kRestoreSkill,
	kFortifyAttribute,
	kFortifyHealth,
	kFortifyMagicka,
	kFortifyFatigue,
	kFortifySkill,
	kFortifyMaximumMagicka,
	kAbsorbAttribute,
	kAbsorbHealth,
	kAbsorbMagicka,
	kAbsorbFatigue,
	kAbsorbSkill,
	kResistFire,
	kResistFrost,
	kResistShock,
	kResistMagicka,
	kResistCommonDisease,
	kResistBlightDisease,
	kResistCorprusDisease,
	kResistPoison,
	kResistNormalWeapons,
	kResistParalysis,
	kRemoveCurse,
	kTurnUndead,
	kSummonScamp,
	kSummonClannfear,
	kSummonDaedroth,
	kSummonDremora,
	kSummonAncestralGhost,
	kSummonSkeletalMinion,
	kSummonBonewalker,
	kSummonGreaterBonewalker,
	kSummonBonelord,
	kSummonWingedTwilight,
	kSummonHunger,
	kSummonGoldenSaint,
	kSummonFlameAtronach,
	kSummonFrostAtronach,
	kSummonStormAtronach,
	kFortifyAttack,
	kCommandCreature,
	kCommandHumanoid,
	kBoundDagger,
	kBoundLongsword,
	kBoundMace,
	kBoundBattleAxe,
	kBoundSpear,
	kBoundLongbow,
	kEXTRASPELL,
	kBoundCuirass,
	kBoundHelm,
	kBoundBoots,
	kBoundShield,
	kBoundGloves,
	kCorprus,
	kVampirism,
	kSummonCenturionSphere,
	kSunDamage,
	kStuntedMagicka,
	kSummonFabricant,
	kCallWolf,
	kCallBear,
	kSummonBonewolf,
	ksEffectSummonCreature04,
	ksEffectSummonCreature05,
	kFirstMagicEffect = kWaterBreathing,
	kLastMagicEffect = ksEffectSummonCreature05
};

struct LinkedListNode
{
	LinkedListNode * previousNode;
	LinkedListNode * nextNode;
	void * dataNode;
};

struct LinkedList
{
	unsigned long size;
	void * head;
	void * tail;
};

struct SKILRecord
{
	void * vTable;
	RecordTypes recordType; // SKIL
	int unknown1;
	void * ptr1; // pointer to first array element?
	long skill;
	long attribute;
	long specialization;
	float actions[4];
	int unknown2;
	int unknown3;
};

struct GMSTRecord
{
	void * vTable;
	RecordTypes recordType;
	int unknown;
	void * mod; // pointer to mod?
	union
	{
		long long_value;
		float float_value;
		char* string_value;
	} value;
	int index; // array index of this GMST
	int unknown2[2];
};

enum MagicSchools
{
	kAlterationMagic = 0,
	kConjurationMagic,
	kDestructionMagic,
	kIllusionMagic,
	kMysticismMagic,
	kRestorationMagic,
	kFirstMagicSchool = kAlteration,
	kLastMagicSchool = kRestoration
};

struct MGEFRecord
{
	void* vtable;
	RecordTypes record_type;
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

struct RecordLists
{
	unsigned long unknown1; // 
	unsigned long unknown2; // always 0 ???
	void * unknown3; // points to info about the last loaded save
	LinkedList * enchantmentsList; // also contains statics, maybe other stuff too
	LinkedList * spellsList;
	void * unknown4;
	GMSTRecord ** GMSTs; // pointer to array of GMST pointers
	void * unknown5[12];
	SKILRecord skills[27];
	MGEFRecord magic_effects[143];
};

struct BaseRecord
{
	void * vTable;
	RecordTypes recordType;
};

enum RangeTypes
{
	kSelf = 0,
	kTouch,
	kTarget,
	kFirstRangeType = kSelf,
	kLastRangeType = kTarget
};

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
};

struct ENCHRecord
{
	void * vTable;
	RecordTypes recordType;
	int recordSize;
	char * modNamePtr;
	int unknown1;
	LinkedList * enchantmentsList;
	int unknown3;
	ENCHRecord * prevRecord;
	ENCHRecord * nextRecord;
	int unknown4;			
	char * id;

	short type;	//0=CASTONCE, 1=CASTONSTRIKE, 2=CASTONUSED, 3=CONSTANT
	short cost;
	long charge;

	Effect effects[8];

	long autocalc;	//0=OFF, 1=ON
};

enum SpellOrigins
{
	kModule = 1,
	kSpellmaker,
	kSpellOriginsFirst = kModule,
	kSpellOriginsLast = kSpellmaker
};

enum SpellTypes
{
	kSpell,
	kAbility,
	kBlight,
	kDisease,
	kCurse,
	kPower,
	kFirstSpellTypes = kSpell,
	kLastSpellTypes = kPower
};

struct SPELRecord
{
	void * vTable;
	RecordTypes recordType; // SPEL
	unsigned long origin;
	char * modName;
	int unknown1;
	LinkedList * spellsList;
	int unknown3;
	SPELRecord * prevRecord;
	SPELRecord * nextRecord;
	int unknown4;
	char * id;
	char * friendlyName;
	short type; //0=SPELL, 1=ABILITY, 2=BLIGHT, 3=DISEASE, 4=CURSE, 5=POWER
	unsigned short cost;

	Effect effects[8];

	long flags;	//1=AUTOCALC, 2=PCSTART, 4=ALWAYSSUCCEEDS
};

struct ALCHRecord
{
	void * vTable;
	RecordTypes recordType;
	int recordSize;
	char * modName;
	int unknown1;
	LinkedList * alchemyList;
	int unknown3;
	ALCHRecord * prevRecord;
	ALCHRecord * nextRecord;
	int unknown4;
	int unknown5;
	char const * id;
	int unknown6;
	int unknown7;
	int unknown8;
	int unknown9;
	int unknown10;
	char const * friendlyName;
	int unknown11;
	char * model;
	char * icon;
	float weight;
	long value;
	Effect effects[8];
	long flags; //1=AUTOCALC
};

struct CLASRecord
{
	void * vTable;
	RecordTypes recordType; // CLAS
	
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

struct NPCBaseRecord	//or the 'base' NPC_ record. you can access it trough the NPCC (NPC Copy) Record (baseNPC)
{
	void * vTable;
	RecordTypes recordType;
	int recordSize;		//should be 0x0F0 big!
	char * modNamePtr;
	int unknown1;
	int unknown2;
	int unknown3;
	int unknown4;	//STAT
	int unknown5;	//BODY
	int unknown6;
	int unknown7;
	char * IDStringPtr;
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
	int unknown39;	
	int unknown40;	//RACE
	CLASRecord * characterClass;
	int unknown42;	//BODY (head)
	int unknown43;	//BODY (hair)
	int unknown44;
	int unknown45;
	int unknown46;
	int numberOfSpells;
	LinkedListNode * spellStart;	//these contain the spells! not items with a special power.
	LinkedListNode * spellEnd;
};

struct NPCCopyRecord
{
	void * vTable;
	RecordTypes recordType;
	int unknown1; //int RecordSize; ?
	int unknown2; //char * modNamePtr; ?
	int unknown3;
	int unknown4;
	void * reference;
	void * prevRecord;
	void * nextRecord;
	int unknown5;
	int unknown6;
	char * IDStringPtr;
	int unknown7;
	int unknown8;
	int unknown9;
	int unknown10;
	int unknown11;
	int AmountInventory;
	LinkedListNode * inventoryStart;
	LinkedListNode * inventoryEnd;
	int unknown13;
	int unknown14;
	int unknown15;	//some pointer
	int amountEquiped;
	LinkedListNode * equipedStart;
	LinkedListNode * equipedEnd;
	int unknown16;
	NPCBaseRecord * baseNPC;
};

struct ARMORecord
{
	// copied from WEAPRecord - needs to be verified
	void * vTable;
	RecordTypes recordType; // "ARMO"
	int recordSize;
	char * modNamePtr;
	int unknown1;
	int unknown2;
	int unknown3; //REFRRecord_t * first //nextOfSameTemplate
	void * previousRecord;
	void * nextRecord;
	void * unknown4;
	int unknown5;
	char * IDStringPtr;
	void * unknownFunctionPtr;
	int unknown6;
	int unknown7;
	int unknown8;
	int unknown9;
	char * nameStringPtr;
	int unknown10;	//char * scriptIDStringPtr;
	char * nifStringPtr;
	char * tgaStringPtr;
	float weight;
	int value;
	/*short weaponType;
	short maxCondition;
	float speed;
	float reach;
	short enchantPoints;
	char chopMin;
	char chopMax;
	char slashMin;
	char slashMax;
	char thrustMin;
	char thrustMax;
	long flags;*/
	int unknowns[25];
	ENCHRecord * enchantment;
};

struct CLOTRecord
{
	// copied from WEAPRecord - needs to be verified
	void * vTable;
	RecordTypes recordType; // "CLOT"
	int recordSize;
	char * modNamePtr;
	int unknown1;
	int unknown2;
	int unknown3; //REFRRecord_t * first //nextOfSameTemplate
	void * previousRecord;
	void * nextRecord;
	void * unknown4;
	int unknown5;
	char * IDStringPtr;
	void * unknownFunctionPtr;
	int unknown6;
	int unknown7;
	int unknown8;
	int unknown9;
	char * nameStringPtr;
	int unknown10;	//char * scriptIDStringPtr;
	char * nifStringPtr;
	char * tgaStringPtr;
	float weight;
	int value;
	/*
	short weaponType;
	short maxCondition;
	float speed;
	float reach;
	short enchantPoints;
	char chopMin;
	char chopMax;
	char slashMin;
	char slashMax;
	char thrustMin;
	char thrustMax;
	long flags;
	*/
	int unknowns[22];
	ENCHRecord * enchantment;
};

struct WEAPRecord
{
	void * vTable;
	RecordTypes recordType; // "WEAP"
	int recordSize;
	char * modNamePtr;
	int unknown1;
	int unknown2;
	int unknown3; //REFRRecord_t * first //nextOfSameTemplate
	void * previousRecord;
	void * nextRecord;
	void * unknown4;
	int unknown5;
	char * IDStringPtr;
	void * unknownFunctionPtr;
	int unknown6;
	int unknown7;
	int unknown8;
	int unknown9;
	char * nameStringPtr;
	int unknown10;	//char * scriptIDStringPtr;
	char * nifStringPtr;
	char * tgaStringPtr;
	float weight;
	int value;
	short weaponType;
	short maxCondition;
	float speed;
	float reach;
	short enchantPoints;
	char chopMin;
	char chopMax;
	char slashMin;
	char slashMax;
	char thrustMin;
	char thrustMax;
	long flags;
	ENCHRecord * enchantment;
};

struct MACPRecord
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
	void * vTable; // 0
	RecordTypes recordType; // "MACP" // 4
	int unknown1[3];										//8
	TES3REFERENCE* reference;							//20
	int unknown2[53];						//24
	MACPRecord * combatTarget; // unverified // 236
	int unknown3[89]; // 240
	Statistic attributes[8]; // 596
	Statistic health; // 692
	Statistic magicka; // 704
	Statistic weight_limit; // 716
	Statistic fatigue; // 728 // fatigue has a different vtable pointer than the other Statistic objects.
	Statistic unknown_statistic; // 740
	int unknown4[34]; // 752
	void * currentSpell; // 888 
	int unknown5[13]; // 892
	Skill skills[27]; // 944
	int unknown6[34];  // 1376
	long levelProgress; // 1512
	int unknown7[2];  // 1516
	float skillProgress[27]; // 1524
};

struct FACTRecord
{
	void * vTable;
	RecordTypes recordType; // FACT
	int unknown1[2];
	char id[32];
	char name[32];
	char ranks[10][32];
	int unknown2[71];
};

struct GLOBRecord
{
	void * vTable;
	RecordTypes recordType; //GLOB
	int unknown;
	char * modName;
	char id[32];
	long type; // 'f' 's' 'l'
	float value;
	int unknown2[2];
};

struct OwnerInfo
{
	int unknown;
	void * owner;
	union
	{
		long rank;
		void * variable;
	} rankVar;
};

struct BOOKRecord
{
	void* vtable;
	long record_type;
	int unknown1;
	void* module; // pointer to module?
	int unknown2;
	void* unknown3; // pointer to list?
	int unknown4;
	void* previous; // previous item in list
	void* next; // next item in list
	int unknown5;
	int unknown6;
	char* id;
	void* vtable2; // vtable of embedded object?
	int unknown7;
	int unknown8;
	int unknown9;
	int unknown10;
	char* name;
	void* script;
	char* model;
	char* texture;
	float weight;
	long value;
	long scroll;
	long skill;
	long enchant_capacity;
	ENCHRecord* enchantment;
	void* vtable3; // vtable of embedded object?
	int unknown16;
	int unknown17;
	int unknown18;
	int unknown19;
	void* unknown20;
	void* unknown21;
};

struct TES3LOCK
{
	VMSHORT lockLevel;
	VMSHORT unknown;
	VPVOID owner; // faction or global?
	SPELRecord * trapSpell;
	BYTE locked;
};
typedef TES3LOCK* VPLOCK;

struct TES3CELLMASTER
{
	RecordLists * recordLists;
	VPCELLPTR exteriorcells[9];
	int unknown[33];
	VPCELL	interiorcell;
	int unknown2[4];
};
typedef TES3CELLMASTER* VPCELLMASTER;