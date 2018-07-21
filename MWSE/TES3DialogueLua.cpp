#include "TES3DialogueLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Dialogue.h"
#include "TES3DialogueFilter.h"
#include "TES3DialogueInfo.h"

namespace mwse {
	namespace lua {
		void bindTES3Dialogue() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::Dialogue
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Dialogue>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());
				setUserdataForBaseObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("info", sol::readonly_property(&TES3::Dialogue::info));
				usertypeDefinition.set("journalIndex", sol::readonly_property(&TES3::Dialogue::journalIndex));
				usertypeDefinition.set("type", sol::readonly_property(&TES3::Dialogue::type));

				// Override id property to point to the name.
				usertypeDefinition.set("id", sol::readonly_property(&TES3::Dialogue::name));

				// Finish up our usertype.
				state.set_usertype("tes3dialogue", usertypeDefinition);
			}
		}
	}
}
