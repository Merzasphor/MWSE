#include "NISourceTexture.h"

namespace NI {
	unsigned int SourceTexture::getWidth() {
		return vTable.asSourceTexture->getWidth(this);
	}

	unsigned int SourceTexture::getHeight() {
		return vTable.asSourceTexture->getHeight(this);
	}
}
