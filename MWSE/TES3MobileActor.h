#pragma once

#include "TES3Object.h"
#include "TES3ActionData.h"
#include "TES3Collections.h"
#include "TES3Statistic.h"
#include "TES3Vectors.h"

namespace TES3 {
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

	namespace MobileActorFlag {
		enum MobileActorFlag {
			ActiveAI = 0x4,
			Werewolf = 0x400,
			Underwater = 0x800,
			WeaponDrawn = 0x2000,
			SpellReadied = 0x4000,
			InCombat = 0x10000,
			Attacked = 0x20000,
			IsCrittable = 0x8000000,
			IdleAnim = 0x10000000
		};

		enum MobileActorFlagBit {
			ActiveAIBit = 2,
			WerewolfBit = 10,
			UnderwaterBit = 11,
			WeaponDrawnBit = 13,
			SpellReadiedBit = 14,
			InCombatBit = 16,
			AttackedBit = 17,
			IsCrittableBit = 27,
			IdleAnimBit = 28
		};
	}

	namespace ActorMovement {
		enum ActorMovement {
			Foreward = 0x1,
			Back = 0x2,
			Left = 0x4,
			Right = 0x8,
			TurnLeft = 0x10,
			TurnRight = 0x20,
			Walking = 0x100,
			Running = 0x200,
			Crouching = 0x400,
			Swimming = 0x800,
			Jumping = 0x1000,
			Flying = 0x2000,
			Jumped = 0x4000
		};

		enum ActorMovementBit {
			ForewardBit = 0,
			BackBit = 1,
			LeftBit = 2,
			RightBit = 3,
			TurnLeftBit = 4,
			TurnRightBit = 5,
			WalkingBit = 8,
			RunningBit = 9,
			CrouchingBit = 10,
			SwimmingBit = 11,
			JumpingBit = 12,
			FlyingBit = 13,
			JumpedBit = 14
		};
	}

	struct MobileActor {
		void * vTable; // 0x0
		ObjectType::ObjectType objectType; // 0x4
		short movementFlags; // 0x8
		short prevMovementFlags; // 0xA
		short unknown_0xC;
		short unknown_0xE; // Undefined.
		int actorFlags; // 0x10
		Reference * reference; // 0x14
		void * unknown_0x18;
		short cellX; // 0x1C
		short cellY; // 0x1E
		short unknown_0x20;
		short unknown_0x22;
		short unknown_0x24;
		short unknown_0x26;
		float unknown_0x28;
		float height; // 0x2C
		Vector3 boundSize; // 0x30
		Vector3 velocity; // 0x3C
		Vector3 impulseVelocity; // 0x48
		Vector3 position; // 0x54
		void * unknown_0x60;
		int unknown_0x64;
		Vector3 unknown_0x68;
		float unknown_0x74;
		int unknown_0x78;
		int unknown_0x7C;
		Iterator<MobileActor> listTargetActors; // 0x80
		Iterator<MobileActor> listFriendlyActors; // 0x94
		float scanTimer; // 0xA8
		int scanInterval; // 0xAC
		int greetTimer; // B0
		Vector3 unknown_0xB4;
		char unknown_0xC0;
		char unknown_0xC1; // Undefined.
		char unknown_0xC2; // Undefined.
		char unknown_0xC3; // Undefined.
		float unknown_0xC4;
		void * aiPackageData; // 0xC8
		ActionData actionData; // 0xCC
		ActionData actionBeforeCombat; // 0x13C
		int unknown_0x1AC;
		int unknown_0x1B0;
		int unknown_0x1B4;
		int unknown_0x1B8;
		int unknown_0x1BC;
		void * aiCombatData; // 0x1C0
		char unknown_0x1C4;
		char unknown_0x1C5;
		char unknown_0x1C6;
		char unknown_0x1C7;
		void * activeMagicEffects; // 0x1C8 // Maybe?
		int activeMagicEffectCount; // 0x1CC
		int unknown_0x1D0;
		char unknown_0x1D4;
		char unknown_0x1D5; // Undefined.
		char unknown_0x1D6; // Undefined.
		char unknown_0x1D7; // Undefined.
		float unknown_0x1D8;
		Vector3 unknown_0x1DC;
		Vector3 unknown_0x1E8;
		Vector3 unknown_0x1F4;
		int unknown_0x200;
		int unknown_0x204;
		int unknown_0x208;
		short unknown_0x20C;
		short unknown_0x20E;
		short unknown_0x210;
		char unknown_0x212;
		char unknown_0x213;
		HashMap powers;
		char unknown_0x224;
		char unknown_0x225;
		char unknown_0x226;
		signed char nextActionWeight; // 0x227
		signed char actorType; // 0x228
		char unknown_0x229;
		char unknown_0x22A; // Undefined.
		char unknown_0x22B; // Undefined.
		int lastGroundZ; // 0x22C
		int unknown_0x230;
		Reference * collidingReference; // 0x234
		int unknown_0x238;
		int unknown_0x23C;
		int unknown_0x240;
		void * animationData; // 0x244
		char unknown_0x248;
		char unknown_0x249; // Undefined.
		char unknown_0x24A; // Undefined.
		char unknown_0x24B; // Undefined.
		void * unknown_0x24C;
		int unknown_0x250;
		Statistic attributes[8];
		Statistic health;
		Statistic magicka;
		Statistic encumbrance;
		Statistic fatigue;
		Statistic magickaMultiplier;
		int attackBonus;
		int sanctuary;
		int resistMagicka;
		int resistFire;
		int resistFrost;
		int resistShock;
		int resistCommonDisease;
		int resistBlightDisease;
		int resistCorprus;
		int resistPoison;
		int resistParalysis;
		int chameleon;
		int resistNormalWeapons;
		int waterBreathing;
		int waterWalking;
		int swiftSwim;
		int jump;
		int levitate;
		int shield;
		int sound;
		int silence;
		int blind;
		int paralyze;
		int invisibility;
		int fight;
		int flee;
		int hello;
		int alarm;
		int barterGold;
		short widthInUnits;
		short unknown_0x366;
		short readiedAmmoCount;
		short corpseHourstamp;
		short greetDuration;
		char unknown_0x36E;
		char unknown_0x36F; // Undefined.
		float holdBreathTime;
		int unknown_0x374;
		Spell * currentSpell;
		unsigned char spellSource;
		char unknown_0x37D; // Undefined.
		char unknown_0x37E; // Undefined.
		char unknown_0x37F; // Undefined.
		Item * currentEnchItem;
		ItemData * currentEnchItemData;
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
	};
	static_assert(sizeof(MobileActor) == 0x3B0, "TES3::MobileActor failed size validation");
}
