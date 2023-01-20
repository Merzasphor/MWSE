#include "TES3Land.h"

namespace TES3 {
	std::reference_wrapper<decltype(Land::textureIndices)> Land::getTextureIndices() {
		return std::ref(textureIndices);
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::Land)
