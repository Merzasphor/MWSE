#include "NIColorLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIColor.h"

#include <iomanip>

namespace mwse {
	namespace lua {
		void bindNIColor() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<NI::Color>("niColor");
			usertypeDefinition["new"] = sol::no_constructor;

			// Operator overloading.
			usertypeDefinition[sol::meta_function::addition] = &NI::Color::operator+;
			usertypeDefinition[sol::meta_function::subtraction] = &NI::Color::operator-;
			usertypeDefinition[sol::meta_function::multiplication] = sol::overload(
				sol::resolve<NI::Color(const NI::Color&)>(&NI::Color::operator*),
				sol::resolve<NI::Color(const float)>(&NI::Color::operator*)
			);
			usertypeDefinition[sol::meta_function::to_string] = [](NI::Color& self) {
				std::ostringstream ss;
				ss << std::fixed << std::setprecision(2) << "<" << self.r << ", " << self.g << ", " << self.b << ">";
				return ss.str();
			};

			// Basic property binding.
			usertypeDefinition["r"] = &NI::Color::r;
			usertypeDefinition["g"] = &NI::Color::g;
			usertypeDefinition["b"] = &NI::Color::b;

			// Long aliases for color access.
			usertypeDefinition["red"] = &NI::Color::r;
			usertypeDefinition["green"] = &NI::Color::g;
			usertypeDefinition["blue"] = &NI::Color::b;

			// Basic function binding.
			usertypeDefinition["copy"] = [](NI::Color& self) { return NI::Color(self); };
			usertypeDefinition["clamp"] = &NI::Color::clamp;

			// Conversion to TES3::Vector3.
			usertypeDefinition["toVector3"] = [](NI::Color& self) { return TES3::Vector3(self.r, self.g, self.b); };
		}
	}
}
