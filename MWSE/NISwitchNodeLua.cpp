#include "NISwitchNode.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		void bindNISwitchNode() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<NI::SwitchNode>("NISwitchNode",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"runTimeTypeInformation", sol::readonly_property([](NI::SwitchNode& self) { return self.getRunTimeTypeInformation(); }),
				"references", sol::readonly_property(&NI::SwitchNode::references),

				"name", sol::readonly_property(&NI::SwitchNode::name),

				"flags", &NI::SwitchNode::flags,
				"parentNode", &NI::SwitchNode::parentNode,
				"worldBoundOrigin", &NI::SwitchNode::worldBoundOrigin,
				"worldBoundRadius", &NI::SwitchNode::worldBoundRadius,
				"localRotation", &NI::SwitchNode::localRotation,
				"localTranslate", &NI::SwitchNode::localTranslate,
				"localScale", &NI::SwitchNode::localScale,
				"worldTransform", &NI::SwitchNode::worldTransform,

				"children", sol::readonly_property(&NI::SwitchNode::children),

				"switchIndex", &NI::SwitchNode::switchIndex,

				//
				// Methods.
				//

				"isOfType", [](NI::SwitchNode& self, unsigned int type) { return self.isOfType((NI::RunTimeTypeInformation::RTTI)type); },
				"isInstanceOfType", [](NI::SwitchNode& self, unsigned int type) { return self.isInstanceOfType((NI::RunTimeTypeInformation::RTTI)type); },

				"getObjectByName", [](NI::Node& self, const char* name) { return makeLuaObject(self.getObjectByName(name)); }

			);
		}
	}
}
