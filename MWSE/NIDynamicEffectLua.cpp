#include "NIDynamicEffectLua.h"

#include "NIObjectLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NINode.h"
#include "NIRTTI.h"


namespace mwse {
	namespace lua {
		void bindNIDynamicEffect() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;


			// Binding for NI::DynamicEffect.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::DynamicEffect>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::AVObject, NI::ObjectNET, NI::Object>());
				setUserdataForNIDynamicEffect(usertypeDefinition);

				// Finish up our usertype.
				state.set_usertype("niDynamicEffect", usertypeDefinition);
			}
		}
	}
}
