#include "TES3MobileCreatureLua.h"

#include "LuaManager.h"
#include "TES3MobileActorLua.h"

#include "TES3MobileCreature.h"
#include "TES3Creature.h"
#include "TES3Statistic.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileCreature() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::MobileCreature>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::MobileActor, TES3::MobileObject>());
			setUserdataForMobileActor(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("skills", sol::property([](TES3::MobileCreature& self) { return std::ref(self.skills); }));

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("object", sol::readonly_property([](TES3::MobileCreature& self) { return makeLuaObject(self.creatureInstance); }));

			// Allow read access to movement speeds.
			usertypeDefinition.set("moveSpeed", sol::readonly_property([](TES3::MobileCreature& self) { return self.animationData.asActor->calculateMovementSpeed(); }));
			usertypeDefinition.set("walkSpeed", sol::readonly_property(&TES3::MobileCreature::calculateWalkSpeed));
			usertypeDefinition.set("runSpeed", sol::readonly_property(&TES3::MobileCreature::calculateWalkSpeed));
			usertypeDefinition.set("swimSpeed", sol::readonly_property(&TES3::MobileCreature::calculateWalkSpeed));
			usertypeDefinition.set("swimRunSpeed", sol::readonly_property(&TES3::MobileCreature::calculateWalkSpeed));
			usertypeDefinition.set("flySpeed", sol::readonly_property(&TES3::MobileCreature::calculateWalkSpeed));

			// Friendly access to skills.
			usertypeDefinition.set("combat", sol::readonly_property([](TES3::MobileCreature& self) { return &self.skills[TES3::CreatureSkillID::Combat]; }));
			usertypeDefinition.set("magic", sol::readonly_property([](TES3::MobileCreature& self) { return &self.skills[TES3::CreatureSkillID::Magic]; }));
			usertypeDefinition.set("stealth", sol::readonly_property([](TES3::MobileCreature& self) { return &self.skills[TES3::CreatureSkillID::Stealth]; }));

			// Finish up our usertype.
			state.set_usertype("tes3mobileCreature", usertypeDefinition);
		}
	}
}
