#pragma once

#include "TES3Defines.h"
#include "TES3HashMap.h"
#include "TES3Stream.h"

#include "TES3CriticalSection.h"

namespace TES3 {
	struct BSALoader {
		Archive* lastLoadedArchive; // 0x0
		Archive* archiveIterator; // 0x4

		static BSALoader* get();

		bool findFile(const char* path, int* out_thing = nullptr);
	};
	static_assert(sizeof(BSALoader) >= 0x8, "TES3::BSALoader failed size validation");

	struct Archive : Stream {
		struct CaseInsensitiveFileHash {
			DWORD unknown_0x0;
			DWORD unknown_0x4;

			CaseInsensitiveFileHash(const char* path);
		};
		char path[128]; // 0xB0
		int unknown_0x130;
		int unknown_0x134;
		int unknown_0x138;
		void* niFile; // 0x13C
		TES3::HashMap<CaseInsensitiveFileHash, void*> containedFiles; // 0x140
		Archive* nextArchive; // 0x150
		CriticalSection criticalSection; // 0x154

		bool findFileHash(CaseInsensitiveFileHash& hash, int* out_result, const char* validationPath = nullptr);
	};
	static_assert(sizeof(Archive) >= 0x178, "TES3::Archive failed size validation");
	static_assert(sizeof(Archive::CaseInsensitiveFileHash) >= 0x8, "TES3::Archive::FileHash failed size validation");
}
