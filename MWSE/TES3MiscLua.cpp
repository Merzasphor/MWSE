#include "TES3MiscLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Misc.h"
#include "TES3Script.h"
#include "TES3SoulGemData.h"

namespace mwse {
	namespace lua {
		void bindTES3Misc() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::SoulGemData>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("id", sol::readonly_property(&TES3::SoulGemData::id));
				usertypeDefinition.set("model", sol::readonly_property(&TES3::SoulGemData::model));
				usertypeDefinition.set("name", sol::readonly_property(&TES3::SoulGemData::name));
				usertypeDefinition.set("texture", sol::readonly_property(&TES3::SoulGemData::texture));
				usertypeDefinition.set("value", &TES3::SoulGemData::value);
				usertypeDefinition.set("weight", &TES3::SoulGemData::weight);

				// Data that needs to be packaged.
				usertypeDefinition.set("item", sol::readonly_property([](TES3::SoulGemData& self) { makeLuaObject(self.item); }));

				// Finish up our usertype.
				state.set_usertype("tes3soulGemData", usertypeDefinition);
			}

			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Misc>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
				setUserdataForPhysicalObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("value", &TES3::Misc::value);
				usertypeDefinition.set("weight", &TES3::Misc::weight);

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("script", sol::readonly_property([](TES3::Misc& self) { return makeLuaObject(self.getScript()); }));

				// Functions exposed as properties.
				usertypeDefinition.set("icon", sol::property(
					&TES3::Misc::getIconPath,
					[](TES3::Misc& self, const char* value) { if (strlen(value) < 32) tes3::setDataString(&self.icon, value); }
				));
				usertypeDefinition.set("isKey", sol::property(
					[](TES3::Misc& self) { return bool(self.flags & 1); },
					[](TES3::Misc& self, bool value) {
					if (value) {
						self.flags |= 1;
					}
					else {
						self.flags &= ~1;
					}
				}
				));
				usertypeDefinition.set("isSoulGem", sol::readonly_property(&TES3::Misc::isSoulGem));
				usertypeDefinition.set("soulGemData", sol::readonly_property(&TES3::Misc::getSoulGemData));

				usertypeDefinition.set("mesh", sol::property(&TES3::Misc::getModelPath, &TES3::Misc::setModelPath));
				usertypeDefinition.set("name", sol::property(&TES3::Misc::getName, &TES3::Misc::setName));

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition.set("model", sol::property(&TES3::Misc::getModelPath, &TES3::Misc::setModelPath));

				// Finish up our usertype.
				state.set_usertype("tes3misc", usertypeDefinition);
			}
		}
	}
}
