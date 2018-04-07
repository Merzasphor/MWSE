#include "TES3Script.h"

#define TES3_Script_getLocalVarIndexAndType 0x50E7B0

namespace TES3 {
	char Script::getLocalVarIndexAndType(const char* name, int* out_value) {
		return reinterpret_cast<char(__thiscall *)(Script*, const char*, int*)>(TES3_Script_getLocalVarIndexAndType)(this, name, out_value);
	}
}
