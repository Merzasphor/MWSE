#pragma once

namespace NI {
	template <typename T>
	struct LinkedList {
		T* data;
		LinkedList<T>* next;
	};
	static_assert(sizeof(LinkedList<void>) == 0x8, "NI::LinkedList failed size validation");
}
