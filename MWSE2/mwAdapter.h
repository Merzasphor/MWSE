#pragma once

#include <windows.h>

namespace mwse
{
	namespace mwAdapter
	{
		struct Context
		{
			//general registers
			DWORD eax;
			DWORD ebx;
			DWORD ecx;
			DWORD edx;

			//string operators
			DWORD esi;
			DWORD edi;

			//stack
			DWORD ebp;
			DWORD esp;

			//flags (cmp, test)
			DWORD flags;

			DWORD callbackAddress; //address to return to
		};

		void Hook();
	}
}