#include "TES3GameSetting.h"

#include "TES3Util.h"

namespace TES3 {
	GameSettingInfo * GameSettingInfo::get(int id) {
		return &reinterpret_cast<TES3::GameSettingInfo*>(0x794800)[id];
	}

	GameSettingInfo * GameSetting::getInfo() {
		return GameSettingInfo::get(index);
	}

	char GameSetting::getType() {
		// The type is unreliable, instead use the first character of the name.
		return getInfo()->name[0];
	}

	const char* GameSetting::getName() {
		return getInfo()->name;
	}

	const char* GameSetting::getDefaultStringValue() {
		return getInfo()->defaultStringValue;
	}

	int GameSetting::getDefaultIntValue() {
		return getInfo()->defaultIntValue;
	}

	float GameSetting::getDefaultFloatValue() {
		return getInfo()->defaultFloatValue;
	}
}
