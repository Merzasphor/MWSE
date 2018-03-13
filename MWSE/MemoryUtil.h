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
	void genJump(DWORD Address, DWORD To);

	// Code to generate a call in memory. Don't forget to unprotect it first!
	void genCall(DWORD Address, DWORD To);

	// Code to generate a nop in memory. Don't forget to unprotect it first!
	void genNOP(DWORD Address);
}
