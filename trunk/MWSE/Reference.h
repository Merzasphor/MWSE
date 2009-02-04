/************************************************************************
               Stack.h - Copyright (c) 2008 The MWSE Project
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

#include "mwseTypes.h"
#include <cstdlib>
#include <map>
#include "Log.h"

namespace mwse {
    class Reference {
      public:
        Reference(void *address)    // construct reference from address
        {
            // ASSUMPTION: All address do not have the high bit set
            this->key = reinterpret_cast<mwLong_t>(address);
            // If the value cannot be stored as a Morrowind float, it must be translated
            if (static_cast<mwFloat_t>(this->key) != this->key) {
                // Lookup or add to dictionary.
                this->key = dictionary_key(address);
            }
        }
        
        Reference(mwLong_t key)     // construct reference from key
        {
            this->key = key;
        }

        Reference(const Reference &source)  // copy constructor
        {
            this->key = source.key;
        }

        mwLong_t getKey() const
        {
            return this->key;
        }

        void *getAddress() const
        {
            return (this->key < 0) ? dictionary_value(key) : reinterpret_cast<void *>(key);
        }

        Reference &operator=(const Reference &source)  // assignment operator
        {
            this->key = source.key;
			return *this;
        }

        operator mwLong_t() const           // convert
        {
            return getKey();
        }
        
        operator void *() const
        {
            return getAddress();
        }

    private:
        mwLong_t    key;

        typedef std::map<void *, mwLong_t> map_by_address_t;
        static map_by_address_t map_by_address;
        typedef std::map<mwLong_t, void *> map_by_key_t;
        static map_by_key_t map_by_key;

        static mwLong_t dictionary_key(void *address)
        {
            map_by_address_t::iterator point = map_by_address.find(address);
            if (point == map_by_address.end()) {
                // Note old keys are never released. This is based on the assumption there won't begin
                // that many addresses that don't map to float with no loss of precision.

				//DEBUG
				log::getLog() << "Creating new Reference key" << std::endl;
				//DEBUG

                mwLong_t key = -1 - map_by_address.size();
                map_by_address[address] = key;
                map_by_key[key] = address;
                return key;
            } else {
                return point->second;
            }
        }
        static void *dictionary_value(mwLong_t key)
        {
            map_by_key_t::iterator point = map_by_key.find(key);
            if (point != map_by_key.end()) {
                return point->second;
            } else {
                return NULL;
            }
        }
    };
};
