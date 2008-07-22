/************************************************************************
               Reference.h - Copyright (c) 2008 The MWSE Project
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

namespace mwse
{
	class Reference { 
		Reference(void *item_address): 
	my_id(nextID()) 
	{ 
		map[my_id] = item_address; 
		map_count[my_id] = 1; 
		// map_frame[my_id] = ? 
	} 
	~Reference() 
	{ 
		map_count[my_id]--; 
	} 
	Reference(const Reference &source): 
	my_id(source.my_id) 
	{ 
		map_count[my_id]++; 
		// map_frame[my_id] = ? // update frame of reference 
	} 
	Reference &operator =(const Reference &source) 
	{ 
		if (my_id != source.my_id) { 
			map_count[my_id]--; 
			my_id = source.my_id; 
			map_count[my_id]++; 
		} 
		// map_frame[my_id] = ? // update frame of reference 
	} 
	operator void*() const
	{ 
		return map[my_id]; 
		// map_frame[my_id] = ? // update frame of reference 
	} 
	operator float() const
	{ 
		return static_cast<float>(my_id); 
		// map_frame[my_id] = ? // update frame of reference 
	} 
	private: 
		int my_id; 
		static const size_t map_size = (1<<24);
		static void *map[map_size]; 
		static int   map_count[map_size]; 
		static int   map_frame[map_size]; 
		static int   last_id; 

		static int nextID()
		{ 
			bool found = false; 
			int  id = last_id; 
			int  count = 0; 
			while(!found && count < map_size) { 
				if (id == map_size + 1) id = -1;    // wraparound 
				found = map_count[++id] == 0; 
				count++; 
			} 
			if (!found) { 
				// find least recently used reference and use that 
			} 
		} 
	};
}