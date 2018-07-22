#include "NINode.h"

namespace NI {
	void Node::attachChild(AVObject * child, bool useFirstAvailable) {
		vTable.asNode->attachChild(this, child, useFirstAvailable);
	}

	AVObject * Node::detachChild(AVObject * child) {
		return vTable.asNode->detachChild(this, child);
	}

	AVObject * Node::detachChildAt(unsigned int index) {
		return vTable.asNode->detachChildAt(this, index);
	}
}
