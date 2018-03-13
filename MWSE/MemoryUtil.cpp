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
}