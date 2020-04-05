#include "TES3BodyPartLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3ObjectLua.h"

#include "TES3BodyPart.h"
#include "TES3BodyPartManager.h"
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

			// Binding for TES3::BodyPartManager::AttachNode
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::BodyPartManager::AttachNode>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("flags", &TES3::BodyPartManager::AttachNode::flags);
				usertypeDefinition.set("node", &TES3::BodyPartManager::AttachNode::node);
				usertypeDefinition.set("rotation", &TES3::BodyPartManager::AttachNode::rotation);
				usertypeDefinition.set("translation", &TES3::BodyPartManager::AttachNode::translation);

				// Finish up our usertype.
				state.set_usertype("tes3bodyPartManagerAttachNode", usertypeDefinition);
			}

			// Binding for TES3::BodyPartManager::ActiveBodyPart
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::BodyPartManager::ActiveBodyPart>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("flags", &TES3::BodyPartManager::ActiveBodyPart::flags);
				usertypeDefinition.set("item", &TES3::BodyPartManager::ActiveBodyPart::item);
				usertypeDefinition.set("node", &TES3::BodyPartManager::ActiveBodyPart::node);

				// Properties that need packaging.
				usertypeDefinition.set("bodyPart", sol::readonly_property([](TES3::BodyPartManager::ActiveBodyPart& self) { return makeLuaObject(self.bodyPart); }));

				// Finish up our usertype.
				state.set_usertype("tes3bodyPartManagerActiveBodyPart", usertypeDefinition);
			}

			// Binding for TES3::BodyPartManager
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::BodyPartManager>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("activeBodyParts", sol::readonly_property(&TES3::BodyPartManager::activeBodyParts));
				usertypeDefinition.set("animationPhase", sol::readonly_property(&TES3::BodyPartManager::animationPhase));
				usertypeDefinition.set("attachNodes", sol::readonly_property(&TES3::BodyPartManager::attachNodes));
				usertypeDefinition.set("reference", sol::readonly_property(&TES3::BodyPartManager::reference));

				// Basic function bindings.
				usertypeDefinition.set("getActiveBodyPart", &TES3::BodyPartManager::getActiveBodyPart);
				usertypeDefinition.set("getActiveBodyPartForItem", &TES3::BodyPartManager::getActiveBodyPartForItem);
				usertypeDefinition.set("getActiveBodyPartNode", &TES3::BodyPartManager::getActiveBodyPartNode);
				usertypeDefinition.set("removeEquippedLayers", &TES3::BodyPartManager::removeEquippedLayers);
				usertypeDefinition.set("setActivePartData", &TES3::BodyPartManager::setActivePartData);
				usertypeDefinition.set("setBodyPartByIdForObject", &TES3::BodyPartManager::setBodyPartByIdForObject);
				usertypeDefinition.set("setBodyPartForObject", &TES3::BodyPartManager::setBodyPartForObject);
				usertypeDefinition.set("updateForReference", &TES3::BodyPartManager::updateForReference);

				// Legacy support, being removed.
				usertypeDefinition.set("setBodyPartByIdForItem", &TES3::BodyPartManager::setBodyPartByIdForObject);
				usertypeDefinition.set("setBodyPartForItem", &TES3::BodyPartManager::setBodyPartForObject);

				// Finish up our usertype.
				state.set_usertype("tes3bodyPartManager", usertypeDefinition);
			}
		}
	}
}
