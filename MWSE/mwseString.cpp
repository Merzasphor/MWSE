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

// ID values. An ID is constructed as
//   two bytes, 'M' and 'S' characters
// XOR'd with clear_id << 8 (so usually one byte)
// XOR'd with next_id (usually one byte)
static mwLong_t next_id = 0;      // zeroed each clearStore()
static mwLong_t clear_id = 0;     // incremented each clearStore()
static mwLong_t id_overlay = ( ( ('M' << 8) | 'S' ) << 8 ) << 16;

mwseString_t::mwseString_t():
    my_id(nextID())
{
    store.insert(StringMap_t::value_type(my_id, *this));
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
    store.insert(StringMap_t::value_type(my_id, *this));
}

mwseString_t::mwseString_t(mwLong_t id):
    std::string(lookup(id)),
    my_id(lookup(id).my_id)
{
    // already in map
}

mwseString_t::operator mwLong_t() const
{
    return my_id;
}

bool mwseString_t::exists(mwLong_t id)
{
    return store.find(id) != store.end();
}

mwseString_t & mwseString_t::lookup(mwLong_t id)
{
    StringMap_t::iterator item = store.find(id);
    if (item == store.end()) {
        throw StringStoreException(id);
    }
    return item->second;
}

void mwseString_t::clearStore()
{
    clear_id++;
    next_id = 0;
    store.clear();
}

mwLong_t mwseString_t::nextID()
{
    next_id ++;
    return id_overlay ^ (clear_id << 8) ^ next_id;
}
