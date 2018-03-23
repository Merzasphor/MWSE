#include "TES3MobileCreatureLua.h"

#include "LuaManager.h"

#include "TES3Armor.h"
#include "TES3Creature.h"
#include "TES3Inventory.h"
#include "TES3Item.h"
#include "TES3Light.h"
#include "TES3MobileCreature.h"
#include "TES3Reference.h"
#include "TES3Spell.h"
#include "TES3Statistic.h"
#include "TES3Vectors.h"
#include "TES3Weapon.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileCreature() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::MobileCreature>("TES3MobileCreature",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties: MACT
				//

				"objectType", &TES3::MobileCreature::objectType,


				"movementFlags", &TES3::MobileCreature::movementFlags,
				"prevMovementFlags", &TES3::MobileCreature::prevMovementFlags,
				"actorFlags", &TES3::MobileCreature::actorFlags,

				"actorType", &TES3::MobileCreature::actorType,
				"reference", &TES3::MobileCreature::reference,

				"cellX", &TES3::MobileCreature::cellX,
				"cellY", &TES3::MobileCreature::cellY,

				"height", &TES3::MobileCreature::height,
				"boundSize", &TES3::MobileCreature::boundSize,
				"velocity", &TES3::MobileCreature::velocity,
				"impulseVelocity", &TES3::MobileCreature::impulseVelocity,
				"position", &TES3::MobileCreature::position,
				"lastGroundZ", &TES3::MobileCreature::lastGroundZ,
				"collidingReference", &TES3::MobileCreature::collidingReference,
				"widthInUnits", &TES3::MobileCreature::widthInUnits,

				"listTargetActors", &TES3::MobileCreature::listTargetActors,
				"listFriendlyActors", &TES3::MobileCreature::listFriendlyActors,

				"scanTimer", &TES3::MobileCreature::scanTimer,
				"scanInterval", &TES3::MobileCreature::scanInterval,
				"greetTimer", &TES3::MobileCreature::greetTimer,

				"actionData", &TES3::MobileCreature::actionData,
				"actionBeforeCombat", &TES3::MobileCreature::actionBeforeCombat,

				//"activeMagicEffects", &TES3::MobileCreature::activeMagicEffects,
				"activeMagicEffectCount", &TES3::MobileCreature::activeMagicEffectCount,

				//"powers", &TES3::MobileCreature::powers,

				"nextActionWeight", &TES3::MobileCreature::nextActionWeight,

				//"animationData", &TES3::MobileCreature::animationData,

				"attributes", sol::property([](TES3::MobileCreature* self) { return std::ref(self->attributes); }),
				"health", &TES3::MobileCreature::health,
				"magicka", &TES3::MobileCreature::magicka,
				"encumbrance", &TES3::MobileCreature::encumbrance,
				"fatigue", &TES3::MobileCreature::fatigue,
				"magickaMultiplier", &TES3::MobileCreature::magickaMultiplier,

				"attackBonus", &TES3::MobileCreature::attackBonus,
				"sanctuary", &TES3::MobileCreature::sanctuary,
				"resistMagicka", &TES3::MobileCreature::resistMagicka,
				"resistFire", &TES3::MobileCreature::resistFire,
				"resistFrost", &TES3::MobileCreature::resistFrost,
				"resistShock", &TES3::MobileCreature::resistShock,
				"resistCommonDisease", &TES3::MobileCreature::resistCommonDisease,
				"resistBlightDisease", &TES3::MobileCreature::resistBlightDisease,
				"resistCorprus", &TES3::MobileCreature::resistCorprus,
				"resistPoison", &TES3::MobileCreature::resistPoison,
				"resistParalysis", &TES3::MobileCreature::resistParalysis,
				"chameleon", &TES3::MobileCreature::chameleon,
				"resistNormalWeapons", &TES3::MobileCreature::resistNormalWeapons,
				"waterBreathing", &TES3::MobileCreature::waterBreathing,
				"waterWalking", &TES3::MobileCreature::waterWalking,
				"swiftSwim", &TES3::MobileCreature::swiftSwim,
				"jump", &TES3::MobileCreature::jump,
				"levitate", &TES3::MobileCreature::levitate,
				"shield", &TES3::MobileCreature::shield,
				"sound", &TES3::MobileCreature::sound,
				"silence", &TES3::MobileCreature::silence,
				"blind", &TES3::MobileCreature::blind,
				"paralyze", &TES3::MobileCreature::paralyze,
				"invisibility", &TES3::MobileCreature::invisibility,

				"fight", &TES3::MobileCreature::fight,
				"flee", &TES3::MobileCreature::flee,
				"hello", &TES3::MobileCreature::hello,
				"alarm", &TES3::MobileCreature::alarm,

				"barterGold", &TES3::MobileCreature::barterGold,

				"readiedAmmoCount", &TES3::MobileCreature::readiedAmmoCount,
				"corpseHourstamp", &TES3::MobileCreature::corpseHourstamp,
				"greetDuration", &TES3::MobileCreature::greetDuration,
				"holdBreathTime", &TES3::MobileCreature::holdBreathTime,
				"currentSpell", &TES3::MobileCreature::currentSpell,
				"spellSource", &TES3::MobileCreature::spellSource,

				"currentEnchItem", &TES3::MobileCreature::currentEnchItem,
				"currentEnchItemData", &TES3::MobileCreature::currentEnchItemData,
				"readiedWeapon", &TES3::MobileCreature::readiedWeapon,
				"readiedAmmo", &TES3::MobileCreature::readiedAmmo,
				"readiedShield", &TES3::MobileCreature::readiedShield,
				"torchSlot", &TES3::MobileCreature::torchSlot,

				"arrowBone", &TES3::MobileCreature::arrowBone,

				//
				// Properties: MACR
				//

				"object", sol::readonly_property(&TES3::MobileCreature::creatureInstance),

				"combatSkill", &TES3::MobileCreature::combatSkill,
				"magicSkill", &TES3::MobileCreature::magicSkill,
				"stealthSkill", &TES3::MobileCreature::stealthSkill

				);
		}
	}
}
