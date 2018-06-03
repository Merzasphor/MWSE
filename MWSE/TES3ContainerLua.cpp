#include "TES3ContainerLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Container.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Container() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Container>("TES3Container",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::Actor, TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::Container::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Container::objectType,

				"boundingBox", &TES3::Container::boundingBox,

				"id", sol::readonly_property(&TES3::Container::getObjectID),
				"name", sol::property(&TES3::Container::getName, &TES3::Container::setName),

				"model", sol::readonly_property(&TES3::Container::getModelPath),

				"flags", &TES3::Container::actorFlags,
				"organic", sol::property(
					[](TES3::Container& self) { return self.getActorFlag(TES3::ActorFlag::Female); },
					[](TES3::Container& self, bool set) { self.setActorFlag(TES3::ActorFlag::Female, set); }
					),
				"respawns", sol::property(
					[](TES3::Container& self) { return self.getActorFlag(TES3::ActorFlag::Essential); },
					[](TES3::Container& self, bool set) { self.setActorFlag(TES3::ActorFlag::Essential, set); }
					),

				"cloneCount", &TES3::Container::cloneCount,

				"isRespawn", sol::readonly_property(&TES3::Container::isRespawn),
				"isInstance", sol::var(false),

				"inventory", sol::readonly_property(&TES3::Container::inventory),
				"capacity", &TES3::Container::capacity,

				"script", sol::readonly_property(&TES3::Container::getScript),

				//
				// Functions.
				//

				"clone", &TES3::Container::clone

				);

			state.new_usertype<TES3::ContainerInstance>("TES3ContainerInstance",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::Actor, TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::ContainerInstance::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::ContainerInstance::objectType,

				"boundingBox", &TES3::ContainerInstance::boundingBox,

				"id", sol::readonly_property(&TES3::ContainerInstance::getObjectID),
				"name", sol::property(&TES3::ContainerInstance::getName, &TES3::ContainerInstance::setName),

				"model", sol::readonly_property(&TES3::ContainerInstance::getModelPath),

				"flags", &TES3::ContainerInstance::actorFlags,
				"organic", sol::property(
					[](TES3::ContainerInstance& self) { return self.getActorFlag(TES3::ActorFlag::Female); },
					[](TES3::ContainerInstance& self, bool set) { self.setActorFlag(TES3::ActorFlag::Female, set); }
					),
				"respawns", sol::property(
					[](TES3::ContainerInstance& self) { return self.getActorFlag(TES3::ActorFlag::Essential); },
					[](TES3::ContainerInstance& self, bool set) { self.setActorFlag(TES3::ActorFlag::Essential, set); }
					),

				"cloneCount", &TES3::ContainerInstance::cloneCount,

				"isRespawn", sol::readonly_property(&TES3::ContainerInstance::isRespawn),
				"isInstance", sol::var(true),

				"inventory", sol::readonly_property(&TES3::ContainerInstance::inventory),
				"capacity", sol::property(&TES3::ContainerInstance::getCapacity, &TES3::ContainerInstance::setCapacity),

				"script", sol::readonly_property(&TES3::ContainerInstance::getScript),

				"container", sol::readonly_property(&TES3::ContainerInstance::container)

				);
		}
	}
}
