#include "TES3ObjectLua.h"

#include "LuaManager.h"

#include "TES3Object.h"
#include "TES3Race.h"
#include "TES3Class.h"

namespace mwse {
	namespace lua {
		void bindTES3Object() {;
			LuaManager::getInstance().getState().new_usertype<TES3::BaseObject>("TES3BaseObject",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Easy vtable victories.
				//

				"getObjectID", [](TES3::BaseObject* self) { return self->vTable->getObjectID(self); },
				"getName", [](TES3::BaseObject* self) { return self->vTable->getName(self); },

				"getIcon", [](TES3::BaseObject* self) { return self->vTable->getIconPath(self); },
				"getModel", [](TES3::BaseObject* self) { return self->vTable->getModelPath(self); },

				"getRace", [](TES3::BaseObject* self) { return self->vTable->getRace(self); },
				"getRaceID", [](TES3::BaseObject* self) { return self->vTable->getRaceID(self); },

				"getClass", [](TES3::BaseObject* self) { return self->vTable->getClass(self); },
				"getClassID", [](TES3::BaseObject* self) { return self->vTable->getClassID(self); }
			);
		}
	}
}
