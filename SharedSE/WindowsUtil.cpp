#include "WindowsUtil.h"

namespace se::windows {
	bool isKeyDown(int key) {
		return (GetKeyState(key) & 0x8000) != 0;
	}

	std::filesystem::path getModulePath(HINSTANCE hInstance) {
		char path[MAX_PATH] = { 0 };
		if (GetModuleFileNameA(hInstance, path, sizeof(path)) == 0) {
			return {};
		}
		return path;
	}
}
