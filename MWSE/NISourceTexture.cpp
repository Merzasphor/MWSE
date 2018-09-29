#include "NISourceTexture.h"

namespace NI {
	unsigned int SourceTexture::getWidth() {
		return vTable.asSourceTexture->getWidth(this);
	}

	unsigned int SourceTexture::getHeight() {
		return vTable.asSourceTexture->getHeight(this);
	}

	const auto NI_SourceTexture_createFromPath = reinterpret_cast<SourceTexture*(__cdecl*)(const char*, SourceTexture::FormatPrefs *)>(0x6DE7F0);
	Pointer<SourceTexture> SourceTexture::createFromPath(const char* path, SourceTexture::FormatPrefs * formatPrefs) {
		return NI_SourceTexture_createFromPath(path, formatPrefs);
	}

	const auto NI_SourceTexture_createFromPixelData = reinterpret_cast<SourceTexture*(__cdecl*)(PixelData*, SourceTexture::FormatPrefs *)>(0x6DE940);
	Pointer<SourceTexture> SourceTexture::createFromPixelData(PixelData* pixelData, SourceTexture::FormatPrefs * formatPrefs) {
		return NI_SourceTexture_createFromPixelData(pixelData, formatPrefs);
	}
}
