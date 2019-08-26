#pragma once

#include "sol_forward.hpp"

#include "TES3Defines.h"

#include "NINode.h"
#include "NIPointer.h"
#include "TES3Object.h"
#include "TES3Vectors.h"

namespace TES3 {
	namespace MobileActorFlag {
		typedef unsigned int value_type;

		enum Flag : value_type {
			ActiveAI = 0x4,
			Werewolf = 0x400,
			Underwater = 0x800,
			WeaponDrawn = 0x2000,
			SpellReadied = 0x4000,
			InCombat = 0x10000,
			Attacked = 0x20000,
			IsCrittable = 0x8000000,
			IdleAnim = 0x10000000,
			BodypartsChanged = 0x80000000
		};

		enum FlagBit {
			ActiveAIBit = 2,
			WerewolfBit = 10,
			UnderwaterBit = 11,
			WeaponDrawnBit = 13,
			SpellReadiedBit = 14,
			InCombatBit = 16,
			AttackedBit = 17,
			IsCrittableBit = 27,
			IdleAnimBit = 28,
			BodypartsChangedBit = 31
		};
	}

	namespace ActorMovement {
		typedef unsigned short value_type;

		enum Flag : value_type {
			Forward = 0x1,
			Back = 0x2,
			Left = 0x4,
			Right = 0x8,
			TurnLeft = 0x10,
			TurnRight = 0x20,
			Walking = 0x100,
			Running = 0x200,
			Sneaking = 0x400,
			Swimming = 0x800,
			Jumping = 0x1000,
			Flying = 0x2000,
			Jumped = 0x4000
		};

		enum FlagBit {
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

	struct MobileObject_vTable {
		void * destructor; // 0x0
		void * save; // 0x4
		void * unknown_0x8;
		void * unknown_0xC;
		void * unknown_0x10;
		void * unknown_0x14;
		void * resolveCollisions; // 0x18
		void * unknown_0x1C;
		void * simulate; // 0x20
		bool (__thiscall * isActor)(MobileObject*); // 0x24
		void * unknown_0x28;
		void * unknown_0x2C;
		void * unknown_0x30;
		void * unknown_0x34;
		void * unknown_0x38;
		void * unknown_0x3C;
		void * setPosition; // 0x40
		void * setFacing; // 0x44
		void * setorientation; // 0x48
		void * setReference; // 0x4C
		void * jumpingFalling; // 0x50
		void * unknown_0x54;
		void * unknown_0x58;
		void * unknown_0x5C;
		void * unknown_0x60;
		void * setJumping; // 0x64
		void * unknown_0x68;
		void * waterImpact; // 0x6C
		void (__thiscall * enterLeaveSimulation)(MobileObject*, bool); // 0x70
		void * setActorFlag8; // 0x74
		void * setActorFlag40; // 0x78
		void * unknown_0x7C;
		bool (__thiscall * onActorCollision)(MobileProjectile*, int); // 0x80
		bool (__thiscall * onObjectCollision)(MobileProjectile*, int, bool); // 0x84
		bool (__thiscall * onTerrainCollision)(MobileProjectile*, int); // 0x88
		bool (__thiscall * onWaterCollision)(MobileProjectile*, int); // 0x8C
		bool (__thiscall * onActivatorCollision)(MobileProjectile*, int); // 0x90
		void * unknown_0x94;
	};
	static_assert(sizeof(MobileObject_vTable) == 0x98, "TES3::MobileObject_vTable failed size validation");

	struct MobileActor_vTable : MobileObject_vTable {
		void * initializeStats; // 0x98
		void * getDispositionRaw; // 0x9C
		void * calculateNPCWidth; // 0xA0
		void * calculateNPCHeight; // 0xA4
		void * unknown_0xA8; // 0xA8
		bool(__thiscall * is3rdPerson)(MobileActor*); // 0xAC
		void * changeWerewolf; // 0xB0
		void * calculateWalkSpeed; // 0xB4
		void * onDeath; // 0xB8
		void * calculateAttackMin; // 0xBC
		void * calculateAttackMax; // 0xC0
		void * calculateWeaponDamage; // 0xC4
		void * getWeaponSwingWeightProduct; // 0xC8
		void * getReferenceData0; // 0xCC
		SkillStatistic * (__thiscall * getSkillStatistic)(MobileActor*, int); // 0xD0
		float(__thiscall * getSkillValue)(MobileActor*, int); // 0xD4
		void * unknown_0xD8;
		void * unknown_0xDC;
		float(__thiscall * applyArmorRating)(MobileActor*, float, float, bool); // 0xE0
		float(__thiscall * calculateArmorRating)(MobileActor*, int*); // 0xE4
		void * getReadiedWeaponCurrentSkill; // 0xE8
		void * getReadiedWeaponAnimationGroup; // 0xEC
		void * onWeaponEquip; // 0xF0
		void * onReleaseProjectile; // 0xF4
		void * onNewProjectile; // 0xF8
		void * resolveArrowBone; // 0xFC
		void * setArrowBone; // 0x100
		void * unknown_0x104; // 0x104
	};
	static_assert(sizeof(MobileActor_vTable) == 0x108, "TES3::MobileActor_vTable failed size validation");

	struct MobileNPC_vTable : MobileActor_vTable {
		void * unpackSkillValues; // 0x108
		int (__thiscall * getDisposition)(MobileNPC*); // 0x10C
	};
	static_assert(sizeof(MobileNPC_vTable) == 0x110, "TES3::MobileNPC_vTable failed size validation");

	struct MobileObject {
		struct Collision {
			bool valid;
			float fTime;
			TES3::Vector3 point;
			TES3::Vector3 objectPosAtCollision;
			TES3::Vector3 velocity;
			NI::Pointer<NI::Node> colliderRoot;
			TES3::Reference * colliderRef;
			NI::Pointer<NI::Node> node_34;
			short quantizedNormal[3];
			unsigned char collisionType;
			unsigned char unknown_3F;
		};

		union {
			MobileObject_vTable * mobileObject;
			MobileActor_vTable * mobileActor;
			MobileNPC_vTable * mobileNPC;
		} vTable; // 0x0
		ObjectType::ObjectType objectType; // 0x4
		mwse::bitset16 movementFlags; // 0x8
		mwse::bitset16 prevMovementFlags; // 0xA
		short unknown_0xC;
		short unknown_0xE; // Undefined.
		mwse::bitset32 actorFlags; // 0x10
		Reference * reference; // 0x14
		Collision * arrayCollisionResults; // 0x18
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
		void * collisionGroup;
		float thisFrameDistanceMoved;
		Vector3 thisFrameDeltaPosition;
		float unknown_0x74;
		void * lightMagicEffectData;
		unsigned char countCollisionResults;

		//
		// vTable accessor functions.
		//

		bool onActorCollision(int collisionIndex);
		bool onObjectCollision(int collisionIndex, bool flag);
		bool onTerrainCollision(int collisionIndex);
		bool onWaterCollision(int collisionIndex);
		bool onActivatorCollision(int collisionIndex);

		bool isActor();
		void enterLeaveSimulation(bool entering);

		//
		// Other related this-call functions.
		//

		void enterLeaveSimulationByDistance();

		//
		// Lua interface functions.
		//

		void setImpulseVelocityFromLua(sol::stack_object);
		void setPositionFromLua(sol::stack_object);
		void setVelocityFromLua(sol::stack_object);

	};
	static_assert(sizeof(MobileObject) == 0x80, "TES3::MobileObject failed size validation");
	static_assert(sizeof(MobileObject::Collision) == 0x40, "TES3::MobileObject::Collision failed size validation");
}
