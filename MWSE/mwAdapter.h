/************************************************************************
	
	mwAdapter.h - Copyright (c) 2008 The MWSE Project
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

#pragma once

#include <windows.h>

namespace mwse
{
	class VirtualMachine;

	namespace mwAdapter
	{
		// Container for registers, flags, and other information to help with the
		// native to MWSE code bridge.
		struct Context_t
		{
			// General registers.
			DWORD eax;
			DWORD ebx;
			DWORD ecx;
			DWORD edx;

			// String operators.
			DWORD esi;
			DWORD edi;

			// Stack.
			DWORD ebp;
			DWORD esp;

			// Flags (cmp, test).
			DWORD flags;

			// Address to return to.
			DWORD callbackAddress;
		};

		void Hook();

		VirtualMachine* GetVMInstance();
	}
}