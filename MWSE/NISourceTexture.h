#pragma once

#include "NITexture.h"

namespace NI {
	struct SourceTexture_vTable : Texture_vTable {
		void * unknown_0x34;
		void * clearPixelData; // 0x38
	};

	struct SourceTexture : Texture {
		const char * fileName; // 0x2C
		const char * platformFileName; // 0x30
		Pointer<PixelData> pixelData; // 0x34
		bool isStatic; // 0x38

		//
		// Static functions.
		//

		__declspec(dllexport) static Pointer<SourceTexture> createFromPath(const char* path, SourceTexture::FormatPrefs * formatPrefs);
		__declspec(dllexport) static Pointer<SourceTexture> createFromPixelData(PixelData* pixelData, SourceTexture::FormatPrefs * formatPrefs);

	};
	static_assert(sizeof(SourceTexture) == 0x3C, "NI::SourceTexture failed size validation");
}
