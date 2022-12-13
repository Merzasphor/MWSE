#pragma once

#include "NIDefines.h"
#include "NIPointer.h"
#include "NITArray.h"
#include "NINode.h"

#include "NIColor.h"
#include "NIVector2.h"
#include "NIVector3.h"

namespace NI {
	enum class PickType {
		FIND_ALL,
		FIND_FIRST
	};

	enum class PickSortType {
		SORT,
		NO_SORT
	};

	enum class PickIntersectType {
		BOUND_INTERSECT,
		TRIANGLE_INTERSECT
	};

	enum class PickCoordinateType {
		MODEL_COORDINATES,
		WORLD_COORDINATES
	};

	struct Pick {
		PickType pickType;
		PickSortType sortType;
		PickIntersectType intersectType;
		PickCoordinateType coordinateType;
		bool frontOnly;
		bool observeAppCullFlag;
		bool unknown_0x12;
		Pointer<Node> root;
		TArray<PickRecord*> results;
		PickRecord* lastAddedRecord;
		bool returnTexture;
		bool returnNormal;
		bool returnSmoothNormal;
		bool returnColor;

		//
		// Other related this-call functions.
		//

		Pick();
		~Pick();

		bool pickObjects(const Vector3* origin, const Vector3* direction, bool append = false, float maxDistance = 0.0f);
		void clearResults();

	};
	static_assert(sizeof(Pick) == 0x38, "NI::Pick failed size validation");

	struct PickRecord {
		AVObject* object;
		AVObject* proxyParent;
		Vector3 intersection;
		float distance;
		unsigned short triangleIndex;
		unsigned short vertexIndex[3];
		Vector2 texture;
		Vector3 normal;
		PackedColor color;

		//
		// Custom functions.
		//

		std::reference_wrapper<unsigned short[3]> getVertexIndex();

#if defined(SE_IS_MWSE) && SE_IS_MWSE == 1
		Reference* getTES3Reference();
#endif

	};
	static_assert(sizeof(PickRecord) == 0x38, "NI::PickRecord failed size validation");
}
