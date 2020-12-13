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

	Pointer<Node> Node::create() {
		return new Node();
	}

	const auto NI_CreateBoundingBoxForNode = reinterpret_cast<void(__cdecl*)(const Node*, TES3::Vector3*, TES3::Vector3*, TES3::Vector3*, TES3::Matrix33*, float*)>(0x4EF410);
	TES3::BoundingBox Node::createBoundingBox_lua(sol::optional<float> _scale) const {
		TES3::BoundingBox bb;
		bb.minimum.x = FLT_MAX;
		bb.minimum.y = FLT_MAX;
		bb.minimum.z = FLT_MAX;
		bb.maximum.x = FLT_MIN;
		bb.maximum.y = FLT_MIN;
		bb.maximum.z = FLT_MIN;
		float scale = _scale.value_or(1.0f);
		NI_CreateBoundingBoxForNode(this, &bb.minimum, &bb.maximum, (TES3::Vector3*)0x7DE6CC, (TES3::Matrix33*)0x7DE664, &scale);
		return bb;
	}

	Pointer<AVObject> Node::detachChildHandled(AVObject* child) {
		AVObject* returnedChild = nullptr;
		detachChild(&returnedChild, child);
		return returnedChild;
	}

	Pointer<AVObject> Node::detachChildAtHandled(size_t index) {
		AVObject* returnedChild = nullptr;
		detachChildAt(&returnedChild, index);
		return returnedChild;
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

	void Node::attachChild_lua(AVObject* child, sol::optional<bool> useFirstAvailable) {
		attachChild(child, useFirstAvailable.value_or(false));
		updateProperties();
	}

	Pointer<AVObject> Node::detachChildAt_lua(size_t index) {
		if (index == 0) {
			throw std::invalid_argument("This function is 1-indexed. Cannot accept a param less than 1.");
		}
		return detachChildAtHandled(index - 1);
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::Node)
