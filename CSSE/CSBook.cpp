#include "CSBook.h"

#include "CSDataHandler.h"
#include "CSRecordHandler.h"
#include "CSGameSetting.h"

namespace se::cs {
	const char* Book::getTaughtSkillName() const {
		const auto gmst = DataHandler::get()->recordHandler->getGameSettingForSkill(skillId);
		if (gmst == nullptr) {
			return "";
		}

		return gmst->value.asString;
	}
}
