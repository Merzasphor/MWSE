#include "TES3AIData.h"

namespace TES3 {
	const auto TES3_AIData_getActivePackage = reinterpret_cast<AIPackage *(__thiscall*)(AIData*)>(0x564DF0);
	AIPackage * AIData::getActivePackage() {
		return TES3_AIData_getActivePackage(this);
	}
}