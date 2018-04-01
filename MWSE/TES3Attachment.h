#pragma once

#include "TES3Object.h"
#include "TES3Item.h"
#include "TES3MobileActor.h"
#include "TES3Vectors.h"

namespace TES3 {
	namespace AttachmentType {
		enum AttachmentType {
			Lock = 0x3,
			LoadDoor = 0x5,
			Variables = 0x6,
			ActorData = 0x8,
			Action = 0x9,
			NewOrientation = 0xA,
			LuaTable = 0x0100
		};
	}

	struct Attachment {
		AttachmentType::AttachmentType type;
		Attachment * next;
	};
	static_assert(sizeof(Attachment) == 0x8, "TES3::Attachment failed size validation");

	template <typename T>
	struct AttachmentWithNode : Attachment {
		T * data;
	};
	static_assert(sizeof(AttachmentWithNode<void>) == 0xC, "TES3::AttachmentWithNode failed size validation");

	//
	// Locks
	//

	struct LockAttachmentNode {
		int lockLevel; // 0x00
		BaseObject * owner; // 0x04 // Faction or global?
		Spell * trapSpell; // 0x08
		char locked; // 0x0C
	};
	static_assert(sizeof(LockAttachmentNode) == 0x10, "TES3::LockAttachmentNode failed size validation");

	typedef AttachmentWithNode<LockAttachmentNode> LockAttachment;

	//
	// Variables
	//

	typedef AttachmentWithNode<ItemData> ItemDataAttachment;

	//
	// Ownership
	//

	struct OwnershipAttachmentNode {
		int unknown_0x00;
		BaseObject * owner; // 0x04
		union {
			long rank;
			void * variable;
		} rankVar; // 0x08
	};
	static_assert(sizeof(OwnershipAttachmentNode) == 0x0C, "TES3::OwnershipAttachmentNode failed size validation");

	typedef AttachmentWithNode<OwnershipAttachmentNode> OwnershipAttachment;

	//
	// Actor Data / Mobile Object
	//

	typedef AttachmentWithNode<MobileActor> MobileActorAttachment;

	//
	// Action
	//

	struct ActionAttachment : Attachment {
		int flags;
		Reference * reference;
	};
	static_assert(sizeof(ActionAttachment) == 0x10, "TES3::ActionAttachment failed size validation");
	
	//
	// New Orientation
	//

	struct NewOrientationAttachment : Attachment {
		Vector3 position;
		Vector3 orientation;
	};
	static_assert(sizeof(NewOrientationAttachment) == 0x20, "TES3::NewOrientationAttachment failed size validation");
}
