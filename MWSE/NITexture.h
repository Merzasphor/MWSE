#pragma once

#include "NIObjectNET.h"
#include "NIPixelFormat.h"
#include "NIPixelData.h"

namespace NI {
	struct Texture_vTable : Object_vTable {
		unsigned int(__thiscall * getWidth)(Texture*); // 0x2C
		unsigned int(__thiscall * getHeight)(Texture*); // 0x30
	};

	struct Texture : ObjectNET {
		struct FormatPrefs {
			int pixelLayout; // 0x0
			int mipMapped; // 0x4
			int alphaFormat; // 0x8
		};
		FormatPrefs formatPrefs; // 0x14;
		void * renderData; // 0x20
		Texture * previousTexture; // 0x24
		Texture * nextTexture; // 0x28

		//
		// vTable wrappers.
		//

		__declspec(dllexport) unsigned int getWidth();
		__declspec(dllexport) unsigned int getHeight();

	};
	static_assert(sizeof(Texture) == 0x2C, "NI::Texture failed size validation");
}
