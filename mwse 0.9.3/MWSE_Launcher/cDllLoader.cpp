#include "StdAfx.h"

#include <psapi.h>
#include <malloc.h>

#include "cDllLoader.h"
#include "ModuleVersion.h"

static const char * const morrowindLauncher = "Morrowind Launcher.exe";
static const char * const morrowindRegistryHive = "Software\\Bethesda Softworks\\Morrowind";
static const char * const morrowindRegistryInstallKey = "Installed Path";
static const char * const morrowindExeSlash = "\\morrowind.exe";    // used in trimming exe from module path

static const char * const mwseDLL = "MWSE.DLL";

bool cDllLoader::LaunchMorrowind()
{
    bool result = false;
	//Thanks for the idea Timeslip :)
    result = 0 != CreateProcess(const_cast<char *>(morrowindLauncher),
        const_cast<char *>(morrowindLauncher), 0, 0, false, NORMAL_PRIORITY_CLASS,0,0,&sSi,&sPi);
	if(!result)
	{
	//Fallback to a registry search
    	HKEY registry_key;

		if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,morrowindRegistryHive,0,KEY_READ,&registry_key)==ERROR_SUCCESS)
	    {
            DWORD length;
            // get required length
		    RegQueryValueEx(registry_key,morrowindRegistryInstallKey,0,0,NULL,&length);
            char *location = reinterpret_cast<char *>(alloca(length+1));
            location[length] = '\0';
		    RegQueryValueEx(registry_key, const_cast<char *>(morrowindRegistryInstallKey),
                0,0,
                reinterpret_cast<LPBYTE>(location),
                &length);
            std::string mw_launcher = location + std::string("\\") + morrowindLauncher;
		    result = 0 != CreateProcess(mw_launcher.c_str(),
                const_cast<char *>(mw_launcher.c_str()),0,0,false,NORMAL_PRIORITY_CLASS,0,location,&sSi,&sPi);
	    }
	    RegCloseKey(registry_key);
    }

    return result;
}

bool cDllLoader::LaunchMorrowindCommandline(char* vCommandline)
{

	return 0 != CreateProcess(vCommandline, vCommandline, 0, 0, false, NORMAL_PRIORITY_CLASS, 0, 0, &sSi, &sPi);
}

bool cDllLoader::mInjectDll(HWND windowHandle)
{
    DWORD ProcID;
	GetWindowThreadProcessId(windowHandle,&ProcID);
    bool result = false;
	HANDLE morrowindProcess = 
        OpenProcess(PROCESS_CREATE_THREAD|PROCESS_QUERY_INFORMATION|PROCESS_VM_OPERATION|PROCESS_VM_WRITE|PROCESS_VM_READ,
		            false,ProcID);

	if(morrowindProcess)
	{
		size_t hookMemoryBlock = (size_t) VirtualAllocEx(morrowindProcess,0,8192,MEM_COMMIT,PAGE_EXECUTE_READWRITE);

		if(hookMemoryBlock)
		{
            // MWSE.DLL is assumed to be in the current directory.
            // (With the detection of the Morrowind location above and below,
            //  this means MWSE doesn't have to be installed in the Morrowind
            //  directory.)
            char buffer[1024];
            GetCurrentDirectory(sizeof buffer, buffer);

            HMODULE kernel32Handle = GetModuleHandle("kernel32.dll");
            void *libraryAddress=reinterpret_cast<void *>(GetProcAddress(kernel32Handle,
                                                                         "LoadLibraryA"));

            std::string mwsePath = buffer + std::string("\\") + mwseDLL;
        	DWORD bytesWritten;
            WriteProcessMemory(morrowindProcess,(LPVOID)(hookMemoryBlock+5),
                mwsePath.c_str(),mwsePath.size(),&bytesWritten);

            // hookCode contains code to invoke LoadLibrary.
        	BYTE vHookCode[5];
			vHookCode[0]=0xE9;
			*((size_t*)&vHookCode[1])=reinterpret_cast<size_t>(libraryAddress)-(hookMemoryBlock+5);

			WriteProcessMemory(morrowindProcess, reinterpret_cast<LPVOID>(hookMemoryBlock),
                vHookCode, sizeof(vHookCode), &bytesWritten);

			HANDLE injectorThread =
                CreateRemoteThread(morrowindProcess,0,0,(LPTHREAD_START_ROUTINE)hookMemoryBlock,
                                   (void *)(hookMemoryBlock+5),0,0);

			if(injectorThread)
			{
				switch(WaitForSingleObject(injectorThread, 5000))
				{
				case WAIT_OBJECT_0:
					break;
				case WAIT_ABANDONED:
					break;
				case WAIT_TIMEOUT:
					break;
				}
				CloseHandle(injectorThread);
            }

            // See if MWSE.dll was actually injected into the process.
            DWORD needed;
            EnumProcessModules(morrowindProcess, NULL, 0, &needed);
            HMODULE *list = reinterpret_cast<HMODULE *>(alloca(needed * sizeof (HMODULE)));
            EnumProcessModules(morrowindProcess, list, needed, &needed);
            size_t i;
            bool loaded = false;
            for (i = 0; i < needed/sizeof *list && !loaded; i++) {
                if (GetModuleBaseName(morrowindProcess, list[i], buffer, sizeof(buffer))) {
                    if (stricmp(buffer, mwseDLL) == 0) {
                        loaded = true;
                    }
                }
            }

            if (loaded) {
                // Determine the directory of Morrowind.exe. This will be where the
                // MWSE log is located.
                int length = GetModuleFileNameEx(morrowindProcess, NULL, buffer, sizeof(buffer));
                morrowindVersion = ModuleVersion::getModuleVersion(buffer).getVersionString();
                // strip 'morrowind.exe' from buffer
                int endIndex = length - strlen(morrowindExeSlash);
                if (stricmp(buffer + endIndex, morrowindExeSlash) == 0) {
                    buffer[endIndex] = '\0';
                }
                runningModuleLocation = buffer;

                injectedMWSEVersion = ModuleVersion::getModuleVersion(mwsePath).getVersionString();
                result = true;
            }
			VirtualFreeEx(morrowindProcess,(LPVOID)hookMemoryBlock,8192,MEM_RELEASE);
		}
		
		CloseHandle(morrowindProcess);
	}
    return result;
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