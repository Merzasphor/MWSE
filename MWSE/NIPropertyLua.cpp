#include "NIPropertyLua.h"
#include "NIObjectLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIRTTI.h"
#include "NIProperty.h"
#include "NITexture.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForNIProperty(T& usertypeDefinition) {
			setUserdataForNIObjectNET(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["type"] = &NI::Property::getType;
		}

		void bindNIProperties() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for NI::Property.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<NI::Property>("niProperty");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::ObjectNET, NI::Object>();
				setUserdataForNIProperty(usertypeDefinition);
			}

			// Binding for NI::AlphaProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<NI::AlphaProperty>("niAlphaProperty");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::Property, NI::ObjectNET, NI::Object>();
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["alphaTestRef"] = &NI::AlphaProperty::alphaTestRef;
			}

			// Binding for NI::FogProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<NI::FogProperty>("niFogProperty");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::Property, NI::ObjectNET, NI::Object>();
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["color"] = sol::readonly_property([](NI::FogProperty& self) { return std::ref(self.color); });
				usertypeDefinition["density"] = &NI::FogProperty::density;
			}

			// Binding for NI::MaterialProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<NI::MaterialProperty>("niMaterialProperty");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::Property, NI::ObjectNET, NI::Object>();
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["alpha"] = sol::property(
					[](NI::MaterialProperty& self) { return self.alpha; },
					[](NI::MaterialProperty& self, float alpha) { self.alpha = alpha; ++self.revisionID; }
				);
				usertypeDefinition["ambient"] = sol::property(
					[](NI::MaterialProperty& self) { return self.ambient; },
					[](NI::MaterialProperty& self, const NI::Color& ambient) { self.ambient = ambient; ++self.revisionID; }
				);
				usertypeDefinition["diffuse"] = sol::property(
					[](NI::MaterialProperty& self) { return self.diffuse; },
					[](NI::MaterialProperty& self, const NI::Color& diffuse) { self.diffuse = diffuse; ++self.revisionID; }
				);
				usertypeDefinition["emissive"] = sol::property(
					[](NI::MaterialProperty& self) { return self.emissive; },
					[](NI::MaterialProperty& self, const NI::Color& emissive) { self.emissive = emissive; ++self.revisionID; }
				);
				usertypeDefinition["shininess"] = sol::property(
					[](NI::MaterialProperty& self) { return self.shininess; },
					[](NI::MaterialProperty& self, float shininess) { self.shininess = shininess; ++self.revisionID; }
				);
				usertypeDefinition["specular"] = sol::property(
					[](NI::MaterialProperty& self) { return self.specular; },
					[](NI::MaterialProperty& self, const NI::Color& specular) { self.specular = specular; ++self.revisionID; }
				);
			}

			// Binding for NI::StencilProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<NI::StencilProperty>("niStencilProperty");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::Property, NI::ObjectNET, NI::Object>();
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["drawMode"] = &NI::StencilProperty::drawMode;
				usertypeDefinition["enabled"] = &NI::StencilProperty::enabled;
				usertypeDefinition["failAction"] = &NI::StencilProperty::failAction;
				usertypeDefinition["mask"] = &NI::StencilProperty::mask;
				usertypeDefinition["passAction"] = &NI::StencilProperty::passAction;
				usertypeDefinition["testFunc"] = &NI::StencilProperty::testFunc;
				usertypeDefinition["reference"] = &NI::StencilProperty::reference;
				usertypeDefinition["zFailAction"] = &NI::StencilProperty::zFailAction;
			}

			// Binding for NI::TexturingProperty::Map.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<NI::TexturingProperty::Map>("niTexturingPropertyMap");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["clampMode"] = &NI::TexturingProperty::Map::clampMode;
				usertypeDefinition["filterMode"] = &NI::TexturingProperty::Map::filterMode;
				usertypeDefinition["texCoordSet"] = &NI::TexturingProperty::Map::texCoordSet;

				// Properties that need extra work before returning.
				usertypeDefinition["texture"] = sol::property(
					[](NI::TexturingProperty::Map& self) { return self.texture; },
					[](NI::TexturingProperty::Map& self, NI::Texture * texture) { self.texture = texture; }
				);
			}

			// Binding for NI::TexturingProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<NI::TexturingProperty>("niTexturingProperty");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::Property, NI::ObjectNET, NI::Object>();
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["applyMode"] = &NI::TexturingProperty::applyMode;
				usertypeDefinition["maps"] = sol::readonly_property(&NI::TexturingProperty::maps);
			}

			// Binding for NI::VertexColorProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<NI::VertexColorProperty>("niVertexColorProperty");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<NI::Property, NI::ObjectNET, NI::Object>();
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["lighting"] = &NI::VertexColorProperty::lighting;
				usertypeDefinition["source"] = &NI::VertexColorProperty::source;
			}

		}
	}
}
