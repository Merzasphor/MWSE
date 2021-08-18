#pragma once

#include "LuaExecutor.h"

namespace mwse::lua {
	size_t getVirtualMemoryUsage();

	std::optional<std::string> getClipboardText();
	bool setClipboardText(std::optional<std::string> text);

	std::tuple<unsigned int, sol::optional<std::shared_ptr<LuaExecutor>>> execute(const char* command, sol::optional<bool> async);

	bool getIsVirtualKeyPressed(int VK_key);
}
