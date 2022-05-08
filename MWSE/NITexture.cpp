#include "NITexture.h"

namespace NI {
	Texture::FormatPrefs::FormatPrefs() {
		pixelLayout = PixelLayout::PIX_DEFAULT;
		mipMapped = MipFlag::MIP_DEFAULT;
		alphaFormat = AlphaFormat::ALPHA_DEFAULT;
	}

	unsigned int Texture::getWidth() {
		return vTable.asTexture->getWidth(this);
	}

	unsigned int Texture::getHeight() {
		return vTable.asTexture->getHeight(this);
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::Texture)
