#include "TES3ArmorLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Armor.h"
#include "TES3BodyPart.h"
#include "TES3Enchantment.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Armor() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Armor>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("armorRating", &TES3::Armor::armorRating);
			usertypeDefinition.set("enchantCapacity", &TES3::Armor::enchantCapacity);
			usertypeDefinition.set("parts", sol::readonly_property([](TES3::Armor& self) { return std::ref(self.parts); }));
			usertypeDefinition.set("slot", &TES3::Armor::slot);
			usertypeDefinition.set("value", &TES3::Armor::value);
			usertypeDefinition.set("weight", &TES3::Armor::weight);

			// Functions exposed as properties.
			usertypeDefinition.set("enchantment", sol::property(&TES3::Armor::getEnchantment, &TES3::Armor::setEnchantment));
			usertypeDefinition.set("maxCondition", sol::property(&TES3::Armor::getDurability, &TES3::Armor::setDurability));
			usertypeDefinition.set("icon", sol::property(
				&TES3::Armor::getIconPath,
				[](TES3::Armor& self, const char* value) { if (strlen(value) < 32) tes3::setDataString(&self.icon, value); }
			));
			usertypeDefinition.set("isLeftPart", sol::property(&TES3::Armor::isLeftPartOfPair));
			usertypeDefinition.set("mesh", sol::property(&TES3::Armor::getModelPath, &TES3::Armor::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Armor::getName, &TES3::Armor::setName));
			usertypeDefinition.set("script", sol::property(&TES3::Armor::getScript));
			usertypeDefinition.set("slotName", sol::property(&TES3::Armor::getTypeName));
			usertypeDefinition.set("weightClass", sol::property(&TES3::Armor::getWeightClass));

			// Basic function binding.
			usertypeDefinition.set("calculateArmorRating", [](TES3::Armor& self, sol::object actor) {
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
			});
			
			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("health", sol::property(&TES3::Armor::getDurability, &TES3::Armor::setDurability));
			usertypeDefinition.set("model", sol::property(&TES3::Armor::getModelPath, &TES3::Armor::setModelPath));

			// Finish up our usertype.
			state.set_usertype("tes3armor", usertypeDefinition);
		}
	}
}
