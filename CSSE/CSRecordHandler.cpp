#include "CSRecordHandler.h"

#include "StringUtil.h"

namespace se::cs {
	size_t RecordHandler::getCellCount() const {
		const auto RecordHandler_getCellCount = reinterpret_cast<size_t(__thiscall*)(const RecordHandler*)>(0x401F7D);
		return RecordHandler_getCellCount(this);
	}

	Cell* RecordHandler::getCellByIndex(size_t index) const {
		const auto RecordHandler_getCellByIndex = reinterpret_cast<Cell*(__thiscall*)(const RecordHandler*, size_t)>(0x401230);
		return RecordHandler_getCellByIndex(this, index);
	}

	Cell* RecordHandler::getCellByID(const char* id) const {
		const auto RecordHandler_getCellByID = reinterpret_cast<Cell * (__thiscall*)(const RecordHandler*, const char*)>(0x403B66);
		return RecordHandler_getCellByID(this, id);
	}

	const char* RecordHandler::getBaseAnimation(int sex, bool firstPerson) const {
		const auto RecordHandler_getBaseAnimation = reinterpret_cast<const char* (__thiscall*)(const RecordHandler*, int, int)>(0x40236F);
		return RecordHandler_getBaseAnimation(this, sex, firstPerson);
	}

	bool RecordHandler::isBaseAnimation(const char* animation) const {
		const std::string_view animationSV = animation;
		
		const auto maleAnim = getBaseAnimation(0);
		if (maleAnim && string::iequal(maleAnim, animationSV)) {
			return true;
		}

		const auto femaleAnim = getBaseAnimation(1);
		if (femaleAnim && string::iequal(femaleAnim, animationSV)) {
			return true;
		}

		if (string::iequal("base_animKnA.nif", animationSV)) {
			return true;
		}

		if (string::iequal("argonian_swimKnA.nif", animationSV)) {
			return true;
		}

		return false;
	}
}
