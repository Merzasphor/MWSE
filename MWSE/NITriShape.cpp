#include "NITriShape.h"

namespace NI {
	TriShapeData* TriShape::getModelData() {
		return modelData;
	}

	void TriShape::setModelData(TriShapeData* data) {
		vTable.asTriShape->setModelData(this, data);
	}
}
