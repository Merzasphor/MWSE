#pragma once

#include "NIDefines.h"
#include "NIObject.h"
#include "NIPointer.h"
#include "NITimeController.h"

namespace NI {
	struct ObjectNET : Object {
		char * name; // 0x8
		ExtraData* extraData; // 0xC
		Pointer<TimeController> controllers; // 0x10

		//
		// Other related this-call functions.
		//

		void prependController(TimeController * controller);
		void removeController(TimeController * controller);
		void removeAllControllers();

		void setName(const char* name);

		//
		// Custom functions.
		//

		sol::object getExtraData_lua() const;

		StringExtraData* getStringDataWithValue(const char* value) const;
		sol::object getStringDataWithValue_lua(const char* value) const;
		bool hasStringDataWithValue(const char* value) const;

		StringExtraData* getStringDataStartingWithValue(const char* value) const;
		sol::object getStringDataStartingWithValue_lua(const char* value) const;
		bool hasStringDataStartingWithValue(const char* value) const;

	};
	static_assert(sizeof(ObjectNET) == 0x14, "NI::ObjectNET failed size validation");
}
