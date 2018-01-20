/************************************************************************
			   mwseString.h - Copyright (c) 2008 The MWSE Project
				http://www.sourceforge.net/projects/mwse

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#pragma once

#include <string>
#include <map>
#include <exception>

#include "mwseTypes.h"

namespace mwse {
	/*
		A string implementation for mwse. Derived from std::string; however, the strings
		can also be identified by a value stored as a mwLong_t. This value is an ID;
		invalid IDs will cause exceptions.

		Because strings are exclusively referenced by this ID, this class shouldn't
		be instantiated frequently. Instead, the lookup() and get() functions should
		be used to get a mutable reference to the string.
	*/
	class mwseString_t : public std::string {
	public:
		// Constructor for an invalid string.
		mwseString_t();

		// Constructs a new mwseString 
		mwseString_t(mwLong_t id);

		// 
		mwseString_t(mwLong_t id, const char* value);

		// 
		mwseString_t(mwLong_t id, const char* value, size_t length);

		// 
		mwseString_t(mwLong_t id, const std::string& value);

		// Get only the id of the string.
		operator mwLong_t() const;

		// Determines if the string has a valid ID.
		bool isValid();

		// Get the ID of the string.
		mwLong_t getId();

	private:
		// Unique identifier for the string, used to identify strings back to mwscript.
		mwLong_t m_ID;
	};
};
