#include "TES3SoulGemData.h"

#include "TES3DataHandler.h"
#include "TES3GameSetting.h"

namespace TES3 {
	std::string SoulGemData::toString() const{
		return id;
	}

	std::string SoulGemData::toJson() const {
		std::ostringstream ss;
		ss << "\"tes3soulGemData:" << id << "\"";
		return std::move(ss.str());
	}

	float SoulGemData::getCapacity() const {
		return value * TES3::DataHandler::get()->nonDynamicData->GMSTs[TES3::GMST::fSoulGemMult]->value.asFloat;
	}
}
