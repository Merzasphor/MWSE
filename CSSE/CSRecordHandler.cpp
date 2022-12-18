#include "CSRecordHandler.h"

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
}
