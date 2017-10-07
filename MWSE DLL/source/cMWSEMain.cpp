#include <windows.h>
#include <dbghelp.h>

#include "cMWSEMain.h"

void* external_malloc = NULL;
void* external_free = NULL;
void* external_realloc = NULL;
TES3MACHINE* cMWSEMain::vScriptMachine;
HWBREAKPOINT* cMWSEMain::vHWBreakpoint;
VPVOID cMWSEMain::vPrevScript;

static BOOL CALLBACK EnumSymbolsCallback(PSYMBOL_INFO symbol_info,
										 ULONG /*symbol_size*/, 
										 PVOID /*user_context*/);

void cMWSEMain::mStartMWSE()
{
	vScriptMachine = new TES3MACHINE();
	AddBreakpoint(BP_RUNSCRIPT, mOnRunScript);
	AddBreakpoint(BP_FIXUPSCRIPT, mOnFixupScript);
	// Find the addresses of malloc(), realloc(), free() that MW uses,
	// so that we can interact with its heap.
	HANDLE process = GetCurrentProcess();
	SymInitialize(process,
		NULL,  // No search path.
		TRUE); // Load symbol tables for all modules.
	SymEnumSymbols(process,
		0,                    // No base address.
		"msvcrt!*",           // Only look in msvcrt.dll.
		EnumSymbolsCallback,
		NULL);                // No context.
	SymCleanup(process);
	if (!external_malloc) {
		cLog::mLogMessage("Error: unable to find malloc()\n");
	}
	if (!external_free) {
		cLog::mLogMessage("Error: unable to find free()\n");
	}
	if (!external_realloc) {
		cLog::mLogMessage("Error: unable to find realloc()\n");
	}
	vScriptMachine->set_external_malloc(external_malloc);
	vScriptMachine->set_external_free(external_free);
	vScriptMachine->set_external_realloc(external_realloc);
}

void cMWSEMain::mOnRunScript(Context *context)
{
	AddBreakpoint(BP_FIXUPSCRIPT, mOnFixupScript);
	RemoveBreakpoint(BP_RUNSCRIPT);

	AddBreakpoint(BP_RUNFUNCIDXERR, mOnRunFuncIdxError);
	RemoveBreakpoint(BP_DECODEWITHINFO);
}

void cMWSEMain::mOnFixupScript(Context *context)
{
	AddBreakpoint(BP_RUNSCRIPT, mOnRunScript);
	RemoveBreakpoint(BP_FIXUPSCRIPT);

	AddBreakpoint(BP_DECODEWITHINFO, mOnDecode);
	RemoveBreakpoint(BP_RUNFUNCIDXERR);
}

void cMWSEMain::mOnDecode(Context *context)
{
	if(vScriptMachine->IsInstruction(context->Eax))
	{
		mChangeReference((VPVOID)context->Ebx); //script

		VMREGTYPE ip = (VMREGTYPE)context->Ebp; //sip

		if(vScriptMachine->SetRegister(IP, ip))
		{
			while(vScriptMachine->step(true))
			{
			}
			vScriptMachine->step(true);

			if(vScriptMachine->GetRegister(IP, ip))
			{
				OPCODE opcode = 0;
				if(vScriptMachine->GetInstruction((VPVOID)ip, opcode)
					&& vScriptMachine->WriteMem((VPVOID)context->Esp + sizeof(context->Edi), &ip, sizeof(ip)))
				{
					context->Eax = (DWORD)opcode;
					context->Ebp = (DWORD)ip;
				}
				else
					cLog::mLogMessage("DLL: OnDecode: GetInstruction failed\n");
			}
			else
				cLog::mLogMessage("DLL: OnDecode: GetRegister(IP) failed\n");
		}
		else
			cLog::mLogMessage("DLL: OnDecode: SetRegister(IP) failed\n");
	}
}

void cMWSEMain::mOnRunFuncIdxError(Context *context)
{
	OPCODE opcode = RUNFUNCIDXTOCODE(context->Edx);
	VPVOID stack = (VPVOID)context->Esp;

	if(vScriptMachine->IsInstruction(opcode))
	{
		VPVOID ppscript = (VPVOID)context->Ebp + 0x48;
		VPVOID pscript = 0;

		if(vScriptMachine->ReadMem(ppscript, &pscript, sizeof(pscript)))
		{
			mChangeReference(pscript);

			VMREGTYPE ip = 0;
			
			if(vScriptMachine->ReadMem(stack + sizeof(context->Edi), &ip, sizeof(ip)))
			{
				ip -= sizeof(OPCODE);
				vScriptMachine->SetRegister(IP, (VMREGTYPE)ip);

				context->Eip = (DWORD)reltolinear(RUNFUNCIDXERRCONTINUE);
				vScriptMachine->SetVMDebuggerBreakpoint(0);
				vScriptMachine->SetFlow(*context);
				vScriptMachine->step();

				if(vScriptMachine->GetRegister(IP, ip))
				{
					if(vScriptMachine->WriteMem(stack + sizeof(context->Edi), &ip, sizeof(ip)))
					{
						*context = vScriptMachine->GetFlow();
						vHWBreakpoint = vScriptMachine->GetVMDebuggerBreakpoint();
						if(vHWBreakpoint) AddBreakpoint(vHWBreakpoint->getid(), mOnOtherBreakpoint);
					}
					else
						cLog::mLogMessage("DLL: OnRunFuncIdxError: WriteMem(IP) failed\n");
				}
				else
					cLog::mLogMessage("DLL: OnRunFuncIdxError: GetRegister(IP) post run failed\n");
			}
			else
				cLog::mLogMessage("DLL: OnRunFuncIdxError: GetRegister(IP) pre run failed\n");
		}
		else
			cLog::mLogMessage("DLL: OnRunFuncIdxError: ReadMem pscript failed\n");
	}
}

void cMWSEMain::mOnOtherBreakpoint(Context *context)
{
	RemoveBreakpoint(vHWBreakpoint->getid());
	vScriptMachine->SetVMDebuggerBreakpoint(0);
	vScriptMachine->SetFlow(*context);
	vHWBreakpoint->breakpoint();
	*context = vScriptMachine->GetFlow();
	vHWBreakpoint = vScriptMachine->GetVMDebuggerBreakpoint();
	if(vHWBreakpoint) AddBreakpoint(vHWBreakpoint->getid(), mOnOtherBreakpoint);
}

bool cMWSEMain::mChangeReference(VPVOID pscript)
{
	bool result = false;

	if(pscript != vPrevScript)
	{
		vPrevScript = pscript;
		if(vScriptMachine->SetScript((VPSCRIPT)pscript))
		{
			if(vScriptMachine->Interrupt(INTSWITCHREFERENCE))
			{
				result = true;
			}
			else
				cLog::mLogMessage("DLL: ChangeReference: Interrupt failed\n");
		}
		else
			cLog::mLogMessage("DLL: ChangeReference: SetScript failed\n");
	}

	return result;
}

TES3MACHINE * cMWSEMain::mGetVM()
{
	return vScriptMachine;
}

TES3MACHINE* MWSEGetVM()
{
	return cMWSEMain::mGetVM();
}

bool MWSEAddInstruction(OPCODE op, INSTRUCTION *ins)
{
	return cMWSEMain::mGetVM()->AddInstruction(op, ins);
}

static BOOL CALLBACK EnumSymbolsCallback(PSYMBOL_INFO symbol_info,
										 ULONG /*symbol_size*/, 
										 PVOID /*user_context*/) 
{
	if(strcmp(symbol_info->Name, "malloc") == 0) {
		external_malloc = reinterpret_cast<void*>(symbol_info->Address);
	}
	else if (strcmp(symbol_info->Name, "free") == 0) {
		external_free = reinterpret_cast<void*>(symbol_info->Address);
	}
	else if (strcmp(symbol_info->Name, "realloc") == 0) {
		external_realloc = reinterpret_cast<void*>(symbol_info->Address);
	}
	return TRUE;
}
