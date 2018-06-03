#include "TES3Vectors.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Vectors.h"

#include <iomanip>

namespace mwse {
	namespace lua {
		void bindTES3Vectors() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Vector2>("TES3Vector2",
				"new", sol::constructors<TES3::Vector2(), TES3::Vector2(float, float)>(),
				"x", &TES3::Vector2::x,
				"y", &TES3::Vector2::y
			);

			state.new_usertype<TES3::Vector3>("TES3Vector3",
				"new", sol::constructors<TES3::Vector3(), TES3::Vector3(float, float, float)>(),

				sol::meta_function::addition, &TES3::Vector3::operator+,
				sol::meta_function::subtraction, &TES3::Vector3::operator-,
				sol::meta_function::length, &TES3::Vector3::length,
				sol::meta_function::to_string, [](TES3::Vector3& self)
			{
				std::ostringstream ss;
				ss << std::fixed << std::setprecision(2) << "<" << self.x << ", " << self.y << ", " << self.z << ">";
				return ss.str();
			},

				//
				// Properties.
				//

				"x", &TES3::Vector3::x,
				"y", &TES3::Vector3::y,
				"z", &TES3::Vector3::z,

				// This can also be used for colors, to expose it as rgb.
				"r", &TES3::Vector3::x,
				"g", &TES3::Vector3::y,
				"b", &TES3::Vector3::z,

				//
				// Functions.
				//

				"cross", &TES3::Vector3::crossProduct,
				"dot", &TES3::Vector3::dotProduct,

				"length", &TES3::Vector3::length,
				"distance", &TES3::Vector3::distance,
				"heightDifference", &TES3::Vector3::heightDifference,
				"negate", &TES3::Vector3::negate

				);

			state.new_usertype<TES3::Vector4>("TES3Vector4",
				"new", sol::constructors<TES3::Vector4(), TES3::Vector4(float, float, float, float)>(),
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
