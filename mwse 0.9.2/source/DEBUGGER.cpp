//Debugger.cpp
//this is the base of MWSE, it's an 'standard' debugger

// functions which might be useful
// StackWalk
// VirtualProtect
// MapAndLoad

#include "DEBUGGER.h"
#include <winnt.h>
#include <stdlib.h>
#include <string.h>

// 22-08-2006 Tp21
#include "warnings.h"

#define BUFSIZE 512

using namespace std; 	//introduces namespace std

char DEBUGGER::emptystring[] = "";
SECURITY_ATTRIBUTES DEBUGGER::security = {
	sizeof(SECURITY_ATTRIBUTES), 
	NULL, 
	FALSE
};
STARTUPINFO DEBUGGER::startup = {
	sizeof(STARTUPINFO), 
	NULL, 
	emptystring, 
	NULL, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0, 
	0
};

DEBUGGER::DEBUGGER(void) : procinfo(), procbase(0), stepbreakpoint(0)
{
	procinfo.hProcess = INVALID_HANDLE_VALUE;
	procinfo.hThread  = INVALID_HANDLE_VALUE;
}

DEBUGGER::~DEBUGGER(void)
{
}

int DEBUGGER::main( int argc, char* argv[])
{
	char commandline[BUFSIZE] = "\0";
	
	for(int i = 1; i < argc; i++)
	{
		strncat(commandline, argv[i], NELEMS(commandline)-strlen(commandline));
		strncat(commandline, " ", NELEMS(commandline)-strlen(commandline));
	}
	commandline[sizeof(commandline)-1] = '\0';
		
	return debug(commandline);
}

int DEBUGGER::log(char* fmt, ...)
{
	int result = 0;
	va_list args;
	va_start(args, fmt);
	result = vfprintf(stdout, fmt, args);
	va_end(args);

	return result;
}

void DEBUGGER::logerror(char* fmt)
{
	char buffer[512] = "\0";
	
	buffer[FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(), 0, buffer, sizeof(buffer)-1, NULL)] = '\0';
	log(fmt, buffer);
}

int DEBUGGER::debug(char* commandline)
{
	int result = 0;
	try
	{
		if(CreateProcess(
			NULL, 
			commandline, 
			&security, 
			&security, 
			TRUE, 
			DEBUG_PROCESS|DEBUG_ONLY_THIS_PROCESS|NORMAL_PRIORITY_CLASS, 
			NULL, 
			NULL, 
			&startup, 
			&procinfo
		))
			result = debug(procinfo);
		else
		{
			logerror("debug: CreateProcess failed: %s\n");
			result = -1;
		}
	}
	catch(...)
	{
		log("Exception!\n");
	}
	closethreadhandles();
	if(procinfo.hThread != INVALID_HANDLE_VALUE)
		CloseHandle(procinfo.hThread);
	procinfo.hThread = INVALID_HANDLE_VALUE;
	if(procinfo.hProcess != INVALID_HANDLE_VALUE)
		CloseHandle(procinfo.hProcess);
				
	return result;
}

int DEBUGGER::debug(DWORD processID)
{
	int result = 0;
	procinfo.hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	if(procinfo.hProcess != INVALID_HANDLE_VALUE)
	{
		if(DebugActiveProcess(processID))
			result = debug(procinfo);
		else
			logerror("debug(procID): DebugActiveProcess failed: %s\n");
		closethreadhandles();
		if(procinfo.hThread != INVALID_HANDLE_VALUE)
			CloseHandle(procinfo.hThread);
		procinfo.hThread = INVALID_HANDLE_VALUE;
		if(procinfo.hProcess != INVALID_HANDLE_VALUE)
			CloseHandle(procinfo.hProcess);
		procinfo.hProcess = INVALID_HANDLE_VALUE;
	}
	else
		logerror("debug(procID): OpenProcess failed: %s\n");
		
	return result;
}

int DEBUGGER::debug(const PROCESS_INFORMATION& /*procinfo*/)
{
	int result = 0;
	DEBUG_EVENT DebugEv;
	DWORD dwContinue = DBG_CONTINUE;
	bool done = false;
	bool initialbreakpoint = true;

	while(!done)
	{ 
		WaitForDebugEvent(&DebugEv,INFINITE);
	    dwContinue = DBG_CONTINUE;
	    switch (DebugEv.dwDebugEventCode) 
    	{ 
        	case EXCEPTION_DEBUG_EVENT: 

	        // Process the exception code. When handling 
    	    // exceptions, remember to set the continuation 
        	// status parameter (dwContinueStatus). This value 
	        // is used by the ContinueDebugEvent function. 
 				if(DebugEv.u.Exception.dwFirstChance)
				    dwContinue = DBG_EXCEPTION_NOT_HANDLED;
				else
				{
//					dwContinue = DBG_CONTINUE;
				    dwContinue = DBG_EXCEPTION_NOT_HANDLED;
				}
    	        switch (DebugEv.u.Exception.ExceptionRecord.ExceptionCode) 
        	    { 
					case EXCEPTION_SINGLE_STEP: 
					// First chance: Update the display of the 
					// current instruction and register values. 
                		DoSingleStep(DebugEv);
					    dwContinue = DBG_CONTINUE;
			            break;
 
    	            case EXCEPTION_BREAKPOINT: 
        	        // First chance: Display the current 
            	    // instruction and register values. 
		                if(initialbreakpoint)
		                {
		                	DoInitialBreakpoint(DebugEv);
				            initialbreakpoint = false;
				        }
		                else
			                DoBreakpoint(DebugEv);
					    dwContinue = DBG_CONTINUE;
			            break;
 
					case EXCEPTION_GUARD_PAGE:
					// This may occur if I place a page watch VirtualProtect(GUARD)
					// on the page containing RunFunction
						DoPageGuard(DebugEv);
					    dwContinue = DBG_CONTINUE;
						break;
					
	                case EXCEPTION_ACCESS_VIOLATION: 
    	            // First chance: Pass this on to the kernel. 
        	        // Last chance: Display an appropriate error. 
						if(!DebugEv.u.Exception.dwFirstChance)
	        	        	DoAccessViolation(DebugEv);
//					default:
//            	    // Handle other exceptions.
//            	    	break; 
	            } 
	            break;
 
    	    case CREATE_THREAD_DEBUG_EVENT: 
	        // As needed, examine or change the thread's registers 
    	    // with the GetThreadContext and SetThreadContext functions; 
        	// and suspend and resume thread execution with the 
	        // SuspendThread and ResumeThread functions. 
	            DoCreateThread(DebugEv);
	            break;
 
    	    case CREATE_PROCESS_DEBUG_EVENT: 
        	// As needed, examine or change the registers of the 
	        // process's initial thread with the GetThreadContext and 
    	    // SetThreadContext functions; read from and write to the 
	        // process's virtual memory with the ReadProcessMemory and 
    	    // WriteProcessMemory functions; and suspend and resume 
	        // thread execution with the SuspendThread and ResumeThread 
	        // functions. 
	        	DoCreateProc(DebugEv);
	            break;

    	    case EXIT_THREAD_DEBUG_EVENT: 
        	// Display the thread's exit code. 
	            DoExitThread(DebugEv);
 	            break;

	        case EXIT_PROCESS_DEBUG_EVENT: 
    	    // Display the process's exit code. 
	            DoExitProc(DebugEv);
	        	done = true;
	            break;
 
	        case OUTPUT_DEBUG_STRING_EVENT: 
    	    // Display the output debugging string. 
	            DoDebugString(DebugEv);
	            break;
	    } 
		ContinueDebugEvent(DebugEv.dwProcessId,DebugEv.dwThreadId,dwContinue); 
	}
	return result;
}


void DEBUGGER::closethreadhandles(void)
{
		THREADHANDLEMAP::iterator it = threadhandles.begin();
		while(it != threadhandles.end())
		{
			if(it->second != INVALID_HANDLE_VALUE)
				CloseHandle(it->second);
		}
		threadhandles.clear();
}

void DEBUGGER::DoCreateProc(DEBUG_EVENT& DebugEv)
{
//	LPVOID pProcName;
//	char buffer[512]="\0";
//	DWORD len= 0;
//	
//	if(ReadProcessMemory(procinfo.hProcess,
//		DebugEv.u.CreateProcessInfo.lpImageName,
//		&pProcName,sizeof(pProcName),NULL))
//	{
//		if(pProcName)
//		{
//			if(ReadProcessMemory(procinfo.hProcess,pProcName,buffer,sizeof(buffer)-1,&len))
//			{
//				buffer[len]= '\0';
//				log("%s\n",buffer);
//			}
//			else
//				logerror("DoCreateProc: ReadProcessMemory failed %s\n");
//		}
//	}
//	else
//		logerror("DoCreateProc: ReadProcessMemory failed %s\n");
		
//	dumpmemlist();
	procbase = (LPVOID)DebugEv.u.CreateProcessInfo.lpBaseOfImage;
	threadhandles[DebugEv.dwThreadId] = DebugEv.u.CreateProcessInfo.hThread;
}

void DEBUGGER::DoExitProc(DEBUG_EVENT& DebugEv)
{
	threadhandles.erase(DebugEv.dwThreadId);
	
	if(procinfo.hThread)
		CloseHandle(procinfo.hThread);
	procinfo.hThread = 0;
	if(procinfo.hProcess)
		CloseHandle(procinfo.hProcess);
	procinfo.hProcess = 0;
}

void DEBUGGER::DoCreateThread(DEBUG_EVENT& DebugEv)
{
	threadhandles[DebugEv.dwThreadId]= DebugEv.u.CreateThread.hThread;
}

void DEBUGGER::DoExitThread(DEBUG_EVENT& DebugEv)
{
	threadhandles.erase(DebugEv.dwThreadId);
}

void DEBUGGER::DoDebugString(DEBUG_EVENT& /*DebugEv*/)
{
}

void DEBUGGER::DoInitialBreakpoint(DEBUG_EVENT& /*DebugEv*/)
{
}

void DEBUGGER::DoBreakpoint(DEBUG_EVENT& DebugEv) //triggers when breakpoint occurs
{
	if(breakpoints.find(DebugEv.u.Exception.ExceptionRecord.ExceptionAddress) != breakpoints.end())
	{
		HANDLE hThread = threadhandles[DebugEv.dwThreadId];
		if(hThread)
		{
			BYTE ret = breakpoints[DebugEv.u.Exception.ExceptionRecord.ExceptionAddress];
			if(WriteProcessMemory(procinfo.hProcess, 
				DebugEv.u.Exception.ExceptionRecord.ExceptionAddress,
				&ret, 
				sizeof(BYTE),NULL
			))
			{
				if(!FlushInstructionCache(procinfo.hProcess, 
					DebugEv.u.Exception.ExceptionRecord.ExceptionAddress, 
					sizeof(BYTE)
				))
					logerror("\tDoBreakpoint: FlushInstructionCache failed: %s\n");
				CONTEXT context;
				context.ContextFlags = CONTEXT_FULL;
				if(GetThreadContext(hThread, &context))
				{
					context.Eip--;
					context.EFlags|= EFLAGS_SINGLE_STEP;
					context.ContextFlags = CONTEXT_FULL;
					if(!SetThreadContext(hThread, &context))
						logerror("DoBreakpoint: SetThreadContext failed: %s\n");
				}
				else
					logerror("DoBreakpoint: GetThreadContext failed: %s\n");
			}
			else
				logerror("DoBreakpoint: WriteProcessMemory failed: %s\n");
		}
		else
			log("DoBreakpoint: ThreadId Unknown %8lx\n", DebugEv.dwThreadId);
	}
}

void DEBUGGER::DoPageGuard(DEBUG_EVENT& DebugEv)
{
	log("PageGuard caught at %lx\n", DebugEv.u.Exception.ExceptionRecord.ExceptionAddress);
}

void DEBUGGER::DoSingleStep(DEBUG_EVENT& DebugEv)
{
	HANDLE hThread = threadhandles[DebugEv.dwThreadId];
	if(hThread)
	{
		if(stepbreakpoint)
		{
			setbreakpoint(stepbreakpoint);
			stepbreakpoint = 0;
		}
		clearsinglestep(hThread);
	}
	else
		log("DoSingleStep: ThreadId Unknown %8lx\n", DebugEv.dwThreadId);
}

void DEBUGGER::DoAccessViolation(DEBUG_EVENT& DebugEv)
{
}

bool DEBUGGER::setpageguard(LPVOID addr)
{
	bool result = false;
	DWORD oldprotect = 0;
	if(VirtualProtectEx(procinfo.hProcess, addr, 1, PAGE_EXECUTE_READWRITE|PAGE_GUARD, &oldprotect))
	{
		if(VirtualProtectEx(procinfo.hProcess, addr, 1, PAGE_GUARD|oldprotect, NULL))
			result = true;
		else
			logerror("setpageguard: VirtualProtectEx 2 failed: %s\n");
	}
	else
		logerror("setpageguard: VirtualProtectEx 1 failed: %s\n");
		
	return result;
}

bool DEBUGGER::setbreakpoint(LPVOID addr) //set an breakpoint on a address
{
	bool result = false;
	BYTE opcode = 0;
	BYTE breakpoint = BREAKPOINT;
	if(ReadProcessMemory(procinfo.hProcess, addr, &opcode, sizeof(opcode), NULL))
	{
		if(WriteProcessMemory(procinfo.hProcess, addr, &breakpoint, sizeof(breakpoint), NULL))
		{
			if(opcode != BREAKPOINT	// if its a BREAKPOINT we already set then we have the opcode already
				|| breakpoints.find(addr) == breakpoints.end())
				breakpoints[addr] = opcode;
			if(!FlushInstructionCache(procinfo.hProcess, addr, sizeof(BYTE)))
				logerror("\tsetbreakpoint: FlushInstructionCache failed: %s\n");
			result = true;
		}
		else
			logerror("setbreakpoint: WriteProcessMemory failed: %s\n");
	}
	else
			logerror("setbreakpoint: ReadProcessMemory failed: %s\n");

	return result;
}

bool DEBUGGER::clearbreakpoints(void) //remove all breakpoints
{
	bool result = true;
	
	while(!breakpoints.empty())
	{
		BREAKPOINTMAP::iterator it = breakpoints.begin();
		clearbreakpoint(it->first);
	}

	return result;
}

bool DEBUGGER::clearbreakpoint(LPVOID addr) //remove one breakpoint at given address
{
	bool result = false;
	if(breakpoints.find(addr) != breakpoints.end())
	{
		BYTE opcode = breakpoints[addr];
		if(WriteProcessMemory(procinfo.hProcess, addr, &opcode, sizeof(opcode), NULL))
		{
			breakpoints.erase(addr);
			if(!FlushInstructionCache(procinfo.hProcess, addr, sizeof(BYTE)))
				logerror("\tclearbreakpoint: FlushInstructionCache failed: %s\n");
			result = true;
		}
		else
			logerror("\tclearbreakpoint: WriteProcessMemory failed: %s\n");
	}
	
	return result;
}

bool DEBUGGER::runbreakpoint(CONTEXT& context)
{
	bool result = false;
	LPVOID addr = (LPVOID)(context.Eip - 1);
	if(breakpoints.find(addr) != breakpoints.end())
	{
		stepbreakpoint = addr;
		BYTE opcode = breakpoints[addr];
		if(WriteProcessMemory(procinfo.hProcess, addr, &opcode, sizeof(opcode), NULL))
		{
			if(!FlushInstructionCache(procinfo.hProcess, addr, sizeof(BYTE)))
				logerror("\trunbreakpoint: FlushInstructionCache failed: %s\n");
			context.Eip--;
			context.EFlags|= EFLAGS_SINGLE_STEP;
			result = true;
		}
		else
			logerror("\trunbreakpoint: WriteProcessMemory failed: %s\n");
	}
	
	return result;
}

bool DEBUGGER::setsinglestep(HANDLE hThread)
{
	bool result = false;
	CONTEXT context;
	DWORD prevcount = SuspendThread(hThread);
	if(prevcount >= 0)
	{
		context.ContextFlags = CONTEXT_FULL;
		if(GetThreadContext(hThread, &context))
		{
			context.EFlags|= EFLAGS_SINGLE_STEP;
			context.ContextFlags = CONTEXT_FULL;
			if(SetThreadContext(hThread, &context))
				result = true;
			else
				logerror("\tsetsinglestep: SetThreadContext failed: %s\n");
		}
		else
			logerror("\tsetsinglestep: GetThreadContext failed: %s\n");
		ResumeThread(hThread);
	}
	else
		log("\tsetsinglestep: SuspendThread failed\n");

	return result;
}

bool DEBUGGER::clearsinglestep(HANDLE hThread)
{
	bool result = false;
	CONTEXT context;
	DWORD prevcount = SuspendThread(hThread);
	if(prevcount >= 0)
	{
		context.ContextFlags = CONTEXT_FULL;
		if(GetThreadContext(hThread, &context))
		{
			context.ContextFlags = CONTEXT_FULL;
			if(context.EFlags&EFLAGS_SINGLE_STEP)
				log("\tclearsinglestep: single step trap already clear\n");
			context.EFlags&= ~((DWORD)EFLAGS_SINGLE_STEP);
			if(SetThreadContext(hThread, &context))
				result = true;
			else
				logerror("\tclearsinglestep: SetThreadContext failed: %s\n");
		}
		else
			logerror("\tclearsinglestep: GetThreadContext failed: %s\n");
		ResumeThread(hThread);
	}
	else
		log("\tclearsinglestep: SuspendThread failed\n");

	return result;
}


