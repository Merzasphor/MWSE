#include "TES3Container.h"

namespace TES3 {
	const auto TES3_ContainerInstance_onCloseInventory = reinterpret_cast<void (__thiscall*)(Actor *, Reference *, int)>(0x4A4460);
	void ContainerInstance::onCloseInventory(Reference* reference, int unknown) {
		Actor::onCloseInventory(reference, unknown);
		TES3_ContainerInstance_onCloseInventory(this, reference, unknown);
	}

	float ContainerInstance::getCapacity() {
		return container->capacity;
	}

	void ContainerInstance::setCapacity(float value) {
		container->capacity = value;
	}
}
