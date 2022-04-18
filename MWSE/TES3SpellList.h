#pragma once

#include "TES3Defines.h"

#include "TES3IteratedList.h"
#include "TES3Spell.h"

namespace TES3 {
	struct SpellList {
		int unknown_0x0;
		IteratedList<Spell*> list;

		//
		// Other related this-call functions.
		//

		bool add(Spell*);
		bool add(const char*);
		bool add(const std::string&);

		bool remove(Spell*);
		bool remove(const char*);
		bool remove(const std::string&);

		bool contains(Spell*);
		bool contains(const char*);
		bool contains(const std::string&);

		Spell* getCheapest();

		//
		// Custom functions.
		//

		bool add_lua(sol::object value);
		bool remove_lua(sol::object value);
		bool contains_lua(sol::object value);

		bool containsType(SpellCastType::value_type);

		//
		// Container wrapping methods.
		// This allows lua and C++ to interface with this container as if it were the wrapped object.
		//

		using T = Spell*;
		using value_type = T;
		using size_type = size_t;
		using difference_type = int;
		using pointer = T*;
		using const_pointer = const T*;
		using reference = T&;
		using const_reference = const T&;
		using iterator = IteratedList<Spell*>::iterator;
		using const_iterator = const iterator;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		iterator begin() const { return list.begin(); }
		iterator end() const { return list.end(); }
		reverse_iterator rbegin() const { return std::make_reverse_iterator(end()); }
		reverse_iterator rend() const { return std::make_reverse_iterator(begin()); }
		const_iterator cbegin() const { return begin(); }
		const_iterator cend() const { return end(); }
		const_reverse_iterator crbegin() const { return rbegin(); }
		const_reverse_iterator crend() const { return rend(); }
		size_type size() const noexcept { return list.count; }
		bool empty() const noexcept { return list.count == 0; }
	};
}
