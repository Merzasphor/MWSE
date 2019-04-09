#include "NILightLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NINode.h"
#include "NIAmbientLight.h"
#include "NIDirectionalLight.h"
#include "NIRTTI.h"
#include "NISpotLight.h"

namespace mwse {
	namespace lua {
		void bindNILight() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for NI::DynamicEffect. TODO: MOVE THIS OUTSIDE OF HERE AT SOME POINT!
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::DynamicEffect>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Inherit NI::DynamicEffect.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object, NI::ObjectNET, NI::AVObject>());
				setUserdataForNIDynamicEffect(usertypeDefinition);

				// Finish up our usertype.
				state.set_usertype("niDynamicEffect", usertypeDefinition);
			}

			// Binding for NI::Light.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::Light>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Inherit NI::DynamicEffect.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object, NI::ObjectNET, NI::AVObject, NI::DynamicEffect>());
				setUserdataForNILight(usertypeDefinition);

				// Finish up our usertype.
				state.set_usertype("niLight", usertypeDefinition);
			}

			// Binding for NI::AmbientLight.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::AmbientLight>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Inherit NI::Light.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object, NI::ObjectNET, NI::AVObject, NI::DynamicEffect, NI::Light>());
				setUserdataForNILight(usertypeDefinition);

				// Finish up our usertype.
				state.set_usertype("niAmbientLight", usertypeDefinition);
			}

			// Binding for NI::DirectionalLight.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::DirectionalLight>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Inherit NI::Light.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object, NI::ObjectNET, NI::AVObject, NI::DynamicEffect, NI::Light>());
				setUserdataForNILight(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("direction", &NI::DirectionalLight::direction);

				// Finish up our usertype.
				state.set_usertype("niDirectionalLight", usertypeDefinition);
			}

			// Binding for NI::PointLight.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::PointLight>();
				usertypeDefinition.set("new", []() { return makeLuaNiPointer(NI::PointLight::create()); });

				// Inherit NI::Light.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object, NI::ObjectNET, NI::AVObject, NI::DynamicEffect, NI::Light>());
				setUserdataForNIPointLight(usertypeDefinition);

				// Finish up our usertype.
				state.set_usertype("niPointLight", usertypeDefinition);
			}

			// Binding for NI::SpotLight.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::SpotLight>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Inherit NI::Light.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object, NI::ObjectNET, NI::AVObject, NI::DynamicEffect, NI::Light, NI::PointLight>());
				setUserdataForNIPointLight(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("direction", &NI::SpotLight::direction);
				usertypeDefinition.set("spotAngle", &NI::SpotLight::spotAngle);
				usertypeDefinition.set("spotExponent", &NI::SpotLight::spotExponent);

				// Finish up our usertype.
				state.set_usertype("niSpotLight", usertypeDefinition);
			}
		}
	}
}
