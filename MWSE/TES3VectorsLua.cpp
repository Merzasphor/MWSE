#include "TES3Vectors.h"

#include "LuaUnifiedHeader.h"
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
				"x", &TES3::Vector3::x,
				"y", &TES3::Vector3::y,
				"z", &TES3::Vector3::z,

				//
				// This can also be used for colors, to expose it as rgb.
				//

				"r", &TES3::Vector3::x,
				"g", &TES3::Vector3::y,
				"b", &TES3::Vector3::z
				);

			state.new_usertype<TES3::Vector4>("TES3Vector4",
				"x", &TES3::Vector4::x,
				"y", &TES3::Vector4::y,
				"z", &TES3::Vector4::z,
				"w", &TES3::Vector4::w
				);

			state.new_usertype<TES3::BoundingBox>("TES3BoundingBox",
				"min", &TES3::BoundingBox::minimum,
				"max", &TES3::BoundingBox::maximum
				);
		}
	}
}
