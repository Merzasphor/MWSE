#pragma once

#include "NIObjectNET.h"
#include "NIPixelFormat.h"
#include "NIPixelData.h"

namespace NI {
	struct SourceTexture_vTable : Object_vTable {
		unsigned int(__thiscall * getWidth)(SourceTexture*); // 0x2C
		unsigned int(__thiscall * getHeight)(SourceTexture*); // 0x30
		void * unknown_0x34;
		void * clearPixelData; // 0x38
	};

	struct SourceTexture : ObjectNET {
		struct FormatPrefs {
			int pixelLayout; // 0x0
			int mipMapped; // 0x4
			int alphaFormat; // 0x8
		};
		FormatPrefs formatPrefs; // 0x14;
		int unknown_0x20;
		int unknown_0x24;
		int unknown_0x28;
		const char * fileName; // 0x2C
		const char * platformFileName; // 0x30
		Pointer<PixelData> pixelData; // 0x34
		bool isStatic; // 0x38

		//
		// vTable wrappers.
		//

		__declspec(dllexport) unsigned int getWidth();
		__declspec(dllexport) unsigned int getHeight();

	};
	static_assert(sizeof(SourceTexture) == 0x3C, "NI::SourceTexture failed size validation");
}
