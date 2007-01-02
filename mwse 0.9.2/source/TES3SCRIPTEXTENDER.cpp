//Tes3ScriptExtender.cpp
//Based upon DEBUGGER, but is edited for Morrowind specificly

#include "TES3SCRIPTEXTENDER.h"
#include "TES3MEMMAP.h"
#include "DEBUGGING.h"

#include <fcntl.h>
// 22-08-2006 Tp21
#include "warnings.h"

#define RUNFUNCIDXTOCODE(a) (OPCODE)(((a)+0x1000))

// 2005-08-02  CDC
// 30-12-2006  Tp21
const char TES3SCRIPTEXTENDER::WelcomeMessage[]= 
 "Morrowind Script Extender v0.9.2a\n"
 "Copyright (C) 2003-2006 FreshFish, copyleft GPL\n\n"
 "This program is free software, licensed according to the GNU Public License,\n"
 "and comes with ABSOLUTELY NO WARRANTY.  See the file 'gpl.txt' for details.\n";

//not used?
const char TES3SCRIPTEXTENDER::RunFunctionErrorMsg[]= "Trying to RunFunction index greater than function count";

#define SUPER DEBUGGER //define that SUPER is DEBUGGER... ??? ...

TES3SCRIPTEXTENDER::TES3SCRIPTEXTENDER(void) : SUPER(), prevscript(0), scriptmachine(0), HWbreakpoint(0)
{
	//constructor
}

TES3SCRIPTEXTENDER::~TES3SCRIPTEXTENDER(void)
{
	//destructor
}

//original code from TimeSlip, modified to return the version of any Executable.
int TES3SCRIPTEXTENDER::getVersion(char* filename)
{
	DWORD size;
	DWORD* buffer = NULL;
	VS_FIXEDFILEINFO* info;
	UINT infosize;
	int version = 0;
	
	size = GetFileVersionInfoSizeA(filename, buffer);
	if (!size)
	{
		log("Unable to get Morrowind file version.\n");
		return 0;
	}
	buffer = new DWORD[size];
	if (!GetFileVersionInfoA(filename, NULL, size, buffer))
	{
		log("Unable to get Morrowind file version.\n");
		delete[size] buffer;
		return 0;
	}
	if (!VerQueryValueA(buffer, "\\", (void**)&info, &infosize))
	{
		log("Unable to get Morrowind file version.\n");
		delete[size] buffer;
		return 0;
	}

	version = (int)info->dwFileVersionLS;
	delete[size] buffer;

	return version;

}

//main function, calls directly from program's main entry point
//in this function we start the real work, start 'Morrowind.exe'
//and start debugging it
int TES3SCRIPTEXTENDER::main(int argc, char* argv[]) //TODO: cleanup!
{
	int result = 0;
	char* app = "Morrowind.exe"; //default app to load //isn't used, is overwritten with command-line argument, or isn't used at all

	//version checking...
	//checks if 'Morrowind.exe' is version 1820 or 1875 (don't know, got it from TimeSlip's code, think it's 'boosted' code)
	int version = getVersion(app);
	if(!(version == 1820 || version == 1875))
	{
		log("Incorrect Version, Version: %d\n",version);
		log("Please upgrade your Morrowind to version 1.6.0.1820.\n"
			"That's Bloodmoon with the latest patch");
		return -1;
	}
	else
	{
		log("Correct Version, Version: %d\n",version);
	}

	printf("%s\n",WelcomeMessage); //prints the welcome message
	if(argc > 1) //if there is an Application given as an Command Argument, run that
		app = argv[1]; //app to run is first argument given.

	// 2005-03-08  CDC  Run the Launcher and then search for the running Morrowind by default
	else { //there aren't given any extra parameters
		STARTUPINFO startup_info = { sizeof(STARTUPINFO), NULL, NULL, NULL, 
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0 };
		PROCESS_INFORMATION proc_info;
		if (!CreateProcess("Morrowind Launcher.exe", 
			"Morrowind Launcher.exe", 
			NULL, 
			NULL, 
			FALSE, 
			NORMAL_PRIORITY_CLASS, 
			NULL, 
			NULL, 
			&startup_info, 
			&proc_info)) 
		{
			printf("Unable to find the Morrowind Launcher program!\n");
			return -1;
		}
		while ( !WaitForInputIdle(proc_info.hProcess, INFINITE) );
		// Launcher is finished, and may or may not have started the game

		// Now we wait for Morrowind itself to start
		printf("\nWaiting for game to start...\n");
		fflush(stdout);

		//we search for the Morrowind window
		DWORD mwpid = 0;
		while ( !mwpid ) {
			HWND mwwin = ::FindWindow("Morrowind", "Morrowind");
			if (mwwin) ::GetWindowThreadProcessId(mwwin, &mwpid);
		}

		// Found it so start the debugger to catch any script errors
		printf("\n\n\n\n\n\n\n\n\n\n\n\nFound Morrowind Process.\n");
		fflush(stdout);
		return debug(mwpid);
	}
	result = debug(app);

	return result;
}

TES3MACHINE* TES3SCRIPTEXTENDER::CreateScriptMachine(void)
{
	TES3MACHINE* machine = new TES3MACHINE(procinfo.hProcess, procbase);
	return machine;
}

int TES3SCRIPTEXTENDER::log(char* fmt, ...)
{
	char buf[512];

	int result = 0;
	va_list args;
	va_start(args, fmt);
	result = vsprintf(buf, fmt, args);
	va_end(args);
	LOG::log(buf);

	return result;
}

void TES3SCRIPTEXTENDER::logbinary(const VOID* addr, int size)
{
	BYTE* ptr = (BYTE*)addr;
	for(int y = 0; y < size; y += 16)
	{
		log("\t");
		for(int x = 0; x < 16 && (x+y) < size; x++)
			log("%02X ",((int)ptr[y+x])&0xFF);
		log("\t");
		for(int x=0;x<16 && (x+y)<size;x++)
			if(isprint(ptr[y+x]))
				log("%c",ptr[y+x]);
			else
				log(".");
		log("\n");
	}
}

void TES3SCRIPTEXTENDER::dumpstack(LPVOID mem)
{
	BYTE buffer[128];
	if(ReadProcessMemory(procinfo.hProcess,mem,buffer,sizeof(buffer),NULL))
	{
		log("\tStack Dump from %08lx\n",(ULONG)mem);
		logbinary(buffer,sizeof(buffer));
	}
	else
		logerror("\tdumpstack: ReadProcessMemory failed: %s\n");
}

void TES3SCRIPTEXTENDER::dumpcontext(HANDLE hThread, CONTEXT& context)
{
	if(context.ContextFlags&CONTEXT_INTEGER)
	{
		log("\tEAX:%08X, EBX:%08X, ECX:%08X, EDX:%08X, EDI:%08X, ESI:%08X\n",
			context.Eax,context.Ebx,context.Ecx,context.Edx,context.Edi,context.Esi);
	}
	if(context.ContextFlags&CONTEXT_SEGMENTS)
	{
		char buffer[512]= "DS:";
		sprintseg(&buffer[strlen(buffer)],hThread,context.SegDs);
		strcat(buffer,", ES:");
		sprintseg(&buffer[strlen(buffer)],hThread,context.SegEs);
		strcat(buffer,", FS:");
		sprintseg(&buffer[strlen(buffer)],hThread,context.SegFs);
		strcat(buffer,", GS:");
		sprintseg(&buffer[strlen(buffer)],hThread,context.SegGs);
		log("\t%s\n",buffer);
	}
	if(context.ContextFlags&CONTEXT_CONTROL)
	{
		char buffer[512]= "CS:";
		sprintseg(&buffer[strlen(buffer)],hThread,context.SegCs);
		sprintf(&buffer[strlen(buffer)],", EIP:%08X, SS:",context.Eip);
		sprintseg(&buffer[strlen(buffer)],hThread,context.SegSs);
		sprintf(&buffer[strlen(buffer)],", ESP:%08X, EBP:%08X",context.Esp,context.Ebp);
		log("\t%s\n",buffer);
		dumpstack((LPVOID)context.Esp);
	}
}

void TES3SCRIPTEXTENDER::dumpcontext(HANDLE hThread)
{
	CONTEXT context;
	DWORD prevcount= SuspendThread(hThread);
	if(prevcount>=0)
	{
//		if(prevcount>0)
//			log("\tAlready suspended\n"); // this is always true until we call ContinueDebugEvent
		context.ContextFlags= CONTEXT_FULL;
		if(GetThreadContext(hThread,&context))
			dumpcontext(hThread,context);
		else
			logerror("\tdumpcontext: GetThreadContext failed: %s\n");
		ResumeThread(hThread);
	}
	else
		log("\tdumpcontext: SuspendThread failed\n");
}

void TES3SCRIPTEXTENDER::sprintseg(char* str, HANDLE hThread, DWORD seg)
{
	LDT_ENTRY descriptor;
	if(GetThreadSelectorEntry(hThread,seg,&descriptor))
	{
		sprintf(str,"%08X:%02X%02X%04X",(int)seg,descriptor.HighWord.Bytes.BaseHi,
			(int)descriptor.HighWord.Bytes.BaseMid,(int)descriptor.BaseLow);
	}
	else
		sprintf(str,"%08X:XXXXXXXX",seg);
}

void TES3SCRIPTEXTENDER::dumpmemlist(void)
{
	bool first= true;
	ULONG address= 0;
	int section= 0;
	MEMORY_BASIC_INFORMATION mbi;
	while(VirtualQueryEx(procinfo.hProcess,(PVOID)address,&mbi,sizeof(mbi)))
	{
		ULONG base = (ULONG)mbi.BaseAddress;
		ULONG size = mbi.RegionSize;
//		if(mbi.State&MEM_COMMIT)
		{
			log("\tSection %3d, %08lx %8lx: ",section,base,size);
			if(mbi.State&MEM_COMMIT)
				log("MEM_COMMIT  ");
			if(mbi.State&MEM_FREE)
				log("MEM_FREE    ");
			if(mbi.State&MEM_RESERVE)
				log("MEM_RESERVE ");

			if(mbi.Type&MEM_IMAGE)
				log("MEM_IMAGE   ");
			if(mbi.Type&MEM_MAPPED)
				log("MEM_MAPPED  ");
			if(mbi.Type&MEM_PRIVATE)
				log("MEM_PRIVATE ");

			if(!(mbi.State&MEM_FREE))
			{
				if(mbi.Protect&PAGE_READONLY)
					log("PAGE_READONLY ");
				if(mbi.Protect&PAGE_READWRITE)
					log("PAGE_READWRITE ");
				if(mbi.Protect&PAGE_WRITECOPY)
					log("PAGE_WRITECOPY ");
				if(mbi.Protect&PAGE_EXECUTE)
					log("PAGE_EXECUTE ");
				if(mbi.Protect&PAGE_EXECUTE_READ)
					log("PAGE_EXECUTE_READ ");
				if(mbi.Protect&PAGE_EXECUTE_READWRITE)
					log("PAGE_EXECUTE_READWRITE ");
				if(mbi.Protect&PAGE_EXECUTE_WRITECOPY)
					log("PAGE_EXECUTE_WRITECOPY ");
				if(mbi.Protect&PAGE_GUARD)
					log("PAGE_GUARD ");
				if(mbi.Protect&PAGE_NOACCESS)
					log("PAGE_NOACCESS ");
				if(mbi.Protect&PAGE_NOCACHE)
					log("PAGE_NOCACHE ");
			}
			log("\n");
			if(mbi.State&MEM_COMMIT)
			{
				if(first)
				{
					DWORD oldprotect= 0;
					if(!VirtualProtectEx(procinfo.hProcess,mbi.BaseAddress,mbi.RegionSize,mbi.Protect|PAGE_GUARD,&oldprotect))
						logerror("\tdumpmemlist: VirtualProtectEx test failed: %s\n");
					first= false;
				}
			}
		}
		section++;
		address= base+size;
	}
}

void TES3SCRIPTEXTENDER::DoCreateProc(DEBUG_EVENT& DebugEv)
{
	SUPER::DoCreateProc(DebugEv);
	scriptmachine= CreateScriptMachine();
	if(!scriptmachine)
		log("DoCreateProc: no scriptmachine\n");
}

void TES3SCRIPTEXTENDER::DoInitialBreakpoint(DEBUG_EVENT& /*DebugEv*/)
{
//	setbreakpoint(reltolinear(DISPLAYERRORBREAK));
	if(!setbreakpoint(reltolinear(RUNSCRIPTBREAK)))
		log("DoInitialBreakpoint: setbreakpoint(RUNSCRIPT) failed\n");
	if(!setbreakpoint(reltolinear(FIXUPSCRIPTBREAK)))
		log("DoInitialBreakpoint: setbreakpoint(FIXUPSCRIPT) failed\n");
//	setbreakpoint((void*)477400);
}

void TES3SCRIPTEXTENDER::DoExitProc(DEBUG_EVENT& DebugEv)
{
	if(scriptmachine)
		delete scriptmachine;
	scriptmachine= NULL;
	SUPER::DoExitProc(DebugEv);
}

void TES3SCRIPTEXTENDER::DoAccessViolation(DEBUG_EVENT& DebugEv)
{
	log("Access Violation at %lx\n",DebugEv.u.Exception.ExceptionRecord.ExceptionAddress);
	HANDLE hThread= threadhandles[DebugEv.dwThreadId];
	if(hThread)
		dumpcontext(hThread);
}

#ifdef INVESTIGATE
bool logsinglestep= false;
#endif

void TES3SCRIPTEXTENDER::DoDebugString(DEBUG_EVENT& DebugEv)
{
#ifdef INVESTIGATE
	char buffer[512]="\0";
	DWORD len= 0;

	if(ReadProcessMemory(procinfo.hProcess,
		DebugEv.u.DebugString.lpDebugStringData,
		buffer,sizeof(buffer)-1,&len))
	{
		buffer[len]= '\0';
		log("DebugString: %s\n",buffer);
	}
	else
		logerror("DoDebugString: ReadProcessMemory failed: %s\n");
	HANDLE hThread= threadhandles[DebugEv.dwThreadId];
	if(hThread)
		dumpcontext(hThread);
	logsinglestep= true;
#endif
}

void TES3SCRIPTEXTENDER::DoSingleStep(DEBUG_EVENT& DebugEv)
{
	SUPER::DoSingleStep(DebugEv);
#ifdef INVESTIGATE
	if(logsinglestep)
	{
		logsinglestep= false;
		log("Single Step\n");
		HANDLE hThread= threadhandles[DebugEv.dwThreadId];
		if(hThread)
			dumpcontext(hThread);
	}
#endif
}

void TES3SCRIPTEXTENDER::DoBreakpoint(DEBUG_EVENT& DebugEv)
{
//	log("breakpoint at %lx\n",DebugEv.u.Exception.ExceptionRecord.ExceptionAddress);
	if(!scriptmachine)
		return;
	if(breakpoints.find(DebugEv.u.Exception.ExceptionRecord.ExceptionAddress)!=breakpoints.end())
	{
		HANDLE hThread= threadhandles[DebugEv.dwThreadId];
		if(hThread)
		{
			CONTEXT context;
			context.ContextFlags= CONTEXT_FULL;
			if(GetThreadContext(hThread,&context))
			{
				LPVOID exaddr= DebugEv.u.Exception.ExceptionRecord.ExceptionAddress;
				if(reltolinear(DECODEWITHINFOBREAK)==exaddr)
				{
					OnDecode(context);
				}
				else
				{
//					log("breakpoint at %lx\n",DebugEv.u.Exception.ExceptionRecord.ExceptionAddress);
					if(reltolinear(RUNFUNCIDXERRBREAK)==exaddr)
					{
						OnRunFuncIdxError(context);
					}
					else if(reltolinear(RUNSCRIPTBREAK)==exaddr)
					{
						OnRunScript(context);
					}
					else if(reltolinear(FIXUPSCRIPTBREAK)==exaddr)
					{
						OnFixupScript(context);
					}
					else if(HWbreakpoint && HWbreakpoint->getaddress()==exaddr)
					{
						OnHWBreakpoint(context);
					}
					else
					{
						log("Other Breakpoint @ %lx\n",exaddr);
						dumpcontext(hThread,context);
						runbreakpoint(context);
					}
				}
				context.ContextFlags= CONTEXT_FULL;
				if(!SetThreadContext(hThread,&context))
					logerror("\tDoBreakpoint: SetThreadContext failed: %s\n");
			}
			else
				logerror("DoBreakpoint: GetThreadContext failed: %s\n");
		}
		else
			log("DoBreakpoint: ThreadId Unknown %8lx\n",DebugEv.dwThreadId);
	}
}

void TES3SCRIPTEXTENDER::OnRunScript(CONTEXT& context)
{
	context.Eip--;
	if(!clearbreakpoint((LPVOID)context.Eip))
		log("OnRunScript: clearbreakpoint(thisBP) failed\n");

	if(!setbreakpoint(reltolinear(FIXUPSCRIPTBREAK)))
		log("OnRunScript: setbreakpoint(FIXUPSCRIPT) failed\n");

	if(!setbreakpoint(reltolinear(RUNFUNCIDXERRBREAK)))
		log("OnRunScript: setbreakpoint(RUNFUNC) failed\n");
	if(!clearbreakpoint(reltolinear(DECODEWITHINFOBREAK)))
		log("OnRunScript: clearbreakpoint((DECODEWITHINFO) failed\n");
}

void TES3SCRIPTEXTENDER::OnFixupScript(CONTEXT& context)
{
	context.Eip--;
	if(!clearbreakpoint((LPVOID)context.Eip))
		log("OnFixupScript: clearbreakpoint(thisBP) failed\n");
	if(!setbreakpoint(reltolinear(RUNSCRIPTBREAK)))
		log("OnFixupScript: setbreakpoint(RUNSCRIPT) failed\n");

	if(!setbreakpoint(reltolinear(DECODEWITHINFOBREAK)))
		log("OnFixupScript: setbreakpoint(DECODEWITHINFO) failed\n");
	if(!clearbreakpoint(reltolinear(RUNFUNCIDXERRBREAK)))
		log("OnFixupScript: clearbreakpoint(RUNFUNC) failed\n");
}

bool TES3SCRIPTEXTENDER::ChangeReference(VPVOID pscript)
{
	bool result= false;
	if(pscript!=prevscript)
	{
#ifdef DEBUG
		if(prevscript)
		{
			log("ChangeReference: Old Script:\n");
			scriptmachine->dumpscript();
		}
#endif
		prevscript= pscript;
		if(scriptmachine->SetScript((VPSCRIPT)pscript))
		{
			if(scriptmachine->Interrupt(INTSWITCHREFERENCE))
			{
#ifdef DEBUG
				log("ChangeReference: New Script:\n");
				scriptmachine->dumpscript();
#endif
				result= true;
			}
			else
				log("ChangeReference: Interrupt failed\n");
		}
		else
			logerror("ChangeReference: SetScript failed: %s\n");
	}

	return result;
}

void TES3SCRIPTEXTENDER::OnDecode(CONTEXT& context)
{
#ifdef DEBUG
	log("OnDecode: opcode f= %lx, sip= %lx\n",context.Eax,context.Ebp);
	ChangeReference((VPVOID)context.Ebx);
	if(!strcmp(scriptmachine->GetScriptName(),"testing"))
	{
		log("OnDecode: Dump Script\n");
		scriptmachine->dumpscript();
	}
#endif
	if(scriptmachine->IsInstruction(context.Eax)) //opcode //check if the instruction exists in our instruction table
	{
		ChangeReference((VPVOID)context.Ebx); //script

		VMREGTYPE ip= (VMREGTYPE)context.Ebp; //sip
		if(scriptmachine->SetRegister(IP,ip))
		{
			while(scriptmachine->step(true))
			{
#ifdef DEBUG
				OPCODE opcode= 0;
				if(scriptmachine->GetRegister(IP,ip)
					&& scriptmachine->GetInstruction((VPVOID)ip,opcode))
						log("OnDecode: opcode c= %lx, sip= %lx\n",opcode,ip);
				else
						log("OnDecode: unable to fetch next instruction\n");
#endif
			}
			scriptmachine->step(true);

			if(scriptmachine->GetRegister(IP,ip))
			{
				OPCODE opcode= 0;
				if(scriptmachine->GetInstruction((VPVOID)ip,opcode)
					&& scriptmachine->WriteMem((VPVOID)context.Esp+sizeof(context.Edi),&ip,sizeof(ip)))
				{
					context.Eax= (DWORD)opcode;
					context.Ebp= (DWORD)ip;
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
	runbreakpoint(context);
}

void TES3SCRIPTEXTENDER::OnRunFuncIdxError(CONTEXT& context)
{
	OPCODE opcode= RUNFUNCIDXTOCODE(context.Edx);
	VPVOID stack= (VPVOID)context.Esp;
	if(scriptmachine->IsInstruction(opcode))
	{
		VPVOID ppscript= (VPVOID)context.Ebp+0x48;
		VPVOID pscript= 0;
		if(scriptmachine->ReadMem(ppscript,&pscript,sizeof(pscript)))
		{
			ChangeReference(pscript);

			VMREGTYPE ip= 0;
			if(scriptmachine->ReadMem(stack+sizeof(context.Edi),&ip,sizeof(ip)))
			{
				ip-= sizeof(OPCODE);
#ifdef DEBUG
				log("OnRunFuncIdxError: start IP= %lx\n",ip);
#endif
				scriptmachine->SetRegister(IP,(VMREGTYPE)ip);

				context.Eip= (DWORD)reltolinear(RUNFUNCIDXERRCONTINUE);
				scriptmachine->SetVMDebuggerBreakpoint(0);
				scriptmachine->SetFlow(context);
				scriptmachine->step();

				if(scriptmachine->GetRegister(IP,ip))
				{
					if(scriptmachine->WriteMem(stack+sizeof(context.Edi),&ip,sizeof(ip)))
					{
#ifdef DEBUG
						log("OnRunFuncIdxError: end IP= %lx\n",ip);
#endif
						context= scriptmachine->GetFlow();
						HWbreakpoint= scriptmachine->GetVMDebuggerBreakpoint();
						if(HWbreakpoint && !setbreakpoint(HWbreakpoint->getaddress()))
							log("OnRunFuncIdxError: setbreakpoint(HWBREAK@%lx) failed\n",(DWORD)(HWbreakpoint->getaddress()));			
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
			logerror("OnRunFuncIdxError: ReadMem pscript failed: %s\n");
	}
	else
	{
#ifdef DEBUG
		VMREGTYPE ip= 0;
		scriptmachine->ReadMem(stack+sizeof(context.Edi),&ip,sizeof(ip));
		log("Genuine RunFuncIdxError: %x @ %lx\n",opcode,ip-sizeof(OPCODE));
		scriptmachine->dumpscript();
#endif
		runbreakpoint(context);
	}
}

void TES3SCRIPTEXTENDER::OnHWBreakpoint(CONTEXT& context)
{
#ifdef DEBUG
	log("OnHWBreakpoint: break at %lx\n",context.Eip);
#endif
	context.Eip--;
	scriptmachine->SetVMDebuggerBreakpoint(0);
	scriptmachine->SetFlow(context);
	HWbreakpoint->breakpoint();
	if(!clearbreakpoint(HWbreakpoint->getaddress()))
		log("OnHWBreakpoint: clearbreakpoint failed\n");
	context= scriptmachine->GetFlow();
	HWbreakpoint= scriptmachine->GetVMDebuggerBreakpoint();
	if(HWbreakpoint && !setbreakpoint(HWbreakpoint->getaddress()))
		log("OnHWBreakpoint: setbreakpoint(HWBREAK@%lx) failed\n",(DWORD)(HWbreakpoint->getaddress()));			
}
