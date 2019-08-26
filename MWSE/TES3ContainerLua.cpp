#include "TES3ContainerLua.h"

#include "LuaManager.h"
#include "TES3ActorLua.h"

#include "TES3Container.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Container() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::Container.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Container>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
				setUserdataForActor(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("capacity", &TES3::Container::capacity);

				// Friendly access to actor flags.
				usertypeDefinition.set("organic", sol::property(
					[](TES3::Container& self) { return self.actorFlags.test(TES3::ActorFlagContainer::OrganicBit); },
					[](TES3::Container& self, bool set) { self.actorFlags.set(TES3::ActorFlagContainer::OrganicBit, set); }
				));
				usertypeDefinition.set("respawns", sol::property(
					[](TES3::Container& self) { return self.actorFlags.test(TES3::ActorFlagContainer::RespawnsBit); },
					[](TES3::Container& self, bool set) { self.actorFlags.set(TES3::ActorFlagContainer::RespawnsBit, set); }
				));

				// Constant values.
				usertypeDefinition.set("isInstance", sol::var(false));

				// Functions exposed as properties.
				usertypeDefinition.set("mesh", sol::property(&TES3::Container::getModelPath, &TES3::Container::setModelPath));
				usertypeDefinition.set("name", sol::property(&TES3::Container::getName, &TES3::Container::setName));
				usertypeDefinition.set("script", sol::readonly_property(&TES3::Container::getScript));

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition.set("clone", &TES3::Container::clone);
				usertypeDefinition.set("model", sol::property(&TES3::Container::getModelPath, &TES3::Container::setModelPath));

				// Finish up our usertype.
				state.set_usertype("tes3container", usertypeDefinition);
			}

			// Binding for TES3::ContainerInstance.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::ContainerInstance>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
				setUserdataForActor(usertypeDefinition);
				
				// Friendly access to actor flags.
				usertypeDefinition.set("organic", sol::property(
					[](TES3::ContainerInstance& self) { return self.actorFlags.test(TES3::ActorFlagContainer::OrganicBit); },
					[](TES3::ContainerInstance& self, bool set) { self.actorFlags.set(TES3::ActorFlagContainer::OrganicBit, set); }
				));
				usertypeDefinition.set("respawns", sol::property(
					[](TES3::ContainerInstance& self) { return self.actorFlags.test(TES3::ActorFlagContainer::RespawnsBit); },
					[](TES3::ContainerInstance& self, bool set) { self.actorFlags.set(TES3::ActorFlagContainer::RespawnsBit, set); }
				));

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("baseObject", sol::readonly_property([](TES3::ContainerInstance& self) { return makeLuaObject(self.container); }));

				// Constant values.
				usertypeDefinition.set("isInstance", sol::var(true));

				// Functions exposed as properties.
				usertypeDefinition.set("capacity", sol::property(&TES3::ContainerInstance::getCapacity, &TES3::ContainerInstance::setCapacity));
				usertypeDefinition.set("isRespawn", sol::readonly_property(&TES3::ContainerInstance::isRespawn));
				usertypeDefinition.set("mesh", sol::property(&TES3::ContainerInstance::getModelPath, &TES3::ContainerInstance::setModelPath));
				usertypeDefinition.set("name", sol::property(&TES3::ContainerInstance::getName, &TES3::ContainerInstance::setName));
				usertypeDefinition.set("script", sol::readonly_property(&TES3::ContainerInstance::getScript));

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition.set("container", sol::readonly_property([](TES3::ContainerInstance& self) { return makeLuaObject(self.container); }));
				usertypeDefinition.set("model", sol::property(&TES3::ContainerInstance::getModelPath, &TES3::ContainerInstance::setModelPath));

				// Finish up our usertype.
				state.set_usertype("tes3containerInstance", usertypeDefinition);
			}
		}
	}
}
