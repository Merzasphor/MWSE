#include "TES3Dialogue.h"

#include "LuaManager.h"

#include "LuaJournalEvent.h"

#define TES3_Dialogue_journalAdd 0x4B2F80
#define TES3_Dialogue_journalSetIndex 0x50F8B0

namespace TES3 {
	const auto TES3_Dialogue_getFilteredInfo = reinterpret_cast<DialogueInfo* (__thiscall*)(Dialogue*, Actor*, Reference*, bool)>(0x4B29E0);

	const auto TES3_getBaseDialogue = reinterpret_cast<Dialogue* (__cdecl*)(int, int)>(0x4B2C00);

	bool Dialogue::addToJournal(int index, MobileActor * actor) {
		if (type != DialogueType::Journal) {
			return false;
		}

		// Store our old index so we can refer to it later.
		int oldIndex = journalIndex;

		// Call the original function.
		bool added = reinterpret_cast<bool(__thiscall *)(Dialogue*, int, MobileActor *)>(TES3_Dialogue_journalAdd)(this, index, actor);

		// If the journal index changed, raise an event that it was modified.
		if (journalIndex > oldIndex) {
			mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::JournalEvent(this, oldIndex, index));
		}

		return added;
	}

	bool Dialogue::setJournalIndex(int index) {
		// Only valid for journal entries.
		if (type != DialogueType::Journal) {
			return false;
		}

		// Only run if the index changes.
		if (journalIndex == index) {
			return false;
		}

		// Store our old index so we can refer to it later.
		int oldIndex = journalIndex;

		// Update the journal index, as the original function would do.
		journalIndex = index;

		// Raise a modified event.
		if (journalIndex > oldIndex) {
			mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::JournalEvent(this, oldIndex, index));
		}

		return true;
	}

	DialogueInfo* Dialogue::getDeepFilteredInfo(Actor* actor, Reference* reference, bool flag) {
		auto info = getFilteredInfo(actor, reference, flag);
		if (info == nullptr) {
			info = TES3_getBaseDialogue(3, 0)->getFilteredInfo(actor, reference, flag);
		}
		return info;
	}

	DialogueInfo* Dialogue::getFilteredInfo(Actor* actor, Reference* reference, bool flag) {
		return TES3_Dialogue_getFilteredInfo(this, actor, reference, flag);
	}
}

