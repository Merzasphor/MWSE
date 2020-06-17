#include "TES3MobilePlayerLua.h"

#include "LuaManager.h"
#include "TES3MobileNPCLua.h"

#include "TES3Collections.h"

#include "TES3Alchemy.h"
#include "TES3Enchantment.h"
#include "TES3MobilePlayer.h"
#include "TES3Apparatus.h"
#include "TES3Birthsign.h"
#include "TES3Collections.h"
#include "TES3GlobalVariable.h"
#include "TES3NPC.h"
#include "TES3PlayerAnimationData.h"
#include "TES3Spell.h"

namespace mwse {
	namespace lua {
		void bindTES3MobilePlayer() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::MobilePlayer
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::MobilePlayer>("tes3mobilePlayer");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::MobileNPC, TES3::MobileActor, TES3::MobileObject>();
				setUserdataForMobileNPC(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["alwaysRun"] = &TES3::MobilePlayer::alwaysRun;
				usertypeDefinition["attackDisabled"] = &TES3::MobilePlayer::attackDisabled;
				usertypeDefinition["autoRun"] = &TES3::MobilePlayer::autoRun;
				usertypeDefinition["birthsign"] = &TES3::MobilePlayer::birthsign;
				usertypeDefinition["bounty"] = sol::property(&TES3::MobilePlayer::getBounty, &TES3::MobilePlayer::setBounty);
				usertypeDefinition["castReady"] = &TES3::MobilePlayer::castReady;
				usertypeDefinition["clawMultiplier"] = sol::readonly_property(&TES3::MobilePlayer::clawMultiplier);
				usertypeDefinition["controlsDisabled"] = &TES3::MobilePlayer::controlsDisabled;
				usertypeDefinition["dialogueList"] = sol::readonly_property(&TES3::MobilePlayer::dialogueList);
				usertypeDefinition["firstPerson"] = sol::readonly_property(&TES3::MobilePlayer::firstPerson);
				usertypeDefinition["firstPersonReference"] = sol::readonly_property(&TES3::MobilePlayer::firstPersonReference);
				usertypeDefinition["inactivityTime"] = &TES3::MobilePlayer::inactivityTime;
				usertypeDefinition["inJail"] = &TES3::MobilePlayer::playerInJail;
				usertypeDefinition["jumpingDisabled"] = &TES3::MobilePlayer::jumpingDisabled;
				usertypeDefinition["knownWerewolf"] = sol::readonly_property(&TES3::MobilePlayer::knownWerewolf);
				usertypeDefinition["lastUsedAlembic"] = &TES3::MobilePlayer::lastUsedAlembic;
				usertypeDefinition["lastUsedAmmoCount"] = &TES3::MobilePlayer::lastUsedAmmoCount;
				usertypeDefinition["lastUsedCalcinator"] = &TES3::MobilePlayer::lastUsedCalcinator;
				usertypeDefinition["lastUsedMortar"] = &TES3::MobilePlayer::lastUsedMortar;
				usertypeDefinition["lastUsedRetort"] = &TES3::MobilePlayer::lastUsedRetort;
				usertypeDefinition["levelUpProgress"] = &TES3::MobilePlayer::levelUpProgress;
				usertypeDefinition["magicDisabled"] = &TES3::MobilePlayer::magicDisabled;
				usertypeDefinition["markLocation"] = sol::readonly_property(&TES3::MobilePlayer::markLocation);
				usertypeDefinition["mouseLookDisabled"] = &TES3::MobilePlayer::mouseLookDisabled;
				usertypeDefinition["restHoursRemaining"] = &TES3::MobilePlayer::restHoursRemaining;
				usertypeDefinition["sleeping"] = &TES3::MobilePlayer::sleeping;
				usertypeDefinition["telekinesis"] = &TES3::MobilePlayer::telekinesis;
				usertypeDefinition["travelling"] = &TES3::MobilePlayer::playerIsTravelling;
				usertypeDefinition["vanityDisabled"] = &TES3::MobilePlayer::vanityDisabled;
				usertypeDefinition["viewSwitchDisabled"] = &TES3::MobilePlayer::viewSwitchDisabled;
				usertypeDefinition["visionBonus"] = &TES3::MobilePlayer::visionBonus;
				usertypeDefinition["waiting"] = &TES3::MobilePlayer::waiting;
				usertypeDefinition["weaponReady"] = &TES3::MobilePlayer::weaponReady;

				// Indirect bindings to unions and arrays.
				usertypeDefinition["levelupsPerAttribute"] = sol::property([](TES3::MobilePlayer& self) { return std::ref(self.levelupPerAttributeCount); });
				usertypeDefinition["levelupsPerSpecialization"] = sol::property([](TES3::MobilePlayer& self) { return std::ref(self.levelupPerSpecialization); });
				usertypeDefinition["skillProgress"] = sol::property([](TES3::MobilePlayer& self) { return std::ref(self.skillProgress); });

				// Overwrite MobileActor::animationData for player.
				usertypeDefinition["animationData"] = sol::readonly_property([](TES3::MobilePlayer& self) { return self.animationData.asPlayer; });

				// Overwrite MobileNPC::forceSneak so that it works on the player. 
				usertypeDefinition["forceSneak"] = sol::property(
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
				);

				// Basic function binding.
				usertypeDefinition["exerciseSkill"] = &TES3::MobilePlayer::exerciseSkill;
				usertypeDefinition["levelSkill"] = &TES3::MobilePlayer::levelSkill;

				// Functions exposed as properties.
				usertypeDefinition["is3rdPerson"] = sol::readonly_property(&TES3::MobilePlayer::is3rdPerson);
			}

			// Binding for TES3::MarkData.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::MarkData>("tes3markData");

				// Basic property bindings.
				usertypeDefinition["position"] = &TES3::MarkData::position;
				usertypeDefinition["rotation"] = &TES3::MarkData::rotation;

				// Access to other objects that need to be packaged.
				usertypeDefinition["cell"] = sol::property(
					[](TES3::MarkData& self) { return self.cell; },
					[](TES3::MarkData& self, sol::optional<TES3::Cell*> cell) { self.cell = cell.value_or(nullptr); }
				);
			}
		}
	}
}
