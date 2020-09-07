#include "NIExtraData.h"

#include "LuaUtil.h"

#include "TES3Util.h"

namespace NI {
	ExtraData* ExtraData::getNext() const {
		return next;
	}

	sol::object ExtraData::getNext_lua() const {
		return mwse::lua::makeLuaNiPointer(next);
	}

	void ExtraData::setNext(ExtraData* n) {
		next = n;
	}

	const char* StringExtraData::getString() const {
		return string;
	}

	void StringExtraData::setString(const char* str) {
		mwse::tes3::setDataString(&string, str);
	}

	const char* TextKey::getText() const {
		return text;
	}

	void TextKey::setText(const char* t) {
		mwse::tes3::setDataString(&text, t);
	}

	nonstd::span<TextKey> TextKeyExtraData::getKeys() const {
		return nonstd::span(key, keyCount);
	}
}
