#include "TES3MobilePlayerLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3MobilePlayer() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::MobilePlayer>("TES3MobilePlayer",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties: MACT
				//

				"objectType", &TES3::MobilePlayer::objectType,

				"movementFlags", &TES3::MobilePlayer::movementFlags,
				"prevMovementFlags", &TES3::MobilePlayer::prevMovementFlags,
				"actorFlags", &TES3::MobilePlayer::actorFlags,

				"actorType", &TES3::MobilePlayer::actorType,
				"reference", &TES3::MobilePlayer::reference,

				"cellX", &TES3::MobilePlayer::cellX,
				"cellY", &TES3::MobilePlayer::cellY,

				"height", &TES3::MobilePlayer::height,
				"boundSize", &TES3::MobilePlayer::boundSize,
				"velocity", &TES3::MobilePlayer::velocity,
				"impulseVelocity", &TES3::MobilePlayer::impulseVelocity,
				"position", &TES3::MobilePlayer::position,
				"lastGroundZ", &TES3::MobilePlayer::lastGroundZ,
				"collidingReference", &TES3::MobilePlayer::collidingReference,
				"widthInUnits", &TES3::MobilePlayer::widthInUnits,

				"listTargetActors", &TES3::MobilePlayer::listTargetActors,
				"listFriendlyActors", &TES3::MobilePlayer::listFriendlyActors,

				"scanTimer", &TES3::MobilePlayer::scanTimer,
				"scanInterval", &TES3::MobilePlayer::scanInterval,
				"greetTimer", &TES3::MobilePlayer::greetTimer,

				"actionData", &TES3::MobilePlayer::actionData,
				"actionBeforeCombat", &TES3::MobilePlayer::actionBeforeCombat,

				//"activeMagicEffects", &TES3::MobilePlayer::activeMagicEffects,
				"activeMagicEffectCount", &TES3::MobilePlayer::activeMagicEffectCount,

				//"powers", &TES3::MobilePlayer::powers,

				"nextActionWeight", &TES3::MobilePlayer::nextActionWeight,

				//"animationData", &TES3::MobilePlayer::animationData,

				"attributes", sol::property([](TES3::MobilePlayer& self) { return std::ref(self.attributes); }),
				"health", &TES3::MobilePlayer::health,
				"magicka", &TES3::MobilePlayer::magicka,
				"encumbrance", &TES3::MobilePlayer::encumbrance,
				"fatigue", &TES3::MobilePlayer::fatigue,
				"magickaMultiplier", &TES3::MobilePlayer::magickaMultiplier,

				"attackBonus", &TES3::MobilePlayer::attackBonus,
				"sanctuary", &TES3::MobilePlayer::sanctuary,
				"resistMagicka", &TES3::MobilePlayer::resistMagicka,
				"resistFire", &TES3::MobilePlayer::resistFire,
				"resistFrost", &TES3::MobilePlayer::resistFrost,
				"resistShock", &TES3::MobilePlayer::resistShock,
				"resistCommonDisease", &TES3::MobilePlayer::resistCommonDisease,
				"resistBlightDisease", &TES3::MobilePlayer::resistBlightDisease,
				"resistCorprus", &TES3::MobilePlayer::resistCorprus,
				"resistPoison", &TES3::MobilePlayer::resistPoison,
				"resistParalysis", &TES3::MobilePlayer::resistParalysis,
				"chameleon", &TES3::MobilePlayer::chameleon,
				"resistNormalWeapons", &TES3::MobilePlayer::resistNormalWeapons,
				"waterBreathing", &TES3::MobilePlayer::waterBreathing,
				"waterWalking", &TES3::MobilePlayer::waterWalking,
				"swiftSwim", &TES3::MobilePlayer::swiftSwim,
				"jump", &TES3::MobilePlayer::jump,
				"levitate", &TES3::MobilePlayer::levitate,
				"shield", &TES3::MobilePlayer::shield,
				"sound", &TES3::MobilePlayer::sound,
				"silence", &TES3::MobilePlayer::silence,
				"blind", &TES3::MobilePlayer::blind,
				"paralyze", &TES3::MobilePlayer::paralyze,
				"invisibility", &TES3::MobilePlayer::invisibility,

				"fight", &TES3::MobilePlayer::fight,
				"flee", &TES3::MobilePlayer::flee,
				"hello", &TES3::MobilePlayer::hello,
				"alarm", &TES3::MobilePlayer::alarm,

				"barterGold", &TES3::MobilePlayer::barterGold,

				"readiedAmmoCount", &TES3::MobilePlayer::readiedAmmoCount,
				"corpseHourstamp", &TES3::MobilePlayer::corpseHourstamp,
				"greetDuration", &TES3::MobilePlayer::greetDuration,
				"holdBreathTime", &TES3::MobilePlayer::holdBreathTime,
				"currentSpell", &TES3::MobilePlayer::currentSpell,
				"spellSource", &TES3::MobilePlayer::spellSource,

				"currentEnchItem", &TES3::MobilePlayer::currentEnchItem,
				"currentEnchItemData", &TES3::MobilePlayer::currentEnchItemData,
				"readiedWeapon", &TES3::MobilePlayer::readiedWeapon,
				"readiedAmmo", &TES3::MobilePlayer::readiedAmmo,
				"readiedShield", &TES3::MobilePlayer::readiedShield,
				"torchSlot", &TES3::MobilePlayer::torchSlot,

				"arrowBone", &TES3::MobilePlayer::arrowBone,

				//
				// Properties: MACH
				//

				"object", &TES3::MobilePlayer::npcInstance,
				"skills", sol::property([](TES3::MobilePlayer& self) { return std::ref(self.skills); }),

				"forceSneak", &TES3::MobilePlayer::flagForceSneak,
				"flagForceRun", &TES3::MobilePlayer::flagForceRun,
				"flagForceJump", &TES3::MobilePlayer::flagForceJump,
				"flagForceMoveJump", &TES3::MobilePlayer::flagForceMoveJump,

				//
				// Properties: MACP
				//

				"levelupProgress", &TES3::MobilePlayer::levelUpProgress,
				"levelupsPerAttribute", sol::property([](TES3::MobilePlayer& self) { return std::ref(self.levelupPerAttributeCount); }),
				"levelupsPerSpecialization", sol::property([](TES3::MobilePlayer& self) { return std::ref(self.levelupPerSpecialization); }),
				"skillProgress", sol::property([](TES3::MobilePlayer& self) { return std::ref(self.skillProgress); }),

				// "bounty", &TES3::MobilePlayer::bounty,

				"lastUsedAmmoCount", &TES3::MobilePlayer::lastUsedAmmoCount,

				"lastUsedMortar", &TES3::MobilePlayer::apparatus0,
				"lastUsedAlembic", &TES3::MobilePlayer::apparatus1,
				"lastUsedCalcinator", &TES3::MobilePlayer::apparatus2,
				"lastUsedRetort", &TES3::MobilePlayer::apparatus3,

				"clawMultiplier", &TES3::MobilePlayer::clawMultiplier,
				"knownWerewolf", &TES3::MobilePlayer::knownWerewolf,

				"controlsDisabled", &TES3::MobilePlayer::controlsDisabled,
				"jumpingDisabled", &TES3::MobilePlayer::jumpingDisabled,
				"mouseLookDisabled", &TES3::MobilePlayer::mouselookDisabled,
				"viewSwitchDisabled", &TES3::MobilePlayer::viewSwitchDisabled,
				"vanityDisabled", &TES3::MobilePlayer::vanityDisabled,
				"attackDisabled", &TES3::MobilePlayer::attackDisabled,
				"magicDisabled", &TES3::MobilePlayer::magicDisabled,
				"alwaysRun", &TES3::MobilePlayer::alwaysRun,
				"autoRun", &TES3::MobilePlayer::autoRun,
				"sleeping", &TES3::MobilePlayer::sleeping,
				"weaponReady", &TES3::MobilePlayer::weaponReady,
				"castReady", &TES3::MobilePlayer::castReady,
				"isJailed", &TES3::MobilePlayer::playerInJail,
				"isTravelling", &TES3::MobilePlayer::playerIsTravelling,

				"telekinesis", &TES3::MobilePlayer::telekinesis,
				"visionBonus", &TES3::MobilePlayer::visionBonus,

				"restHoursRemaining", &TES3::MobilePlayer::restHoursRemaining,

				// "birthsign", &TES3::MobilePlayer::birthsign,

				// "markLocation", &TES3::MobilePlayer::markLocation,

				"inactivityTime", &TES3::MobilePlayer::inactivityTime

				);
		}
	}
}
