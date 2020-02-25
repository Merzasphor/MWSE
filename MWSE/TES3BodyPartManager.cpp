#include "TES3BodyPartManager.h"

namespace TES3 {
	const auto TES3_BodyPartManager_getActiveBodyPartForItem = reinterpret_cast<BodyPartManager::ActiveBodyPart * (__thiscall*)(BodyPartManager*, Item*)>(0x472DA0);
	BodyPartManager::ActiveBodyPart* BodyPartManager::getActiveBodyPartForItem(Item* item) {
		return TES3_BodyPartManager_getActiveBodyPartForItem(this, item);
	}

	const auto TES3_BodyPartManager_getActiveBodyPartNode = reinterpret_cast<NI::Node * (__thiscall*)(BodyPartManager*, BodyPartManager::ActiveBodyPart::Layer, BodyPartManager::ActiveBodyPart::Index)>(0x473030);
	NI::Node* BodyPartManager::getActiveBodyPartNode(ActiveBodyPart::Layer layer, ActiveBodyPart::Index index) {
		return TES3_BodyPartManager_getActiveBodyPartNode(this, layer, index);
	}

	const auto TES3_BodyPartManager_setActivePartData = reinterpret_cast<void(__thiscall*)(BodyPartManager*, BodyPartManager::ActiveBodyPart::Layer, BodyPartManager::ActiveBodyPart::Index, bool, NI::Node*)>(0x472EA0);
	void BodyPartManager::setActivePartData(ActiveBodyPart::Layer layer, ActiveBodyPart::Index index, bool overwriteData, NI::Node* node) {
		TES3_BodyPartManager_setActivePartData(this, layer, index, overwriteData, node);
	}

	const auto TES3_BodyPartManager_setBodyPartForItem = reinterpret_cast<void(__thiscall*)(BodyPartManager*, Item*, BodyPartManager::ActiveBodyPart::Index, BodyPart*, int)>(0x473CB0);
	void BodyPartManager::setBodyPartForItem(Item* item, ActiveBodyPart::Index index, BodyPart* bodyPart, bool isFirstPerson) {
		TES3_BodyPartManager_setBodyPartForItem(this, item, index, bodyPart, isFirstPerson);
	}

	const auto TES3_BodyPartManager_setBodyPartByIdForItem = reinterpret_cast<void(__thiscall*)(BodyPartManager*, Item*, BodyPartManager::ActiveBodyPart::Index, const char*, int)>(0x473C80);
	void BodyPartManager::setBodyPartByIdForItem(Item* item, ActiveBodyPart::Index index, const char* bodyPartId, bool isFirstPerson) {
		TES3_BodyPartManager_setBodyPartByIdForItem(this, item, index, bodyPartId, isFirstPerson);
	}

	const auto TES3_BodyPartManager_removeEquippedLayers = reinterpret_cast<void(__thiscall*)(BodyPartManager*)>(0x472D70);
	void BodyPartManager::removeEquippedLayers() {
		TES3_BodyPartManager_removeEquippedLayers(this);
	}

	const auto TES3_BodyPartManager_updateForReference = reinterpret_cast<void(__thiscall*)(BodyPartManager*, Reference*)>(0x473EA0);
	void BodyPartManager::updateForReference(Reference* reference) {
		TES3_BodyPartManager_updateForReference(this, reference);
	}
}
