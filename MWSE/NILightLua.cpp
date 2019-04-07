#include "NILightLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NINode.h"
#include "NIPointLight.h"
#include "NIRTTI.h"

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

			// Binding for NI::PointLight.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::PointLight>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Inherit NI::Light.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object, NI::ObjectNET, NI::AVObject, NI::DynamicEffect, NI::Light>());
				setUserdataForNILight(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("constantAttenuation", &NI::PointLight::constantAttenuation);
				usertypeDefinition.set("linearAttenuation", &NI::PointLight::linearAttenuation);
				usertypeDefinition.set("quadraticAttenuation", &NI::PointLight::quadraticAttenuation);

				// Finish up our usertype.
				state.set_usertype("niPointLight", usertypeDefinition);
			}
		}
	}
}
