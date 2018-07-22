#include "NINode.h"

namespace NI {
	void Node::attachChild(AVObject * child, bool useFirstAvailable) {
		vTable.asNode->attachChild(this, child, useFirstAvailable);
	}

	void Node::detachChild(AVObject ** out_detached, AVObject * child) {
		vTable.asNode->detachChild(this, out_detached, child);
	}

	void Node::detachChildAt(AVObject ** out_detached, unsigned int index) {
		vTable.asNode->detachChildAt(this, out_detached, index);
	}
}
