#include "TES3MobilePlayerLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Collections.h"

#include "TES3Apparatus.h"
#include "TES3Collections.h"
#include "TES3GlobalVariable.h"
#include "TES3MobilePlayer.h"
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
			auto mobilePlayerUsertype = state.create_simple_usertype<TES3::MobilePlayer>();

			// We inherit MobileActor.
			mobilePlayerUsertype.set(sol::base_classes, sol::bases<TES3::MobileNPC, TES3::MobileActor, TES3::MobileObject>());

			// Basic property binding.
			mobilePlayerUsertype.set("alwaysRun", &TES3::MobilePlayer::alwaysRun);
			mobilePlayerUsertype.set("attackDisabled", &TES3::MobilePlayer::attackDisabled);
			mobilePlayerUsertype.set("autoRun", &TES3::MobilePlayer::autoRun);
			mobilePlayerUsertype.set("castReady", &TES3::MobilePlayer::castReady);
			mobilePlayerUsertype.set("controlsDisabled", &TES3::MobilePlayer::controlsDisabled);
			mobilePlayerUsertype.set("controlsDisabled", &TES3::MobilePlayer::controlsDisabled);
			mobilePlayerUsertype.set("inactivityTime", &TES3::MobilePlayer::inactivityTime);
			mobilePlayerUsertype.set("inJail", &TES3::MobilePlayer::playerInJail);
			mobilePlayerUsertype.set("jumpingDisabled", &TES3::MobilePlayer::jumpingDisabled);
			mobilePlayerUsertype.set("lastUsedAmmoCount", &TES3::MobilePlayer::lastUsedAmmoCount);
			mobilePlayerUsertype.set("levelUpProgress", &TES3::MobilePlayer::levelUpProgress);
			mobilePlayerUsertype.set("magicDisabled", &TES3::MobilePlayer::magicDisabled);
			mobilePlayerUsertype.set("mouseLookDisabled", &TES3::MobilePlayer::mouseLookDisabled);
			mobilePlayerUsertype.set("restHoursRemaining", &TES3::MobilePlayer::restHoursRemaining);
			mobilePlayerUsertype.set("sleeping", sol::readonly_property(&TES3::MobilePlayer::sleeping));
			mobilePlayerUsertype.set("telekinesis", &TES3::MobilePlayer::telekinesis);
			mobilePlayerUsertype.set("travelling", &TES3::MobilePlayer::playerIsTravelling);
			mobilePlayerUsertype.set("vanityDisabled", &TES3::MobilePlayer::vanityDisabled);
			mobilePlayerUsertype.set("viewSwitchDisabled", &TES3::MobilePlayer::viewSwitchDisabled);
			mobilePlayerUsertype.set("visionBonus", &TES3::MobilePlayer::visionBonus);
			mobilePlayerUsertype.set("weaponReady", &TES3::MobilePlayer::weaponReady);

			// Indirect bindings to unions and arrays.
			mobilePlayerUsertype.set("levelupsPerAttribute", sol::property([](TES3::MobilePlayer& self) { return std::ref(self.levelupPerAttributeCount); }));
			mobilePlayerUsertype.set("levelupsPerSpecialization", sol::property([](TES3::MobilePlayer& self) { return std::ref(self.levelupPerSpecialization); }));
			mobilePlayerUsertype.set("skillProgress", sol::property([](TES3::MobilePlayer& self) { return std::ref(self.skillProgress); }));

			// Access to other objects that need to be packaged.
			mobilePlayerUsertype.set("clawMultiplier", sol::readonly_property([](TES3::MobilePlayer& self) { makeLuaObject(self.clawMultiplier); }));
			mobilePlayerUsertype.set("firstPerson", sol::readonly_property([](TES3::MobilePlayer& self) { makeLuaObject(self.firstPerson); }));
			mobilePlayerUsertype.set("firstPersonReference", sol::readonly_property([](TES3::MobilePlayer& self) { makeLuaObject(self.firstPersonReference); }));
			mobilePlayerUsertype.set("knownWerewolf", sol::readonly_property([](TES3::MobilePlayer& self) { makeLuaObject(self.knownWerewolf); }));
			mobilePlayerUsertype.set("lastUsedAlembic", sol::readonly_property([](TES3::MobilePlayer& self) { makeLuaObject(self.lastUsedAlembic); }));
			mobilePlayerUsertype.set("lastUsedCalcinator", sol::readonly_property([](TES3::MobilePlayer& self) { makeLuaObject(self.lastUsedCalcinator); }));
			mobilePlayerUsertype.set("lastUsedMortar", sol::readonly_property([](TES3::MobilePlayer& self) { makeLuaObject(self.lastUsedMortar); }));
			mobilePlayerUsertype.set("lastUsedRetort", sol::readonly_property([](TES3::MobilePlayer& self) { makeLuaObject(self.lastUsedRetort); }));

			// Overwrite MobileActor::animationData for player.
			mobilePlayerUsertype.set("animationData", sol::readonly_property([](TES3::MobileActor& self) { return self.animationData.asPlayer; }));

			// Overwrite MobileNPC::forceSneak so that it works on the player. 
			mobilePlayerUsertype.set("forceSneak", sol::property(
				[](TES3::MobilePlayer& self) { return (self.movementFlags & TES3::ActorMovement::Crouching) != 0; },
				[](TES3::MobilePlayer& self, bool set)
			{
				if (set) {
					self.movementFlags |= TES3::ActorMovement::Crouching;
				}
				else {
					self.movementFlags &= ~TES3::ActorMovement::Crouching;
				}
			}
			));

			// Basic function binding.
			mobilePlayerUsertype.set("exerciseSkill", &TES3::MobilePlayer::exerciseSkill);
			mobilePlayerUsertype.set("levelSkill", &TES3::MobilePlayer::levelSkill);

			// Functions exposed as read-only properties.
			mobilePlayerUsertype.set("is3rdPerson", sol::readonly_property(&TES3::MobilePlayer::is3rdPerson));

			// Finish up our usertype.
			state.set_usertype("TES3MobilePlayer", mobilePlayerUsertype);
		}
	}
}
