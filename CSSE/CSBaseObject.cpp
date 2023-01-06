#include "CSBaseObject.h"

namespace se::cs {
	const char* BaseObject::getObjectID() const {
		return vtbl.baseObject->getObjectID(this);
	}

	bool BaseObject::getModified() const {
		return (flags & 0x2);
	}

	void BaseObject::setModified(bool modified) {
		vtbl.baseObject->setObjectModified(this, modified);
	}

	bool BaseObject::getDeleted() const {
		return (flags & 0x20);
	}

	bool BaseObject::getPersists() const {
		return (flags & 0x400);
	}

	bool BaseObject::getBlocked() const {
		return (flags & 0x2000);
	}

	void BaseObject::setFlag80(bool set) {
		const auto BaseObject_setFlag80 = reinterpret_cast<void(__thiscall*)(BaseObject*, bool)>(0x4019E7);
		BaseObject_setFlag80(this, set);
	}
}
