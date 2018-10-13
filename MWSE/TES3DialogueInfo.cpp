#include "TES3DialogueInfo.h"

#include "LuaManager.h"

#include "LuaInfoFilterEvent.h"

namespace TES3 {
	const auto TES3_DialogueInfo_getText = reinterpret_cast<const char* (__thiscall*)(DialogueInfo*)>(0x4B1B80);
	const auto TES3_DialogueInfo_loadId = reinterpret_cast<bool(__thiscall*)(DialogueInfo*)>(0x4B1A10);
	const auto TES3_DialogueInfo_unloadId = reinterpret_cast<void(__thiscall*)(DialogueInfo*)>(0x4AF3A0);
	const auto TES3_DialogueInfo_filter = reinterpret_cast<bool(__thiscall*)(DialogueInfo*, Actor*, Reference*, signed char, Dialogue*)>(0x4B0190);

	const char* DialogueInfo::getText() {
		return TES3_DialogueInfo_getText(this);
	}

	bool DialogueInfo::loadId() {
		return TES3_DialogueInfo_loadId(this);
	}

	void DialogueInfo::unloadId() {
		TES3_DialogueInfo_unloadId(this);
	}

	bool DialogueInfo::filter(Actor * actor, Reference * reference, signed char source, Dialogue * dialogue) {
		bool result = TES3_DialogueInfo_filter(this, actor, reference, source, dialogue);

		sol::object eventResult = mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::InfoFilterEvent(this, actor, reference, source, dialogue, result));
		if (eventResult.valid()) {
			sol::table eventData = eventResult;
			sol::optional<bool> passes = eventData["passes"];
			result = passes.value_or(result);
		}

		return result;
	}
}

