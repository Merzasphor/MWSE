#include "TES3ContainerLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3AIConfig.h"
#include "TES3Container.h"
#include "TES3Item.h"
#include "TES3Inventory.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Container() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Container>("TES3Container",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Container::objectType,

				"id", sol::readonly_property(&TES3::Container::getObjectID),
				"name", sol::property(&TES3::Container::getName, &TES3::Container::setName),

				"model", sol::readonly_property(&TES3::Container::getModelPath),

				"flags", &TES3::Container::actorFlags,
				"cloneCount", &TES3::Container::cloneCount,

				"isRespawn", sol::readonly_property(&TES3::Container::isRespawn),
				"isInstance", sol::var(false),

				"inventory", sol::readonly_property(&TES3::Container::getInventory),
				"capacity", &TES3::Container::capacity,

				"script", sol::readonly_property(&TES3::Container::getScript)

				);

			state.new_usertype<TES3::ContainerInstance>("TES3ContainerInstance",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Container::objectType,

				"id", sol::readonly_property(&TES3::Container::getObjectID),
				"name", sol::property(&TES3::Container::getName, &TES3::Container::setName),

				"model", sol::readonly_property(&TES3::Container::getModelPath),

				"flags", &TES3::Container::actorFlags,
				"cloneCount", &TES3::Container::cloneCount,

				"isRespawn", sol::readonly_property(&TES3::Container::isRespawn),
				"isInstance", sol::var(true),

				"inventory", sol::readonly_property(&TES3::Container::getInventory),
				"capacity", sol::property(&TES3::ContainerInstance::getCapacity, &TES3::ContainerInstance::setCapacity),

				"script", sol::readonly_property(&TES3::Container::getScript)

				);
		}
	}
}
