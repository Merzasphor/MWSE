#include "TES3Reference.h"

#include "LuaManager.h"
#include "LuaUtil.h"
#include "TES3Util.h"

#define TES3_Reference_activate 0x4E9610
#define TES3_Reference_setActionFlag 0x4E55A0
#define TES3_Reference_clearActionFlag 0x4E55E0
#define TES3_Reference_testActionFlag 0x4E5520
#define TES3_Reference_setActionReference 0x4E5610
#define TES3_Reference_getActionReference 0x4E5650

namespace TES3 {
	void Reference::activate(Reference* activator, int unknown) {
		// Prepare our event data.
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();
		sol::table eventData = state.create_table();
		eventData["activator"] = activator;
		eventData["target"] = this;

		// If our event data says to block, don't let the object activate.
		mwse::lua::event::trigger("activate", eventData);
		if (eventData["block"] == true) {
			return;
		}

		reinterpret_cast<void(__thiscall *)(Reference*, Reference*, int)>(TES3_Reference_activate)(this, activator, unknown);
	}

	void Reference::setActionFlag(int flag) {
		reinterpret_cast<void(__thiscall *)(Reference*, int)>(TES3_Reference_setActionFlag)(this, flag);
	}

	void Reference::clearActionFlag(int flag) {
		reinterpret_cast<void(__thiscall *)(Reference*, int)>(TES3_Reference_clearActionFlag)(this, flag);
	}

	bool Reference::testActionFlag(int flag) {
		return (reinterpret_cast<signed char(__thiscall *)(Reference*, int)>(TES3_Reference_testActionFlag)(this, flag) != 0);
	}

	void Reference::setActionReference(Reference* reference) {
		reinterpret_cast<void (__thiscall *)(Reference*, Reference*)>(TES3_Reference_setActionReference)(this, reference);
	}

	Reference* Reference::getActionReference() {
		return reinterpret_cast<Reference* (__thiscall *)(Reference*)>(TES3_Reference_getActionReference)(this);
	}
}
