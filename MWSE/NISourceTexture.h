#pragma once

#include "NITexture.h"

namespace NI {
	struct SourceTexture_vTable : Texture_vTable {
		void * loadPixelDataFromFile; // 0x34
		void(__thiscall* clearPixelData)(SourceTexture*); // 0x38
	};
	static_assert(sizeof(SourceTexture_vTable) == 0x3C, "NI::SourceTexture's vtable failed size validation");

	struct SourceTexture : Texture {
		const char * fileName; // 0x2C
		const char * platformFileName; // 0x30
		Pointer<PixelData> pixelData; // 0x34
		bool isStatic; // 0x38

		//
		// Static functions.
		//

		static Pointer<SourceTexture> createFromPath(const char* path, SourceTexture::FormatPrefs * formatPrefs);
		static Pointer<SourceTexture> createFromPixelData(PixelData* pixelData, SourceTexture::FormatPrefs * formatPrefs);

		//
		// Virtual table functions.
		//

		void clearPixelData();

	};
	static_assert(sizeof(SourceTexture) == 0x3C, "NI::SourceTexture failed size validation");
}
