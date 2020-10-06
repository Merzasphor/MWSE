#pragma once

#include "TES3Defines.h"

#include "TES3IteratedList.h"

#include "NINode.h"

namespace TES3 {
	struct Object_0x751248 {
		int unknown_0x0;
		int unknown_0x4;
		int unknown_0x8;
		int unknown_0xC;
		int unknown_0x10;
		int unknown_0x14;
	};
	static_assert(sizeof(Object_0x751248) == 0x18, "TES3::Object_0x751248 failed size validation");

	struct MobController_0x0 {
		Object_0x751248 unknown_0x0;
		Object_0x751248 unknown_0x18;
	};
	static_assert(sizeof(MobController_0x0) == 0x30, "TES3::MobController_0x0 failed size validation");

	struct ProcessManager {
		MobilePlayer * mobilePlayer; // 0x0
		IteratedList<MobileActor*> unknown_0x4;
		bool unknown_0x18;
		bool unknown_0x19; // Maybe force new actions?
		_RTL_CRITICAL_SECTION criticalSection; // 0x1C
		unsigned char unknown[0x7F8]; // 0x34
		float aiDistance; // 0x82C

		//
		// Related this-call functions.
		//

		bool detectPresence(MobileActor * actor, bool unknown = true);
		bool detectSneak(MobileActor* detector, MobileActor* target, bool unknown = true);
		void checkRadius(MobileActor * actor, IteratedList<AIPlanner*> * container);
		void checkPlayerDistance();

		float getAIDistanceScale() const;
		void setAIDistanceScale(float scalar);

	};
	static_assert(sizeof(ProcessManager) == 0x830, "TES3::MobController_0x24 failed size validation");

	struct ProjectileController {
		IteratedList<MobileProjectile*> activeProjectiles; // 0x0
		NI::Pointer<NI::Node> worldProjectileRoot; // 0x14
		_RTL_CRITICAL_SECTION criticalSection; // 0x18
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
	};
	static_assert(sizeof(ProjectileController) == 0x3C, "TES3::ProjectileController failed size validation");

	struct MobController {
		MobController_0x0 * unknown_0x0;
		int unknown_0x4;
		int unknown_0x8;
		float gravity; // 0xC
		int unknown_0x10;
		int unknown_0x14;
		float unknown_0x18; // Initialized to -4005.5
		float unknown_0x1C; // Initialized to 46 degrees.
		float unknown_0x20; // Initialized to cos(46 degrees)
		ProcessManager * processManager; // Mobile actor controller?
		ProjectileController* projectileController; // 0x28
		bool unknown_0x2C;
		IteratedList<void*> unknown_0x30;
		int unknown_0x44;
		int unknown_0x48;
		int unknown_0x4C;
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		int unknown_0x6C;
		int unknown_0x70;
		int unknown_0x74;
		int unknown_0x78;
		int unknown_0x7C;
		int unknown_0x80;
		int unknown_0x84;
		int unknown_0x88;

		//
		// Related this-call functions.
		//

		void addMob(Reference * reference);
		void removeMob(Reference * reference);

		void checkPlayerDistance();

	};
	static_assert(sizeof(MobController) == 0x8C, "TES3::MobController failed size validation");
}
