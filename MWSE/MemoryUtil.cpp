#include "MemoryUtil.h"

#include "MemAccess.h"

namespace mwse {
	void genJump(DWORD Address, DWORD To) {
		MemAccess<unsigned char>::Set(Address, 0xE9);
		MemAccess<DWORD>::Set(Address + 1, To - Address - 0x5);
	}

	void genCall(DWORD Address, DWORD To) {
		MemAccess<unsigned char>::Set(Address, 0xE8);
		MemAccess<DWORD>::Set(Address + 1, To - Address - 0x5);
	}

	void genNOP(DWORD Address) {
		MemAccess<unsigned char>::Set(Address, 0x90);
	}

	void genCallUnprotected(DWORD address, DWORD to, DWORD size) {
		// Unprotect memory.
		DWORD oldProtect;
		VirtualProtect((DWORD*)address, 0x5, PAGE_READWRITE, &oldProtect);

		// Create our call.
		MemAccess<unsigned char>::Set(address, 0xE8);
		MemAccess<DWORD>::Set(address + 1, to - address - 0x5);

		// NOP out the rest of the block.
		for (DWORD i = address + 5; i < address + size; i++) {
			genNOP(i);
		}

		// Protect memory again.
		VirtualProtect((DWORD*)address, 0x5, oldProtect, &oldProtect);
	}

	void overrideVirtualTable(DWORD address, DWORD offset, DWORD to) {
		DWORD location = address + offset;

		// Unprotect memory.
		DWORD oldProtect;
		VirtualProtect((DWORD*)location, 0x4, PAGE_READWRITE, &oldProtect);

		// Create our call.
		MemAccess<DWORD>::Set(location, to);

		// Protect memory again.
		VirtualProtect((DWORD*)location, 0x4, oldProtect, &oldProtect);
	}
}