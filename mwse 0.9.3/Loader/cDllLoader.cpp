#include"cDllLoader.h"

void cDllLoader::mInitMorrowind()
{
	vMorroWin=FindWindow("Morrowind","Morrowind");

	if(!vMorroWin)
	{
		if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,"Software\\Bethesda Softworks\\Morrowind",0,KEY_READ,&vKeyRes)!=ERROR_SUCCESS)
			printf("Could not locate Morrowind Installation, You may have a corrupted install, Or no install at all \n");
		else
		{
			vSizeOfBuf=1000;

			RegQueryValueEx(vKeyRes,"Installed Path",0,0,(BYTE *)vMorroLauncherLocation,&vSizeOfBuf);
			sprintf(vMorroLauncherFormattedLocation,"%s\\Morrowind Launcher.exe",vMorroLauncherLocation);
			printf("Morrowind Located At: %s\n",vMorroLauncherFormattedLocation);
			
			if(!CreateProcess(vMorroLauncherFormattedLocation,vMorroLauncherFormattedLocation,0,0,false,NORMAL_PRIORITY_CLASS,0,0,&sSi,&sPi))
				printf("Could not start Morrowind Launcher.exe\n");
		}
		RegCloseKey(vKeyRes);

		while(!vMorroWin)
		{
			Sleep(20);
			vMorroWin=FindWindow("Morrowind","Morrowind");
		}
	}

	vMorroID=GetWindowThreadProcessId(vMorroWin,&vMorroID);
}

void cDllLoader::mInjectDll(DWORD ProcID)
{
	vProcess=OpenProcess(PROCESS_CREATE_THREAD|PROCESS_QUERY_INFORMATION|PROCESS_VM_OPERATION|PROCESS_VM_WRITE|PROCESS_VM_READ,
		false,ProcID);

	if(vProcess)
	{
		vBaseHook=(DWORD)VirtualAllocEx(vProcess,0,8192,MEM_COMMIT,PAGE_EXECUTE_READWRITE);

		if(vBaseHook)
		{
			vLoadLibraryAddr=(DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"LoadLibraryA");

			printf("vBaseHook= 0x%X\n",vBaseHook);
			printf("vLoadLibraryAddr= 0x%X\n",vLoadLibraryAddr);

			WriteProcessMemory(vProcess,(LPVOID)(vBaseHook+5),"MWSE.dll",9,&vBytesWritten);

			vHookCode[0]=0xE9;
			*((DWORD*)&vHookCode[1])=vLoadLibraryAddr-(vBaseHook+5);

			WriteProcessMemory(vProcess, (LPVOID)vBaseHook, vHookCode, sizeof(vHookCode), &vBytesWritten);

			vThread=CreateRemoteThread(vProcess,0,0,(LPTHREAD_START_ROUTINE)vBaseHook,(void *)(vBaseHook+5),0,0);

			if(vThread)
			{
				switch(WaitForSingleObject(vThread, 5000))
				{
				case WAIT_OBJECT_0:
					printf("hook thread complete\n");
					break;
				case WAIT_ABANDONED:
					printf("Process::InstallHook: waiting for thread = WAIT_ABANDONED\n");
					break;
				case WAIT_TIMEOUT:
					printf("Process::InstallHook: waiting for thread = WAIT_TIMEOUT\n");
					break;
				}
				CloseHandle(vThread);
			}
			else //vThread
				printf("Could Not Create Thread Error->%d\n",GetLastError());

			VirtualFreeEx(vProcess,(LPVOID)vBaseHook,8192,MEM_RELEASE);
		}
		else //vBaseHook
			printf("Could Not Allocate Memory For Hook->%d\n",GetLastError());
		
		CloseHandle(vProcess);
	}
	else //vProccess
		printf("Could Not Open Process->%d\n",GetLastError());
}

cDllLoader::cDllLoader()
{
	//Fill it with zeros(Easier than nullifying each member manually)
	ZeroMemory(&sSi,sizeof(STARTUPINFO));

	sSi.cb=sizeof(STARTUPINFO);
}

cDllLoader::~cDllLoader()
{
}