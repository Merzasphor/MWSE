#include "TES3ArmorLua.h"

#include "LuaManager.h"

#include "TES3Armor.h"
#include "TES3Enchantment.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Armor() {
			LuaManager::getInstance().getState().new_usertype<TES3::Armor>("TES3Armor",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Armor::objectType,

				"id", sol::readonly_property(&TES3::Armor::getObjectID),
				"name", sol::property(&TES3::Armor::getName, &TES3::Armor::setName),

				"icon", sol::readonly_property(&TES3::Armor::getIconPath),
				"model", sol::readonly_property(&TES3::Armor::getModelPath),

				"slot", sol::readonly_property(&TES3::Armor::getType),
				"slotName", sol::readonly_property(&TES3::Armor::getTypeName),
				"isLeftPart", sol::readonly_property(&TES3::Armor::isLeftPartOfPair),

				"weight", sol::readonly_property(&TES3::Armor::getWeight),
				"weightClass", sol::readonly_property(&TES3::Armor::getWeightClass),
				"value", sol::readonly_property(&TES3::Armor::getValue),
				"health", sol::readonly_property(&TES3::Armor::getDurability),
				"armorRating", &TES3::Armor::armorRating,

				"enchantCapacity", &TES3::Armor::enchantCapacity,
				"enchantment", sol::property(&TES3::Armor::getEnchantment, &TES3::Armor::setEnchantment),

				"script", sol::readonly_property(&TES3::Armor::getScript)

				);
		}
	}
}
