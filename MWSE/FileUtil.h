/************************************************************************
	
	FileUtil.h - Copyright (c) 2008 The MWSE Project
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
#include "mwseString.h"
#include "Log.h"

/**
*
*/
namespace mwse {
	namespace file {
		int read(const char* filename, void* pdata, int size) {
			int result = 0;
			HANDLE file = cache.getfile(filename);
			if (file != INVALID_HANDLE_VALUE)
			{
				//Tp21 2006-06-21: Stop MWSE getting stuck if there's no data available to be read (original code from timeslip)
				if (*filename == '|') { //check if it's an pipe
					DWORD toread;
					PeekNamedPipe(file, NULL, 0, NULL, &toread, NULL); //look if there is something to read
					if (!toread) return 0; //if not, return
				}

				DWORD red = 0;
				ReadFile(file, pdata, size, &red, 0);
				result = (int)red;
			}

			return result;
		}

		int readcstring(const char* filename, char* string, int bufsize) {

		}

		int write(const char* filename, const void* pdata, int size) {

		}

		bool seek(const char* filename, long absolute) {

		}
	}
}