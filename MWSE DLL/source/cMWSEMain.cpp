#include "cMWSEMain.h"

#include <imagehlp.h>

void * external_malloc = NULL;
void * external_free = NULL;

static BOOL CALLBACK enumSymbolsCallback(PSYMBOL_INFO symbolInfo, ULONG symbolSize, PVOID userContext){

	if(strcmp(symbolInfo->Name, "malloc") == 0)
	{
		external_malloc = reinterpret_cast<void*>(symbolInfo->Address);
	}
	else if (strcmp(symbolInfo->Name, "free") == 0)
	{
		external_free = reinterpret_cast<void*>(symbolInfo->Address);
	}

	return true;
}

TES3MACHINE* cMWSEMain::vScriptMachine;
HWBREAKPOINT* cMWSEMain::vHWBreakpoint;
VPVOID cMWSEMain::vPrevScript;

void cMWSEMain::mStartMWSE()
{
	vScriptMachine = new TES3MACHINE();
	AddBreakpoint(BP_RUNSCRIPT, mOnRunScript);
	AddBreakpoint(BP_FIXUPSCRIPT, mOnFixupScript);

	// Find the addresses of malloc() and free() that MW uses,
	// so that we can interact with its heap.
	SymInitialize(GetCurrentProcess(), NULL, true);
	SymEnumSymbols(GetCurrentProcess(), 0, "msvcrt!*", enumSymbolsCallback, NULL);

	if (!external_malloc)
	{
		cLog::mLogMessage("Error: unable to find malloc()\n");
	}
	if (!external_free)
	{
		cLog::mLogMessage("Error: unable to find free()\n");
	}

	vScriptMachine->set_external_malloc(external_malloc);
	vScriptMachine->set_external_free(external_free);
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