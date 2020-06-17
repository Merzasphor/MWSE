#pragma once

#include "NIObject.h"
#include "NIPointer.h"
#include "NITimeController.h"

#include "TES3Defines.h"

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

		TES3::Reference* getTes3Reference(bool searchParents = false);
		sol::object getTes3Reference_lua(sol::optional<bool> searchParents);

	};
	static_assert(sizeof(ObjectNET) == 0x14, "NI::ObjectNET failed size validation");
}
