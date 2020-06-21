#pragma once

#include "NIDynamicEffectLua.h"

#include "NIColor.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForNILight(sol::usertype<T>& usertypeDefinition) {
			setUserdataForNIDynamicEffect(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["ambient"] = &NI::Light::ambient;
			usertypeDefinition["diffuse"] = &NI::Light::diffuse;
			usertypeDefinition["dimmer"] = &NI::Light::dimmer;
			usertypeDefinition["specular"] = &NI::Light::specular;
		}

		template <typename T>
		void setUserdataForNIPointLight(sol::usertype<T>& usertypeDefinition) {
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
