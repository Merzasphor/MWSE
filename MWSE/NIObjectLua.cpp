#include "NIObjectLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

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

			state.new_usertype<NI::ObjectNET>("NIObjectNET",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"runTimeTypeInformation", sol::readonly_property([](NI::ObjectNET& self) { return self.getRunTimeTypeInformation(); }),
				"references", &NI::ObjectNET::references,

				"name", sol::readonly_property(&NI::ObjectNET::name),

				//
				// Methods.
				//

				"isOfType", [](NI::ObjectNET& self, unsigned int type) { return self.isOfType((NI::RunTimeTypeInformation::RTTI)type); },
				"isInstanceOfType", [](NI::ObjectNET& self, unsigned int type) { return self.isInstanceOfType((NI::RunTimeTypeInformation::RTTI)type); }

			);

			state.new_usertype<NI::AVObject>("NIAVObject",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"runTimeTypeInformation", sol::readonly_property([](NI::AVObject& self) { return self.getRunTimeTypeInformation(); }),
				"references", &NI::AVObject::references,

				"name", sol::readonly_property(&NI::AVObject::name),

				"flags", &NI::AVObject::flags,
				"parentNode", &NI::AVObject::parentNode,
				"worldBoundOrigin", &NI::AVObject::worldBoundOrigin,
				"worldBoundRadius", &NI::AVObject::worldBoundRadius,
				"localRotation", &NI::AVObject::localRotation,
				"localTranslate", &NI::AVObject::localTranslate,
				"localScale", &NI::AVObject::localScale,
				"worldTransform", &NI::AVObject::worldTransform,

				//
				// Methods.
				//

				"isOfType", [](NI::AVObject& self, unsigned int type) { return self.isOfType((NI::RunTimeTypeInformation::RTTI)type); },
				"isInstanceOfType", [](NI::AVObject& self, unsigned int type) { return self.isInstanceOfType((NI::RunTimeTypeInformation::RTTI)type); },

				"getObjectByName", [](NI::AVObject& self, const char* name) { return makeLuaObject(self.getObjectByName(name)); }

			);
		}
	}
}
