#include "TES3LightLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Inventory.h"
#include "TES3ItemData.h"
#include "TES3Light.h"
#include "TES3Reference.h"
#include "TES3Script.h"
#include "TES3Sound.h"

namespace mwse {
	namespace lua {
		sol::optional<float> getTimeLeftEquipStack(const TES3::Light& light, TES3::EquipmentStack& equipStack) {
			if (equipStack.object == &light) {
				return (equipStack.variables) ? equipStack.variables->timeLeft : float(light.time);
			}
			return sol::optional<float>();
		}

		sol::optional<float> getTimeLeftReference(const TES3::Light& light, TES3::Reference& refr) {
			if (refr.baseObject == &light) {
				auto variables = refr.getAttachedItemData();
				return (variables) ? variables->timeLeft : float(light.time);
			}
			return sol::optional<float>();
		}

		float getTimeLeftItemData(const TES3::Light& light, TES3::ItemData& itemData) {
			return itemData.timeLeft;
		}

		void bindTES3Light() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Light>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("value", &TES3::Light::value);
			usertypeDefinition.set("weight", &TES3::Light::weight);
			usertypeDefinition.set("time", &TES3::Light::time);
			usertypeDefinition.set("radius", &TES3::Light::radius);
			usertypeDefinition.set("flags", &TES3::Light::flags);

			// User-friendly access to flags.
			usertypeDefinition.set("canCarry", sol::property(&TES3::Light::getCanCarry, &TES3::Light::setCanCarry));
			usertypeDefinition.set("flickers", sol::property(&TES3::Light::getFlickers, &TES3::Light::setFlickers));
			usertypeDefinition.set("flickersSlowly", sol::property(&TES3::Light::getFlickersSlowly, &TES3::Light::setFlickersSlowly));
			usertypeDefinition.set("isDynamic", sol::property(&TES3::Light::getIsDynamic, &TES3::Light::setIsDynamic));
			usertypeDefinition.set("isFire", sol::property(&TES3::Light::getIsFire, &TES3::Light::setIsFire));
			usertypeDefinition.set("isNegative", sol::property(&TES3::Light::getIsNegative, &TES3::Light::setIsNegative));
			usertypeDefinition.set("isOffByDefault", sol::property(&TES3::Light::getIsOffByDefault, &TES3::Light::setIsOffByDefault));
			usertypeDefinition.set("pulses", sol::property(&TES3::Light::getPulses, &TES3::Light::setPulses));
			usertypeDefinition.set("pulsesSlowly", sol::property(&TES3::Light::getPulsesSlowly, &TES3::Light::setPulsesSlowly));

			// Indirect bindings to unions and arrays.
			usertypeDefinition.set("color", sol::readonly_property([](TES3::Light& self) { return std::ref(self.color); }));

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("sound", sol::readonly_property([](TES3::Light& self) { return makeLuaObject(self.sound); }));
			usertypeDefinition.set("script", sol::readonly_property([](TES3::Light& self) { return makeLuaObject(self.script); }));

			// Functions exposed as properties.
			usertypeDefinition.set("icon", sol::property(
				&TES3::Light::getIconPath,
				[](TES3::Light& self, const char* value) { if (strlen(value) < 32) tes3::setDataString(&self.icon, value); }
			));
			usertypeDefinition.set("mesh", sol::property(&TES3::Light::getModelPath, &TES3::Light::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Light::getName, &TES3::Light::setName));

			// Methods.
			usertypeDefinition.set("getTimeLeft", sol::overload(&getTimeLeftEquipStack, &getTimeLeftReference, &getTimeLeftItemData));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("model", sol::property(&TES3::Light::getModelPath, &TES3::Light::setModelPath));

			// Finish up our usertype.
			state.set_usertype("tes3light", usertypeDefinition);
		}
	}
}
