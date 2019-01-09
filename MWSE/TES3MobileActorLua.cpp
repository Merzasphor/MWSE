#include "TES3MobileActorLua.h"

#include "LuaManager.h"

#include "TES3MobileActor.h"
#include "TES3SpellInstanceController.h"
#include "TES3WorldController.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileActor() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

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
				usertypeDefinition.set("flag9", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::unknown_0x9));
				usertypeDefinition.set("harmful", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::isHarmful));
				usertypeDefinition.set("magnitudeMin", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::magnitudeMin));
				usertypeDefinition.set("next", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::next));
				usertypeDefinition.set("previous", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::prev));
				usertypeDefinition.set("serial", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::magicInstanceSerial));
				usertypeDefinition.set("skillId", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::skillOrAttributeID));

				// Expose easy access to the instance's magnitude.
				usertypeDefinition.set("magnitude", sol::readonly_property([](TES3::MobileActor::ActiveMagicEffect& self) {
					return TES3::WorldController::get()->spellInstanceController->getInstanceFromSerial(self.magicInstanceSerial)->getMagnitude(self.magicInstanceEffectIndex);
				}));

				// Expose quick access to the source instance.
				usertypeDefinition.set("instance", sol::readonly_property([](TES3::MobileActor::ActiveMagicEffect& self) {
					return TES3::WorldController::get()->spellInstanceController->getInstanceFromSerial(self.magicInstanceSerial);
				}));

				// Finish up our usertype.
				state.set_usertype("tes3activeMagicEffect", usertypeDefinition);
			}
		}
	}
}
