#include "TES3NPC.h"

#include "TES3UIManager.h"

#include "TES3MobileNPC.h"
#include "TES3UIElement.h"

#define TES3_NPC_getDisposition 0x4DA330

#define TES3_UI_ID_MenuDialog 0x7D3442
#define TES3_UI_ID_MenuDialog_start_disposition 0x7D3486

namespace TES3 {
	float NPCBase::getDisposition(bool clamp = true) {
		return vTable.actor->getDispositionRaw(this);
	}

	unsigned char NPCInstance::getReputation() {
		return baseNPC->reputation;
	}

	void NPCInstance::setReputation(unsigned char value) {
		baseNPC->reputation = value;
	}

	short NPCInstance::getDisposition() {
		return disposition;
	}

	void NPCInstance::setDisposition(short value) {
		disposition = value;

		// Handle case where we're in dialog with this character.
		auto menuDialog = TES3::UI::findMenu(*reinterpret_cast<short*>(TES3_UI_ID_MenuDialog));
		auto serviceActor = TES3::UI::getServiceActor();
		if (menuDialog && serviceActor && serviceActor->actorType == TES3::MobileActorType::NPC && reinterpret_cast<TES3::MobileNPC*>(serviceActor)->npcInstance == this) {
			menuDialog->setProperty(static_cast<TES3::UI::Property>(*reinterpret_cast<short*>(TES3_UI_ID_MenuDialog_start_disposition)), disposition);
			TES3::UI::updateDialogDisposition();
		}
	}

	void NPCInstance::setFactionRank(unsigned char value) {
		baseNPC->factionRank = value;
	}
}
