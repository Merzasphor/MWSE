#include "CSBaseObject.h"

namespace se::cs {
	const char* BaseObject::getObjectID() const {
		return vtbl.baseObject->getObjectID(this);
	}

	void BaseObject::setModified(bool modified) {
		vtbl.baseObject->setObjectModified(this, modified);
	}

	void BaseObject::setFlag80(bool set) {
		const auto BaseObject_setFlag80 = reinterpret_cast<void(__thiscall*)(BaseObject*, bool)>(0x4019E7);
		BaseObject_setFlag80(this, set);
	}
}
