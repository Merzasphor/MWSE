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
				auto usertypeDefinition = state.create_simple_usertype<TES3::LightAttachmentNode>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Access to node properties.
				usertypeDefinition.set("light", &TES3::LightAttachmentNode::light);
				usertypeDefinition.set("value", &TES3::LightAttachmentNode::flickerPhase);

				// Finish up our usertype.
				state.set_usertype("tes3lightNode", usertypeDefinition);
			}

			// Bind TES3::LockAttachmentNode
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::LockAttachmentNode>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Access to node properties.
				usertypeDefinition.set("level", &TES3::LockAttachmentNode::lockLevel);
				usertypeDefinition.set("locked", &TES3::LockAttachmentNode::locked);

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("key", sol::property(
					[](TES3::LockAttachmentNode& self) { return makeLuaObject(self.key); },
					[](TES3::LockAttachmentNode& self, TES3::Misc * key)
				{
					if (key && !(key->flags & 1)) {
						throw std::exception("Invalid key specified. Object is not a key.");
					}

					self.key = key;
				}
				));
				usertypeDefinition.set("trap", sol::property(
					[](TES3::LockAttachmentNode& self) { return makeLuaObject(self.trap); },
					[](TES3::LockAttachmentNode& self, TES3::Spell * spell) { self.trap = spell; }
				));

				// Finish up our usertype.
				state.set_usertype("tes3lockNode", usertypeDefinition);
			}

			// Bind TES3::TravelDestination
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::TravelDestination>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("cell", sol::property(
					[](TES3::TravelDestination& self) { return makeLuaObject(self.cell); },
					[](TES3::TravelDestination& self, TES3::Cell * cell) { self.cell = cell; }
				));
				usertypeDefinition.set("marker", sol::property(
					[](TES3::TravelDestination& self) { return makeLuaObject(self.destination); },
					[](TES3::TravelDestination& self, TES3::Reference * destination) { self.destination = destination; }
				));

				// Finish up our usertype.
				state.set_usertype("tes3travelDestinationNode", usertypeDefinition);
			}
		}
	}
}
