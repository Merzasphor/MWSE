#include "TES3BookLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Book.h"
#include "TES3Enchantment.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Book() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Book>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("enchantCapacity", &TES3::Book::enchantCapacity);
			usertypeDefinition.set("skill", &TES3::Book::skillToRaise);
			usertypeDefinition.set("type", &TES3::Book::bookType);
			usertypeDefinition.set("value", &TES3::Book::value);
			usertypeDefinition.set("weight", &TES3::Book::weight);

			// Functions exposed as properties.
			usertypeDefinition.set("enchantment", sol::property(&TES3::Book::getEnchantment, &TES3::Book::setEnchantment));
			usertypeDefinition.set("icon", sol::property(
				&TES3::Book::getIconPath,
				[](TES3::Book& self, const char* value) { if (strlen(value) < 32) tes3::setDataString(&self.icon, value); }
			));
			usertypeDefinition.set("mesh", sol::property(&TES3::Book::getModelPath, &TES3::Book::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Book::getName, &TES3::Book::setName));
			usertypeDefinition.set("script", sol::property(&TES3::Book::getScript));
			usertypeDefinition.set("text", sol::property(&TES3::Book::getBookText));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("model", sol::property(&TES3::Book::getModelPath, &TES3::Book::setModelPath));

			// Finish up our usertype.
			state.set_usertype("tes3book", usertypeDefinition);
		}
	}
}
