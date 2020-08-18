#pragma once

#include "MemoryUtil.h"

namespace NI {
	template <typename T>
	class TArray {
	public:

		//
		// std interface functions
		//

		using value_type = T;
		using reference = value_type&;
		using const_reference = const T&;
		using pointer = T*;
		using const_pointer = const T*;
		using size_type = size_t;

		static constexpr int INVALID_INDEX = -1;

#pragma region STD iterator access
		class iterator {
		public:
			using self_type = iterator;
			using value_type = T;
			using reference = T&;
			using pointer = T*;
			using iterator_category = std::forward_iterator_tag;
			using difference_type = int;

			iterator(pointer p) : ptr(p) {}
			self_type operator++() { auto i = *this; ptr++; return i; }
			bool operator==(const self_type& rhs) { return ptr == rhs.ptr; }
			bool operator!=(const self_type& rhs) { return ptr != rhs.ptr; }
			self_type operator++(int) { ptr++; return *this; }
			reference operator*() { return *ptr; }
			pointer operator->() { return ptr; }

		private:
			pointer ptr;
		};

		class const_iterator {
		public:
			using self_type = const_iterator;
			using value_type = T;
			using reference = T&;
			using pointer = T*;
			using difference_type = int;
			using iterator_category = std::forward_iterator_tag;

			const_iterator(pointer p) : ptr(p) { }
			self_type operator++() { self_type i = *this; ptr++; return i; }
			self_type operator++(int) { ptr++; return *this; }
			const reference operator*() { return *ptr; }
			const pointer operator->() { return ptr; }
			bool operator==(const self_type& rhs) { return ptr == rhs.ptr; }
			bool operator!=(const self_type& rhs) { return ptr != rhs.ptr; }

		private:
			pointer ptr;
		};

		size_type size() const { return storageCount; }
		iterator begin() { return iterator(storage); }
		iterator end() { return iterator(storage + storageCount); }
		const_iterator begin() const { return const_iterator(storage); }
		const_iterator end() const { return const_iterator(storage + storageCount); }

#pragma endregion

	protected:
		value_type* storage; // 0x4
		size_type storageCount; // 0x8
		size_type endIndex; // 0xC
		size_type filledCount; // 0x10
		size_type growByCount; // 0x14

	public:

		//
		// Ensure that we use Morrowind's memory allocators.
		//

		static void* operator new(size_t size) {
			return mwse::tes3::_new(size);
		}

		static void operator delete(void* block) {
			return mwse::tes3::_delete(block);
		}

		//
		// Implementation.
		//

		TArray::TArray(size_type size = 1) {
			storageCount = size;
			growByCount = size;
			endIndex = 0;
			filledCount = 0;
			storage = reinterpret_cast<value_type*>(mwse::tes3::_new(size * sizeof(value_type)));
		}

		virtual TArray::~TArray() {
			mwse::tes3::_delete(storage);
		}

		reference operator[](const size_t index) {
			if (index >= storageCount) {
				throw std::out_of_range("TES3::TArray::operator[] - Access out of bounds.");
			}
			return storage[index];
		}

		const_reference operator[](const size_type index) const {
			if (index >= storageCount) {
				throw std::out_of_range("TES3::TArray::operator[] - Access out of bounds.");
			}
			return storage[index];
		}

		reference at(const size_t pos) const {
			if (pos >= storageCount) {
				throw std::out_of_range("TES3::TArray::at - Access out of bounds.");
			}
			return storage[pos];
		}

		// getIndexOfValue returns -1 if not found.
		int getIndexOfValue(const_reference value) const {
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

		void setAtIndex(size_t index, const T& value) {
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
			auto newStorage = reinterpret_cast<T*>(mwse::tes3::_new(size * sizeof(T)));
			for (auto i = 0U; i < endIndex; i++) {
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

		bool empty() const { return filledCount == 0; }
		size_type getFilledCount() const { return filledCount; }
		size_type getEndIndex() const { return endIndex; }
		size_type getGrowCount() const { return growByCount; }

	};
	static_assert(sizeof(TArray<void*>) == 0x18, "NI::TArray failed size validation");
}
