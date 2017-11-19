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
    /**
     * A string implementation for mwse. Derived from std::string; however,
     * the strings can also be identified by a value stored in a mwLong_t.
     * This value is an ID; invalid IDs will cause exceptions.
     */
    class mwseString_t: public std::string {
        public:
            mwseString_t();
            mwseString_t(const char *string);
            mwseString_t(const mwseString_t &source); // copy constructor
            mwseString_t(mwLong_t id);          // find and initialize from ID
			mwseString_t(const char *string, size_t length);

            operator mwLong_t() const;          // cast to mwLong_t

            static bool exists(mwLong_t id);    // true if given string known
            static mwseString_t &lookup(mwLong_t id);
            static void clearStore();           // release all stored strings
            class StringStoreException: public std::exception {
              public:
                StringStoreException(mwLong_t ctor_id):
                  id(ctor_id)
                {
                };
                const mwLong_t id;
                virtual const char *what() const throw()
                {
                    return "String no longer found in storage";
                }
            };
        private:
            mwLong_t            my_id;

            static mwLong_t     nextID();

            typedef std::map<mwLong_t, mwseString_t>    StringMap_t;
            static StringMap_t  store;          // storage for strings
    };
};
