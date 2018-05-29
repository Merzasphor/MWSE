#include "TES3StaticLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Static() {
			LuaManager::getInstance().getState().new_usertype<TES3::Static>("TES3Static",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::meta_function::to_string, &TES3::Static::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Static::objectType,

				"boundingBox", &TES3::Static::boundingBox,

				"id", sol::readonly_property(&TES3::Static::getObjectID),

				"model", sol::readonly_property(&TES3::Static::getModelPath)

				);
		}
	}
}
