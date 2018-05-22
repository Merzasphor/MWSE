#include "NINode.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIAVObject.h"
#include "TES3Collections.h"

namespace mwse {
	namespace lua {
		void bindNINode() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::TArray<NI::AVObject>>("NITArrayAVObject",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Meta functions.
				//

				sol::meta_function::index, [](TES3::TArray<NI::AVObject>& self, int index) { return makeLuaObject(self.storage[index - 1]); },
				sol::meta_function::length, [](TES3::TArray<NI::AVObject>& self) { return self.filledCount; }

				);

			state.new_usertype<NI::Node>("NINode",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"runTimeTypeInformation", sol::readonly_property([](NI::Node& self) { return self.getRunTimeTypeInformation(); }),
				"references", sol::readonly_property(&NI::Node::references),

				"name", sol::readonly_property(&NI::Node::name),

				"flags", &NI::Node::flags,
				"parentNode", &NI::Node::parentNode,
				"worldBoundOrigin", &NI::Node::worldBoundOrgin,
				"worldBoundRadius", &NI::Node::worldBoundRadius,
				"localRotation", &NI::Node::localRotation,
				"localTranslate", &NI::Node::localTranslate,
				"localScale", &NI::Node::localScale,
				"worldTransform", &NI::Node::worldTransform,

				"children", sol::readonly_property(&NI::Node::children),

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
