#pragma once

#include "NIDynamicEffectLua.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::Light.
		template <typename T>
		void setUserdataForNILight(T& usertypeDefinition) {
			setUserdataForNIDynamicEffect(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["ambient"] = &NI::Light::ambient;
			usertypeDefinition["diffuse"] = &NI::Light::diffuse;
			usertypeDefinition["dimmer"] = &NI::Light::dimmer;
			usertypeDefinition["specular"] = &NI::Light::specular;
		}

		// Speed-optimized binding for NI::PointLight.
		template <typename T>
		void setUserdataForNIPointLight(T& usertypeDefinition) {
			setUserdataForNILight(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["constantAttenuation"] = &NI::PointLight::constantAttenuation;
			usertypeDefinition["linearAttenuation"] = &NI::PointLight::linearAttenuation;
			usertypeDefinition["quadraticAttenuation"] = &NI::PointLight::quadraticAttenuation;

			// Basic function binding.
			usertypeDefinition["setAttenuationForRadius"] = &NI::PointLight::setAttenuationForRadius;
		}

		void bindNILight();
	}
}
