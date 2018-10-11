#include "TES3Book.h"

#include "TES3Util.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "LuaBookGetTextEvent.h"

#include "Log.h"

#define TES3_Book_loadBookText 0x4A2A90

namespace TES3 {
	const char* Book::getBookText() {
		// Allow the event to override the text.
		sol::object eventResult = mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::BookGetTextEvent(this));
		if (eventResult.valid()) {
			sol::table eventData = eventResult;
			sol::optional<const char*> newText = eventData["text"];
			if (newText) {
				// Create our new buffer.
				auto length = strlen(newText.value());
				char * buffer = reinterpret_cast<char*>(mwse::tes3::_new(length + 1));

				// Delete the previous buffer and replace it with this one.
				mwse::tes3::_delete(*reinterpret_cast<char**>(0x7CA44C));
				*reinterpret_cast<char**>(0x7CA44C) = buffer;

				// Copy into the buffer and get out of here.
				buffer[length] = '\0';
				strcpy(buffer, newText.value());
				return buffer;
			}
		}

		return reinterpret_cast<char*(__thiscall *)(Book*)>(TES3_Book_loadBookText)(this);
	}
}

