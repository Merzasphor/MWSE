#include "TES3MagicEffectLua.h"

#include "LuaManager.h"

#include "TES3MagicEffect.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3MagicEffect() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Effect>("TES3Effect",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"effect", &TES3::Effect::effectID,
				"skill", &TES3::Effect::skillID,
				"attribute", &TES3::Effect::attributeID,
				"rangeType", &TES3::Effect::rangeType,
				"radius", &TES3::Effect::radius,
				"duration", &TES3::Effect::duration,
				"min", &TES3::Effect::magnitudeMin,
				"max", &TES3::Effect::magnitudeMax

				);
		}
	}
}
