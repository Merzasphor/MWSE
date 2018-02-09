#pragma once

namespace TES3 {
	template <typename T>
	struct LinkedList
	{
		unsigned long size;
		T * head;
		T * tail;
	};
	static_assert(sizeof(LinkedList<void>) == 0x0C, "TES3::LinkedList failed size validation");

	template <typename T>
	struct IteratorNode
	{
		IteratorNode<T> * previous;
		IteratorNode<T> * next;
		T * data;
	};
	static_assert(sizeof(IteratorNode<void>) == 0x0C, "TES3::IteratorNode failed size validation");

	template <typename T>
	struct Iterator
	{
		void * unknown_0x00;
		mwLong size;
		IteratorNode<T> * head;
		IteratorNode<T> * tail;
		IteratorNode<T> * current;
	};
	static_assert(sizeof(Iterator<void>) == 0x14, "TES3::Iterator failed size validation");

	struct InventoryNode
	{
		int itemCount;
		BaseObject * object;
	};
	static_assert(sizeof(InventoryNode) == 0x08, "TES3::InventoryNode failed size validation");
}
