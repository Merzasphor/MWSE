#pragma once

#include "sol.hpp"

#include "LuaUtil.h"

#include "NIObjectLua.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::ObjectNET.
		template <typename T>
		void setUserdataForNIDynamicEffect(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForNIAVObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("enabled", &NI::DynamicEffect::enabled);
		}
	}
}
