#include "MWSEmain.h"
#include "Breakpoint.h"
#include "TES3MACHINE.h"
#include "cLog.h"
#include "TES3MemMap.h"

#define log cLog::mLogMessage

static void OnDecode(Context* context);
static void OnRunFuncIdxError(Context* context);
static void OnRunScript(Context* context);
static void OnFixupScript(Context* context);

static TES3MACHINE* scriptmachine;
static VPVOID prevscript;
static HWBREAKPOINT* HWbreakpoint;

static void OnOtherBreakpoint(Context* context) {
	RemoveBreakpoint(HWbreakpoint->getid());
	scriptmachine->SetVMDebuggerBreakpoint(0);
	scriptmachine->SetFlow(*context);
	HWbreakpoint->breakpoint();
	*context= scriptmachine->GetFlow();
	HWbreakpoint= scriptmachine->GetVMDebuggerBreakpoint();
	if(HWbreakpoint) AddBreakpoint(HWbreakpoint->getid(), OnOtherBreakpoint);
}

static bool ChangeReference(VPVOID pscript)
{
	bool result= false;
	if(pscript!=prevscript)
	{
		prevscript= pscript;
		if(scriptmachine->SetScript((VPSCRIPT)pscript))
		{
			if(scriptmachine->Interrupt(INTSWITCHREFERENCE))
			{
				result= true;
			}
			else
				log("ChangeReference: Interrupt failed\n");
		}
		else
			log("ChangeReference: SetScript failed: %s\n");
	}

	return result;
}

static void OnDecode(Context* context) {
	if(scriptmachine->IsInstruction(context->Eax)) //opcode //check if the instruction exists in our instruction table
	{
		ChangeReference((VPVOID)context->Ebx); //script

		VMREGTYPE ip= (VMREGTYPE)context->Ebp; //sip
		if(scriptmachine->SetRegister(IP,ip))
		{
			while(scriptmachine->step(true))
			{
			}
			scriptmachine->step(true);

			if(scriptmachine->GetRegister(IP,ip))
			{
				OPCODE opcode= 0;
				if(scriptmachine->GetInstruction((VPVOID)ip,opcode)
					&& scriptmachine->WriteMem((VPVOID)context->Esp+sizeof(context->Edi),&ip,sizeof(ip)))
				{
					context->Eax= (DWORD)opcode;
					context->Ebp= (DWORD)ip;
				}
				else
					log("OnDecode: GetInstruction failed\n");
			}
			else
				log("OnDecode: GetRegister(IP) failed\n");
		}
		else
			log("OnDecode: SetRegister(IP) failed\n");
	}
}

static void OnRunFuncIdxError(Context* context) {
	OPCODE opcode= RUNFUNCIDXTOCODE(context->Edx);
	VPVOID stack= (VPVOID)context->Esp;
	if(scriptmachine->IsInstruction(opcode))
	{
		VPVOID ppscript= (VPVOID)context->Ebp+0x48;
		VPVOID pscript= 0;
		if(scriptmachine->ReadMem(ppscript,&pscript,sizeof(pscript)))
		{
			ChangeReference(pscript);

			VMREGTYPE ip= 0;
			if(scriptmachine->ReadMem(stack+sizeof(context->Edi),&ip,sizeof(ip)))
			{
				ip-= sizeof(OPCODE);
				scriptmachine->SetRegister(IP,(VMREGTYPE)ip);

				context->Eip= (DWORD)reltolinear(RUNFUNCIDXERRCONTINUE);
				scriptmachine->SetVMDebuggerBreakpoint(0);
				scriptmachine->SetFlow(*context);
				scriptmachine->step();

				if(scriptmachine->GetRegister(IP,ip))
				{
					if(scriptmachine->WriteMem(stack+sizeof(context->Edi),&ip,sizeof(ip)))
					{
						*context= scriptmachine->GetFlow();
						HWbreakpoint= scriptmachine->GetVMDebuggerBreakpoint();
						if(HWbreakpoint) AddBreakpoint(HWbreakpoint->getid(), OnOtherBreakpoint);
					}
					else
						log("OnRunFuncIdxError: WriteMem IP failed\n");
				}
				else
					log("OnRunFuncIdxError: GetRegister(IP) post run failed\n");
			}
			else
				log("OnRunFuncIdxError: GetRegister(IP) pre run failed\n");
		}
		else
			log("OnRunFuncIdxError: ReadMem pscript failed: %s\n");
	}
}

static void OnRunScript(Context* context) {
	AddBreakpoint(BP_FIXUPSCRIPT, OnFixupScript);
	RemoveBreakpoint(BP_RUNSCRIPT);

	AddBreakpoint(BP_RUNFUNCIDXERR, OnRunFuncIdxError);
	RemoveBreakpoint(BP_DECODEWITHINFO);
}

static void OnFixupScript(Context* context) {
	AddBreakpoint(BP_RUNSCRIPT, OnRunScript);
	RemoveBreakpoint(BP_FIXUPSCRIPT);

	AddBreakpoint(BP_DECODEWITHINFO, OnDecode);
	RemoveBreakpoint(BP_RUNFUNCIDXERR);
}

void MWSEOnProcessStart() {
	scriptmachine=new TES3MACHINE();
	AddBreakpoint(BP_RUNSCRIPT, OnRunScript);
	AddBreakpoint(BP_FIXUPSCRIPT, OnFixupScript);
}
