/************************************************************************

	mwAdapter.cpp - Copyright (c) 2008 The MWSE Project
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

#include "mwOffsets.h"
#include "mwAdapter.h"
#include "MemAccess.h"

#include "VirtualMachine.h"

using namespace mwse;
using namespace mwAdapter;

namespace mwse
{
	namespace mwAdapter
	{
		// House the registers obtained before/to return after hooking a function.
		static Context_t context;

		// Our virtual machine. It's not really a virtual machine, and all the heavy
		// lifting is still done by the Morrowind scripting VM.
		static VirtualMachine vmInstance;

		// Determines if we want to own this opcode, and handles it if so.
		static void _stdcall HookGetNextInstructionIndirect()
		{
			mwOpcode_t opcode = context.eax;

			if (vmInstance.isOpcode(opcode))
			{
				SCPTRecord_t * script = reinterpret_cast<SCPTRecord_t*>(context.ebx);

				vmInstance.loadParametersForOperation(opcode, context, *script);

				// Set eax to zero. This tells Morrowind that the opcode is invalid and it will return GetNextInstruction.
				// It doesn't throw any errors when doing so.
				context.eax = 0x0;
			}
		}

		// If we own the opcode here, execute the code assigned to it.
		static float _stdcall HookRunFunctionIndirect()
		{
			mwOpcode_t opcode = context.edx;

			if (vmInstance.isOpcode(opcode))
			{
				SCPTRecord_t * script = *(reinterpret_cast<SCPTRecord_t**>(context.esp + 0x8));

				// Our default return address. This can be changed below.
				context.callbackAddress = 0x50D62D;

				float returnValue = vmInstance.executeOperation(opcode, context, *script);

				long * returnESI = reinterpret_cast<long*>(context.esp + 4);
				*returnESI = *(vmInstance.getScriptIP());

				return returnValue;
			}
			else
			{
				return 0.0;
			}
		}

		// Code to generate a jump in memory. Don't forget to unprotect it first!
		void genJump(DWORD Address, DWORD To)
		{
			MemAccess<unsigned char>::Set(Address, 0xE9);
			MemAccess<DWORD>::Set(Address + 1, To - Address - 0x5);
		}

		// Code to generate a call in memory. Don't forget to unprotect it first!
		void genCall(DWORD Address, DWORD To)
		{
			MemAccess<unsigned char>::Set(Address, 0xE8);
			MemAccess<DWORD>::Set(Address + 1, To - Address - 0x5);
		}

		// Code to generate a nop in memory. Don't forget to unprotect it first!
		void genNOP(DWORD Address)
		{
			MemAccess<unsigned char>::Set(Address, 0x90);
		}

		// Hook scaffolding for HookGetNextInstructionIndirect().
		static const DWORD getNextInstructionReturnAddress = 0x500561;
		static __declspec(naked) void HookGetNextInstructionDirect()
		{
			_asm
			{
				// Save eax.
				mov context.eax, eax

				// Save the flags.
				pushfd
				pop eax
				mov context.flags, eax

				// Save the other registers.
				mov context.ebx, ebx
				mov context.ecx, ecx
				mov context.edx, edx
				mov context.esi, esi
				mov context.edi, edi
				mov context.ebp, ebp
				mov context.esp, esp

				// Overwritten code. This is adjusted slightly.
				//! TODO: Why was this changed?
				mov eax, 0x7CEC08
				mov[eax], esi

				// Actually use our hook.
				call HookGetNextInstructionIndirect

				// Restore all registers and flags.
				mov eax, context.eax
				mov ebx, context.ebx
				mov ecx, context.ecx
				mov edx, context.edx
				mov esi, context.esi
				mov edi, context.edi
				mov ebp, context.ebp
				mov esp, context.esp
				push context.flags
				popfd

				// Resume normal execution. This can't be changed.
				jmp getNextInstructionReturnAddress
			}
		}

		// Hook scaffolding for HookRunFunctionIndirect().
		static __declspec(naked) void HookRunFunctionDirect()
		{
			_asm
			{
				// Save eax.
				mov context.eax, eax

				// Save the flags.
				pushfd
				pop eax
				mov context.flags, eax

				// Save the other registers.
				mov context.ebx, ebx
				mov context.ecx, ecx
				mov context.edx, edx
				mov context.esi, esi
				mov context.edi, edi
				mov context.ebp, ebp
				mov context.esp, esp

				// Store our default return address. HookRunFunctionIndirect may
				// change this (relatively) safely.
				mov context.callbackAddress, 0x505837

				// Actually use our hook.
				call HookRunFunctionIndirect

				// Restore all registers and flags.
				mov eax, context.eax
				mov ebx, context.ebx
				mov ecx, context.ecx
				mov edx, context.edx
				mov esi, context.esi
				mov edi, context.edi
				mov ebp, context.ebp
				mov esp, context.esp
				push context.flags
				popfd

				// We use the stack from original runFunction, adjust to compensate.
				// Store FPU FP0 in [esp+0C], and pop it off the stack.
				fstp[esp + 0x0C]

				// Overwritten code from our hook that we need to duplicate.
				add edx, 0x0FFFFF000

				// Return to where execution was before.
				jmp context.callbackAddress
			}
		}

		// Put our hooks into the Morrowind engine.
		void Hook()
		{
			DWORD OldProtect;

			// Add our first hook. This hook happens when Morrowind is trying to
			// determine the next instruction. We determine if we want to own the
			// opcode and set up anything important here.
			VirtualProtect((DWORD*)TES3_HOOK_GET_NEXT_INSTRUCTION, TES3_HOOK_GET_NEXT_INSTRUCTION_SIZE, PAGE_READWRITE, &OldProtect);
			genJump(TES3_HOOK_GET_NEXT_INSTRUCTION, reinterpret_cast<DWORD>(HookGetNextInstructionDirect));
			genNOP(TES3_HOOK_GET_NEXT_INSTRUCTION_RETURN - 1);
			VirtualProtect((DWORD*)TES3_HOOK_GET_NEXT_INSTRUCTION, TES3_HOOK_GET_NEXT_INSTRUCTION_SIZE, OldProtect, &OldProtect);

			// Add our second hook. This is where the actual run call would get
			// executed, and if we own the opcode we again take over and run our code.
			VirtualProtect((DWORD*)TES3_HOOK_RUN_FUNCTION, TES3_HOOK_RUN_FUNCTION_SIZE, PAGE_READWRITE, &OldProtect);
			genJump(TES3_HOOK_RUN_FUNCTION, reinterpret_cast<DWORD>(HookRunFunctionDirect));
			genNOP(TES3_HOOK_RUN_FUNCTION_RETURN - 1);
			VirtualProtect((DWORD*)TES3_HOOK_RUN_FUNCTION, TES3_HOOK_RUN_FUNCTION_SIZE, OldProtect, &OldProtect);
		}

		// If we need access to our virtual machine outside of the usual context,
		// this is how we get it. Useful for things like our MGE XE interface hack.
		VirtualMachine* GetVMInstance()
		{
			return &vmInstance;
		}
	}
}