#pragma once

namespace TES3 {
	//
	// Linked lists.
	//

	template <typename T>
	struct LinkedList {
		unsigned long size;
		T * head;
		T * tail;
	};
	static_assert(sizeof(LinkedList<void>) == 0x0C, "TES3::LinkedList failed size validation");

	//
	// HashMap
	//

	struct HashMap {
		void * vTable; // 0x0
		long count; // 0x4
		long bucketCount; // 0x8
		void * buckets; // 0xC
	};
	static_assert(sizeof(HashMap) == 0x10, "TES3::HashMap failed size validation");

	//
	// Iterators.
	//

	template <typename T>
	struct IteratorNode {
		IteratorNode<T> * previous;
		IteratorNode<T> * next;
		T * data;
	};
	static_assert(sizeof(IteratorNode<void>) == 0x0C, "TES3::IteratorNode failed size validation");

	template <typename T>
	struct Iterator {
		void * vTable;
		int size;
		IteratorNode<T> * head;
		IteratorNode<T> * tail;
		IteratorNode<T> * current;
	};
	static_assert(sizeof(Iterator<void>) == 0x14, "TES3::Iterator failed size validation");
}
