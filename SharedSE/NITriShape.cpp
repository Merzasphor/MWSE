#include "NITriShape.h"

#include "NITriShapeData.h"

namespace NI {
	TriShapeData* TriShape::getModelData() const {
		return static_cast<TriShapeData*>(modelData.get());
	}
}
