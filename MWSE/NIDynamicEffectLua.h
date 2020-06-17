#pragma once

#include "NIDynamicEffect.h"

#include "LuaUtil.h"

#include "NIObjectLua.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::DynamicEffect.
		template <typename T>
		void setUserdataForNIDynamicEffect(T& usertypeDefinition) {
			setUserdataForNIAVObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["affectedNodes"] = &NI::DynamicEffect::affectedNodes;
			usertypeDefinition["enabled"] =  &NI::DynamicEffect::enabled;

			// Functions exposed as properties.
			usertypeDefinition["type"] = sol::readonly_property(&NI::DynamicEffect::getType);
		}

		void bindNIDynamicEffect();
	}
}
