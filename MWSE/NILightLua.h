#pragma once

#include "NIDynamicEffectLua.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::Light.
		template <typename T>
		void setUserdataForNILight(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForNIDynamicEffect(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("ambient", &NI::Light::ambient);
			usertypeDefinition.set("diffuse", &NI::Light::diffuse);
			usertypeDefinition.set("dimmer", &NI::Light::dimmer);
			usertypeDefinition.set("specular", &NI::Light::specular);
		}

		// Speed-optimized binding for NI::PointLight.
		template <typename T>
		void setUserdataForNIPointLight(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForNILight(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("constantAttenuation", &NI::PointLight::constantAttenuation);
			usertypeDefinition.set("linearAttenuation", &NI::PointLight::linearAttenuation);
			usertypeDefinition.set("quadraticAttenuation", &NI::PointLight::quadraticAttenuation);

			// Basic function binding.
			usertypeDefinition.set("setAttenuationForRadius", &NI::PointLight::setAttenuationForRadius);
		}

		void bindNILight();
	}
}
