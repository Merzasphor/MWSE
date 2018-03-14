#include "TES3ObjectLua.h"

#include "LuaManager.h"

#include "TES3AIConfig.h"
#include "TES3Class.h"
#include "TES3Enchantment.h"
#include "TES3Faction.h"
#include "TES3Object.h"
#include "TES3Race.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Object() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::BaseObject>("TES3BaseObject",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", sol::readonly(&TES3::BaseObject::objectType),

				//
				// Easy vtable victories.
				//

				"getObjectID", [](TES3::BaseObject* self) { return self->vTable->getObjectID(self); },
				"getObjectType", [](TES3::BaseObject* self) { return self->objectType; },
				"getName", [](TES3::BaseObject* self) { return self->vTable->getName(self); },

				"getType", [](TES3::BaseObject* self) { return self->vTable->getType(self); },
				"getTypeName", [](TES3::BaseObject* self) { return self->vTable->getTypeName(self); },

				"getIcon", [](TES3::BaseObject* self) { return self->vTable->getIconPath(self); },
				"getModel", [](TES3::BaseObject* self) { return self->vTable->getModelPath(self); },

				"getRace", [](TES3::BaseObject* self) { return self->vTable->getRace(self); },
				"getRaceID", [](TES3::BaseObject* self) { return self->vTable->getRaceID(self); },

				"getBirthsignID", [](TES3::BaseObject* self) { return self->vTable->getBirthsignID(self); },

				"getClass", [](TES3::BaseObject* self) { return self->vTable->getClass(self); },
				"getClassID", [](TES3::BaseObject* self) { return self->vTable->getClassID(self); },
				"getLevel", [](TES3::BaseObject* self) { return self->vTable->getLevel(self); },

				"getFaction", [](TES3::BaseObject* self) { return self->vTable->getFaction(self); },
				"getFactionRank", [](TES3::BaseObject* self) { return self->vTable->getFactionRank(self); },

				"getEnchantment", [](TES3::BaseObject* self) { return self->vTable->getEnchantment(self); },
				"setEnchantment", [](TES3::BaseObject* self, TES3::Enchantment* enchantment) { return self->vTable->setEnchantment(self, enchantment); },

				"getScript", [](TES3::BaseObject* self) { return self->vTable->getScript(self); },

				"getAIConfig", [](TES3::BaseObject* self) { return self->vTable->getAIConfig(self); },

				"isMale", [](TES3::BaseObject* self) { return !self->vTable->isFemale(self); },
				"isFemale", [](TES3::BaseObject* self) { return self->vTable->isFemale(self); },

				"getWeight", [](TES3::BaseObject* self) { return self->vTable->getWeight(self); },
				"getValue", [](TES3::BaseObject* self) { return self->vTable->getValue(self); }
			);

			state.new_usertype<TES3::Object>("TES3Object",
				// Disable construction of this type.
				"new", sol::no_constructor
				);

			state.new_usertype<TES3::PhysicalObject>("TES3PhysicalObject",
				// Disable construction of this type.
				"new", sol::no_constructor
				);
		}
	}
}
