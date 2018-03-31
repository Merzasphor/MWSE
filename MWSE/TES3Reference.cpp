#include "TES3Reference.h"

#include "LuaManager.h"
#include "TES3Util.h"

#define TES3_Reference_activate 0x4E9610
#define TES3_Reference_setActivationFlag 0x4E55A0
#define TES3_Reference_clearActivationFlag 0x4E55E0
#define TES3_Reference_testActivationFlag 0x4E5520
#define TES3_Reference_setActivationReference 0x4E5610
#define TES3_Reference_getActivationReference 0x4E5650

namespace TES3 {
	void Reference::activate(Reference* target) {
		// In this case we want to flip the target and this, so that it is more logical to write.
		reinterpret_cast<void(__thiscall *)(Reference*, Reference*, int)>(TES3_Reference_activate)(target, this, 1);
	}

	void Reference::setActivationFlag(int flag) {
		reinterpret_cast<void(__thiscall *)(Reference*, int)>(TES3_Reference_setActivationFlag)(this, flag);
	}

	void Reference::clearActivationFlag(int flag) {
		reinterpret_cast<void(__thiscall *)(Reference*, int)>(TES3_Reference_clearActivationFlag)(this, flag);
	}

	bool Reference::testActivationFlag(int flag) {
		return (reinterpret_cast<signed char(__thiscall *)(Reference*, int)>(TES3_Reference_testActivationFlag)(this, flag) != 0);
	}

	void Reference::setActivationReference(Reference* reference) {
		reinterpret_cast<void (__thiscall *)(Reference*, Reference*)>(TES3_Reference_setActivationReference)(this, reference);
	}

	Reference* Reference::getActivationReference() {
		return reinterpret_cast<Reference* (__thiscall *)(Reference*)>(TES3_Reference_getActivationReference)(this);
	}
}
