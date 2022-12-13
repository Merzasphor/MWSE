#pragma once

#include "NIDefines.h"

#include "NITArray.h"
#include "NIHashMap.h"

#include "NIObject.h"

namespace NI {
	struct Stream {
		// TODO: This is probably subclassed and the fields are per-type. Needs further research.
		struct LoadingObject {
			struct VirtualTable {
				void(__thiscall* dtor)(LoadingObject*, bool); //0x0
			};
			VirtualTable* vTable; // 0x0
			int unknown_0x4;
			int unknown_0x8;
			int linkId; // 0xC

			static void* operator new(size_t size);
			static void operator delete(void* block);

			LoadingObject();
		};
		int unknown_0x0;
		int unknown_0x4;
		int unknown_0x8;
		int unknown_0xC;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		void* unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
		int unknown_0x28;
		int unknown_0x2C;
		TArray<Pointer<Object>> unknown_0x30;
		HashMap<int, Object*> unknown_0x48;
		BinaryStream* inStream; // 0x58
		BinaryStream* outStream; // 0x5C
		TArray<Pointer<Object>> loadedObjects; // 0x60
		LoadingObject* currentlyLoading; // 0x78
		TArray<LoadingObject*> loadingObjects; // 0x7C
		HashMap<Object*, int> linkIds; // 0x94
		int unknown_0xA4;
		HashMap<int, Object*>* unknown_0xA8;

		Stream();
		~Stream();

		bool load(const char* file);
		bool save(const char* file);

		void insertObject(Object* object);

		void readString(char** out_string);
		void writeString(const char* string);

		Object* getLinkObject(int id) const;
		int getLinkId(const Object* object) const;
		void readLinkId(unsigned int index);
		void writeLinkId(Object* object);

		static Object* getCopiedObject(const Object* existing);

		typedef Object* (__cdecl* CreateFunction)(Stream*);
		static void __cdecl registerLoader(const char* className, CreateFunction createObjectFunction);

		//
		// Custom functions.
		//

		std::string readStdString();

	};
	static_assert(sizeof(Stream) == 0xAC, "NI::Stream failed size validation");
	static_assert(sizeof(Stream::LoadingObject) == 0x10, "NI::Stream::LoadingObject failed size validation");
}
