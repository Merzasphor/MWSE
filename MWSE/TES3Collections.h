#pragma once

namespace TES3 {
	//
	// Linked lists.
	//

	template <typename T>
	struct LinkedList {
		size_t size;
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
		size_t size;
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
		struct VirtualTable {
			void(__thiscall* destructor)(Iterator<T>*, bool); // 0x0
		};
		VirtualTable* vTable;
		size_t size;
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

		void addItemAtIndex(T* item, size_t index) {
			reinterpret_cast<void(__thiscall*)(Iterator<T>*, T*, size_t)>(0x47E4D0)(this, item, index);
		}

		void removeItemByValue(T* value) {
			reinterpret_cast<void(__thiscall*)(Iterator<T>*, T*)>(0x47E6A0)(this, value);
		}

		IteratorNode<T> * getFirstNode() {
			return reinterpret_cast<IteratorNode<T> *(__thiscall *)(Iterator<T>*)>(0x47E710)(this);
		}

		IteratorNode<T> * getNextNode() {
			return reinterpret_cast<IteratorNode<T> *(__thiscall *)(Iterator<T>*)>(0x47E720)(this);
		}
	};
	static_assert(sizeof(Iterator<void>) == 0x14, "TES3::Iterator failed size validation");
}
