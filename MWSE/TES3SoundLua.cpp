#include "TES3SoundLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Sound.h"
#include "TES3SoundGenerator.h"

namespace mwse {
	namespace lua {
		void bindTES3Sound() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::Sound.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Sound>("tes3sound");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
				setUserdataForBaseObject(usertypeDefinition);

				// Override the id property to use the sound name, rather than the vtable.
				usertypeDefinition[sol::meta_function::to_string] = sol::readonly_property([](TES3::Sound& self) { return self.id; });
				usertypeDefinition["id"] = sol::readonly_property([](TES3::Sound& self) { return self.id; });

				// Allow object to be serialized to json.
				usertypeDefinition["__tojson"] = [](TES3::Sound& self, sol::table state) {
					std::ostringstream ss;
					ss << "\"tes3sound:" << self.id << "\"";
					return ss.str();
				};

				// Access to other objects that need to be packaged.
				usertypeDefinition["filename"] = sol::readonly_property([](TES3::Sound& self) { return self.filename; });

				// Basic function binding.
				usertypeDefinition["play"] = [](TES3::Sound& self, sol::optional<sol::table> params) {
					bool loop = getOptionalParam<bool>(params, "loop", false);
					unsigned char volume = getOptionalParam<double>(params, "volume", 1.0) * 250;
					float pitch = getOptionalParam<double>(params, "pitch", 1.0);
					return self.play(loop ? TES3::SoundPlayFlags::Loop : 0, volume, pitch, true);
				};
				usertypeDefinition["stop"] = &TES3::Sound::stop;
				usertypeDefinition["isPlaying"] = &TES3::Sound::isPlaying;
			}

			// Binding for TES3::SoundGenerator.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::SoundGenerator>("tes3soundGenerator");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
				setUserdataForBaseObject(usertypeDefinition);

				// Allow object to be serialized to json.
				usertypeDefinition["__tojson"] = [](TES3::SoundGenerator& self, sol::table state) {
					std::ostringstream ss;
					ss << "\"tes3soundGenerator:" << self.name << "\"";
					return ss.str();
				};

				// Basic property binding.
				usertypeDefinition["type"] = sol::readonly_property(&TES3::SoundGenerator::soundType);

				// Override the id property to use the soundgen name, rather than the vtable.
				usertypeDefinition["id"] = sol::readonly_property([](TES3::SoundGenerator& self) { return self.name; });

				// Access to other objects that need to be packaged.
				usertypeDefinition["sound"] = sol::readonly_property([](TES3::SoundGenerator& self) { return makeLuaObject(self.sound); });
			}
		}
	}
}
