#pragma once

#include "NIObjectLua.h"

#include "NIDynamicEffect.h"
#include "NILinkedList.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForNIDynamicEffect(sol::usertype<T>& usertypeDefinition) {
			setUserdataForNIAVObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["affectedNodes"] = &NI::DynamicEffect::affectedNodes;
			usertypeDefinition["enabled"] = &NI::DynamicEffect::enabled;

			// Functions exposed as properties.
			usertypeDefinition["type"] = sol::readonly_property(&NI::DynamicEffect::getType);
		}

		void bindNIDynamicEffect();
	}
}
