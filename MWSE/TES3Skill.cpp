#include "TES3Skill.h"

#include "TES3Util.h"

#include "TES3DataHandler.h"
#include "TES3GameSetting.h"

namespace TES3 {
	const char* Skill::getName() const {
		return DataHandler::get()->nonDynamicData->GMSTs[getNameGMST()]->value.asString;
	}

	int Skill::getNameGMST() const {
		return NAME_GMSTS[skill];
	}

	std::string Skill::getIconPath() const {
		std::string path = "icons\\k\\";
		path.append(ICON_PATHS[skill]);
		return std::move(path);
	}

	std::reference_wrapper<float[4]> Skill::getProgressActions() {
		return std::ref(progressActions);
	}
}
