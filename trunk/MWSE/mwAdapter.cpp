#include "mwAdapter.h"
#include "MemAccess.h"

using namespace mwse;
using namespace mwAdapter;

namespace mwse
{
	namespace mwAdapter
	{
		static Context_t context;

		//-----------------------------------------------
		//-----------------------------------------------
		//in these functions you should call the virtualmachine, and set things as neccecary, and when done set the correct registers in their correct state

		//in here you can use normal code :), this is called when the hook is called
		//cannot chance return address
		static void _stdcall HookGetNextInstructionIndirect()
		{
			//context.eax = opcode (you need to make this zero (0x0), when the opcode is processed by MWSE)
			//context.ebx = reference (SCPTDataPointer)
			//context.ebp = scriptIP (you need to write it back to address: 0x7CEBB0 !!!)
		}

		//in here you can use normal code :), this is called when the hook is called
		//can chance return address
		static void _stdcall HookRunFunctionIndirect()
		{
			//context.edx = opcode
			//context.callbackAddress = '0x505837' when MWSE does not process the opcode, and should be '0x50D62D' when MWSE DOES process the opcode, first value is default (0x505837)!
		}

		//-----------------------------------------------
		//-----------------------------------------------

		//code to generate a Jump in memory, don't forget to unprotect it first!
		void genJump(DWORD Address, DWORD To) //5 bytes
		{
			MemAccess<char>::Set(Address, 0xE9); //jump ...
			MemAccess<DWORD>::Set(Address + 1, To - Address - 0x5); //Destination
		}

		//code to generate a Call in memory, don't forget to unprotect it first!
		void genCall(DWORD Address, DWORD To) //5 bytes
		{
			MemAccess<char>::Set(Address, 0xE8); //call ...
			MemAccess<DWORD>::Set(Address + 1, To - Address - 0x5); //Destination
		}
		void genNOP(DWORD Address) //1 byte
		{
			MemAccess<char>::Set(Address, 0x90); //NOP ...
		}

		static const DWORD getNextInstructionReturnAddress = 0x500561;
		static const DWORD getNextInstructionOverwriteAddress = 0x7CEC08;
		static __declspec(naked) void HookGetNextInstructionDirect()
		{
			_asm
			{
				//save eax
				mov context.eax, eax

				//save the flags
				pushfd
				pop eax
				mov context.flags, eax

				mov context.ebx, ebx
				mov context.ecx, ecx
				mov context.edx, edx

				mov context.esi, esi
				mov context.edi, edi

				mov context.ebp, ebp
				mov context.esp, esp

				//overwritten code (chanced a little to work :P)
				mov eax, getNextInstructionOverwriteAddress
				mov [eax], esi
				//---

				call HookGetNextInstructionIndirect //call second function

				//restore all registers and flags
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

				//return
				jmp getNextInstructionReturnAddress
			}
		}



		//---
		static __declspec(naked) void HookRunFunctionDirect()
		{
			_asm
			{
				//save eax
				mov context.eax, eax

				//save the flags
				pushfd
				pop eax
				mov context.flags, eax

				mov context.ebx, ebx
				mov context.ecx, ecx
				mov context.edx, edx

				mov context.esi, esi
				mov context.edi, edi

				mov context.ebp, ebp
				mov context.esp, esp

				mov context.callbackAddress, 0x505837 //set the default return address

				call HookRunFunctionIndirect //call second function

				//restore all registers and flags
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

				//overwritten code
				add edx, 0x0FFFFF000
				//---

				//return
				jmp context.callbackAddress
			}
		}

		void Hook()
		{
			DWORD OldProtect;

			VirtualProtect((DWORD*)0x50055B, 0x6, PAGE_READWRITE, &OldProtect);
			genJump(0x50055B, reinterpret_cast<DWORD>(HookGetNextInstructionDirect));
			genNOP(0x500560);
			VirtualProtect((DWORD*)0x50055B, 0x6, OldProtect, &OldProtect);

			VirtualProtect((DWORD*)0x505831, 0x6, PAGE_READWRITE, &OldProtect);
			genJump(0x505831, reinterpret_cast<DWORD>(HookRunFunctionDirect));
			genNOP(0x505836);
			VirtualProtect((DWORD*)0x505831, 0x6, OldProtect, &OldProtect);
		}

	}
}