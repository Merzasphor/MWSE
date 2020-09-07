#include "NIExtraDataLua.h"

#include "LuaManager.h"

#include "NIRTTI.h"
#include "NIExtraData.h"

namespace mwse::lua {
	void bindNIExtraData() {
		// Get our lua state.
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		// Binding for NI::ExtraData.
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<NI::ExtraData>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object>());
			setUserdataForNIExtraData(usertypeDefinition);

			// Finish up our usertype.
			state.set_usertype("niExtraData", usertypeDefinition);
		}

		// Binding for NI::StringExtraData.
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<NI::StringExtraData>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<NI::ExtraData, NI::Object>());
			setUserdataForNIExtraData(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("string", sol::property(&NI::StringExtraData::getString, &NI::StringExtraData::setString));

			// Finish up our usertype.
			state.set_usertype("niStringExtraData", usertypeDefinition);
		}

		// Binding for NI::TextKeyExtraData.
		{
			// Binding for NI::TextKey.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::TextKey>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("text", sol::property(&NI::TextKey::getText, &NI::TextKey::setText));
				usertypeDefinition.set("time", &NI::TextKey::time);

				// Finish up our usertype.
				state.set_usertype("niTextKey", usertypeDefinition);
			}

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<NI::TextKeyExtraData>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<NI::ExtraData, NI::Object>());
			setUserdataForNIExtraData(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("keys", sol::readonly_property(&NI::TextKeyExtraData::getKeys));

			// Finish up our usertype.
			state.set_usertype("niTextKeyExtraData", usertypeDefinition);
		}
	}
}
