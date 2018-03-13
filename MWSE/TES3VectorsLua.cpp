#include "TES3Vectors.h"

#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Vectors() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Vector2>("TES3Vector2",
				"x", &TES3::Vector2::x,
				"y", &TES3::Vector2::y
			);

			state.new_usertype<TES3::Vector3>("TES3Vector3",
				"z", &TES3::Vector3::z
				);

			state.new_usertype<TES3::Vector4>("TES3Vector4",
				"w", &TES3::Vector4::w
				);
		}
	}
}
