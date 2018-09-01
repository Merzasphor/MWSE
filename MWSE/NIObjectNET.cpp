#include "NIObjectNET.h"

namespace NI {
	const auto NI_ObjectNET_prependController = reinterpret_cast<void(__thiscall*)(const ObjectNET*, TimeController*)>(0x6EA3E0);
	const auto NI_ObjectNET_removeController = reinterpret_cast<void(__thiscall*)(const ObjectNET*, TimeController*)>(0x6EA450);
	const auto NI_ObjectNET_removeAllControllers = reinterpret_cast<void(__thiscall*)(const ObjectNET*)>(0x6EA5A0);

	const auto NI_ObjectNET_setName = reinterpret_cast<void(__thiscall*)(const ObjectNET*, const char *)>(0x6EA1A0);

	void ObjectNET::prependController(TimeController * controller) {
		NI_ObjectNET_prependController(this, controller);
	}

	void ObjectNET::removeController(TimeController * controller) {
		NI_ObjectNET_removeController(this, controller);
	}

	void ObjectNET::removeAllControllers() {
		NI_ObjectNET_removeAllControllers(this);
	}

	void ObjectNET::setName(const char* name) {
		NI_ObjectNET_setName(this, name);
	}
}
