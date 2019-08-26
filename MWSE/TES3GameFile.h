#pragma once

#include <cstdint>

#include "TES3Collections.h"

#include "Bitset.h"

namespace TES3 {
	struct GameFile {
		struct Header {
			char tag[4];
			unsigned int size;
			unsigned int data;
			mwse::bitset32 flags;
		};
		struct ChunkHeader {
			char tag[4];
			unsigned int size;
		};
		struct GMDT {
			float currentHealth;
			float maxHealth;
			float gameHour;
			float day;
			float month;
			float year;
			char cellName[64];
			float daysPassed;
			char playerName[32];
		};

		int errorCode;
		void* ioObjectBeforeSave;
		void* ioObject;
		char filename[260];
		char path[260];
		void* field_214;
		int field_218;
		int field_21C;
		int field_220;
		int field_224;
		int field_228;
		Header currentFormHeader;
		ChunkHeader currentChunkHeader;
		int field_244;
		unsigned int fileOffsetNextForm;
		unsigned int countFormBytesRead;
		int field_250;
		Header writeFormHeader;
		unsigned int fileOffsetCurrentForm;
		unsigned int bytesWritten;
		char findData[0x140];	// Real type: WIN32_FIND_DATAA
		float version;
		int flags_3B0;
		char author[32];
		char description[256];
		unsigned int countRecords;
		int flags_4D8;
		int loadIndex;
		LinkedList<void>* masterNames;
		LinkedList<void>* masterFileSizes;
		GameFile* arrayMasters;
		unsigned int highestFormID;
		GMDT gmdt;
		void* sgSaveImage;
		Iterator<void>* list_570;

		//
		// Other related this-call functions.
		//

		GameFile(const char* path, const char* filename, void * unknown = nullptr);
		~GameFile();

		void deleteFile();
		bool __declspec(dllexport) readChunkData(void * data, unsigned int size);
		int __declspec(dllexport) writeChunkData(unsigned int tag, const void * data, unsigned int size);

		bool hasNextSubrecord();
		int getNextSubrecord();

		bool collectActiveMods(bool showMasterErrors = false);
		bool load(int unknown1 = 0, bool unknown2 = false);
		bool loadByPath(const char* path, const char* filename, int unknown1 = 0, bool unknown2 = false);
		bool setFilePointer(unsigned int offset);

		//
		// Custom functions.
		//

		std::uint64_t getFileSize() const;
		std::uint64_t getModifiedTime() const;
	};
	static_assert(sizeof(GameFile) == 0x574, "TES3::Game failed size validation");
}
