#include "TES3NPC.h"

#include "TES3UIManager.h"

#include "TES3MobileNPC.h"
#include "TES3UIElement.h"

#include "LuaManager.h"
#include "LuaIsGuardEvent.h"

#define TES3_UI_ID_MenuDialog 0x7D3442
#define TES3_UI_ID_MenuDialog_start_disposition 0x7D3486

namespace TES3 {
	//
	// NPC Base
	//

	int NPCBase::getBaseDisposition(bool clamp = true) {
		return vTable.actor->getDispositionRaw(this);
	}


	const auto TES3_NPCBase_isGuard = reinterpret_cast<bool(__thiscall*)(NPCBase*)>(0x04DA5E0);
	bool NPCBase::isGuard() {
		bool isGuard = TES3_NPCBase_isGuard(this);

		// Trigger isGuard event.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		auto stateHandle = luaManager.getThreadSafeStateHandle();
		sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::IsGuardEvent(this, isGuard));
		if (eventData.valid()) {
			isGuard = eventData.get<bool>("isGuard");
		}

		return isGuard;
	}

	//
	// NPC Instance
	//

	const auto TES3_NPCInstance_calculateDisposition = reinterpret_cast<int (__thiscall*)(const NPCInstance*, bool)>(0x4DA330);
	int NPCInstance::getDisposition(bool clamp) {
		return TES3_NPCInstance_calculateDisposition(this, clamp);
	}

	unsigned char NPCInstance::getReputation() {
		return baseNPC->reputation;
	}

	void NPCInstance::setReputation(unsigned char value) {
		baseNPC->reputation = value;
	}

	short NPCInstance::getBaseDisposition() {
		return baseDisposition;
	}

	void NPCInstance::setBaseDisposition(short value) {
		vTable.actor->setDispositionRaw(this, value);

		// Handle case where we're in dialog with this character.
		auto menuDialog = TES3::UI::findMenu(*reinterpret_cast<short*>(TES3_UI_ID_MenuDialog));
		auto serviceActor = TES3::UI::getServiceActor();
		if (menuDialog && serviceActor && serviceActor->actorType == TES3::MobileActorType::NPC && reinterpret_cast<TES3::MobileNPC*>(serviceActor)->npcInstance == this) {
			menuDialog->setProperty(static_cast<TES3::UI::Property>(*reinterpret_cast<short*>(TES3_UI_ID_MenuDialog_start_disposition)), baseDisposition);
			TES3::UI::updateDialogDisposition();
		}
	}

	void NPCInstance::setFactionRank(unsigned char value) {
		baseNPC->factionRank = value;
	}
}
