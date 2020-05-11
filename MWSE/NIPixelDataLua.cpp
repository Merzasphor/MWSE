#include "NIPixelDataLua.h"

#include "NIObjectLua.h"

#include "sol.hpp"
#include "Log.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIPixelData.h"
#include "NIRTTI.h"
#include "NISourceTexture.h"

namespace mwse {
	namespace lua {
		void bindNIPixelData() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for NI::PixelData.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::PixelData>();
				usertypeDefinition.set("new", [](unsigned int width, unsigned int height, sol::optional<unsigned int> mipMapLevels) {
					return NI::PixelData::create(width, height, mipMapLevels.value_or(1));
				});

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object>());
				setUserdataForNIObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("bytesPerPixel", sol::readonly_property(&NI::PixelData::bytesPerPixel));
				usertypeDefinition.set("mipMapLevels", sol::readonly_property(&NI::PixelData::mipMapLevels));

				// Basic function binding.
				usertypeDefinition.set("createSourceTexture", [](NI::PixelData& self) {
					using FormatPrefs = NI::Texture::FormatPrefs;
					FormatPrefs prefs = { FormatPrefs::PixelLayout::PIX_DEFAULT, FormatPrefs::MipFlag::MIP_DEFAULT, FormatPrefs::AlphaFormat::ALPHA_DEFAULT };
					return NI::SourceTexture::createFromPixelData(&self, &prefs);
				});
				usertypeDefinition.set("getWidth", [](NI::PixelData& self, sol::optional<unsigned int> mipMapLevel) -> sol::optional<unsigned int> {
					unsigned int level = mipMapLevel.value_or(1) - 1;

					if (level < 0 || level >= self.mipMapLevels) {
						return sol::optional<unsigned int>();
					}

					return self.widths[level];
				});
				usertypeDefinition.set("getHeight", [](NI::PixelData& self, sol::optional<unsigned int> mipMapLevel) -> sol::optional<unsigned int> {
					unsigned int level = mipMapLevel.value_or(1) - 1;

					if (level < 0 || level >= self.mipMapLevels) {
						return sol::optional<unsigned int>();
					}

					return self.heights[level];
				});
				usertypeDefinition.set("setPixelsByte", [](NI::PixelData& self, sol::table data, sol::optional<unsigned int> mipMapLevel) {
					unsigned int level = mipMapLevel.value_or(1) - 1;
					if (level < 0 || level >= self.mipMapLevels) {
						log::getLog() << "setPixels: Invalid mip level." << std::endl;
						return;
					}

					// Check that the array is the correct size.
					size_t srcSize = data.size();
					size_t destSize = self.bytesPerPixel * self.widths[level] * self.heights[level];
					if (srcSize != destSize) {
						log::getLog() << "setPixels: data array argument (" << srcSize << ") is not the same size as the PixelData target (" << destSize << ")." << std::endl;
						return;
					}

					// Convert number array to byte data.
					unsigned char *dest = self.pixels + self.offsets[level];
					for (size_t i = 1; i <= srcSize; ++i) {
						*dest++ = unsigned char(data[i]);
					}

					// Indicate the pixel data has changed.
					self.revisionID++;
				});
				usertypeDefinition.set("setPixelsFloat", [](NI::PixelData& self, sol::table data, sol::optional<unsigned int> mipMapLevel) {
					unsigned int level = mipMapLevel.value_or(1) - 1;
					if (level < 0 || level >= self.mipMapLevels) {
						log::getLog() << "setPixels: Invalid mip level." << std::endl;
						return;
					}

					// Check that the array is the correct size.
					size_t srcSize = data.size();
					size_t destSize = self.bytesPerPixel * self.widths[level] * self.heights[level];
					if (srcSize != destSize) {
						log::getLog() << "setPixels: data array argument (" << srcSize << ") is not the same size as the PixelData target (" << destSize << ")." << std::endl;
						return;
					}

					// Convert number array to byte data.
					unsigned char *dest = self.pixels + self.offsets[level];
					for (size_t i = 1; i <= srcSize; ++i) {
						*dest++ = unsigned char(255.0 * double(data[i]) + 0.5);
					}

					// Indicate the pixel data has changed.
					self.revisionID++;
				});
				usertypeDefinition.set("fill", [](NI::PixelData& self, sol::table data, sol::optional<unsigned int> mipMapLevel) {
					unsigned int level = mipMapLevel.value_or(1) - 1;
					if (level < 0 || level >= self.mipMapLevels) {
						throw std::invalid_argument("Invalid mip level.");
					}
					
					if (self.bytesPerPixel == 3) {
						NI::PixelRGB pixel{
							unsigned char(255.0 * double(data.get_or(1, 0.0)) + 0.5),
							unsigned char(255.0 * double(data.get_or(2, 0.0)) + 0.5),
							unsigned char(255.0 * double(data.get_or(3, 0.0)) + 0.5),
						};

						size_t pixelCount = self.widths[level] * self.heights[level];
						NI::PixelRGB* dest = reinterpret_cast<NI::PixelRGB*>(self.pixels + self.offsets[level]);
						for (size_t i = 1; i <= pixelCount; ++i) {
							*dest++ = pixel;
						}
					}
					else if (self.bytesPerPixel == 4) {
						NI::PixelRGBA pixel{
							unsigned char(255.0 * double(data.get_or(1, 0.0)) + 0.5),
							unsigned char(255.0 * double(data.get_or(2, 0.0)) + 0.5),
							unsigned char(255.0 * double(data.get_or(3, 0.0)) + 0.5),
							unsigned char(255.0 * double(data.get_or(4, 1.0)) + 0.5),
						};

						size_t pixelCount = self.widths[level] * self.heights[level];
						NI::PixelRGBA* dest = reinterpret_cast<NI::PixelRGBA*>(self.pixels + self.offsets[level]);
						for (size_t i = 1; i <= pixelCount; ++i) {
							*dest++ = pixel;
						}
					}
					else {
						throw std::runtime_error("Pixel data does not support 3 or 4-byte pixel values.");
					}
				});

				// Finish up our usertype.
				state.set_usertype("niPixelData", usertypeDefinition);
			}
		}
	}
}
