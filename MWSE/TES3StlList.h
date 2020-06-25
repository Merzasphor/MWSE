#pragma once

namespace TES3 {
	template <typename T>
	class StlList {
	public:
		class Node {
		public:
			T data;
			Node* previous;
			Node* next;

			static void* operator new(size_t size) { return reinterpret_cast<void* (__cdecl*)(size_t)>(0x727692)(size); }
			static void operator delete(void* block) { reinterpret_cast<void(__cdecl*)(void*)>(0x727530)(block); }

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
			friend class StlList;

		private:
			Node* m_Node;

			iterator(Node* node) : m_Node(node) {}

		public:
			using iterator_category = std::random_access_iterator_tag;

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
		iterator end() const { return nullptr; }
		reverse_iterator rbegin() const { return tail; }
		reverse_iterator rend() const { return nullptr; }
		const_iterator cbegin() const { return head; }
		const_iterator cend() const { nullptr; }
		const_reverse_iterator crbegin() const { return tail; }
		const_reverse_iterator crend() const { return nullptr; }
		size_type size() const noexcept { return count; }
		bool empty() const noexcept { return count == 0; }

		//
		// General access functions.
		//

		size_type count;
		Node* head;
		Node* tail;

		static void* operator new(size_t size) { return reinterpret_cast<void* (__cdecl*)(size_t)>(0x727692)(size); }
		static void operator delete(void* block) { reinterpret_cast<void(__cdecl*)(void*)>(0x727530)(block); }

		const_iterator operator[](size_type index) const {
			return begin() + index;
		}

		reference front() { return *begin(); }
		const_reference front() const { return *begin(); }

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

			auto beforeNode = position.m_Node;
			if (beforeNode) {
				if (beforeNode->next) {
					beforeNode->next->previous = newNode;
					beforeNode->next = newNode;
				}
				beforeNode->next = newNode;

				count++;
			}
			else {
				if (head) {
					tail->next = newNode;
					newNode->previous = tail;
					count++;
				}
				else {
					head = newNode;
					tail = newNode;
					count++;
				}
			}

			return newNode;
		}

		iterator insert(size_type position, const_reference value) {
			return insert(begin() + position, value);
		}

		void push_front(const_reference value) {
			auto newNode = new Node(value);
			newNode->next = head;

			if (head) {
				head->previous = newNode;
			}
			else {
				tail = newNode;
			}

			head = newNode;
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

		iterator erase(const_reference value) {
			return erase(std::find(cbegin(), cend(), value));
		}

	};
	static_assert(sizeof(StlList<void*>) == 0x0C, "TES3::StlList failed size validation");
}
