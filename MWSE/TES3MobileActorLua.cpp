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

			// Binding for TES3::ActiveMagicEffect
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::ActiveMagicEffect>("tes3activeMagicEffect");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["attributeId"] = sol::readonly_property(&TES3::ActiveMagicEffect::skillOrAttributeID);
				usertypeDefinition["duration"] = sol::readonly_property(&TES3::ActiveMagicEffect::duration);
				usertypeDefinition["effectId"] = sol::readonly_property(&TES3::ActiveMagicEffect::magicEffectID);
				usertypeDefinition["effectIndex"] = sol::readonly_property(&TES3::ActiveMagicEffect::magicInstanceEffectIndex);
				usertypeDefinition["harmful"] = sol::readonly_property(&TES3::ActiveMagicEffect::isHarmful);
				usertypeDefinition["isSummon"] = sol::readonly_property(&TES3::ActiveMagicEffect::isSummon);
				usertypeDefinition["magnitudeMin"] = sol::readonly_property(&TES3::ActiveMagicEffect::magnitudeMin);
				usertypeDefinition["serial"] = sol::readonly_property(&TES3::ActiveMagicEffect::magicInstanceSerial);
				usertypeDefinition["skillId"] = sol::readonly_property(&TES3::ActiveMagicEffect::skillOrAttributeID);

				// Expose functions as properties.
				usertypeDefinition["instance"] = sol::readonly_property(&TES3::ActiveMagicEffect::getInstance);
				usertypeDefinition["magnitude"] = sol::readonly_property(&TES3::ActiveMagicEffect::getMagnitude);

				// Legacy support.
				usertypeDefinition["flag9"] = sol::readonly_property(&TES3::ActiveMagicEffect::isSummon);

			}
		}
	}
}
