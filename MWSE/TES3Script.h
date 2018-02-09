#pragma once

#include "ObjectTypes.h"

namespace TES3 {
	struct Script {
		void * vTable; // 0x00
		ObjectType::ObjectType recordType; // 0x04 // "SCPT"
		int baseFlags; // 0x08
		int unknown_0x0C;
		char name[32]; // 0x10
		long shortCount; // 0x30
		long longCount; // 0x34
		long floatCount; // 0x38
		long dataLength; // 0x3C
		int localVarLength; // The length of the local var names concatenated (includes \0 for string endings)
		char ** shortVarNamePointers; // 0x44
		char ** longVarNamePointers; // 0x48
		char ** floatVarNamePointers; // 0x4C
		char * varNamePointers; // 0x50
		int unknown_0x54; // equals zero?
		void * machineCode; // 0x58
		mwShort * shortVarValues; // 0x5C
		mwLong * longVarValues; // 0x60
		mwFloat * floatVarValues; // 0x64
	};
}
