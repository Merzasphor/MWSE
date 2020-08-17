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
		void setUserdataForNIProperty(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForNIObjectNET(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("type", &NI::Property::getType);
		}

		void bindNIProperties() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for NI::Property.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::Property>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::ObjectNET, NI::Object>());
				setUserdataForNIProperty(usertypeDefinition);

				// Finish up our usertype.
				state.set_usertype("niProperty", usertypeDefinition);
			}

			// Binding for NI::AlphaProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::AlphaProperty>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Property, NI::ObjectNET, NI::Object>());
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("alphaTestRef", &NI::AlphaProperty::alphaTestRef);

				// Finish up our usertype.
				state.set_usertype("niAlphaProperty", usertypeDefinition);
			}

			// Binding for NI::FogProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::FogProperty>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Property, NI::ObjectNET, NI::Object>());
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("color", sol::readonly_property([](NI::FogProperty& self) { return std::ref(self.color); }));
				usertypeDefinition.set("density", &NI::FogProperty::density);

				// Finish up our usertype.
				state.set_usertype("niFogProperty", usertypeDefinition);
			}

			// Binding for NI::MaterialProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::MaterialProperty>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Property, NI::ObjectNET, NI::Object>());
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("alpha", sol::property(
					[](NI::MaterialProperty& self) { return self.alpha; },
					[](NI::MaterialProperty& self, float alpha) { self.alpha = alpha; ++self.revisionID; }
				));
				usertypeDefinition.set("ambient", sol::property(
					[](NI::MaterialProperty& self) { return self.ambient; },
					[](NI::MaterialProperty& self, const NI::Color& ambient) { self.ambient = ambient; ++self.revisionID; }
				));
				usertypeDefinition.set("diffuse", sol::property(
					[](NI::MaterialProperty& self) { return self.diffuse; },
					[](NI::MaterialProperty& self, const NI::Color& diffuse) { self.diffuse = diffuse; ++self.revisionID; }
				));
				usertypeDefinition.set("emissive", sol::property(
					[](NI::MaterialProperty& self) { return self.emissive; },
					[](NI::MaterialProperty& self, const NI::Color& emissive) { self.emissive = emissive; ++self.revisionID; }
				));
				usertypeDefinition.set("shininess", sol::property(
					[](NI::MaterialProperty& self) { return self.shininess; },
					[](NI::MaterialProperty& self, float shininess) { self.shininess = shininess; ++self.revisionID; }
				));
				usertypeDefinition.set("specular", sol::property(
					[](NI::MaterialProperty& self) { return self.specular; },
					[](NI::MaterialProperty& self, const NI::Color& specular) { self.specular = specular; ++self.revisionID; }
				));

				// Finish up our usertype.
				state.set_usertype("niMaterialProperty", usertypeDefinition);
			}

			// Binding for NI::StencilProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::StencilProperty>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Property, NI::ObjectNET, NI::Object>());
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("drawMode", &NI::StencilProperty::drawMode);
				usertypeDefinition.set("enabled", &NI::StencilProperty::enabled);
				usertypeDefinition.set("failAction", &NI::StencilProperty::failAction);
				usertypeDefinition.set("mask", &NI::StencilProperty::mask);
				usertypeDefinition.set("passAction", &NI::StencilProperty::passAction);
				usertypeDefinition.set("testFunc", &NI::StencilProperty::testFunc);
				usertypeDefinition.set("reference", &NI::StencilProperty::reference);
				usertypeDefinition.set("zFailAction", &NI::StencilProperty::zFailAction);

				// Finish up our usertype.
				state.set_usertype("niStencilProperty", usertypeDefinition);
			}

			// Binding for NI::TexturingProperty::Map.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::TexturingProperty::Map>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("clampMode", &NI::TexturingProperty::Map::clampMode);
				usertypeDefinition.set("filterMode", &NI::TexturingProperty::Map::filterMode);
				usertypeDefinition.set("texCoordSet", &NI::TexturingProperty::Map::texCoordSet);

				// Properties that need extra work before returning.
				usertypeDefinition.set("texture", sol::property(
					[](NI::TexturingProperty::Map& self) { return makeLuaNiPointer(self.texture); },
					[](NI::TexturingProperty::Map& self, NI::Texture * texture) { self.texture = texture; }
				));

				// Finish up our usertype.
				state.set_usertype("niTexturingPropertyMap", usertypeDefinition);
			}

			// Binding for NI::TexturingProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::TexturingProperty>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Property, NI::ObjectNET, NI::Object>());
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("applyMode", &NI::TexturingProperty::applyMode);
				usertypeDefinition.set("decalCount", sol::readonly_property(&NI::TexturingProperty::getDecalCount));
				usertypeDefinition.set("canAddDecal", sol::readonly_property(&NI::TexturingProperty::canAddDecalMap));
				usertypeDefinition.set("maps", sol::readonly_property(&NI::TexturingProperty::maps));

				// Basic function binding.
				usertypeDefinition.set("addDecalMap", &NI::TexturingProperty::addDecalMap_lua);
				usertypeDefinition.set("removeDecalMap", &NI::TexturingProperty::removeDecal_lua);

				// Finish up our usertype.
				state.set_usertype("niTexturingProperty", usertypeDefinition);
			}

			// Binding for NI::VertexColorProperty.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::VertexColorProperty>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Property, NI::ObjectNET, NI::Object>());
				setUserdataForNIProperty(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("lighting", &NI::VertexColorProperty::lighting);
				usertypeDefinition.set("source", &NI::VertexColorProperty::source);

				// Finish up our usertype.
				state.set_usertype("niVertexColorProperty", usertypeDefinition);
			}

		}
	}
}
