#include "TES3FaderLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Fader.h"

namespace mwse {
	namespace lua {
		void bindTES3Fader() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Fader>();
			usertypeDefinition.set("new", sol::constructors<TES3::Fader(), TES3::Fader(float, bool)>());

			// Function bindings.
			usertypeDefinition.set("activate", &TES3::Fader::activate);
			usertypeDefinition.set("deactivate", &TES3::Fader::deactivate);
			usertypeDefinition.set("update", &TES3::Fader::updateForFrame);
			usertypeDefinition.set("setTexture", &TES3::Fader::setTexture);
			usertypeDefinition.set("removeMaterialProperty", &TES3::Fader::removeMaterialProperty);

			// Expose writing active state as mapping for activate/deactivate.
			usertypeDefinition.set("active", sol::property(
				&TES3::Fader::isActive,
				[](TES3::Fader& self, bool state)
			{
				if (state) {
					self.activate();
				}
				else {
					self.deactivate();
				}
			}
			));

			// Expose fade as a fancier functions.
			usertypeDefinition.set("fadeIn", [](TES3::Fader& self, sol::optional<sol::table> params) {
				float duration = getOptionalParam(params, "duration", 1.0f);
				self.fadeTo(1.0f, duration);
			});
			usertypeDefinition.set("fadeOut", [](TES3::Fader& self, sol::optional<sol::table> params) {
				float duration = getOptionalParam(params, "duration", 1.0f);
				self.fadeTo(0.0f, duration);
			});
			usertypeDefinition.set("fadeTo", [](TES3::Fader& self, sol::optional<sol::table> params) {
				float value = getOptionalParam(params, "value", 1.0f);
				float duration = getOptionalParam(params, "duration", 1.0f);
				self.fadeTo(value, duration);
			});

			// Expose setColor fancier.
			usertypeDefinition.set("setColor", [](TES3::Fader& self, sol::table params)
			{
				sol::optional <TES3::Vector3> color = getOptionalParamVector3(params, "color");
				if (!color) {
					return false;
				}

				self.setColor(color.value(), getOptionalParam<bool>(params, "flag", false));

				return true;
			});

			// Finish up our usertype.
			state.set_usertype("tes3fader", usertypeDefinition);
		}
	}
}
