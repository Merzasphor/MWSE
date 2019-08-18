#pragma once

#include "TES3Defines.h"

#include "TES3ActionData.h"
#include "TES3AIBehavior.h"
#include "TES3Armor.h"
#include "TES3Clothing.h"
#include "TES3CrimeController.h"
#include "TES3Inventory.h"
#include "TES3MagicSourceInstance.h"
#include "TES3MobileObject.h"
#include "TES3Statistic.h"
#include "TES3Vectors.h"

namespace TES3 {
	enum class MobileActorType : char {
		Creature = 0,
		NPC = 1,
		Player = 2
	};

	namespace Attribute {
		enum Attribute {
			Invalid = -1,
			Strength = 0,
			Intelligence = 1,
			Willpower = 2,
			Agility = 3,
			Speed = 4,
			Endurance = 5,
			Personality = 6,
			Luck = 7,
			FirstAttribute = Strength,
			LastAttribute = Luck
		};
	}

	namespace EffectAttribute {
		enum EffectAttribute {
			AttackBonus,
			Sanctuary,
			ResistMagicka,
			ResistFire,
			ResistFrost,
			ResistShock,
			ResistCommonDisease,
			ResistBlightDisease,
			ResistCorprus,
			ResistPoison,
			ResistParalysis,
			Chameleon,
			ResistNormalWeapons,
			WaterBreathing,
			WaterWalking,
			SwiftSwim,
			Jump,
			Levitate,
			Shield,
			Sound,
			Silence,
			Blind,
			Paralyze,
			Invisibility,
			Fight,
			Flee,
			Hello,
			Alarm,
			NonResistable
		};
	}

	namespace Voiceover {
		enum Voiceover {
			Hello,
			Idle,
			Intruder,
			Thief,
			Hit,
			Attack,
			Flee,

			First = Hello,
			Last = Flee
		};
	}

	struct MobileActor : MobileObject {
		struct ActiveMagicEffect {
			ActiveMagicEffect* next; // 0x0
			ActiveMagicEffect* prev; // 0x4
			unsigned int magicInstanceSerial; // 0x8
			short magicInstanceEffectIndex; // 0xC
			short magicEffectID; // 0xE
			bool isHarmful; // 0x10
			bool unknown_0x9; // 0x11
			unsigned short duration; // 0x14
			unsigned short magnitudeMin; // 0x16
			unsigned char skillOrAttributeID; // 0x18
		};
		struct ActiveMagicEffects {
			bool unknown_0x0;
			ActiveMagicEffect * firstEffect; // 0x4
			int count; // 0x8
		};

		Iterator<MobileActor> listTargetActors; // 0x80
		Iterator<MobileActor> listFriendlyActors; // 0x94
		float scanTimer; // 0xA8
		int scanInterval; // 0xAC
		float greetTimer; // B0
		Vector3 unknown_0xB4;
		char unknown_0xC0;
		char unknown_0xC1; // Undefined.
		char unknown_0xC2; // Undefined.
		char unknown_0xC3; // Undefined.
		float timer_0xC4;
		AIPlanner * aiPlanner; // 0xC8
		ActionData actionData; // 0xCC
		ActionData actionBeforeCombat; // 0x13C
		CrimeController crimesA; // 0x1AC
		int unknown_0x1B8;
		int unknown_0x1BC;
		CombatSession * combatSession; // 0x1C0
		ActiveMagicEffects activeMagicEffects; // 0x1C4
		int unknown_0x1D0;
		Collision collision_1D4;
		HashMap powers;
		char unknown_0x224;
		char prevAIBehaviourState;
		char unknown_0x226;
		signed char nextActionWeight; // 0x227
		MobileActorType actorType; // 0x228
		char unknown_0x229;
		char unknown_0x22A; // Undefined.
		char unknown_0x22B; // Undefined.
		float lastGroundZ; // 0x22C
		int unknown_0x230;
		Reference * collidingReference; // 0x234
		int unknown_0x238;
		int unknown_0x23C;
		int unknown_0x240;
		union {
			ActorAnimationData * asActor;
			PlayerAnimationData * asPlayer;
		} animationData; // 0x244
		CrimeController crimesB; // 0x248
		Statistic attributes[8];
		Statistic health;
		Statistic magicka;
		Statistic encumbrance;
		Statistic fatigue;
		Statistic magickaMultiplier;
		int effectAttributes[24];
		int fight;
		int flee;
		int hello;
		int alarm;
		int barterGold;
		short widthInUnits;
		short heightInUnits;
		short readiedAmmoCount;
		short corpseHourstamp;
		short greetDuration;
		char unknown_0x36E;
		char unknown_0x36F; // Undefined.
		float holdBreathTime;
		int unknown_0x374;
		MagicSourceCombo currentSpell;
		EquipmentStack currentEnchantedItem; // Not a pointer.
		EquipmentStack * readiedWeapon;
		EquipmentStack * readiedAmmo;
		EquipmentStack * readiedShield;
		EquipmentStack * torchSlot;
		char unknown_0x398;
		char unknown_0x399; // Undefined.
		char unknown_0x39A; // Undefined.
		char unknown_0x39B; // Undefined.
		void * arrowBone;
		int unknown_0x3A0;
		Vector3 unknown_0x3A4;

		//
		// vTable accessor functions.
		//

		bool onActorCollision(int collisionIndex);
		bool onObjectCollision(int collisionIndex, bool flag);
		bool onTerrainCollision(int collisionIndex);
		bool onActivatorCollision(int collisionIndex);

		SkillStatistic * getSkillStatistic(int skillId);
		float getSkillValue(int skillId);

		float applyArmorRating(float damage, float swing, bool damageEquipment);
		float calculateArmorRating(int * armorItemCount = nullptr);
		void applyHitModifiers(MobileActor * attacker, MobileActor * defender, float unknown, float swing, MobileProjectile * projectile = nullptr, bool unknown2 = false);

		//
		// Other related this-call functions.
		//

		Cell* getCell();

		float getFatigueTerm();

		void startCombat(MobileActor*);
		void stopCombat(bool);
		void onDeath();
		bool applyHealthDamage(float damage, bool flipDifficultyScale, bool scaleWithDifficulty, bool takeHealth);
		bool hasFreeAction();
		float calculateRunSpeed();
		float calculateSwimSpeed();
		float calculateSwimRunSpeed();
		float calculateFlySpeed();

		void updateDerivedStatistics(Statistic * baseStatistic);

		int determineModifiedPrice(int basePrice, bool buying);

		void playVoiceover(int);
		void startDialogue();

		bool isAffectedByAlchemy(Alchemy * alchemy);
		bool isAffectedByEnchantment(Enchantment * enchantment);
		bool isAffectedBySpell(Spell * spell);

		Iterator<Spell> * getCombatSpellList();

		bool isActive();
		void setCurrentMagicSourceFiltered(Object * magic);
		void setActionTarget(MobileActor * target);

		void dropItem(Object * item, ItemData * itemData = nullptr, int count = 1, bool exact = true);

		// Always returns false for non-MACH.
		bool persuade(int random, int persuasionIndex);

		//
		// Custom functions.
		//

		bool getMobileActorFlag(MobileActorFlag::Flag);
		void setMobileActorFlag(MobileActorFlag::Flag, bool);

		bool getMobileActorMovementFlag(ActorMovement::Flag);
		void setMobileActorMovementFlag(ActorMovement::Flag, bool);

		bool equipItem(Object* item, ItemData * itemData = nullptr, bool addItem = false, bool selectBestCondition = false, bool selectWorstCondition = false);
	};
	static_assert(sizeof(MobileActor::ActiveMagicEffects) == 0xC, "TES3::MobileActor::ActiveMagicEffects failed size validation");
	static_assert(sizeof(MobileActor::ActiveMagicEffect) == 0x18, "TES3::MobileActor::ActiveMagicEffect failed size validation");
	static_assert(sizeof(MobileActor) == 0x3B0, "TES3::MobileActor failed size validation");
}
