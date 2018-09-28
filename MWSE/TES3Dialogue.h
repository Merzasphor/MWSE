#pragma once

#include "TES3Object.h"
#include "TES3Collections.h"

namespace TES3 {
	enum class DialogueType : unsigned char {
		Topic,
		Voice,
		Greeting,
		Persuasion,
		Journal
	};

	struct Dialogue : BaseObject {
		const char* name;
		DialogueType type;
		Iterator<DialogueInfo> info;
		int journalIndex;

		//
		// Other related this-call functions.
		//

		bool addToJournal(int index, MobileActor* actor);
		bool setJournalIndex(int index);

		DialogueInfo* getDeepFilteredInfo(Actor* actor, Reference* reference, bool flag);
		DialogueInfo* getFilteredInfo(Actor* actor, Reference* reference, bool flag);

	};
	static_assert(sizeof(Dialogue) == 0x30, "TES3::Dialogue failed size validation");
}
