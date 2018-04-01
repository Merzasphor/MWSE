#include "TES3Book.h"

#define TES3_Book_loadBookText 0x4A2A90

namespace TES3 {
	char* Book::getBookText() {
		return reinterpret_cast<char*(__thiscall *)(Book*)>(TES3_Book_loadBookText)(this);
	}
}

