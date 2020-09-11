#pragma once

#include "NIObjectLua.h"

namespace mwse::lua {
	template <typename T>
	void setUserdataForNIExtraData(sol::usertype<T>& usertypeDefinition) {
		setUserdataForNIObject(usertypeDefinition);

		// Basic property binding.
		usertypeDefinition["name"] = sol::readonly_property(&NI::ExtraData::name);
		usertypeDefinition["next"] = sol::property(&NI::ExtraData::getNext, &NI::ExtraData::setNext);
	}

	void bindNIExtraData();
}
