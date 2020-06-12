#include "TES3MobileActorLua.h"

#include "LuaManager.h"

#include "TES3MobileActor.h"
#include "TES3SpellInstanceController.h"
#include "TES3WorldController.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileActor() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::MobileActor::ActiveMagicEffect
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::MobileActor::ActiveMagicEffect>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("attributeId", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::skillOrAttributeID));
				usertypeDefinition.set("duration", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::duration));
				usertypeDefinition.set("effectId", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::magicEffectID));
				usertypeDefinition.set("effectIndex", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::magicInstanceEffectIndex));
				usertypeDefinition.set("harmful", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::isHarmful));
				usertypeDefinition.set("isSummon", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::isSummon));
				usertypeDefinition.set("magnitudeMin", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::magnitudeMin));
				usertypeDefinition.set("serial", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::magicInstanceSerial));
				usertypeDefinition.set("skillId", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::skillOrAttributeID));

				// Expose functions as properties.
				usertypeDefinition.set("instance", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::getInstance));
				usertypeDefinition.set("magnitude", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::getMagnitude));

				// Legacy support.
				usertypeDefinition.set("flag9", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::isSummon));

				// Finish up our usertype.
				state.set_usertype("tes3activeMagicEffect", usertypeDefinition);
			}
		}
	}
}
