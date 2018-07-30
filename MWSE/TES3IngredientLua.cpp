#include "TES3IngredientLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Ingredient.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Ingredient() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Ingredient>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("value", &TES3::Ingredient::value);
			usertypeDefinition.set("weight", &TES3::Ingredient::weight);

			// Indirect bindings to unions and arrays.
			usertypeDefinition.set("effects", sol::readonly_property([](TES3::Ingredient& self) { return std::ref(self.effects); }));
			usertypeDefinition.set("effectSkillIds", sol::readonly_property([](TES3::Ingredient& self) { return std::ref(self.effectSkillIds); }));
			usertypeDefinition.set("effectAttributeIds", sol::readonly_property([](TES3::Ingredient& self) { return std::ref(self.effectAttributeIds); }));

			// Functions exposed as properties.
			usertypeDefinition.set("icon", sol::property(
				&TES3::Ingredient::getIconPath,
				[](TES3::Ingredient& self, const char* value) { if (strlen(value) < 32) strcpy(self.texture, value); }
			));
			usertypeDefinition.set("mesh", sol::property(&TES3::Ingredient::getModelPath, &TES3::Ingredient::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Ingredient::getName, &TES3::Ingredient::setName));
			usertypeDefinition.set("script", sol::property(&TES3::Ingredient::getScript));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("model", sol::property(&TES3::Ingredient::getModelPath, &TES3::Ingredient::setModelPath));

			// Finish up our usertype.
			state.set_usertype("tes3ingredient", usertypeDefinition);
		}
	}
}
