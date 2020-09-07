#pragma once

#include "NIObjectLua.h"

namespace mwse::lua {
	template <typename T>
	void setUserdataForNIExtraData(sol::simple_usertype<T>& usertypeDefinition) {
		setUserdataForNIObject(usertypeDefinition);

		// Basic property binding.
		usertypeDefinition.set("name", sol::readonly_property(&NI::ExtraData::name));
		usertypeDefinition.set("next", sol::property(&NI::ExtraData::getNext_lua, &NI::ExtraData::setNext));
	}

	void bindNIExtraData();
}
