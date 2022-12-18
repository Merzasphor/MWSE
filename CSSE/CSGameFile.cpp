#include "CSGameFile.h"

namespace se::cs {
	void GameFile::setToLoadFlag(bool state) {
		const auto GameFile_setToLoadFlag = reinterpret_cast<void(__thiscall*)(GameFile*, bool)>(0x401D84);
		GameFile_setToLoadFlag(this, state);
	}
}
