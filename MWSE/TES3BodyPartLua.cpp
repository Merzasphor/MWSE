#include "TES3BodyPartLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3ObjectLua.h"

#include "TES3BodyPart.h"
#include "TES3WearablePart.h"

namespace mwse {
	namespace lua {
		void bindTES3BodyPart() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::BodyPart.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::BodyPart>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
				setUserdataForPhysicalObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("raceName", sol::readonly_property(&TES3::BodyPart::raceName));
				usertypeDefinition.set("part", &TES3::BodyPart::part);
				usertypeDefinition.set("partType", &TES3::BodyPart::partType);
				usertypeDefinition.set("vampiric", &TES3::BodyPart::vampiric);

				// Properties that need extra work before returning.
				usertypeDefinition.set("sceneNode", sol::property(
					[](TES3::BodyPart& self) { return makeLuaNiPointer(self.mirroredNode); },
					[](TES3::BodyPart& self, NI::Node * node) { return self.mirroredNode = node; }
				));

				// Functions exposed as properties.
				usertypeDefinition.set("mesh", sol::property(&TES3::BodyPart::getModelPath, &TES3::BodyPart::setModelPath));

				// Easier access to flags.
				usertypeDefinition.set("female", sol::property(
					[](TES3::BodyPart& self) { return self.getFlag(TES3::BodyPartFlag::Female); },
					[](TES3::BodyPart& self, bool set) { self.setFlag(TES3::BodyPartFlag::Female, set); }
				));
				usertypeDefinition.set("playable", sol::property(
					[](TES3::BodyPart& self) { return self.getFlag(TES3::BodyPartFlag::Playable); },
					[](TES3::BodyPart& self, bool set) { self.setFlag(TES3::BodyPartFlag::Playable, set); }
				));

				// Finish up our usertype.
				state.set_usertype("tes3bodyPart", usertypeDefinition);
			}

			// Binding for TES3::WearablePart
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::WearablePart>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("type", &TES3::WearablePart::bodypartID);
				usertypeDefinition.set("male", &TES3::WearablePart::male);
				usertypeDefinition.set("female", &TES3::WearablePart::female);

				// Finish up our usertype.
				state.set_usertype("tes3wearablePart", usertypeDefinition);
			}
		}
	}
}
