/************************************************************************
			   mwseString.cpp - Copyright (c) 2008 The MWSE Project
				https://github.com/MWSE/MWSE/

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

#include "Log.h"

#define DEBUG_STRING_CREATION true

using namespace mwse;

mwseString::mwseString() :
	std::string(""),
	m_ID(-1)
{
#if DEBUG_STRING_CREATION
	mwse::log::getDebug() << "mwseString: Created invalid string." << std::endl;
#endif
}

mwseString::mwseString(long id) :
	std::string(""),
	m_ID(id)
{
#if DEBUG_STRING_CREATION
	mwse::log::getDebug() << "mwseString: Created new string of id '" << m_ID << "' with empty value." << std::endl;
#endif
}

mwseString::mwseString(long id, const char* value) :
	std::string(value),
	m_ID(id)
{
#if DEBUG_STRING_CREATION
	mwse::log::getDebug() << "mwseString: Created new string of id '" << m_ID << "' value '" << value << "'." << std::endl;
#endif
}

mwseString::mwseString(long id, const char* value, size_t length) :
	std::string(value, length),
	m_ID(id)
{
#if DEBUG_STRING_CREATION
	mwse::log::getDebug() << "mwseString: Created new string of id '" << m_ID << "' value '" << this->c_str() << "' (" << length << ")." << std::endl;
#endif
}

mwseString::mwseString(long id, const std::string& value) :
	std::string(value),
	m_ID(id)
{
#if DEBUG_STRING_CREATION
	mwse::log::getDebug() << "mwseString: Created new string of id '" << m_ID << "' value '" << value << "'." << std::endl;
#endif
}

mwseString::operator long() const
{
	if (m_ID == -1) return 0;
	return m_ID;
}

bool mwseString::isValid()
{
	return m_ID != -1;
}

long mwseString::getId()
{
	return m_ID;
}
