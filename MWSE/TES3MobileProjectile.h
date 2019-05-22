#pragma once

#include "TES3Defines.h"

#include "TES3MobileObject.h"
#include "TES3Vectors.h"

namespace TES3 {

	struct MobileProjectile : MobileObject {
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

		bool onActorCollision(int collisionIndex);
		bool onObjectCollision(int collisionIndex, bool flag);
		bool onTerrainCollision(int collisionIndex);
		bool onWaterCollision(int collisionIndex);

	};
	static_assert(sizeof(MobileProjectile) == 0xAC, "TES3::MobileProjectile failed size validation");
}
