#include "TES3GameSetting.h"

#include "TES3Util.h"

namespace TES3 {
	GameSettingInfo * GameSettingInfo::get(int id) {
		return &reinterpret_cast<TES3::GameSettingInfo*>(0x794800)[id];
	}

	GameSettingInfo * GameSetting::getInfo() const {
		return GameSettingInfo::get(index);
	}

	char * GameSetting::getObjectID() const {
		return getInfo()->name;
	}

	char GameSetting::getType() const {
		// The type is unreliable, instead use the first character of the name.
		return getInfo()->name[0];
	}

	const char* GameSetting::getName() const {
		return getInfo()->name;
	}

	const char* GameSetting::getDefaultStringValue() const {
		return getInfo()->defaultStringValue;
	}

	int GameSetting::getDefaultIntValue() const {
		return getInfo()->defaultIntValue;
	}

	float GameSetting::getDefaultFloatValue() const {
		return getInfo()->defaultFloatValue;
	}

	std::string GameSetting::toJson() const {
		std::ostringstream ss;
		ss << "\"tes3gameSetting:" << getName() << "\"";
		return std::move(ss.str());
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::GameSetting)
