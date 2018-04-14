#include "TES3MobileNPCLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileNPC() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::MobileNPC>("TES3MobileNPC",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties: MACT
				//

				"objectType", &TES3::MobileNPC::objectType,

				"movementFlags", &TES3::MobileNPC::movementFlags,
				"prevMovementFlags", &TES3::MobileNPC::prevMovementFlags,
				"actorFlags", &TES3::MobileNPC::actorFlags,

				"actorType", &TES3::MobileNPC::actorType,
				"reference", &TES3::MobileNPC::reference,

				"cellX", &TES3::MobileNPC::cellX,
				"cellY", &TES3::MobileNPC::cellY,

				"height", &TES3::MobileNPC::height,
				"boundSize", &TES3::MobileNPC::boundSize,
				"velocity", &TES3::MobileNPC::velocity,
				"impulseVelocity", &TES3::MobileNPC::impulseVelocity,
				"position", &TES3::MobileNPC::position,
				"lastGroundZ", &TES3::MobileNPC::lastGroundZ,
				"collidingReference", &TES3::MobileNPC::collidingReference,
				"widthInUnits", &TES3::MobileNPC::widthInUnits,

				"listTargetActors", &TES3::MobileNPC::listTargetActors,
				"listFriendlyActors", &TES3::MobileNPC::listFriendlyActors,

				"scanTimer", &TES3::MobileNPC::scanTimer,
				"scanInterval", &TES3::MobileNPC::scanInterval,
				"greetTimer", &TES3::MobileNPC::greetTimer,

				"actionData", &TES3::MobileNPC::actionData,
				"actionBeforeCombat", &TES3::MobileNPC::actionBeforeCombat,

				//"activeMagicEffects", &TES3::MobileNPC::activeMagicEffects,
				"activeMagicEffectCount", &TES3::MobileNPC::activeMagicEffectCount,

				//"powers", &TES3::MobileNPC::powers,

				"nextActionWeight", &TES3::MobileNPC::nextActionWeight,

				//"animationData", &TES3::MobileNPC::animationData,

				"attributes", sol::property([](TES3::MobileNPC& self) { return std::ref(self.attributes); }),
				"health", &TES3::MobileNPC::health,
				"magicka", &TES3::MobileNPC::magicka,
				"encumbrance", &TES3::MobileNPC::encumbrance,
				"fatigue", &TES3::MobileNPC::fatigue,
				"magickaMultiplier", &TES3::MobileNPC::magickaMultiplier,

				"attackBonus", &TES3::MobileNPC::attackBonus,
				"sanctuary", &TES3::MobileNPC::sanctuary,
				"resistMagicka", &TES3::MobileNPC::resistMagicka,
				"resistFire", &TES3::MobileNPC::resistFire,
				"resistFrost", &TES3::MobileNPC::resistFrost,
				"resistShock", &TES3::MobileNPC::resistShock,
				"resistCommonDisease", &TES3::MobileNPC::resistCommonDisease,
				"resistBlightDisease", &TES3::MobileNPC::resistBlightDisease,
				"resistCorprus", &TES3::MobileNPC::resistCorprus,
				"resistPoison", &TES3::MobileNPC::resistPoison,
				"resistParalysis", &TES3::MobileNPC::resistParalysis,
				"chameleon", &TES3::MobileNPC::chameleon,
				"resistNormalWeapons", &TES3::MobileNPC::resistNormalWeapons,
				"waterBreathing", &TES3::MobileNPC::waterBreathing,
				"waterWalking", &TES3::MobileNPC::waterWalking,
				"swiftSwim", &TES3::MobileNPC::swiftSwim,
				"jump", &TES3::MobileNPC::jump,
				"levitate", &TES3::MobileNPC::levitate,
				"shield", &TES3::MobileNPC::shield,
				"sound", &TES3::MobileNPC::sound,
				"silence", &TES3::MobileNPC::silence,
				"blind", &TES3::MobileNPC::blind,
				"paralyze", &TES3::MobileNPC::paralyze,
				"invisibility", &TES3::MobileNPC::invisibility,

				"fight", &TES3::MobileNPC::fight,
				"flee", &TES3::MobileNPC::flee,
				"hello", &TES3::MobileNPC::hello,
				"alarm", &TES3::MobileNPC::alarm,

				"barterGold", &TES3::MobileNPC::barterGold,

				"readiedAmmoCount", &TES3::MobileNPC::readiedAmmoCount,
				"corpseHourstamp", &TES3::MobileNPC::corpseHourstamp,
				"greetDuration", &TES3::MobileNPC::greetDuration,
				"holdBreathTime", &TES3::MobileNPC::holdBreathTime,
				"currentSpell", &TES3::MobileNPC::currentSpell,
				"spellSource", &TES3::MobileNPC::spellSource,

				"currentEnchItem", &TES3::MobileNPC::currentEnchItem,
				"currentEnchItemData", &TES3::MobileNPC::currentEnchItemData,
				"readiedWeapon", &TES3::MobileNPC::readiedWeapon,
				"readiedAmmo", &TES3::MobileNPC::readiedAmmo,
				"readiedShield", &TES3::MobileNPC::readiedShield,
				"torchSlot", &TES3::MobileNPC::torchSlot,

				"arrowBone", &TES3::MobileNPC::arrowBone,

				//
				// Properties: MACH
				//

				"object", &TES3::MobileNPC::npcInstance,
				"skills", sol::property([](TES3::MobileNPC& self) { return std::ref(self.skills); }),

				"forceSneak", &TES3::MobileNPC::flagForceSneak,
				"flagForceRun", &TES3::MobileNPC::flagForceRun,
				"flagForceJump", &TES3::MobileNPC::flagForceJump,
				"flagForceMoveJump", &TES3::MobileNPC::flagForceMoveJump

				);
		}
	}
}
