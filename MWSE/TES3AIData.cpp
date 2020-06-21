#include "TES3AIData.h"

namespace TES3 {
	const auto TES3_AIPlanner_getActivePackage = reinterpret_cast<AIPackage *(__thiscall*)(AIPlanner*)>(0x564DF0);
	AIPackage * AIPlanner::getActivePackage() {
		return TES3_AIPlanner_getActivePackage(this);
	}

	std::reference_wrapper<AIPackage* [32]> AIPlanner::getPackages() {
		return std::ref(packages);
	}
}