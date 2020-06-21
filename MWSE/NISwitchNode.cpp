#include "NISwitchNode.h"

namespace NI {
	int SwitchNode::getSwitchIndex() {
		return switchIndex;
	}

	void SwitchNode::setSwitchIndex(int index) {
		if (index < 0 || index >(children.filledCount - 1) || children.storage[index] == nullptr) {
			throw std::exception("Attempted to set switchIndex beyond bounds!");
		}
		switchIndex = index;
	}
}
