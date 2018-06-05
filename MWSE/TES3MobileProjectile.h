#pragma once

#include "TES3Defines.h"

#include "TES3MobileObject.h"
#include "TES3Vectors.h"

namespace TES3 {

	struct MobileProjectile : MobileObject {
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

		signed char onActorCollision(int hitReferenceIndex);
		signed char onObjectCollision(int hitReferenceIndex, signed char flag);
		signed char onTerrainCollision(int hitReferenceIndex);
		signed char onWaterCollision(int hitReferenceIndex);

	};
	static_assert(sizeof(MobileProjectile) == 0xAC, "TES3::MobileProjectile failed size validation");
}
