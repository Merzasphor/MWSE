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
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::SourceTexture::FormatPrefs.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::SourceTexture::FormatPrefs>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("alphaFormat", &NI::SourceTexture::FormatPrefs::alphaFormat);
				usertypeDefinition.set("mipMapped", &NI::SourceTexture::FormatPrefs::mipMapped);
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
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::ObjectNET, NI::Object>());
				setUserdataForNIObjectNET(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("fileName", &NI::SourceTexture::formatPrefs);
				usertypeDefinition.set("formatPrefs", &NI::SourceTexture::formatPrefs);
				usertypeDefinition.set("pixelData", &NI::SourceTexture::pixelData);
				usertypeDefinition.set("platformFileName", &NI::SourceTexture::formatPrefs);

				// Functions bound as properties.
				usertypeDefinition.set("height", sol::readonly_property(&NI::SourceTexture::getHeight));
				usertypeDefinition.set("width", sol::readonly_property(&NI::SourceTexture::getWidth));

				// Finish up our usertype.
				state.set_usertype("niSourceTexture", usertypeDefinition);
			}
		}
	}
}
