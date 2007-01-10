#include"cDllLoader.h"

void cDllLoader::mInitMorrowind()
{
	vMorroWin=FindWindow("Morrowind","Morrowind");

	if(!vMorroWin)
	{
		//Thanks for the idea Timeslip :)
		if(CreateProcess("Morrowind Launcher.exe","Morrowind Launcher.exe",0,0,false,NORMAL_PRIORITY_CLASS,0,0,&sSi,&sPi))
		{
			iUiAction.mConsolePut("Morrowind Found In Current Directory");
			while(!vMorroWin)
			{
				Sleep(20);
				vMorroWin=FindWindow("Morrowind","Morrowind");
			}
		}
		//Fallback to a registry search
		else
		{
			iUiAction.mConsolePut("Morrowind Not Found In Current Directory");
			iUiAction.mConsolePut("Performing RegSearch");
			if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,"Software\\Bethesda Softworks\\Morrowind",0,KEY_READ,&vKeyRes)!=ERROR_SUCCESS)
				iUiAction.mConsolePut("Could not locate Morrowind Installation");
		    else
		    {
			    vSizeOfBuf=1000;

			    RegQueryValueEx(vKeyRes,"Installed Path",0,0,(BYTE *)vMorroLauncherLocation,&vSizeOfBuf);
			    sprintf(vMorroLauncherFormattedLocation,"%s\\Morrowind Launcher.exe",vMorroLauncherLocation);
				iUiAction.mConsolePut("Morrowind Located At: ");
				iUiAction.mConsolePut(vMorroLauncherFormattedLocation);
			
			    if(!CreateProcess(vMorroLauncherFormattedLocation,vMorroLauncherFormattedLocation,0,0,false,NORMAL_PRIORITY_CLASS,0,vMorroLauncherLocation,&sSi,&sPi))
					iUiAction.mConsolePut("Could not start Morrowind Launcher.exe");
				else
				{
					while(!vMorroWin)
					{
						Sleep(20);
						vMorroWin=FindWindow("Morrowind","Morrowind");
					}
				}
		    }
		    RegCloseKey(vKeyRes);
	    }		   
	}
	//it works now :)
	GetWindowThreadProcessId(vMorroWin,&vMorroID);
}

void cDllLoader::mInjectDll(DWORD ProcID)
{
	vProcess=OpenProcess(PROCESS_ALL_ACCESS,false,ProcID);

	if(vProcess)
	{
		vBaseHook=(DWORD)VirtualAllocEx(vProcess,0,8192,MEM_COMMIT,PAGE_EXECUTE_READWRITE);

		if(vBaseHook)
		{
			vLoadLibraryAddr=(DWORD)GetProcAddress(GetModuleHandle("kernel32.dll"),"LoadLibraryA");

			sprintf(vHexVars,"vBaseHook= 0x%X\n",vBaseHook);
			iUiAction.mConsolePut(vHexVars);
			sprintf(vHexVars,"vLoadLibraryAddr= 0x%X\n",vLoadLibraryAddr);
			iUiAction.mConsolePut(vHexVars);

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
					iUiAction.mConsolePut("Hook thread complete");
					break;
				case WAIT_ABANDONED:
					iUiAction.mConsolePut("Process::InstallHook: waiting for thread = WAIT_ABANDONED");
					break;
				case WAIT_TIMEOUT:
					iUiAction.mConsolePut("Process::InstallHook: waiting for thread = WAIT_TIMEOUT");
					break;
				}
				CloseHandle(vThread);
			}
			else //vThread
				iUiAction.mConsolePut("Could Not Create Thread");

			VirtualFreeEx(vProcess,(LPVOID)vBaseHook,8192,MEM_RELEASE);
		}
		else //vBaseHook
			iUiAction.mConsolePut("Could Not Allocate Memory For Hook");
		
		CloseHandle(vProcess);
	}
	else //vProccess
		iUiAction.mConsolePut("Could Not Open Process");
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