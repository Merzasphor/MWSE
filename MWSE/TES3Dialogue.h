#pragma once

#include "TES3Object.h"

#include "TES3IteratedList.h"

namespace TES3 {
	enum class DialogueType : unsigned char {
		Topic,
		Voice,
		Greeting,
		Persuasion,
		Journal
	};

	struct Dialogue : BaseObject {
		char * name;
		DialogueType type;
		IteratedList<DialogueInfo*> info;
		int journalIndex;

		//
		// Virtual table overrides.
		//

		const char * getObjectID() const;

		//
		// Other related this-call functions.
		//

		bool addToJournal(int index, MobileActor* actor);

		sol::optional<const char*> getQuestName() const;
		sol::optional<int> getJournalIndex() const;
		bool setJournalIndex(int index);

		DialogueInfo* getJournalInfoForIndex(int index) const;
		DialogueInfo* getDeepFilteredInfo(Actor* actor, Reference* reference, bool flag);
		DialogueInfo* getFilteredInfo(Actor* actor, Reference* reference, bool flag);

		//
		// Custom functions.
		//

		std::string toJson();

		bool addToJournal_lua(sol::table params);
		DialogueInfo* getDeepFilteredInfo_lua(sol::table params);
		DialogueInfo* getJournalInfo(sol::optional<int> index) const;

		//
		// Other related static functions.
		//

		static Dialogue* getDialogue(int type, int page);

	};
	static_assert(sizeof(Dialogue) == 0x30, "TES3::Dialogue failed size validation");
}

MWSE_SOL_CUSTOMIZED_PUSHER_DECLARE_TES3(TES3::Dialogue)
