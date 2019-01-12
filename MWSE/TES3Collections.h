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
	// STL List
	//

	template <typename T>
	struct StlListNode {
		T * data;
		StlListNode<T> * previous;
		StlListNode<T> * next;

		static StlListNode<T> * create() {
			return reinterpret_cast<StlListNode<T> *(__thiscall *)(StlListNode<T> *)>(0x4D3FA0)(mwse::tes3::_new<StlListNode<T>>());
		}
	};
	static_assert(sizeof(StlListNode<void>) == 0x0C, "TES3::StlListNode failed size validation");

	template <typename T>
	struct StlList {
		unsigned long size;
		StlListNode<T> * head;
		StlListNode<T> * tail;

		void insertAtFront(T * data) {
			auto node = StlListNode<T>::create();
			node->data = data;
			reinterpret_cast<void(__thiscall *)(StlList<T> *, StlListNode<T> *)>(0x4D41F0)(this, node);
		}
	};
	static_assert(sizeof(StlList<void>) == 0x0C, "TES3::StlList failed size validation");

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

		//
		// Related this-call functions.
		//

		void clear() {
			reinterpret_cast<void(__thiscall *)(Iterator<T>*)>(0x47E2F0)(this);
		}

		void addItem(T * item) {
			reinterpret_cast<void(__thiscall *)(Iterator<T>*, T*)>(0x47E360)(this, item);
		}

		void addItemAtIndex(T * item, unsigned int index) {
			reinterpret_cast<void(__thiscall *)(Iterator<T>*, T*, unsigned int)>(0x47E4D0)(this, item, index);
		}

		IteratorNode<T> * getFirstNode() {
			return reinterpret_cast<IteratorNode<T> *(__thiscall *)(Iterator<T>*)>(0x47E710)(this);
		}

		IteratorNode<T> * getNextNode() {
			return reinterpret_cast<IteratorNode<T> *(__thiscall *)(Iterator<T>*)>(0x47E720)(this);
		}
	};
	static_assert(sizeof(Iterator<void>) == 0x14, "TES3::Iterator failed size validation");

	//
	// TArray
	//

	template <typename T>
	struct TArray {
		void * vTable; // 0x0
		T ** storage; // 0x4
		int storageCount; // 0x8
		int endIndex; // 0xC
		int filledCount; // 0x10
		int growByCount; // 0x14

		//
		// Related this-call functions.
		//

		int getIndexOfValue(T * value) {
			return reinterpret_cast<int(__cdecl *)(TArray<T>*, T*)>(0x497B60)(this, value);
		}

		//
		// Custom functions.
		//

		bool contains(T * value) {
			return getIndexOfValue(value) >= 0;
		}

	};
	static_assert(sizeof(TArray<void>) == 0x18, "TES3::TArray failed size validation");

}
