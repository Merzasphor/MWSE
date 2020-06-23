#include "TES3SoulGemData.h"

namespace TES3 {
	std::string SoulGemData::toString() const{
		return id;
	}

	std::string SoulGemData::toJson() const {
		std::ostringstream ss;
		ss << "\"tes3soulGemData:" << id << "\"";
		return std::move(ss.str());
	}
}
