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
			GLOB = 'BOLG', GLOBAL = GLOB
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

    struct NPCBaseRecord_t
    {
        void * vTable;
        RecordTypes::recordType_t recordType;
        int recordSize;
        char * modNamePtr;
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
    };

    struct REFRRecord_t
    {
        void * vTable;
        RecordTypes::recordType_t recordType; // "REFR"
        int recordSize;
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
        short flags;
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
