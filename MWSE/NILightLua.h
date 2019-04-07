#pragma once

#include "NIDynamicEffectLua.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::ObjectNET.
		template <typename T>
		void setUserdataForNILight(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForNIDynamicEffect(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("ambient", &NI::Light::ambient);
			usertypeDefinition.set("diffuse", &NI::Light::diffuse);
			usertypeDefinition.set("dimmer", &NI::Light::dimmer);
			usertypeDefinition.set("specular", &NI::Light::specular);
		}

		void bindNILight();
	}
}
