#include "TES3ClothingLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Clothing.h"
#include "TES3Enchantment.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Clothing() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Clothing>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());

			// Allow object to be converted to strings using their object ID.
			usertypeDefinition.set(sol::meta_function::to_string, &TES3::Clothing::getObjectID);

			// Basic property binding.
			usertypeDefinition.set("enchantCapacity", &TES3::Clothing::enchantCapacity);
			usertypeDefinition.set("slot", &TES3::Clothing::slot);
			usertypeDefinition.set("value", &TES3::Clothing::value);
			usertypeDefinition.set("weight", &TES3::Clothing::weight);

			// Functions exposed as properties.
			usertypeDefinition.set("enchantment", sol::property(&TES3::Clothing::getEnchantment, &TES3::Clothing::setEnchantment));
			usertypeDefinition.set("icon", sol::property(
				&TES3::Clothing::getIconPath,
				[](TES3::Clothing& self, const char* value) { if (strlen(value) < 32) tes3::setDataString(&self.icon, value); }
			));
			usertypeDefinition.set("isLeftPart", sol::property(&TES3::Clothing::isLeftPartOfPair));
			usertypeDefinition.set("model", sol::property(&TES3::Clothing::getModelPath, &TES3::Clothing::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Clothing::getName, &TES3::Clothing::setName));
			usertypeDefinition.set("script", sol::property(&TES3::Clothing::getScript));
			usertypeDefinition.set("slotName", sol::property(&TES3::Clothing::getTypeName));

			// Finish up our usertype.
			state.set_usertype("tes3clothing", usertypeDefinition);
		}
	}
}
