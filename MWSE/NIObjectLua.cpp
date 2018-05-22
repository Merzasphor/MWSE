#include "NIObjectLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindNIObject() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<NI::RTTI>("NIRTTI",
				"name", sol::readonly_property(&NI::RTTI::name),
				"parent", sol::readonly_property(&NI::RTTI::baseRTTI)
				);

			state.new_usertype<NI::Object>("NIObject",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"runTimeTypeInformation", sol::readonly_property([](NI::Object& self) { return self.getRunTimeTypeInformation(); }),
				"references", &NI::Object::references,

				//
				// Methods.
				//

				"isOfType", [](NI::Object& self, unsigned int type) { return self.isOfType((NI::RunTimeTypeInformation::RTTI)type); },
				"isInstanceOfType", [](NI::Object& self, unsigned int type) { return self.isInstanceOfType((NI::RunTimeTypeInformation::RTTI)type); }

				);
		}
	}
}
