#pragma once

#include "NIDefines.h"

#include "TES3Collections.h"
#include "TES3Vectors.h"

namespace NI {
	namespace PickType {
		enum PickType {
			FIND_ALL,
			FIND_FIRST
		};
	}

	namespace PickSortType {
		enum PickSortType {
			SORT,
			NO_SORT
		};
	}

	namespace PickIntersectType {
		enum PickIntersectType {
			BOUND_INTERSECT,
			TRIANGLE_INTERSECT
		};
	}

	namespace PickCoordinateType {
		enum PickCoordinateType {
			MODEL_COORDINATES,
			WORLD_COORDINATES
		};
	}

	struct Pick {
		PickType::PickType pickType;
		PickSortType::PickSortType sortType;
		PickIntersectType::PickIntersectType intersectType;
		PickCoordinateType::PickCoordinateType coordinateType;
		bool frontOnly;
		bool observeAppCullFlag;
		bool unknown_0x12;
		Node * root;
		TES3::TArray<PickRecord> results;
		PickRecord * lastAddedRecord;
		bool returnTexture;
		bool returnNormal;
		bool returnSmoothNormal;
		bool returnColor;

		//
		// Other related this-call functions.
		//

		static Pick* malloc();
		void free();

		void pickObjects(TES3::Vector3 * origin, TES3::Vector3 * direction, bool append = false, float unknown = 0.0f);
		void clearResults();

	};
	static_assert(sizeof(Pick) == 0x38, "NI::Pick failed size validation");

	struct PickRecord {
		Node * object;
		Node * proxyParent;
		TES3::Vector3 intersection;
		float distance;
		unsigned short triangleIndex;
		unsigned short vertexIndex[3];
		TES3::Vector2 texture;
		TES3::Vector3 normal;
		int color;

		//
		// Other related this-call functions.
		//



	};
	static_assert(sizeof(PickRecord) == 0x38, "NI::PickRecord failed size validation");
}
