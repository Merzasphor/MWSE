#include "CSBaseObject.h"

namespace se::cs {
	const char* BaseObject::getObjectID() const {
		return vtbl.baseObject->getObjectID(this);
	}

	void BaseObject::setModified(bool modified) {
		vtbl.baseObject->setObjectModified(this, modified);
	}
}
