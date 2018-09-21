#include "TES3GameFile.h"

#include <string.h>
#define NOMINMAX
#include <Windows.h>

namespace TES3 {
	const auto TES3_TES3File_delete = reinterpret_cast<void(__thiscall *)(GameFile*)>(0x4B48F0);
	const auto TES3_TES3File_getChunkData = reinterpret_cast<bool(__thiscall *)(GameFile*, void*, unsigned int)>(0x4B6880);

	using std::uint64_t;

	void GameFile::deleteFile() {
		// Constrain to save games only
		size_t s = strlen(filename);
		if (s > 4) {
			const char *ext = filename + (s - 4);
			if (_stricmp(ext, ".ess") == 0) {
				TES3_TES3File_delete(this);
			}
		}
	}

	bool GameFile::getChunkData(void * data, unsigned int size) {
		return TES3_TES3File_getChunkData(this, data, size);
	}

	std::uint64_t GameFile::getFileSize() const {
		auto x = reinterpret_cast<const WIN32_FIND_DATAA*>(findData);
		uint64_t fileSize;

		fileSize = (uint64_t(x->nFileSizeHigh) << 32) + uint64_t(x->nFileSizeLow);
		return fileSize;
	}

	std::uint64_t GameFile::getModifiedTime() const {
		auto x = reinterpret_cast<const WIN32_FIND_DATAA*>(findData);
		uint64_t time;

		time = (uint64_t(x->ftLastWriteTime.dwHighDateTime) << 32) + uint64_t(x->ftLastWriteTime.dwLowDateTime);
		return time;
	}
}