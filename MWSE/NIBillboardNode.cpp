#include "NIBillboardNode.h"

#include "NICamera.h"

namespace NI {
	const auto BillboardNode_vTable = reinterpret_cast<Node_vTable*>(0x746B00);
	BillboardNode::BillboardNode() : Node() {
		vTable.asNode = BillboardNode_vTable;
		savedTime = 0.0f;
		updateControllers = true;
		flags |= BillboardNodeFlags::RotateAboutUp;
	}

	Pointer<BillboardNode> BillboardNode::create() {
		return new BillboardNode();
	}

	const auto NI_BillboardNode_rotateToCamera = reinterpret_cast<void(__thiscall*)(BillboardNode*, Camera*)>(0x6D3C00);
	void BillboardNode::rotateToCamera(Camera* camera) {
		NI_BillboardNode_rotateToCamera(this, camera);
	}

	unsigned int BillboardNode::getMode() const {
		return (flags & BillboardNodeFlags::Mask) >> BillboardNodeFlags::ModeBit;
	}

	void BillboardNode::setMode(unsigned int mode) {
		auto f = mode << BillboardNodeFlags::ModeBit;
		flags = (flags & ~BillboardNodeFlags::Mask) | (f & BillboardNodeFlags::Mask);
	}
}