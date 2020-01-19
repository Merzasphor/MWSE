#include "NIGeometryData.h"

namespace NI {
	unsigned short GeometryData::getVertexCount() {
		return vTable.asGeometryData->getVertexCount(this);
	}
}
