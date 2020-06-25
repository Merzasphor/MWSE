#pragma once

namespace TES3 {
	template <typename T>
	class IteratedList {
	public:
		class Node {
		public:
			Node* previous;
			Node* next;
			T data;

#if !defined(MWSE_NO_CUSTOM_ALLOC) || MWSE_NO_CUSTOM_ALLOC == 0
			static void* operator new(size_t size) { return reinterpret_cast<void* (__cdecl*)(size_t)>(0x727692)(size); }
			static void operator delete(void* block) { reinterpret_cast<void(__cdecl*)(void*)>(0x727530)(block); }
#endif

			Node(const Node&) = delete;

			Node(const T& value) {
				previous = nullptr;
				next = nullptr;
				data = value;
			}

			~Node() {
				if (previous) {
					previous->next = nullptr;
				}
				previous = nullptr;

				if (next) {
					next->previous = nullptr;
				}
				next = nullptr;
			}
		};

		//
		// std interface functions
		//

		class iterator {
			friend class IteratedList;

		private:
			Node* m_Node;

			iterator(Node* node) : m_Node(node) {}

		public:
			using iterator_category = std::bidirectional_iterator_tag;

			using value_type = T;
			using difference_type = int;
			using pointer = T*;
			using reference = T&;

			iterator() : m_Node(nullptr) {}

			iterator operator-(difference_type diff) const {
				iterator r = m_Node;
				r -= diff;
				return r;
			}

			iterator& operator--() {
				if (m_Node) {
					m_Node = m_Node->previous;
				}
				return *this;
			}

			iterator operator--(int) {
				return *this - 1;
			}

			iterator& operator-=(difference_type diff) {
				while (m_Node && diff-- > 0) {
					m_Node = m_Node->previous;
				}
				return *this;
			}

			iterator operator+(difference_type diff) const {
				iterator r = m_Node;
				r += diff;
				return r;
			}

			iterator& operator++() {
				if (m_Node) {
					m_Node = m_Node->next;
				}
				return *this;
			}

			iterator operator++(int) {
				return *this + 1;
			}

			iterator& operator+=(difference_type diff) {
				while (m_Node && diff-- > 0) {
					m_Node = m_Node->next;
				}
				return *this;
			}

			bool operator==(const iterator& itt) const {
				return itt.m_Node == m_Node;
			}

			bool operator!=(const iterator& itt) const {
				return itt.m_Node != m_Node;
			}

			reference operator->() const {
				return m_Node->data;
			}

			reference operator*() const {
				return m_Node->data;
			}
		};

		using value_type = T;
		using size_type = size_t;
		using difference_type = int;
		using pointer = T*;
		using const_pointer = const T*;
		using reference = T&;
		using const_reference = const T&;
		using const_iterator = const iterator;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		iterator begin() const { return head; }
		iterator end() const { return tail; }
		reverse_iterator rbegin() const { return std::make_reverse_iterator(begin()); }
		reverse_iterator rend() const { return std::make_reverse_iterator(end()); }
		const_iterator cbegin() const { return head; }
		const_iterator cend() const { return nullptr; }
		const_reverse_iterator crbegin() const { return rbegin(); }
		const_reverse_iterator crend() const { return rend(); }
		size_type size() const noexcept { return count; }
		bool empty() const noexcept { return count == 0; }

		//
		// General access functions.
		//

		size_type count;
		Node* head;
		Node* tail;
		Node* current;

#if !defined(MWSE_NO_CUSTOM_ALLOC) || MWSE_NO_CUSTOM_ALLOC == 0
		static void* operator new(size_t size) { return reinterpret_cast<void* (__cdecl*)(size_t)>(0x727692)(size); }
		static void operator delete(void* block) { reinterpret_cast<void(__cdecl*)(void*)>(0x727530)(block); }
#endif

		virtual ~IteratedList() { clear(); }

		reference operator[](size_type index) const { return *(begin() + index); }

		reference front() { return head->data; }
		const_reference front() const { return head->data; }

		reference back() { return tail->data; }
		const_reference back() const { return tail->data; }

		void clear() {
			auto itt = head;
			while (itt) {
				auto toDelete = itt;
				itt = itt->next;
				delete toDelete;
			}
			head = nullptr;
			tail = nullptr;
			count = 0;
		}

		iterator insert(const_iterator position, const_reference value) {
			auto newNode = new Node(value);
			auto insertBeforeNode = position.m_Node;

			// Insert before a given node.
			if (insertBeforeNode) {
				if (insertBeforeNode->previous) {
					insertBeforeNode->previous->next = newNode;
					newNode->previous = insertBeforeNode->previous;
				}

				insertBeforeNode->previous = newNode;
				newNode->next = insertBeforeNode;
			}
			// Insert at end.
			else {
				if (tail) {
					tail->next = newNode;
				}
				newNode->previous = tail;
				tail = newNode;
			}

			// New head check.
			if (head == nullptr || insertBeforeNode == head) {
				head = newNode;
			}

			// New tail check.
			if (tail == nullptr || newNode->previous == tail) {
				tail = newNode;
			}

			count++;
			return newNode;
		}

		iterator insert(size_type position, const_reference value) {
			return insert(begin() + position, value);
		}

		void push_front(const_reference value) {
			insert(begin(), value);
		}

		void push_back(const_reference value) {
			insert(end(), value);
		}

		iterator erase(const_iterator position) {
			iterator next = nullptr;

			auto node = position.m_Node;
			if (node) {
				if (node == head) {
					head = node->next;
				}
				if (node == tail) {
					tail = node->previous;
				}

				if (node->previous) {
					node->previous->next = node->next;
				}
				if (node->next) {
					next = node->next;
					node->next->previous = node->previous;
				}
				node->previous = nullptr;
				node->next = nullptr;
				delete position.m_Node;
				count--;
			}

			return next;
		}

		iterator erase(const_iterator first, const_iterator last) {
			auto itt = first;
			while (itt != end() && itt != last) {
				itt = erase(itt);
			}
			return itt;
		}

		iterator erase(size_type position) {
			return erase(begin() + position);
		}

		//
		// Cached iterator access.
		//

		Node* cached_begin() {
			current = head;
			return current;
		}

		Node* cached_next() {
			current = current->next;
			return current;
		}

	};
	static_assert(sizeof(IteratedList<void*>) == 0x14, "TES3::IteratedList failed size validation");
	static_assert(sizeof(IteratedList<void*>::Node) == 0xC, "TES3::IteratedList::Node failed size validation");
}
