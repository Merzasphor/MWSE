#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define _ERROR
#define _MESSAGE

static void InjectDLL(DWORD pid) {
	HANDLE	process = OpenProcess(
		PROCESS_CREATE_THREAD|PROCESS_QUERY_INFORMATION|PROCESS_VM_OPERATION|PROCESS_VM_WRITE|PROCESS_VM_READ,false,pid);
	if(process) {
		DWORD	hookBase = (DWORD)VirtualAllocEx(process, NULL, 8192, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if(hookBase) {
			DWORD	loadLibraryAAddr = (DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");

			_MESSAGE("hookBase = %08X", hookBase);
			_MESSAGE("loadLibraryAAddr = %08X", loadLibraryAAddr);

			DWORD	bytesWritten;
			WriteProcessMemory(process, (LPVOID)(hookBase + 5), "MWSE.dll" , 9, &bytesWritten);

			BYTE	hookCode[5];

			hookCode[0] = 0xE9;
			*((DWORD*)&hookCode[1]) = loadLibraryAAddr - (hookBase + 5);

			WriteProcessMemory(process, (LPVOID)(hookBase), hookCode, sizeof(hookCode), &bytesWritten);

			HANDLE	thread = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)hookBase, (void *)(hookBase + 5), 0, NULL);
			if(thread)
			{
					switch(WaitForSingleObject(thread, 5000))
					{
						case WAIT_OBJECT_0:
							_MESSAGE("hook thread complete");
							break;

						case WAIT_ABANDONED:
							_ERROR("Process::InstallHook: waiting for thread = WAIT_ABANDONED");
							break;

						case WAIT_TIMEOUT:
							_ERROR("Process::InstallHook: waiting for thread = WAIT_TIMEOUT");
							break;
					}

				CloseHandle(thread);
			}
			else
				_ERROR("CreateRemoteThread failed (%d)", GetLastError());

			VirtualFreeEx(process, (LPVOID)hookBase, 8192, MEM_RELEASE);
		}
		else
			_ERROR("Process::InstallHook: couldn't allocate memory in target process");

		CloseHandle(process);
	}
	else
		_ERROR("Process::InstallHook: couldn't get process handle");
}

void main()
{
	HWND mwwin = FindWindow("Morrowind", "Morrowind");
	if(!mwwin) {
		STARTUPINFO startup_info = { sizeof(STARTUPINFO), NULL, NULL, NULL, 
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, 0, 0, 0 };
		PROCESS_INFORMATION proc_info;
		if(!CreateProcess("Morrowind Launcher.exe", "Morrowind Launcher.exe", 0, 0, false, NORMAL_PRIORITY_CLASS, 
			0, 0, &startup_info, &proc_info)) _ERROR("Could not launch 'Morrowind Launcher.exe'");
	}
	while(!mwwin) {
		Sleep(20);
		mwwin = FindWindow("Morrowind", "Morrowind");
	}

	DWORD mwpid;
	GetWindowThreadProcessId(mwwin, &mwpid);

	InjectDLL(mwpid);
}

