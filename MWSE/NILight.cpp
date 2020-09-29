#include "NILight.h"

namespace NI {
	const auto NI_Light_ctor = reinterpret_cast<Light*(__thiscall*)(Light*)>(0x6F9940);
	Light * Light::ctor() {
		return NI_Light_ctor(this);
	}

	Color& Light::getAmbientColor() {
		return ambient;
	}

	void Light::setAmbientColor(const Color& color) {
		ambient = color;
	}

	void Light::setAmbientColor_lua(sol::object object) {
		ambient = object;
	}

	Color& Light::getDiffuseColor() {
		return diffuse;
	}

	void Light::setDiffuseColor(const Color& color) {
		diffuse = color;
	}

	void Light::setDiffuseColor_lua(sol::object object) {
		diffuse = object;
	}

	Color& Light::getSpecularColor() {
		return specular;
	}

	void Light::setSpecularColor(const Color& color) {
		specular = color;
	}

	void Light::setSpecularColor_lua(sol::object object) {
		specular = object;
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::Light)
