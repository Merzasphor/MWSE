#pragma once

namespace TES3 {

	template <typename T>
	class Deque {
	public:
		class Node {
		public:
			Node* previous; // 0x0
			Node* next; // 0x4
			T data; // 0x8
		};

		bool unknown_0x0;
		Node* sentinel; // 0x4
		size_t count; // 0x8

		//
		// std interface functions
		//

		class iterator {
			friend class Deque;

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

			iterator& operator--() {
				m_Node = m_Node->previous;
				return *this;
			}

			iterator& operator-=(difference_type diff) {
				while (diff-- > 0) {
					m_Node = m_Node->previous;
				}
				return *this;
			}

			iterator& operator++() {
				m_Node = m_Node->next;
				return *this;
			}

			iterator& operator+=(difference_type diff) {
				while (diff-- > 0) {
					m_Node = m_Node->next;
				}
				return *this;
			}

			bool operator==(iterator& itt) {
				return itt.m_Node == m_Node;
			}

			bool operator!=(iterator& itt) {
				return itt.m_Node != m_Node;
			}

			reference operator*() {
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

		iterator begin() const { return sentinel->next; }
		iterator end() const { return sentinel; }
		size_type size() const noexcept { return count; }
		bool empty() const noexcept { return count == 0; }

	};
	static_assert(sizeof(Deque<int>) == 0xC, "TES3::Deque failed size validation");
	static_assert(offsetof(Deque<int>, unknown_0x0) == 0x0, "TES3::Deque::unknown_0x0 failed offset validation");
	static_assert(offsetof(Deque<int>, sentinel) == 0x4, "TES3::Deque::unknown_0x0 failed offset validation");
	static_assert(offsetof(Deque<int>, count) == 0x8, "TES3::Deque::unknown_0x0 failed offset validation");
	static_assert(sizeof(Deque<int>::Node) == 0xC, "TES3::Deque::Node failed size validation");
	static_assert(offsetof(Deque<int>::Node, previous) == 0x0, "TES3::Deque::Node::previous failed offset validation");
	static_assert(offsetof(Deque<int>::Node, next) == 0x4, "TES3::Deque::Node::next failed offset validation");
	static_assert(offsetof(Deque<int>::Node, data) == 0x8, "TES3::Deque::Node::data failed offset validation");

}
