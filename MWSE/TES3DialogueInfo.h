#pragma once

#include "TES3Defines.h"

#include "TES3Dialogue.h"
#include "TES3Object.h"

namespace TES3 {
	enum class DialogueInfoFilterType {
		Actor,
		Race,
		Class,
		NPCFaction,
		Cell,
		PCFaction,
		ResultScript,
		Conditional0,
		Conditional1,
		Conditional2,
		Conditional3,
		Conditional4,
		Conditional5
	};

	struct DialogueInfoFilterNode {
		DialogueInfoFilterType tag;
		DialogueInfoFilterNode* next;
		union {
			BaseObject* object;
			Actor* actor;
			Race* npcRace;
			Class* npcClass;
			Faction* npcFaction;
			Cell* cell;
			Faction* pcFaction;
			const char* scriptText;
			DialogueConditional* conditional;
		};
	};

	struct DialogueInfo : BaseObject {
		struct LoadLinkNode {
			char * name;
			char * previous;
			char * next;
		};
		LoadLinkNode * loadLinkNode; // 0x10
		DialogueType type; // 0x14
		int disposition; // 0x18
		char npcRank; // 0x1C
		char npcSex; // 0x1D
		char pcRank; // 0x1E
		DialogueInfoFilterNode* conditions; // 0x20
		long espFileOffset; // 0x24
		Actor* firstHeardFrom; // 0x28

		//
		// Other related this-call functions.
		//

		const char* getText();

		bool loadId();
		void unloadId();

		bool filter(Object * actor, Reference * reference, int source, Dialogue * dialogue);

	};
	static_assert(sizeof(DialogueInfo) == 0x2C, "TES3::DialogueInfo failed size validation");
}
