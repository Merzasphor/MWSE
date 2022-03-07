#include "TES3Archive.h"

namespace TES3 {
	BSALoader* BSALoader::get() {
		return *reinterpret_cast<BSALoader**>(0x7C9F74);
	}

	const auto TES3_BSALoader_findFile = reinterpret_cast<bool(__thiscall*)(BSALoader*, const char*, int*)>(0x4936A0);
	bool BSALoader::findFile(const char* path, int* out_thing) {
		return TES3_BSALoader_findFile(this, path, out_thing);
	}

	const auto TES3_Archive_CaseInsensitiveFileHash_ctor = reinterpret_cast<void(__thiscall*)(Archive::CaseInsensitiveFileHash*, const char*)>(0x494380);
	Archive::CaseInsensitiveFileHash::CaseInsensitiveFileHash(const char* path) {
		TES3_Archive_CaseInsensitiveFileHash_ctor(this, path);
	}

	const auto TES3_Archive_findFileHash = reinterpret_cast<bool(__thiscall*)(Archive*, Archive::CaseInsensitiveFileHash&, int*, const char*)>(0x493B20);
	bool Archive::findFileHash(CaseInsensitiveFileHash& hash, int* out_result, const char* validationPath) {
		return TES3_Archive_findFileHash(this, hash, out_result, validationPath);
	}
}
