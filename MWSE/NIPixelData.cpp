#include "NIPixelData.h"

#include "NIPixelFormat.h"
#include "TES3Util.h"

namespace NI {

	const auto NIPixelData_ctor_args = reinterpret_cast<void(__thiscall*)(PixelData*, unsigned int, unsigned int, const PixelFormat*, unsigned int)>(0x6D4FC0);
	const auto NIPixelFormat_RGBA32 = reinterpret_cast<const PixelFormat*>(0x7DE8B8);

	// Create an RGBA-8bpc PixelData with a single mip level.
	PixelData* PixelData::create(unsigned int width, unsigned int height) {
		PixelData* pixelData = mwse::tes3::_new<PixelData>();
		NIPixelData_ctor_args(pixelData, width, height, NIPixelFormat_RGBA32, 1);
		return pixelData;
	}

}