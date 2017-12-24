/************************************************************************
               mwseString.cpp - Copyright (c) 2008 The MWSE Project
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

#include "mwseString.h"

using namespace mwse;

// ID values. 
//  In order to be usable in globals, string values must be restricted to 24 bits or less
// ( globals are floats, and therefore can store at most 24 bits of an integer without truncation).
//
// An ID is constructed as
//  one byte, 'S' character
// XOR'd with clear_id << 8 (so usually one byte)
// XOR'd with next_id (usually one byte)
// masked to fit in 24 bits
static mwLong_t next_id = 0;      // zeroed each clearStore(), if the store was non-empty
static mwLong_t clear_id = 0;     // incremented each clearStore()
static const mwLong_t id_overlay = ( 'S' ) << 16;
static const mwLong_t mask = (1<<24)-1; // 24 bit mask

mwseString_t::StringMap_t  mwseString_t::store;

mwseString_t::mwseString_t():
    my_id(-1)
{
}

mwseString_t::mwseString_t(const char *string):
    std::string(string),
    my_id(nextID())
{
    store.insert(StringMap_t::value_type(my_id, *this));
}

mwseString_t::mwseString_t(const mwseString_t &source):
    std::string(source),
    my_id(source.my_id)
{
}

mwseString_t::mwseString_t(mwLong_t id):
    std::string(lookup(id)),
    my_id(lookup(id).my_id)
{
    // already in map
}

mwseString_t::mwseString_t(const char *string, size_t length):
	std::string(string, length),
	my_id(nextID())
{
	store.insert(StringMap_t::value_type(my_id, *this));
}

mwseString_t::operator mwLong_t() const
{
    if (my_id == -1) return 0;
    return my_id;
}

bool mwseString_t::exists(mwLong_t id)
{
    return store.find(id) != store.end();
}

bool mwseString_t::exists(const char* string)
{
	for (StringMap_t::iterator it = store.begin(); it != store.end(); it++) {
		if (it->second.compare(string) == 0) {
			return true;
		}
	}

	return false;
}

mwseString_t & mwseString_t::lookup(mwLong_t id)
{
    StringMap_t::iterator item = store.find(id);
    if (item == store.end()) {
        throw StringStoreException(id);
    }
    return item->second;
}

mwseString_t& mwseString_t::lookup(const char* string) {
	for (StringMap_t::iterator it = store.begin(); it != store.end(); it++) {
		if (it->second.compare(string) == 0) {
			return it->second;
		}
	}

	return mwseString_t();
}

void mwseString_t::clearStore()
{
    if (next_id != 0) clear_id++;
    next_id = 0;
    store.clear();
}

mwseString_t& mwseString_t::get(mwLong_t id) {
	if (exists(id)) {
		return lookup(id);
	}
	else {
		return mwseString_t();
	}
}

mwseString_t& mwseString_t::get(const char* string) {
	if (exists(string)) {
		return lookup(string);
	}
	else {
		return mwseString_t(string);
	}
}

mwLong_t mwseString_t::nextID()
{
    next_id ++;
    return mask & (id_overlay ^ (clear_id << 8) ^ next_id);
}
