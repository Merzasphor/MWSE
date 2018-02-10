#pragma once

#include "ObjectTypes.h"

#include "TES3Attachment.h"
#include "TES3Cell.h"

namespace TES3 {
	struct ReferenceUnk1 {
		int unknown_0x00; // Reference?
		int unknown_0x04; // Reference?
		int unknown_0x08; // Reference?
		Cell * cell; // 0x0C // Current cell.
	};

	struct Reference_vTable {

	};

	struct Reference {
		Reference_vTable * vTable;
		ObjectType::ObjectType objectType;
		int baseFlags; // 0x08
		int unknown_0x0C;
		int unknown_0x10;
		ReferenceUnk1 * unknown_0x14;
		int unknown_0x18;
		BaseObject * previousRecord; // 0x1C
		BaseObject * nextObject; // 0x20
		int unknown_0x24;
		BaseObject * objectPointer; // 0x28 // Points to the record for which this is a reference.
		int unknown_0x2C;
		int unknown_0x30;
		int unknown_0x34;
		mwFloat x; // 0x38
		mwFloat y; // 0x3C
		mwFloat z; // 0x40
		Attachment<BaseObject> * attachments; // 0x44
		int unknown_0x48;
		int unknown_0x4C;
	};
	static_assert(sizeof(Reference) == 0x50, "TES3::Reference failed size validation");
}
