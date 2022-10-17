#pragma once

#include "TES3Defines.h"

namespace TES3::UI {
	template <typename T>
	struct Vector {
		char tag;
		T* first;
		T* nextEmpty;
		T* storageEnd;

		Vector() = delete;
		~Vector() = delete;

		using iterator = T*;
		using const_iterator = const iterator;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		constexpr iterator begin() noexcept { return first; }
		constexpr const_iterator begin() const noexcept { return first; }
		constexpr const_iterator cbegin() const noexcept { return begin(); }
		constexpr iterator end() noexcept { return nextEmpty; }
		constexpr const_iterator end() const noexcept { return nextEmpty; }
		constexpr const_iterator cend() const noexcept { return end(); }

		constexpr reverse_iterator rbegin() noexcept { std::make_reverse_iterator(end()); }
		constexpr const_reverse_iterator rbegin() const noexcept { return std::make_reverse_iterator(end()); }
		constexpr const_reverse_iterator crbegin() const noexcept { return std::make_reverse_iterator(end()); }
		constexpr reverse_iterator rend() noexcept { std::make_reverse_iterator(begin()); }
		constexpr const_reverse_iterator rend() const noexcept { return std::make_reverse_iterator(begin()); }
		constexpr const_reverse_iterator crend() const noexcept { return std::make_reverse_iterator(begin()); }
	};
	static_assert(sizeof(Vector<void>) == 0x10, "TES3::UI::Vector failed size validation");
}
