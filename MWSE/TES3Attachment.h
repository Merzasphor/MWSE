#pragma once

#include "ObjectTypes.h"
#include "TES3Spell.h"

namespace TES3 {
	enum AttachmentType {
		AttachmentLock = 3,
		AttachmentVariables = 6,
		AttachmentMACP = 8
	};

	template <typename T>
	struct Attachment {
		AttachmentType type;
		Attachment<T> * next;
		T * data;
	};

	struct VariableHolderAttachment {
		struct Variables {
			mwShort * shortVarValues;
			mwLong * longVarValues;
			mwFloat * floatVarValues;
		};
		int unknown_0x00; // For items, this is the item count (as long).
		int unknown_0x04;
		int unknown_0x08;
		int unknown_0x0C; // For LOCK/REPAIR/WEAPON/ARMOR/PROBE, this is the current condition (as long).
		int unknown_0x10; // For enchanted items, this is the current charge (as a float).
		int unknown_0x14;
		Variables * variables; // 0x18
	};
	static_assert(sizeof(VariableHolderAttachment::Variables) == 0x0C, "TES3::VariableHolderAttachment::Variables failed size validation");
	static_assert(sizeof(VariableHolderAttachment) == 0x1C, "TES3::VariableHolderAttachment::Variables failed size validation");

	struct LockAttachment {
		mwShort lockLevel; // 0x00
		mwShort unknown_0x02;
		BaseObject * owner; // 0x04 // Faction or global?
		Spell * trapSpell; // 0x08
		char locked; // 0x0C
	};
	static_assert(sizeof(LockAttachment) == 0x10, "TES3::LockAttachment failed size validation");
}

