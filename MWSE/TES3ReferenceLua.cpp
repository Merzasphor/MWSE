#include "TES3ReferenceLua.h"

#include "TES3Reference.h"

#include "LuaManager.h"
#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		void bindTES3Reference() {
			LuaManager::getInstance().getState().new_usertype<TES3::Reference>("TES3Reference",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				//
				//

				"getObject", [](TES3::Reference* reference) { return makeLuaObject(reference->baseObject); }
				);
		}
	}
}
