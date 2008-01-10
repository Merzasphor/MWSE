#pragma once

namespace mwse
{
	namespace mwTypes
	{

		typedef short mwShort_t;
		typedef long  mwLong_t;
		typedef float mwFloat_t;

		enum recordType_t
		{
			NPC = '_CPN',
			CREA = 'AERC', CREATURE = CREA,
			CONT = 'TNOC', CONTAINER = CONT,
			LIGHT = 'HGIL',
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
			LOCK = 'KCOL'
		};

		struct SCPTRecord_t
		{
			void * vTable; //pointer to the vTable
			recordType_t recordType; // "SCPT"
			int recordSize;
			char * modNamePtr;
			char scriptName[32];
			int numShorts;
			int numLongs;
			int numFloats;
			int scriptDataSize;
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
			struct LinkedList_t * previousNode;
			struct LinkedList_t * nextNode;
			void * dataNode;
		};

		struct InventoryNode_t
		{
			int itemCount;
			void * recordAddress;
		};

		struct NPCBaseRecord_t
		{
			void * vTable;
			recordType_t recordType;
			int recordSize;
			char * modNamePtr;
		};

		struct NPCCopyRecord_t
		{
			void * vTable;
			recordType_t recordType;
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
			int unknown12;
			LinkedList_t * inventoryStart;
			LInkedList_t * inventoryEnd;
		};

		struct REFRRecord_t
		{
			void * vTable;
			recordType_t recordType; // "REFR"
			int recordSize;
			char * modNamePtr;
			int unknown1;
			int unknown2;
			int unknown3; //REFRecord_t * NextOfSameTemplate; ???
			REFRRecord_t * previousRecord;
			REFRRecord_t * nextRecord;
			int unknown4;
			void * recordPointer; //points to the record for which this is a reference;
		};

		struct WEAPRecord_t
		{
			void * vTable;
			recordType_t recordType; // "WEAP"
			int recordSize;
			char * modNamePtr;
			int unknown1;
			int unknown2;
			int unknown3;
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
			int unknown10;
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
	}
}