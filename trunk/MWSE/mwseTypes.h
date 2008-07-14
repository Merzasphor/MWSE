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
            PICK = 'KCIP',
            REPA = 'APER', REPAIR = REPA,
            CLAS = 'SALC', CLASS = CLAS,
            LOCK = 'KCOL',
			GLOB = 'BOLG', GLOBAL = GLOB,
			REFR = 'RFER', REFERENCE = REFR,
			MACP = 'PCAM'
        };

		enum attachType_t
		{
			VARNODE = 6,	//attachment where 'local' variables are stored
			MACHNODE = 8	//PCAM
		};
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

	struct mwVariablesNode_t
	{
		mwShort_t * shortVarValues;
		mwLong_t * longVarValues;
		mwFloat_t * floatVarValues;
	};

	struct mwVarHolderNode_t
	{
		char unknown[0x18];
		mwVariablesNode_t * vars;
	};

	struct REFRRecord_t;

	struct PCAMRecord_t
	{
		void * vTable;										//0
		RecordTypes::recordType_t recordType;				//4
		int unknown1;										//8
		int unknown2;										//12
		int unknown3;										//16
		REFRRecord_t * playerReference;						//20
		int unknown4[216]; // --> int unknown219;			//24
		void * currentSpell; //current selected spell	//this of course points to a SPEL or ENCH record ;)
		//or the one after that, if i miscounted ;-), we'll see when we start using those.
		//vTable + 0x378 is currentSpell @, so you can recount ;-).
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
		struct
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
		int unknown2;
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
		struct
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
		struct
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
		int unknown27;
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
		int unknown39;	//RACE
		int unknown40;	//CLAS
		int unknown41;
		int unknown42;	//BODY
		int unknown43;	//BODY
		int unknown44;
		int unknown45;
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
        char * IDStringPtr;
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
        int recordSize;			//0x50 big, should this be!
        char * modNamePtr;
        int unknown1;
        int unknown2;
        REFRRecord_t * NextOfSameTemplate;
        REFRRecord_t * previousRecord;
        REFRRecord_t * nextRecord;
        int unknown3;
        void * recordPointer; //points to the record for which this is a reference;
		char unknown4[12];	//12 bytes
		float x;
		float y;
		float z;
		ListNode_t * attachments;
		char unknown5[18];	//18 bytes
    };

    struct WEAPRecord_t
    {
        void * vTable;
        RecordTypes::recordType_t recordType; // "WEAP"
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
        char trustMin;
        char trustMax;
        long flags;
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
}
