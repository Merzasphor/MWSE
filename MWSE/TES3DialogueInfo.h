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
		void* dialogLoadLinkNode;
		DialogueType type;
		int disposition;
		char npcRank;
		char npcSex;
		char pcRank;
		DialogueInfoFilterNode* conditions;
		long espFileOffset;
		Actor* firstHeardFrom;
	};
	static_assert(sizeof(DialogueInfo) == 0x2C, "TES3::DialogueInfo failed size validation");
}
