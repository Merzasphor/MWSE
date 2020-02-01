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
	// HashMap
	//

	struct HashMap {
		void * vTable; // 0x0
		size_t count; // 0x4
		size_t bucketCount; // 0x8
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

	//
	// TArray
	//

	template <typename T>
	struct TArray {
		void * vTable; // 0x0
		T ** storage; // 0x4
		size_t storageCount; // 0x8
		size_t endIndex; // 0xC
		size_t filledCount; // 0x10
		size_t growByCount; // 0x14

		//
		// Related functions.
		//

		// getIndexOfValue returns -1 if not found.
		int getIndexOfValue(const T * value) const {
			return reinterpret_cast<int(__cdecl *)(const TArray<T>*, const T*)>(0x497B60)(this, value);
		}

		void setAtIndex(size_t index, const T * value) {
			// Note final parameter is a reference.
			reinterpret_cast<void(__thiscall *)(TArray<T>*, size_t, const T*&)>(0x4975D0)(this, index, value);
		}

		void setSize(size_t size) {
			reinterpret_cast<void(__thiscall *)(TArray<T>*, size_t)>(0x47C5A0)(this, size);
		}

		//
		// Custom functions.
		//

		static TArray<T> * create(size_t size = 1) {
			TArray<T> * arr = mwse::tes3::_new<TArray<T>>();
			arr->vTable = reinterpret_cast<void*>(0x747A60);
			arr->storageCount = size;
			arr->growByCount = size;
			arr->endIndex = 0;
			arr->filledCount = 0;
			arr->storage = reinterpret_cast<T**>(mwse::tes3::_new(size * sizeof(T*)));
			return arr;
		}

		T *& operator[](const size_t pos) {
			if (pos >= storageCount) {
				throw std::out_of_range("TES3::TArray::operator[] - Access out of bounds.");
			}
			return &storage[pos];
		}

		T * at(size_t pos) const {
			if (pos >= storageCount) {
				throw std::out_of_range("TES3::TArray::at - Access out of bounds.");
			}
			return storage[pos];
		}

		bool contains(T * value) const {
			return getIndexOfValue(value) >= 0;
		}

		__inline size_t size() const {
			return storageCount;
		}

		size_t add(T * value) {
			size_t index = endIndex;

			if (index == storageCount) {
				setSize(storageCount + growByCount);
			}
			setAtIndex(index, value);
			return index;
		}

	};
	static_assert(sizeof(TArray<void>) == 0x18, "TES3::TArray failed size validation");

}
