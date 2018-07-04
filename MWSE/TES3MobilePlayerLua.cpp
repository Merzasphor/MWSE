#include "TES3MobilePlayerLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Collections.h"

#include "TES3MobilePlayer.h"
#include "TES3Apparatus.h"
#include "TES3Collections.h"
#include "TES3GlobalVariable.h"
#include "TES3NPC.h"
#include "TES3PlayerAnimationData.h"
#include "TES3Reference.h"
#include "TES3Spell.h"

namespace mwse {
	namespace lua {
		void bindTES3MobilePlayer() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::MobilePlayer>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::MobileNPC, TES3::MobileActor, TES3::MobileObject>());

			// Basic property binding.
			usertypeDefinition.set("alwaysRun", &TES3::MobilePlayer::alwaysRun);
			usertypeDefinition.set("attackDisabled", &TES3::MobilePlayer::attackDisabled);
			usertypeDefinition.set("autoRun", &TES3::MobilePlayer::autoRun);
			usertypeDefinition.set("castReady", &TES3::MobilePlayer::castReady);
			usertypeDefinition.set("controlsDisabled", &TES3::MobilePlayer::controlsDisabled);
			usertypeDefinition.set("inactivityTime", &TES3::MobilePlayer::inactivityTime);
			usertypeDefinition.set("inJail", &TES3::MobilePlayer::playerInJail);
			usertypeDefinition.set("jumpingDisabled", &TES3::MobilePlayer::jumpingDisabled);
			usertypeDefinition.set("lastUsedAmmoCount", &TES3::MobilePlayer::lastUsedAmmoCount);
			usertypeDefinition.set("levelUpProgress", &TES3::MobilePlayer::levelUpProgress);
			usertypeDefinition.set("magicDisabled", &TES3::MobilePlayer::magicDisabled);
			usertypeDefinition.set("mouseLookDisabled", &TES3::MobilePlayer::mouseLookDisabled);
			usertypeDefinition.set("restHoursRemaining", &TES3::MobilePlayer::restHoursRemaining);
			usertypeDefinition.set("sleeping", sol::readonly_property(&TES3::MobilePlayer::sleeping));
			usertypeDefinition.set("telekinesis", &TES3::MobilePlayer::telekinesis);
			usertypeDefinition.set("travelling", &TES3::MobilePlayer::playerIsTravelling);
			usertypeDefinition.set("vanityDisabled", &TES3::MobilePlayer::vanityDisabled);
			usertypeDefinition.set("viewSwitchDisabled", &TES3::MobilePlayer::viewSwitchDisabled);
			usertypeDefinition.set("visionBonus", &TES3::MobilePlayer::visionBonus);
			usertypeDefinition.set("weaponReady", &TES3::MobilePlayer::weaponReady);

			// Indirect bindings to unions and arrays.
			usertypeDefinition.set("levelupsPerAttribute", sol::property([](TES3::MobilePlayer& self) { return std::ref(self.levelupPerAttributeCount); }));
			usertypeDefinition.set("levelupsPerSpecialization", sol::property([](TES3::MobilePlayer& self) { return std::ref(self.levelupPerSpecialization); }));
			usertypeDefinition.set("skillProgress", sol::property([](TES3::MobilePlayer& self) { return std::ref(self.skillProgress); }));

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("clawMultiplier", sol::readonly_property([](TES3::MobilePlayer& self) { return makeLuaObject(self.clawMultiplier); }));
			usertypeDefinition.set("firstPerson", sol::readonly_property([](TES3::MobilePlayer& self) { return makeLuaObject(self.firstPerson); }));
			usertypeDefinition.set("firstPersonReference", sol::readonly_property([](TES3::MobilePlayer& self) { return makeLuaObject(self.firstPersonReference); }));
			usertypeDefinition.set("knownWerewolf", sol::readonly_property([](TES3::MobilePlayer& self) { return makeLuaObject(self.knownWerewolf); }));
			usertypeDefinition.set("lastUsedAlembic", sol::readonly_property([](TES3::MobilePlayer& self) { return makeLuaObject(self.lastUsedAlembic); }));
			usertypeDefinition.set("lastUsedCalcinator", sol::readonly_property([](TES3::MobilePlayer& self) { return makeLuaObject(self.lastUsedCalcinator); }));
			usertypeDefinition.set("lastUsedMortar", sol::readonly_property([](TES3::MobilePlayer& self) { return makeLuaObject(self.lastUsedMortar); }));
			usertypeDefinition.set("lastUsedRetort", sol::readonly_property([](TES3::MobilePlayer& self) { return makeLuaObject(self.lastUsedRetort); }));

			// Overwrite MobileActor::animationData for player.
			usertypeDefinition.set("animationData", sol::readonly_property([](TES3::MobilePlayer& self) { return self.animationData.asPlayer; }));

			// Overwrite MobileNPC::forceSneak so that it works on the player. 
			usertypeDefinition.set("forceSneak", sol::property(
				[](TES3::MobilePlayer& self) { return (self.movementFlags & TES3::ActorMovement::Sneaking) != 0; },
				[](TES3::MobilePlayer& self, bool set)
			{
				if (set) {
					self.movementFlags |= TES3::ActorMovement::Sneaking;
				}
				else {
					self.movementFlags &= ~TES3::ActorMovement::Sneaking;
				}
			}
			));

			// Basic function binding.
			usertypeDefinition.set("exerciseSkill", &TES3::MobilePlayer::exerciseSkill);
			usertypeDefinition.set("levelSkill", &TES3::MobilePlayer::levelSkill);

			// Functions exposed as properties.
			usertypeDefinition.set("is3rdPerson", sol::readonly_property(&TES3::MobilePlayer::is3rdPerson));

			// Finish up our usertype.
			state.set_usertype("tes3mobilePlayer", usertypeDefinition);
		}
	}
}
