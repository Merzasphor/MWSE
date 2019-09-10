#include "TES3ContainerLua.h"

#include "LuaManager.h"
#include "TES3ActorLua.h"

#include "TES3Container.h"
#include "TES3Script.h"

#include "BitUtil.h"

namespace mwse {
	namespace lua {
		void bindTES3Container() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::Container.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Container>("tes3container");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>();
				setUserdataForActor(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["capacity"] = &TES3::Container::capacity;

				// Friendly access to actor flags.
				usertypeDefinition["organic"] = sol::property(
					[](TES3::Container& self) { return BITMASK_TEST(self.actorFlags, TES3::ActorFlagContainer::Organic); },
					[](TES3::Container& self, bool set) { BITMASK_SET(self.actorFlags, TES3::ActorFlagContainer::Organic, set); }
				);
				usertypeDefinition["respawns"] = sol::property(
					[](TES3::Container& self) { return BITMASK_TEST(self.actorFlags, TES3::ActorFlagContainer::Respawns); },
					[](TES3::Container& self, bool set) { BITMASK_SET(self.actorFlags, TES3::ActorFlagContainer::Respawns, set); }
				);

				// Constant values.
				usertypeDefinition["isInstance"] = sol::var(false);

				// Functions exposed as properties.
				usertypeDefinition["mesh"] = sol::property(&TES3::Container::getModelPath, &TES3::Container::setModelPath);
				usertypeDefinition["name"] = sol::property(&TES3::Container::getName, &TES3::Container::setName);
				usertypeDefinition["script"] = sol::readonly_property(&TES3::Container::getScript);

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition["clone"] = &TES3::Container::clone;
				usertypeDefinition["model"] = sol::property(&TES3::Container::getModelPath, &TES3::Container::setModelPath);
			}

			// Binding for TES3::ContainerInstance.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::ContainerInstance>("tes3containerInstance");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::Actor, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>();
				setUserdataForActor(usertypeDefinition);
				
				// Friendly access to actor flags.
				usertypeDefinition["organic"] = sol::property(
					[](TES3::ContainerInstance& self) { return BITMASK_TEST(self.actorFlags, TES3::ActorFlagContainer::Organic); },
					[](TES3::ContainerInstance& self, bool set) { BITMASK_SET(self.actorFlags, TES3::ActorFlagContainer::Organic, set); }
				);
				usertypeDefinition["respawns"] = sol::property(
					[](TES3::ContainerInstance& self) { return BITMASK_TEST(self.actorFlags, TES3::ActorFlagContainer::Respawns); },
					[](TES3::ContainerInstance& self, bool set) { BITMASK_SET(self.actorFlags, TES3::ActorFlagContainer::Respawns, set); }
				);

				// Access to other objects that need to be packaged.
				usertypeDefinition["baseObject"] = sol::readonly_property([](TES3::ContainerInstance& self) { return makeLuaObject(self.container); });

				// Constant values.
				usertypeDefinition["isInstance"] = sol::var(true);

				// Functions exposed as properties.
				usertypeDefinition["capacity"] = sol::property(&TES3::ContainerInstance::getCapacity, &TES3::ContainerInstance::setCapacity);
				usertypeDefinition["isRespawn"] = sol::readonly_property(&TES3::ContainerInstance::isRespawn);
				usertypeDefinition["mesh"] = sol::property(&TES3::ContainerInstance::getModelPath, &TES3::ContainerInstance::setModelPath);
				usertypeDefinition["name"] = sol::property(&TES3::ContainerInstance::getName, &TES3::ContainerInstance::setName);
				usertypeDefinition["script"] = sol::readonly_property(&TES3::ContainerInstance::getScript);

				// TODO: Deprecated. Remove before 2.1-stable.
				usertypeDefinition["container"] = sol::readonly_property([](TES3::ContainerInstance& self) { return makeLuaObject(self.container); });
				usertypeDefinition["model"] = sol::property(&TES3::ContainerInstance::getModelPath, &TES3::ContainerInstance::setModelPath);
			}
		}
	}
}
