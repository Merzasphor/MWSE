#include "TES3Container.h"

namespace TES3 {
	float ContainerInstance::getCapacity() {
		return container->capacity;
	}

	void ContainerInstance::setCapacity(float value) {
		container->capacity = value;
	}
}
