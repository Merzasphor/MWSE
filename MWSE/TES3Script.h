#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct ScriptVariables {
		short * shortVarValues;
		long * longVarValues;
		float * floatVarValues;
	};
	static_assert(sizeof(ScriptVariables) == 0xC, "TES3::ScriptVariables failed size validation");

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
		short * shortVarValues; // 0x5C
		long * longVarValues; // 0x60
		float * floatVarValues; // 0x64
		int unknown_0x68;
		int unknown_0x6C;
	};
	static_assert(sizeof(Script) == 0x70, "TES3::Script failed size validation");
}
