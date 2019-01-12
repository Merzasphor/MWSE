#pragma once

#include <Windows.h>

namespace mwse {
	// Container for registers, flags, and other information to help with the
	// native to MWSE code bridge.
	struct HookContext {
		// General registers.
		DWORD eax;
		DWORD ebx;
		DWORD ecx;
		DWORD edx;

		// String operators.
		DWORD esi;
		DWORD edi;

		// Stack.
		DWORD ebp;
		DWORD esp;

		// Flags (cmp, test).
		DWORD flags;

		// Address to return to.
		DWORD callbackAddress;
	};

	// Code to generate a jump in memory. Don't forget to unprotect it first!
	void __declspec(dllexport) genJump(DWORD Address, DWORD To);

	// Code to generate a call in memory. Don't forget to unprotect it first!
	void __declspec(dllexport) genCall(DWORD Address, DWORD To);

	// Code to generate a nop in memory. Don't forget to unprotect it first!
	void __declspec(dllexport) genNOP(DWORD Address);

	// Code to generate a call in memory. This function unprotects the memory.
	void __declspec(dllexport) genJumpUnprotected(DWORD address, DWORD to, DWORD size = 0x5);

	// Code to generate a call in memory. This function unprotects the memory.
	bool __declspec(dllexport) genJumpEnforced(DWORD address, DWORD previousTo, DWORD to, DWORD size = 0x5);

	// Code to generate a call in memory. This function unprotects the memory.
	void __declspec(dllexport) genCallUnprotected(DWORD address, DWORD to, DWORD size = 0x5);

	// Code to generate a call in memory. This function unprotects the memory.
	bool __declspec(dllexport) genCallEnforced(DWORD address, DWORD previousTo, DWORD to, DWORD size = 0x5);

	bool __declspec(dllexport) genPushEnforced(DWORD address, BYTE value);
	bool __declspec(dllexport) genPushEnforced(DWORD address, DWORD value);

	// Overrides a function in a virtual table.
	void __declspec(dllexport) overrideVirtualTable(DWORD address, DWORD offset, DWORD to);

	// Overrides a function in a virtual table.
	bool __declspec(dllexport) overrideVirtualTableEnforced(DWORD address, DWORD offset, DWORD previousTo, DWORD to);

	// Write NOP instructions over a space.
	bool __declspec(dllexport) genNOPUnprotected(DWORD address, DWORD size);

	// Write a single byte to memory.
	void __declspec(dllexport) writeByteUnprotected(DWORD address, BYTE value);

	// Code to write a patch to a code segment. This function unprotects the memory.
	// WARNING: If passing a function address, always use a non-static function or it will crash.
	void __declspec(dllexport) writePatchCodeUnprotected(DWORD address, const BYTE* patch, DWORD size);

	// Code to determine what function an address calls.
	DWORD __declspec(dllexport) getCallAddress(DWORD address);
}
