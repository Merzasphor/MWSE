#include "WindowsUtil.h"

namespace se::windows {
	bool isKeyDown(int key) {
		return (GetKeyState(key) & 0x8000) != 0;
	}
}
