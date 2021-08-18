#pragma once

#include "LuaExecutor.h"

namespace mwse::lua {
	size_t getVirtualMemoryUsage();

	std::optional<std::string> getClipboardText();
	bool setClipboardText(std::optional<std::string> text);

	sol::optional<std::shared_ptr<LuaExecutor>> createProcess(sol::table params);
	
	void openURL(const std::string& url);

	bool getIsVirtualKeyPressed(int VK_key);
}
