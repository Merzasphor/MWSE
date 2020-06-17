#include "NINode.h"

#include "NIDynamicEffect.h"

namespace NI {
	const auto NI_Node_ctor = reinterpret_cast<void(__thiscall*)(const Node*)>(0x6C81E0);

	Node::Node() {
		NI_Node_ctor(this);
	}

	Node::~Node() {
		// Call dtor without deletion.
		vTable.asObject->destructor(this, 0);
	}

	void Node::attachChild(AVObject * child, bool useFirstAvailable) {
		vTable.asNode->attachChild(this, child, useFirstAvailable);
	}

	void Node::detachChild(AVObject ** out_detached, AVObject * child) {
		vTable.asNode->detachChild(this, out_detached, child);
	}

	void Node::detachChildAt(AVObject ** out_detached, unsigned int index) {
		vTable.asNode->detachChildAt(this, out_detached, index);
	}

	void Node::setChildAt(AVObject ** out_detached, unsigned int index, AVObject * child) {
		vTable.asNode->setChildAt(this, out_detached, index, child);
	}

	const auto NI_Node_AttachEffect = reinterpret_cast<void(__thiscall*)(Node*, DynamicEffect*)>(0x6C91E0);
	void Node::attachEffect(DynamicEffect * effect ) {
		NI_Node_AttachEffect(this, effect);
	}

	const auto NI_Node_DetachEffect = reinterpret_cast<void(__thiscall*)(Node*, DynamicEffect*)>(0x6C9220);
	void Node::detachEffect(DynamicEffect* effect) {
		NI_Node_DetachEffect(this, effect);
	}

	Pointer<DynamicEffect> Node::getEffect(int type) {
		auto effectNode = &effectList;
		while (effectNode) {
			if (effectNode->data && effectNode->data->getType() == type) {
				return effectNode->data;
			}

			effectNode = effectNode->next;
		}

		return nullptr;
	}
}
