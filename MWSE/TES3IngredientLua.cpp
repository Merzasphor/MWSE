#include "TES3IngredientLua.h"

#include "LuaManager.h"

#include "TES3Ingredient.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Ingredient() {
			LuaManager::getInstance().getState().new_usertype<TES3::Ingredient>("TES3Ingredient",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Ingredient::objectType,

				"id", sol::readonly_property(&TES3::Ingredient::getObjectID),
				"name", sol::property(&TES3::Ingredient::getName, &TES3::Ingredient::setName),

				"icon", sol::readonly_property(&TES3::Ingredient::getIconPath),
				"model", sol::readonly_property(&TES3::Ingredient::getModelPath),

				"value", sol::readonly_property(&TES3::Ingredient::getValue),
				"weight", sol::readonly_property(&TES3::Ingredient::getWeight),

				"effects", sol::readonly_property([](TES3::Ingredient* self) { return std::ref(self->effects); }),
				"effectSkillIds", sol::readonly_property([](TES3::Ingredient* self) { return std::ref(self->effectSkillIds); }),
				"effectAttributeIds", sol::readonly_property([](TES3::Ingredient* self) { return std::ref(self->effectAttributeIds); }),

				"script", sol::readonly_property(&TES3::Ingredient::getScript)

				);
		}
	}
}
