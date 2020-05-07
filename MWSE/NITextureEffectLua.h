#pragma once

#include "sol.hpp"

#include "LuaUtil.h"

#include "NITextureEffect.h"

#include "NIObjectLua.h"
#include "NIDynamicEffectLua.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::TextureEffect.
		template <typename T>
		void setUserdataForNITextureEffect(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForNIDynamicEffect(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("sourceTexture", &NI::TextureEffect::sourceTexture);

			// Functions exposed as properties.
			
		}

		void bindNITextureEffect();
	}
}
