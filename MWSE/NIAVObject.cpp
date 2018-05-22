#include "NIAVObject.h"

namespace NI {
	AVObject * AVObject::getObjectByName(const char* name) {
		return vTable.asAVObject->getObjectByName(this, name);
	}
}
