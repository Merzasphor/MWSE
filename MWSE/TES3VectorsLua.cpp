#include "TES3Vectors.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Vectors.h"

#include "NIColor.h"

#include <iomanip>

namespace mwse {
	namespace lua {
		void bindTES3Vectors() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::Range<int>.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Range<int>>("tes3rangeInt");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property bindings.
				usertypeDefinition["min"] = &TES3::Range<int>::min;
				usertypeDefinition["max"] = &TES3::Range<int>::max;
			}

			// Binding for TES3::Vector2.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Vector2>("tes3vector2");
				usertypeDefinition["new"] = sol::constructors<TES3::Vector2(), TES3::Vector2(float, float)>();

				// Basic property bindings.
				usertypeDefinition["x"] = &TES3::Vector2::x;
				usertypeDefinition["y"] = &TES3::Vector2::y;

				// Basic function binding.
				usertypeDefinition["copy"] = [](TES3::Vector2& self) { return TES3::Vector2(self); };
			}

			// Binding for TES3::Vector3.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Vector3>("tes3vector3");
				usertypeDefinition["new"] = sol::constructors<TES3::Vector3(), TES3::Vector3(float, float, float)>();

				// Operator overloading.
				usertypeDefinition[sol::meta_function::addition] = &TES3::Vector3::operator+;
				usertypeDefinition[sol::meta_function::subtraction] = &TES3::Vector3::operator-;
				usertypeDefinition[sol::meta_function::multiplication] = sol::overload(
					sol::resolve<TES3::Vector3(const TES3::Vector3&)>(&TES3::Vector3::operator*),
					sol::resolve<TES3::Vector3(const float)>(&TES3::Vector3::operator*)
				);
				usertypeDefinition[sol::meta_function::length] = &TES3::Vector3::length;
				usertypeDefinition[sol::meta_function::to_string] = [](TES3::Vector3& self) {
					std::ostringstream ss;
					ss << std::fixed << std::setprecision(2) << "<" << self.x << ", " << self.y << ", " << self.z << ">";
					return ss.str();
				};

				// Allow objects to be serialized to json using their ID.
				usertypeDefinition["__tojson"] = [](TES3::Vector3& self, sol::table jsonState) {
					std::ostringstream ss;
					ss << "[\"x\":" << self.x << ",\"y\":" << self.y << ",\"z\":" << self.z << "]";
					return ss.str();
				};

				// Basic property bindings.
				usertypeDefinition["x"] = &TES3::Vector3::x;
				usertypeDefinition["y"] = &TES3::Vector3::y;
				usertypeDefinition["z"] = &TES3::Vector3::z;

				// These can also be used for RGB.
				usertypeDefinition["r"] = &TES3::Vector3::x;
				usertypeDefinition["g"] = &TES3::Vector3::y;
				usertypeDefinition["b"] = &TES3::Vector3::z;

				// Basic function binding.
				usertypeDefinition["copy"] = [](TES3::Vector3& self) { return TES3::Vector3(self); };
				usertypeDefinition["cross"] = &TES3::Vector3::crossProduct;
				usertypeDefinition["distance"] = &TES3::Vector3::distance;
				usertypeDefinition["dot"] = &TES3::Vector3::dotProduct;
				usertypeDefinition["outerProduct"] = &TES3::Vector3::outerProduct;
				usertypeDefinition["heightDifference"] = &TES3::Vector3::heightDifference;
				usertypeDefinition["length"] = &TES3::Vector3::length;
				usertypeDefinition["negate"] = &TES3::Vector3::negate;
				usertypeDefinition["normalize"] = &TES3::Vector3::normalize;
				usertypeDefinition["normalized"] = &TES3::Vector3::normalized;

				// Conversion to NI::Color.
				usertypeDefinition["toColor"] = [](TES3::Vector3& self) { return NI::Color(self.x, self.y, self.z); };
			}

			// Binding for TES3::Vector4.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Vector4>("tes3vector4");
				usertypeDefinition["new"] = sol::constructors<TES3::Vector4(), TES3::Vector4(float, float, float, float)>();

				// Basic property bindings.
				usertypeDefinition["x"] = &TES3::Vector4::x;
				usertypeDefinition["y"] = &TES3::Vector4::y;
				usertypeDefinition["z"] = &TES3::Vector4::z;
				usertypeDefinition["w"] = &TES3::Vector4::w;

				// Basic function binding.
				usertypeDefinition["copy"] = [](TES3::Vector4& self) { return TES3::Vector4(self); };
			}

			// Binding for TES3::BoundingBox.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::BoundingBox>("tes3boundingBox");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property bindings.
				usertypeDefinition["max"] = &TES3::BoundingBox::maximum;
				usertypeDefinition["min"] = &TES3::BoundingBox::minimum;

				// Basic function binding.
				usertypeDefinition["copy"] = [](TES3::BoundingBox& self) { return TES3::BoundingBox(self); };
			}

			// Binding for TES3::Matrix33.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Matrix33>("tes3matrix33");
				usertypeDefinition["new"] = sol::constructors<
						TES3::Matrix33(), 
						TES3::Matrix33(TES3::Vector3*, TES3::Vector3*, TES3::Vector3*),
						TES3::Matrix33(float, float, float, float, float, float, float, float, float)
				>();

				// Operator overloading.
				usertypeDefinition[sol::meta_function::addition] = &TES3::Matrix33::operator+;
				usertypeDefinition[sol::meta_function::subtraction] = &TES3::Matrix33::operator-;
				usertypeDefinition[sol::meta_function::equal_to] = &TES3::Matrix33::operator==;
				usertypeDefinition[sol::meta_function::multiplication] = sol::overload(
					sol::resolve<TES3::Matrix33(const float)>(&TES3::Matrix33::operator*),
					sol::resolve<TES3::Vector3(const TES3::Vector3&)>(&TES3::Matrix33::operator*),
					sol::resolve<TES3::Matrix33(const TES3::Matrix33&)>(&TES3::Matrix33::operator*)
				);

				// Operator overloading.
				usertypeDefinition[sol::meta_function::to_string] = [](TES3::Matrix33& self) {
					std::ostringstream ss;
					ss << std::fixed << std::setprecision(2) << std::dec
						<< "<<<" << self.m0.x << ", " << self.m0.y << ", " << self.m0.z << ">,\n"
						<< "  <" << self.m1.x << ", " << self.m1.y << ", " << self.m1.z << ">,\n"
						<< "  <" << self.m2.x << ", " << self.m2.y << ", " << self.m2.z << ">>>";
					return ss.str();
				};

				// Basic property bindings.
				usertypeDefinition["x"] = sol::readonly_property([](TES3::Matrix33& self) { return self.m0; });
				usertypeDefinition["y"] = sol::readonly_property([](TES3::Matrix33& self) { return self.m1; });
				usertypeDefinition["z"] = sol::readonly_property([](TES3::Matrix33& self) { return self.m2; });

				// Basic function binding.
				usertypeDefinition["copy"] = [](TES3::Matrix33& self) { return TES3::Matrix33(self); };
				usertypeDefinition["fromEulerXYZ"] = &TES3::Matrix33::fromEulerXYZ;
				usertypeDefinition["reorthogonalize"] = &TES3::Matrix33::reorthogonalize;
				usertypeDefinition["toIdentity"] = &TES3::Matrix33::toIdentity;
				usertypeDefinition["toRotation"] = &TES3::Matrix33::toRotation;
				usertypeDefinition["toRotationX"] = &TES3::Matrix33::toRotationX;
				usertypeDefinition["toRotationY"] = &TES3::Matrix33::toRotationY;
				usertypeDefinition["toRotationZ"] = &TES3::Matrix33::toRotationZ;
				usertypeDefinition["toZero"] = &TES3::Matrix33::toZero;
				usertypeDefinition["transpose"] = &TES3::Matrix33::transpose;

				// Handle functions with out values.
				usertypeDefinition["invert"] = [](TES3::Matrix33& self) {
					TES3::Matrix33 matrix;
					bool valid = self.invert(&matrix);
					return std::make_tuple(matrix, valid);
				};
				usertypeDefinition["toEulerXYZ"] = [](TES3::Matrix33& self) {
					float x, y, z;
					bool isUnique = self.toEulerXYZ(&x, &y, &z);
					return std::make_tuple(TES3::Vector3(x, y, z), isUnique);
				};
				usertypeDefinition["toEulerZYX"] = [](TES3::Matrix33& self) {
					float x, y, z;
					bool isUnique = self.toEulerZYX(&x, &y, &z);
					return std::make_tuple(TES3::Vector3(x, y, z), isUnique);
				};
			}

			// Binding for TES3::Transform.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Transform>("tes3transform");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property bindings.
				usertypeDefinition["rotation"] = sol::readonly_property([](TES3::Transform& self) { return self.rotation; });
				usertypeDefinition["translation"] = sol::readonly_property([](TES3::Transform& self) { return self.translation; });
				usertypeDefinition["scale"] = sol::readonly_property([](TES3::Transform& self) { return self.scale; });

				// Basic function binding.
				usertypeDefinition["copy"] = [](TES3::Transform& self) { return TES3::Transform(self); };
			}
		}
	}
}
