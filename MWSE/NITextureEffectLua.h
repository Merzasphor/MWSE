#pragma once

#include "LuaUtil.h"

#include "NITextureEffect.h"

#include "NIObjectLua.h"
#include "NIDynamicEffectLua.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::TextureEffect.
		template <typename T>
		void setUserdataForNITextureEffect(T& usertypeDefinition) {
			setUserdataForNIDynamicEffect(usertypeDefinition);

			// Property binding.
			usertypeDefinition["sourceTexture"] = &NI::TextureEffect::sourceTexture;
		}

		void bindNITextureEffect();
	}
}
