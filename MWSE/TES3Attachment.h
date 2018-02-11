#pragma once

#include "ObjectTypes.h"
#include "TES3Spell.h"

/*
	Attachments are a data type that are added onto references (and possibly other
	data types). They provide extra information, such as data for the lock, variables,
	MACP, and activation targets.
*/

namespace TES3 {
	enum AttachmentType {
		AttachmentLock = 3,
		AttachmentVariables = 6,
		AttachmentMACP = 8,
		AttachmentActivator = 9
	};

	// ----------------------------------------------------------------------------- //

	// The most basic attachment data. Every attachment forms a linked list, defining
	// the type of the attachment and the next attachment in the chain.
	struct BaseAttachment {
		AttachmentType type;
		BaseAttachment * next;
	};
	static_assert(sizeof(BaseAttachment) == 0x08, "TES3::BaseAttachment failed size validation");

	// Some attachment types are the basic linked list structure, with an added pointer
	// to an extra data structure.
	template <typename T>
	struct NodeAttachment {
		AttachmentType type;
		NodeAttachment<T> * next;
		T * node;
	};
	static_assert(sizeof(NodeAttachment<void>) == 0x0C, "TES3::NodeAttachment failed size validation");

	// ----------------------------------------------------------------------------- //

	// Node for LockAttachment.
	struct LockAttachmentNode {
		mwShort lockLevel; // 0x00
		mwShort unknown_0x02;
		BaseObject * owner; // 0x04 // Faction or global?
		Spell * trapSpell; // 0x08
		char locked; // 0x0C
	};
	static_assert(sizeof(LockAttachmentNode) == 0x10, "TES3::LockAttachmentNode failed size validation");

	// AttachmentType = 3
	// Holds information about a door/container's lock state.
	typedef NodeAttachment<LockAttachmentNode> LockAttachment;

	// ----------------------------------------------------------------------------- //

	// Node for VariableAttachment.
	struct VariableAttachmentNode {
		struct Variables {
			mwShort * shortVarValues;
			mwLong * longVarValues;
			mwFloat * floatVarValues;
		};
		mwLong count; // 0x00 // For items, this is the item count (as long).
		BaseObject * owner; // 0x04
		union { mwLong rank; TES3::GlobalVariable * variable; } rankVar; // 0x08
		mwLong condition; // 0x0C // For LOCK/REPAIR/WEAPON/ARMOR/PROBE, this is the current condition (as long).
		mwFloat currentCharge; // 0x10 // For enchanted items, this is the current charge (as a float).
		int unknown_0x14;
		Variables * variables; // 0x18
	};
	static_assert(sizeof(VariableAttachmentNode::Variables) == 0x0C, "TES3::VariableAttachmentNode::Variables failed size validation");
	static_assert(sizeof(VariableAttachmentNode) == 0x1C, "TES3::VariableAttachmentNode failed size validation");

	// AttachmentType = 6
	// Holds variables associated with the object.
	typedef NodeAttachment<VariableAttachmentNode> VariableAttachment;

	// ----------------------------------------------------------------------------- //

	// AttachmentType = 8
	// Holds the MACP record for the associated object.
	typedef NodeAttachment<MACP> MACPAttachment;

	// ----------------------------------------------------------------------------- //

	// AttachmentType = 9
	// Activator attachment holds the activation state, and who is going to activate the
	// object.
	struct ActivatorAttachment {
		AttachmentType type;
		BaseAttachment * next;
		mwLong flags; // 1 = ???; 2 = Ready to activate
		Reference * reference;
	};
	static_assert(sizeof(ActivatorAttachment) == 0x10, "TES3::ActivatorAttachment failed size validation");
}

