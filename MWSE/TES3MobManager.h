#pragma once

#include "TES3Defines.h"

#include "TES3CriticalSection.h"
#include "TES3IteratedList.h"

#include "NINode.h"
#include "NICollisionGroup.h"

namespace TES3 {
	struct ProcessManager {
		MobilePlayer * mobilePlayer; // 0x0
		IteratedList<AIPlanner*> aiPlanners; // 0x4
		bool unknown_0x18;
		bool unknown_0x19; // Maybe force new actions?
		CriticalSection criticalSection; // 0x1C
		unsigned char unknown[0x18]; // 0x40
		unsigned int plannerCount; // 0x58
		AIPlanner * planners[500]; // 0x5C
		float aiDistance; // 0x82C

		ProcessManager() = delete;
		~ProcessManager() = delete;

		//
		// Related this-call functions.
		//

		bool detectPresence(MobileActor * actor, bool unknown = true);
		bool detectSneak(MobileActor * detector, MobileActor * target, bool unknown = true);
		void findActorsInProximity(Vector3 * position, float range, IteratedList<MobileActor*>* outputList);
		void checkAlarmRadius(MobileActor * actor, IteratedList<AIPlanner*> * container);
		void checkPlayerDistance();

		bool checkNearbyEnemiesAllowRest();

		float getAIDistanceScale() const;
		void setAIDistanceScale(float scalar);

	};
	static_assert(sizeof(ProcessManager) == 0x830, "TES3::ProcessManager failed size validation");

	struct ProjectileManager {
		IteratedList<MobileProjectile*> activeProjectiles; // 0x0
		NI::Pointer<NI::Node> worldProjectileRoot; // 0x14
		CriticalSection criticalSection; // 0x18

		ProjectileManager() = delete;
		~ProjectileManager() = delete;

		//
		// Custom functions.
		//

		void resolveCollisions(float deltaTime);
	};
	static_assert(sizeof(ProjectileManager) == 0x3C, "TES3::ProjectileManager failed size validation");

	struct MobManager {
		NI::CollisionGroup * mobCollisionGroup;
		Vector3 gravity; // 0x4
		Vector3 terminalVelocity; // Initialized to {0, 0, -4005.5}.
		float dotProductOfMaxClimableSlope; // Initialized to cos(46 degrees).
		float maxClimableSlopeDegrees; // Initialized to 46 degrees.
		ProcessManager* processManager; // 0x24
		ProjectileManager* projectileManager; // 0x28
		bool mobCollisionActive;
		IteratedList<Reference*> listMovingProps;
		CriticalSection criticalSection_Props;
		CriticalSection criticalSection_Mobs;

		MobManager() = delete;
		~MobManager() = delete;

		//
		// Related this-call functions.
		//

		void addMob(Reference * reference);
		void removeMob(Reference * reference);

		void checkPlayerDistance();

		void addPlayerAsCollider();

		//
		// Custom functions.
		//

		bool hasMobileCollision(const MobileActor* mobile);
		void enableMobileCollision(MobileActor* mobile);
		void disableMobileCollision(MobileActor* mobile);
	};
	static_assert(sizeof(MobManager) == 0x8C, "TES3::MobManager failed size validation");
}
