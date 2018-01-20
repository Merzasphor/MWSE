/************************************************************************
	
	StringUtil.h - Copyright (c) 2008 The MWSE Project
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

#include "VMExecuteInterface.h"
#include "mwseTypes.h"
#include "mwseString.h"

namespace mwse {
	namespace string {
		namespace store {
			// Type of our string storage.
			typedef std::map<mwLong_t, mwseString_t> StringMap_t;

			extern mwLong_t nextId;

			extern StringMap_t store;

			mwseString_t& create(const std::string& value);

			mwseString_t& create(const char* value);

			mwseString_t& create(const char* value, size_t length);

			bool clear();

			bool exists(const mwLong_t id);

			bool exists(const std::string& value);

			bool exists(const char* value);

			mwseString_t& get(const mwLong_t id);

			mwseString_t& get(const std::string& value);

			mwseString_t& getOrCreate(const std::string& value);

			mwseString_t& getOrCreate(const char* value);

			mwseString_t& getOrCreate(const char* value, size_t length);
		}

		//
		// String pattern searching functions.
		//

		std::string interpolate(const std::string& format, mwse::VMExecuteInterface &virtualMachine, bool* suppressNull, std::string* badCodes);

		// Count how many results there should be based on the format string
		bool enumerate(const char *format, int& substitutions, bool& eolmode);

		// Extract the values from the string based on the format data and store them in the resultset array
		int secernate(const char* format, const char* string, mwLong_t* results, int maxResults);
	}
};
