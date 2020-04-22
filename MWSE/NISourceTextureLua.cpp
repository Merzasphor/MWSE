#include "NISourceTextureLua.h"

#include "NIObjectLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NISourceTexture.h"
#include "NIRTTI.h"

namespace mwse {
	namespace lua {
		void bindNISourceTexture() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for NI::SourceTexture::FormatPrefs.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::SourceTexture::FormatPrefs>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("alphaLayout", &NI::SourceTexture::FormatPrefs::alphaFormat);
				usertypeDefinition.set("mipLayout", &NI::SourceTexture::FormatPrefs::mipMapped);
				usertypeDefinition.set("pixelLayout", &NI::SourceTexture::FormatPrefs::pixelLayout);

				// Finish up our usertype.
				state.set_usertype("niFormatPrefs", usertypeDefinition);
			}

			// Binding for NI::SourceTexture.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::SourceTexture>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Texture, NI::ObjectNET, NI::Object>());
				setUserdataForNIObjectNET(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("formatPrefs", &NI::SourceTexture::formatPrefs);
				usertypeDefinition.set("isStatic", &NI::SourceTexture::isStatic);
				usertypeDefinition.set("pixelData", &NI::SourceTexture::pixelData);

				// Functions bound as properties.
				usertypeDefinition.set("fileName", sol::readonly_property(&NI::SourceTexture::fileName));
				usertypeDefinition.set("height", sol::readonly_property(&NI::SourceTexture::getHeight));
				usertypeDefinition.set("platformFileName", sol::readonly_property(&NI::SourceTexture::platformFileName));
				usertypeDefinition.set("width", sol::readonly_property(&NI::SourceTexture::getWidth));

				// Functions that need their results wrapped.
				usertypeDefinition.set("createFromPath", 
					[](const char* path) { 
						using FormatPrefs = NI::Texture::FormatPrefs;
						FormatPrefs prefs = { FormatPrefs::PixelLayout::PIX_DEFAULT, FormatPrefs::MipFlag::MIP_DEFAULT, FormatPrefs::AlphaFormat::ALPHA_DEFAULT };
						return makeLuaNiPointer(NI::SourceTexture::createFromPath(path, &prefs));
					}
				);

				// Finish up our usertype.
				state.set_usertype("niSourceTexture", usertypeDefinition);
			}
		}
	}
}
