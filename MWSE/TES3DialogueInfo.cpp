#include "TES3DialogueInfo.h"

#include "TES3GameFile.h"

#include "LuaManager.h"

#include "LuaInfoGetTextEvent.h"

namespace TES3 {
	const auto TES3_DialogueInfo_getText = reinterpret_cast<const char* (__thiscall*)(DialogueInfo*)>(0x4B1B80);
	const auto TES3_DialogueInfo_loadId = reinterpret_cast<bool(__thiscall*)(DialogueInfo*)>(0x4B1A10);
	const auto TES3_DialogueInfo_unloadId = reinterpret_cast<void(__thiscall*)(DialogueInfo*)>(0x4AF3A0);

	const char* DialogueInfo::getText() {
		// Allow the event to override the text.
		sol::object eventResult = mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::InfoGetTextEvent(this));
		if (eventResult.valid()) {
			sol::table eventData = eventResult;
			sol::object text = eventData["text"];
			if (text.is<const char*>()) {
				return text.as<const char*>();
			}
		}

		return TES3_DialogueInfo_getText(this);
	}

	bool DialogueInfo::loadId() {
		return TES3_DialogueInfo_loadId(this);
	}

	void DialogueInfo::unloadId() {
		TES3_DialogueInfo_unloadId(this);
	}
}

