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

				// TODO: Follow up with sol2 author on binding c-arrays to userdata.
				//"effects", &TES3::Ingredient::effects,

				"script", sol::readonly_property(&TES3::Ingredient::getScript)

				);
		}
	}
}
