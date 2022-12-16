#include "CSScript.h"

namespace se::cs {
	const char* Script::getShortVarName(int index) const {
		const auto Script_getShortName = reinterpret_cast<const char* (__thiscall*)(const Script*, int)>(0x5645E0);
		return Script_getShortName(this, index);
	}

	const char* Script::getLongVarName(int index) const {
		const auto Script_getLongVarName = reinterpret_cast<const char* (__thiscall*)(const Script*, int)>(0x564710);
		return Script_getLongVarName(this, index);

	}

	const char* Script::getFloatVarName(int index) const {
		const auto Script_getFloatVarName = reinterpret_cast<const char* (__thiscall*)(const Script*, int)>(0x564820);
		return Script_getFloatVarName(this, index);

	}
}
