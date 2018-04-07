#include "TES3Script.h"

#define TES3_Script_getLocalVarIndexAndType 0x50E7B0

#define TES3_Script_getShortValue 0x4FFB90
#define TES3_Script_getLongValue 0x4FFC00
#define TES3_Script_getFloatValue 0x4FFC70

namespace TES3 {
	char Script::getLocalVarIndexAndType(const char* name, unsigned int* out_value) {
		return reinterpret_cast<char(__thiscall *)(Script*, const char*, unsigned int*)>(TES3_Script_getLocalVarIndexAndType)(this, name, out_value);
	}

	short Script::getShortValue(unsigned int index, bool useLocalVars) {
		return reinterpret_cast<short(__thiscall *)(Script*, unsigned int, signed char)>(TES3_Script_getLocalVarIndexAndType)(this, index, useLocalVars);
	}

	int Script::getLongValue(unsigned int index, bool useLocalVars) {
		return reinterpret_cast<int(__thiscall *)(Script*, unsigned int, signed char)>(TES3_Script_getLocalVarIndexAndType)(this, index, useLocalVars);
	}

	float Script::getFloatValue(unsigned int index, bool useLocalVars) {
		return reinterpret_cast<float(__thiscall *)(Script*, unsigned int, signed char)>(TES3_Script_getLocalVarIndexAndType)(this, index, useLocalVars);
	}
}
