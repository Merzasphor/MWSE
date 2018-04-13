#include "TES3Reference.h"

#include "LuaManager.h"
#include "TES3Util.h"

#define TES3_Reference_activate 0x4E9610
#define TES3_Reference_setActionFlag 0x4E55A0
#define TES3_Reference_clearActionFlag 0x4E55E0
#define TES3_Reference_testActionFlag 0x4E5520
#define TES3_Reference_setActionReference 0x4E5610
#define TES3_Reference_getActionReference 0x4E5650

namespace TES3 {
	void Reference::activate(Reference* target) {
		// In this case we want to flip the target and this, so that it is more logical to write.
		reinterpret_cast<void(__thiscall *)(Reference*, Reference*, int)>(TES3_Reference_activate)(target, this, 1);
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
