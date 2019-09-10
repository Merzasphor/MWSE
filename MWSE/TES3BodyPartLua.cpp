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
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::BodyPart.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::BodyPart>("tes3bodyPart");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::PhysicalObject, TES3::Object, TES3::BaseObject>();
				setUserdataForPhysicalObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["raceName"] = sol::readonly_property(&TES3::BodyPart::raceName);
				usertypeDefinition["part"] = &TES3::BodyPart::part;
				usertypeDefinition["partType"] = &TES3::BodyPart::partType;
				usertypeDefinition["vampiric"] = &TES3::BodyPart::vampiric;

				// Properties that need extra work before returning.
				usertypeDefinition["sceneNode"] = sol::property(
					[](TES3::BodyPart& self) { return makeLuaNiPointer(self.mirroredNode); },
					[](TES3::BodyPart& self, NI::Node * node) { return self.mirroredNode = node; }
				);

				// Functions exposed as properties.
				usertypeDefinition["mesh"] = sol::property(&TES3::BodyPart::getModelPath, &TES3::BodyPart::setModelPath);

				// Easier access to flags.
				usertypeDefinition["female"] = sol::property(
					[](TES3::BodyPart& self) { return self.getFlag(TES3::BodyPartFlag::Female); },
					[](TES3::BodyPart& self, bool set) { self.setFlag(TES3::BodyPartFlag::Female, set); }
				);
				usertypeDefinition["playable"] = sol::property(
					[](TES3::BodyPart& self) { return self.getFlag(TES3::BodyPartFlag::Playable); },
					[](TES3::BodyPart& self, bool set) { self.setFlag(TES3::BodyPartFlag::Playable, set); }
				);
			}

			// Binding for TES3::WearablePart
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::WearablePart>("tes3wearablePart");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["type"] = &TES3::WearablePart::bodypartID;
				usertypeDefinition["male"] = &TES3::WearablePart::male;
				usertypeDefinition["female"] = &TES3::WearablePart::female;
			}
		}
	}
}
