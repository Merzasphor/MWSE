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

namespace mwse
{
	namespace string
	{
		mwseString_t interpolate(const mwseString_t& format, mwse::VMExecuteInterface &virtualMachine, bool* suppressNull, std::string* badCodes);

		// Count how many results there should be based on the format string
		bool enumerate(const char *format, int& substitutions, bool& eolmode);

		// Extract the values from the string based on the format data and store them in the resultset array
		int secernate(const char* format, const char* string, mwLong_t* results, int maxResults);
	}
};
