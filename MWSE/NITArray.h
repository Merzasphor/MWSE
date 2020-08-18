#pragma once

#define USE_STL 1

namespace NI {
	template <typename T>
	class TArray {
		static_assert(sizeof(T) == 0x4, "TArray types must be 4 bytes in size.");

	public:
		//
		// iterator access
		//

		class iterator {
			friend class TArray;

		private:
			T* m_Ptr;

			iterator(T* ptr) : m_Ptr(ptr) {}

		public:
			using iterator_category = std::random_access_iterator_tag;

			using value_type = T;
			using difference_type = int;
			using pointer = T*;
			using reference = T&;

			iterator() : m_Ptr(nullptr) {}

			iterator operator-(difference_type diff) const {
				iterator r = m_Ptr;
				r -= diff;
				return r;
			}

			iterator& operator--() {
				--m_Ptr;
				return *this;
			}

			iterator operator--(int) {
				return *this - 1;
			}

			iterator& operator-=(difference_type diff) {
				while (diff-- > 0) {
					--m_Ptr;
				}
				return *this;
			}

			iterator operator+(difference_type diff) const {
				iterator r = m_Ptr;
				r += diff;
				return r;
			}

			iterator& operator++() {
				++m_Ptr;
				return *this;
			}

			iterator operator++(int) {
				return *this + 1;
			}

			iterator& operator+=(difference_type diff) {
				while (diff-- > 0) {
					++m_Ptr;
				}
				return *this;
			}

			bool operator==(const iterator& itt) const {
				return itt.m_Ptr == m_Ptr;
			}

			bool operator!=(const iterator& itt) const {
				return itt.m_Ptr != m_Ptr;
			}

			reference operator->() const {
				return *m_Ptr;
			}

			reference operator*() const {
				return *m_Ptr;
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

		constexpr iterator begin() noexcept { return &storage[0]; }
		constexpr const_iterator begin() const noexcept { return &storage[0]; }
		constexpr const_iterator cbegin() const noexcept { return &storage[0]; }
		constexpr iterator end() noexcept { return &storage[storageCount]; }
		constexpr const_iterator end() const noexcept { return &storage[storageCount]; }
		constexpr const_iterator cend() const noexcept { return &storage[storageCount]; }

		constexpr reverse_iterator rbegin() noexcept { std::make_reverse_iterator(end()); }
		constexpr const_reverse_iterator rbegin() const noexcept { return std::make_reverse_iterator(end()); }
		constexpr const_reverse_iterator crbegin() const noexcept { return std::make_reverse_iterator(end()); }
		constexpr reverse_iterator rend() noexcept { std::make_reverse_iterator(begin()); }
		constexpr const_reverse_iterator rend() const noexcept { return std::make_reverse_iterator(begin()); }
		constexpr const_reverse_iterator crend() const noexcept { return std::make_reverse_iterator(begin()); }

		//
		// General access functions.
		//

		pointer storage; // 0x4
		size_type storageCount; // 0x8 // # of slots in the array.
		size_type endIndex; // 0xC // First empty slot in the array.
		size_type filledCount; // 0x10 // Number of filled slots.
		size_type growByCount; // 0x14 // Number of slots to increase storage by.

#if !defined(MWSE_NO_CUSTOM_ALLOC) || MWSE_NO_CUSTOM_ALLOC == 0
		static void* operator new(size_type size) { return reinterpret_cast<void* (__cdecl*)(size_type)>(0x727692)(size); }
		static void operator delete(void* block) { reinterpret_cast<void(__cdecl*)(void*)>(0x727530)(block); }
#endif

		TArray(size_type size = 1) {
			storageCount = size;
			growByCount = size;
			endIndex = 0;
			filledCount = 0;
#if !defined(MWSE_NO_CUSTOM_ALLOC) || MWSE_NO_CUSTOM_ALLOC == 0
			storage = reinterpret_cast<T* (__cdecl*)(size_type)>(0x727692)(size * 4);
#else
			storage = new T[size];
#endif
		}

		TArray(const TArray& other) = delete;

		virtual ~TArray() {
#if !defined(MWSE_NO_CUSTOM_ALLOC) || MWSE_NO_CUSTOM_ALLOC == 0
			reinterpret_cast<void(__cdecl*)(void*)>(0x727530)(storage);
#else
			delete[] storage;
#endif
		}

		const T operator[](size_type index) const { return at(index); }

		constexpr reference at(size_type pos) {
			if (pos >= storageCount) {
				throw std::out_of_range("TES3::TArray::at - Access out of bounds.");
			}
			return storage[pos];
		}

		constexpr reference at(size_type pos) const {
			if (pos >= storageCount) {
				throw std::out_of_range("TES3::TArray::at - Access out of bounds.");
			}
			return storage[pos];
		}
		
		void fill(const_reference value) {
			for (size_type i = 0; i < storageCount; ++i) {
				setAtIndex(i, value);
			}
		}

		constexpr auto size() const noexcept {
			return storageCount;
		}

		constexpr bool empty() const noexcept {
			return filledCount == 0;
		}

		//
		// Non-STL functions.
		//

		value_type at_legacy(size_type pos) const {
			return storage[pos];
		}

		// getIndexOfValue returns -1 if not found.
		static constexpr int INVALID_INDEX = -1;
		int getIndexOfValue(const T value) const {
			if (!value) {
				return INVALID_INDEX;
			}

			for (size_type i = 0; i < endIndex; i++) {
				if (storage[i] == value) {
					return i;
				}
			}

			return INVALID_INDEX;
		}

		void setAtIndex(size_type index, const T value) {
			if (index >= storageCount) {
				return;
			}

			if (index < endIndex) {
				const auto& oldValue = storage[index];
				if (value) {
					if (!oldValue) {
						filledCount++;
					}
				}
				else if (oldValue) {
					filledCount--;
				}
			}
			else {
				endIndex = index + 1;
				if (value) {
					filledCount++;
				}
			}

			storage[index] = value;
		}

		void setSize(size_t size) {
			if (size == storageCount) {
				return;
			}

			if (size < endIndex) {
				for (auto i = size; i < endIndex; i++) {
					if (storage[i]) {
						storage[i] = 0;
						filledCount--;
					}
				}
				endIndex = size;
			}
#if !defined(MWSE_NO_CUSTOM_ALLOC) || MWSE_NO_CUSTOM_ALLOC == 0
			auto newStorage = reinterpret_cast<T* (__cdecl*)(size_t)>(0x727692)(size * 4);
#else
			auto newStorage = new T[size];
#endif
			for (auto i = 0; i < endIndex; i++) {
				newStorage[i] = storage[i];
			}
			mwse::tes3::_delete(storage);
			storage = newStorage;
			storageCount = size;
		}

		bool growToFit(size_t index) {
			if (index < storageCount) {
				return false;
			}

			setSize(std::max(storageCount + growByCount, index + 1));
			return true;
		}

		bool contains(const_reference value) const {
			return getIndexOfValue(value) >= 0;
		}

		size_type add(const_reference value) {
			size_type index = endIndex;

			if (index == storageCount) {
				setSize(storageCount + growByCount);
			}
			setAtIndex(index, value);
			return index;
		}

		size_type getFilledCount() const { return filledCount; }
		size_type getEndIndex() const { return endIndex; }

	};
	static_assert(sizeof(TArray<int>) == 0x18, "NI::TArray failed size validation");
	static_assert(offsetof(TArray<int>, storage) == 0x4, "NI::TArray::storage failed offset validation");
	static_assert(offsetof(TArray<int>, storageCount) == 0x8, "NI::TArray::storageCount failed offset validation");
	static_assert(offsetof(TArray<int>, endIndex) == 0xC, "NI::TArray::endIndex failed offset validation");
	static_assert(offsetof(TArray<int>, filledCount) == 0x10, "NI::TArray::filledCount failed offset validation");
	static_assert(offsetof(TArray<int>, growByCount) == 0x14, "NI::TArray::growByCount failed offset validation");
}
