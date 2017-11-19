/************************************************************************
               Log.cpp - Copyright (c) 2008 The MWSE Project
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

#include "Log.h"

#include <fstream>
#include <ostream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace mwse;
using namespace log;

//debug output stream
template <class CharT, class TraitsT = std::char_traits<CharT> >
class basic_debugbuf :
	public std::basic_stringbuf<CharT, TraitsT>
{
public:
	virtual ~basic_debugbuf()
	{
		sync();
	}

protected:
	int sync()
	{
	}
	void output_debug_string(const CharT *text)
	{
	}
};

template<>
int basic_debugbuf<char>::sync()
{
	OutputDebugStringA(str().c_str());
    return 0;
}

template<class CharT, class TraitsT = std::char_traits<CharT> >
class basic_dostream : 
    public std::basic_ostream<CharT, TraitsT>
{
public:

    basic_dostream() : std::basic_ostream<CharT, TraitsT>
                (new basic_debugbuf<CharT, TraitsT>()) {}
    ~basic_dostream() 
    {
//        delete rdbuf(); 
    }
};

typedef basic_dostream<char>	odstream;


namespace mwse
{
	namespace log
	{
		static std::ofstream logstream;
		static odstream debugstream;

		void OpenLog(const char *path)
		{
			logstream.open(path);
		}

		void CloseLog()
		{
			logstream.close();
		}

		std::ostream& getLog()
		{
			return logstream;
		}

		std::ostream& getDebug()
		{
			return debugstream;
		}

		std::ostream& dump(std::ostream& output, void *data, size_t size)
		{
			unsigned char *cp = reinterpret_cast<unsigned char *>(data);
			for (size_t i = 0; i < size; i++)
			{
				if (i % 16 == 0 && i != 0) output << std::endl;
				output << std::hex << std::setw(2) << std::setfill('0') << *cp++;
			}
			output << std::endl;

			return output;
		}
	}
}