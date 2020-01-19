#include "TES3ActorLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIPointLight.h"

#include "TES3Attachment.h"
#include "TES3Cell.h"
#include "TES3Misc.h"
#include "TES3Spell.h"

namespace mwse {
	namespace lua {
		void bindTES3Attachment() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Bind TES3::LightAttachmentNode
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::LightAttachmentNode>("tes3lightNode");
				usertypeDefinition["new"] = sol::no_constructor;

				// Access to node properties.
				usertypeDefinition["light"] = &TES3::LightAttachmentNode::light;
				usertypeDefinition["value"] = &TES3::LightAttachmentNode::flickerPhase;
			}

			// Bind TES3::LockAttachmentNode
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::LockAttachmentNode>("tes3lockNode");
				usertypeDefinition["new"] = sol::no_constructor;

				// Access to node properties.
				usertypeDefinition["level"] = &TES3::LockAttachmentNode::lockLevel;
				usertypeDefinition["locked"] = &TES3::LockAttachmentNode::locked;

				// Access to other objects that need to be packaged.
				usertypeDefinition["key"] = sol::property(
					[](TES3::LockAttachmentNode& self) { return self.key; },
					[](TES3::LockAttachmentNode& self, TES3::Misc * key)
				{
					if (key && !(key->flags & 1)) {
						throw std::exception("Invalid key specified. Object is not a key.");
					}

					self.key = key;
				}
				);
				usertypeDefinition["trap"] = sol::property(
					[](TES3::LockAttachmentNode& self) { return self.trap; },
					[](TES3::LockAttachmentNode& self, TES3::Spell * spell) { self.trap = spell; }
				);
			}

			// Bind TES3::TravelDestination
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::TravelDestination>("tes3travelDestinationNode");
				usertypeDefinition["new"] = sol::no_constructor;

				// Access to other objects that need to be packaged.
				usertypeDefinition["cell"] = sol::property(
					[](TES3::TravelDestination& self) { return self.cell; },
					[](TES3::TravelDestination& self, TES3::Cell * cell) { self.cell = cell; }
				);
				usertypeDefinition["marker"] = sol::property(
					[](TES3::TravelDestination& self) { return self.destination; },
					[](TES3::TravelDestination& self, TES3::Reference * destination) { self.destination = destination; }
				);
			}
		}
	}
}
