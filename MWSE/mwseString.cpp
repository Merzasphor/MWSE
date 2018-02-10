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

#include "Log.h"

#define DEBUG_STRING_CREATION false

using namespace mwse;

mwseString_t::mwseString_t() :
	std::string(""),
	m_ID(-1)
{
#if DEBUG_STRING_CREATION
	mwse::log::getDebug() << "mwseString_t: Created invalid string." << std::endl;
#endif
}

mwseString_t::mwseString_t(mwLong id) :
	std::string(""),
	m_ID(id)
{
#if DEBUG_STRING_CREATION
	mwse::log::getDebug() << "mwseString_t: Created new string of id '" << m_ID << "' with empty value." << std::endl;
#endif
}

mwseString_t::mwseString_t(mwLong id, const char* value) :
	std::string(value),
	m_ID(id)
{
#if DEBUG_STRING_CREATION
	mwse::log::getDebug() << "mwseString_t: Created new string of id '" << m_ID << "' value '" << value << "'." << std::endl;
#endif
}

mwseString_t::mwseString_t(mwLong id, const char* value, size_t length) :
	std::string(value, length),
	m_ID(id)
{
#if DEBUG_STRING_CREATION
	mwse::log::getDebug() << "mwseString_t: Created new string of id '" << m_ID << "' value '" << value << "'." << std::endl;
#endif
}

mwseString_t::mwseString_t(mwLong id, const std::string& value) :
	std::string(value),
	m_ID(id)
{
#if DEBUG_STRING_CREATION
	mwse::log::getDebug() << "mwseString_t: Created new string of id '" << m_ID << "' value '" << value << "'." << std::endl;
#endif
}

mwseString_t::operator mwLong() const
{
	if (m_ID == -1) return 0;
	return m_ID;
}

bool mwseString_t::isValid()
{
	return m_ID != -1;
}

mwLong mwseString_t::getId()
{
	return m_ID;
}
