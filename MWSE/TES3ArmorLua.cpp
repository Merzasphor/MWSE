#include "TES3ArmorLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Armor.h"
#include "TES3BodyPart.h"
#include "TES3Enchantment.h"
#include "TES3MobileActor.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Armor() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::Armor>("tes3armor");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>();
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["armorRating"] = &TES3::Armor::armorRating;
			usertypeDefinition["enchantCapacity"] = &TES3::Armor::enchantCapacity;
			usertypeDefinition["parts"] = sol::readonly_property([](TES3::Armor& self) { return std::ref(self.parts); });
			usertypeDefinition["slot"] = &TES3::Armor::slot;
			usertypeDefinition["value"] = &TES3::Armor::value;
			usertypeDefinition["weight"] = &TES3::Armor::weight;

			// Functions exposed as properties.
			usertypeDefinition["enchantment"] = sol::property(&TES3::Armor::getEnchantment, &TES3::Armor::setEnchantment);
			usertypeDefinition["maxCondition"] = sol::property(&TES3::Armor::getDurability, &TES3::Armor::setDurability);
			usertypeDefinition["icon"] = sol::property(
				&TES3::Armor::getIconPath,
				[](TES3::Armor& self, const char* value) { if (strlen(value) < 32) tes3::setDataString(&self.icon, value); }
			);
			usertypeDefinition["isLeftPart"] = sol::property(&TES3::Armor::isLeftPartOfPair);
			usertypeDefinition["mesh"] = sol::property(&TES3::Armor::getModelPath, &TES3::Armor::setModelPath);
			usertypeDefinition["name"] = sol::property(&TES3::Armor::getName, &TES3::Armor::setName);
			usertypeDefinition["script"] = sol::property(&TES3::Armor::getScript);
			usertypeDefinition["slotName"] = sol::property(&TES3::Armor::getTypeName);
			usertypeDefinition["weightClass"] = sol::property(&TES3::Armor::getWeightClass);

			// Basic function binding.
			usertypeDefinition["calculateArmorRating"] = [](TES3::Armor& self, sol::object actor) {
				// If we're explicitly given a mobile actor, use that.
				if (actor.is<TES3::MobileActor>()) {
					return self.calculateArmorRating(actor.as<TES3::MobileActor*>());
				}

				// If we're given a reference, try to get its mobile actor.
				else if (actor.is<TES3::Reference>()) {
					TES3::MobileActor * mobileActor = actor.as<TES3::Reference*>()->getAttachedMobileActor();
					if (mobileActor) {
						return self.calculateArmorRating(mobileActor);
					}
					else {
						throw std::exception("Reference does not have an attached mobile actor. Is this an NPC or creature reference?");
					}
				}

				// If we were given something else, tell them they goofed.
				else {
					throw std::exception("Invalid function call. Requires mobile actor or reference as a parameter.");
				}
			};
			
			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition["health"] = sol::property(&TES3::Armor::getDurability, &TES3::Armor::setDurability);
			usertypeDefinition["model"] = sol::property(&TES3::Armor::getModelPath, &TES3::Armor::setModelPath);
		}
	}
}
