#pragma once

#include "NIDefines.h"

#include "NIPointer.h"

#include "TES3Collections.h"

namespace NI {
	struct Stream {
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
		int unknown_0x30;
		Pointer<Object>* unknown_0x34; // Array of 1024 pointers.
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		TES3::HashMap unknown_0x48;
		BinaryStream* inStream; // 0x58
		BinaryStream* outStream; // 0x5C
		int unknown_0x60;
		Pointer<Object>* loadedObject; // 0x64
		int unknown_0x68;
		int loadedObjectCount; // 0x6C
		int unknown_0x70;
		int unknown_0x74;
		int unknown_0x78;
		int unknown_0x7C;
		int unknown_0x80;
		int unknown_0x84;
		int unknown_0x88;
		int unknown_0x8C;
		int unknown_0x90;
		TES3::HashMap unknown_0x94;
		int unknown_0xA4;
		TES3::HashMap* unknown_0xA8;
		int unknown_0xAC;

		Stream();
		~Stream();

		bool load(const char* file);
		bool save(const char* file);

		void insertObject(Object* object);
	};
	static_assert(sizeof(Stream) == 0xB0, "NI::Stream failed size validation");
}
