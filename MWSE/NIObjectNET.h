#pragma once

#include "NIObject.h"
#include "NIPointer.h"
#include "NITimeController.h"

namespace NI {
	struct ObjectNET : Object {
		char * name; // 0x8
		void * extraData; // 0xC
		Pointer<TimeController> controllers; // 0x10

		//
		// Other related this-call functions.
		//

		void prependController(TimeController * controller);
		void removeController(TimeController * controller);
		void removeAllControllers();

		void setName(const char* name);

	};
	static_assert(sizeof(ObjectNET) == 0x14, "NI::ObjectNET failed size validation");
}
