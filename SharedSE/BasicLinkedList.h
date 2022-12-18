#pragma once

namespace se {
	template <typename T>
	struct BasicLinkedList {
		struct Node {
			T data;
			Node* previous;
			Node* next;
		};
		size_t size;
		Node* head;
		Node* tail;
	};
	static_assert(sizeof(BasicLinkedList<void*>) == 0xC, "TES3::BasicLinkedList failed size validation");
	static_assert(sizeof(BasicLinkedList<void*>::Node) == 0xC, "TES3::BasicLinkedList::Node failed size validation");
}
