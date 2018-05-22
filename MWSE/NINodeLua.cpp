#include "NINode.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		void bindNINode() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<NI::Node>("NINode",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"runTimeTypeInformation", sol::readonly_property([](NI::Node& self) { return self.getRunTimeTypeInformation(); }),
				"references", sol::readonly_property(&NI::Node::references),

				"name", sol::readonly_property(&NI::Node::name),

				//
				// Methods.
				//

				"isOfType", [](NI::Node& self, unsigned int type) { return self.isOfType((NI::RunTimeTypeInformation::RTTI)type); },
				"isInstanceOfType", [](NI::Node& self, unsigned int type) { return self.isInstanceOfType((NI::RunTimeTypeInformation::RTTI)type); },

				"getObjectByName", [](NI::Node& self, const char* name) { return makeLuaObject(self.getObjectByName(name)); }

			);
		}
	}
}
