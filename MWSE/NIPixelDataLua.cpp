#include "NIPixelDataLua.h"

#include "NIObjectLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIPixelData.h"
#include "NIRTTI.h"

namespace mwse {
	namespace lua {
		void bindNIPixelData() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for NI::SourceTexture.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::PixelData>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object>());
				setUserdataForNIObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("bytesPerPixel", sol::readonly_property(&NI::PixelData::bytesPerPixel));
				usertypeDefinition.set("mipMapLevels", sol::readonly_property(&NI::PixelData::mipMapLevels));

				// Basic function binding.
				usertypeDefinition.set("getWidth", [](NI::PixelData& self, sol::optional<int> mipMapLevel) -> sol::optional<int> {
					if (!mipMapLevel) {
						return self.widths[0];
					}

					if (mipMapLevel < 1 || mipMapLevel.value() - 1 > self.mipMapLevels) {
						return sol::optional<int>();
					}

					return self.widths[mipMapLevel.value() - 1];
				});
				usertypeDefinition.set("getHeight", [](NI::PixelData& self, sol::optional<int> mipMapLevel) -> sol::optional<int> {
					if (!mipMapLevel) {
						return self.heights[0];
					}

					if (mipMapLevel < 1 || mipMapLevel.value() - 1 > self.mipMapLevels) {
						return sol::optional<int>();
					}

					return self.heights[mipMapLevel.value() - 1];
				});

				// Finish up our usertype.
				state.set_usertype("niSourceTexture", usertypeDefinition);
			}
		}
	}
}
