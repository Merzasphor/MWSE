#pragma once

#include "sol.hpp"

#include "TES3Object.h"
#include "TES3Attachment.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct LuaTableAttachment : Attachment {
		sol::table table;
	};

	struct Reference : Object {
		Object * baseObject; // 0x28
		Vector3 orientation; // 0x2c
		Vector3 position; // 0x38
		Attachment * attachments; // 0x44
		int sourceID; // 0x48
		int targetID; // 0x4C

		//
		// Other related this-call functions.
		//

		void activate(Reference*);
		void setActionFlag(int);
		void clearActionFlag(int);
		bool testActionFlag(int);
		void setActionReference(Reference*);
		Reference * getActionReference();

		//
		// Lua interface functions.
		//

		sol::object getBaseObject();

		// Return a table (or nil) of attachments for this object.
		sol::object getAttachments();

		sol::table getLuaTable();

	};
	static_assert(sizeof(Reference) == 0x50, "TES3::Reference failed size validation");
}
