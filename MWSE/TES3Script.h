#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct ScriptVariables {
		short * shortVarValues;
		long * longVarValues;
		float * floatVarValues;
	};
	static_assert(sizeof(ScriptVariables) == 0xC, "TES3::ScriptVariables failed size validation");

	struct Script : BaseObject {
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
		ScriptVariables varValues; // 0x5C
		int unknown_0x68;
		int unknown_0x6C;

		//
		// Other related this-call functions.
		//

		char getLocalVarIndexAndType(const char*, unsigned int*);

		short getShortValue(unsigned int, bool);
		int getLongValue(unsigned int, bool);
		float getFloatValue(unsigned int, bool);

	};
	static_assert(sizeof(Script) == 0x70, "TES3::Script failed size validation");
}
