#pragma once

namespace se::windows {
	bool isKeyDown(int key);

	std::filesystem::path getModulePath(HINSTANCE hInstance);
}
