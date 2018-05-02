#pragma once

#include "TES3Object.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct MobileProjectile_vTable {
		void * destructor; // 0x0
		void * save; // 0x4
		void * unknown_0x8;
		void * unknown_0xC;
		void * unknown_0x10;
		void * unknown_0x14;
		void * resolveCollisions; // 0x18
		void * unknown_0x1C;
		void * simulate; // 0x20
		void * isActor; // 0x24
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
		void * unknown_0x70;
		void * setActorFlag8; // 0x74
		void * setActorFlag40; // 0x78
		void * unknown_0x7C;
		char (__thiscall * onActorCollision)(MobileProjectile*, int); // 0x80
		void * unknown_0x84;
		void * unknown_0x88;
		void * unknown_0x8C;
		void * unknown_0x90;
		void * unknown_0x94;
	};
	static_assert(sizeof(MobileProjectile_vTable) == 0x98, "TES3::MobileProjectile_vTable failed size validation");

	struct MobileProjectile {
		MobileProjectile_vTable * vTable; // 0x0
		TES3::ObjectType::ObjectType objectType; // 0x4
		unsigned short movementFlags; // 0x8
		unsigned short preMovementFlags; // 0xA
		int unknown_0xC;
		unsigned int actorFlags; // 0x10
		Reference* reference; // 0x14
		int unknown_0x18;
		short cellX; // 0x1C
		short cellY; // 0x1E
		short unknown_0x20;
		short unknown_0x22;
		short unknown_0x24;
		short unknown_0x26;
		short unknown_0x28;
		float height; // 0x2C
		Vector3 unknown_0x30;
		Vector3 unknown_0x3C;
		Vector3 unknown_0x48;
		Vector3 position; // 0x54
		void * unknown_0x60;
		Vector3 unknown_0x64;
		short disposition; // 0x70
		char padding_0x72[2];
		int unknown_0x74;
		int unknown_0x78;
		int unknown_0x7C;
		MobileActor* firingActor; // 0x80
		Weapon* firingWeapon; // 0x84
		unsigned char flagExpire; // 0x88
		char padding_0x89[3];
		int unknown_0x8C;
		int unknown_0x90;
		int unknown_0x94;
		int unknown_0x98;
		int unknown_0x9C;
		int unknown_0xA0;
		int unknown_0xA4;
		int unknown_0xA8;

		//
		// vTable accessor functions.
		//

		char onActorCollision(int);

	};
	static_assert(sizeof(MobileProjectile) == 0xAC, "TES3::MobileProjectile failed size validation");
}
