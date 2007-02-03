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

void cDllLoader::LaunchMorrowind() throw(cDllLoader::LoadException)
{
    bool failure;
	//Thanks for the idea Timeslip :)
    failure = 0 == CreateProcess(const_cast<char *>(morrowindLauncher),
        const_cast<char *>(morrowindLauncher), 0, 0, false, NORMAL_PRIORITY_CLASS,0,0,&sSi,&sPi);
    if(failure) {
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
            RegCloseKey(registry_key);

            std::string mw_launcher = location + std::string("\\") + morrowindLauncher;
		    failure = 0 == CreateProcess(mw_launcher.c_str(),
                const_cast<char *>(mw_launcher.c_str()),0,0,false,NORMAL_PRIORITY_CLASS,0,location,&sSi,&sPi);
            if (failure) {
                throw reportError("Could not create process", true);
            }
        } else {
            RegCloseKey(registry_key);
            throw reportError("Could not find Morrowind installation directory");
        }
    }
}

void cDllLoader::LaunchMorrowindCommandline(char* vCommandline) throw(cDllLoader::LoadException)
{

    if (!CreateProcess(vCommandline, vCommandline, 0, 0, false, NORMAL_PRIORITY_CLASS, 0, 0, &sSi, &sPi)) {
        throw reportError("Could not start Morrowind");
    }
}

void cDllLoader::mInjectDll(HWND windowHandle) throw(cDllLoader::LoadException)
{
    DWORD ProcID;
	GetWindowThreadProcessId(windowHandle,&ProcID);
    bool result = false;
	HANDLE morrowindProcess = 
        OpenProcess(PROCESS_CREATE_THREAD|PROCESS_QUERY_INFORMATION|PROCESS_VM_OPERATION|PROCESS_VM_WRITE|PROCESS_VM_READ,
		            false,ProcID);
    if (morrowindProcess == NULL) {
        throw reportError("Could not get Morrowind process", true);
    }

    // MWSE.DLL is assumed to be in the current directory.
    // (With the detection of the Morrowind location above and below,
    //  this means MWSE doesn't have to be installed in the Morrowind
    //  directory.)
    char buffer[1024];
    DWORD status = GetCurrentDirectory(sizeof buffer, buffer);
    if (status == 0) {
        CloseHandle(morrowindProcess);
        throw reportError("Could not get current directory", true);
    }

    HMODULE kernel32Handle = GetModuleHandle("kernel32.dll");
    if (kernel32Handle == NULL) {
        CloseHandle(morrowindProcess);
        throw reportError("Could not get kernel32", true);
    }

    // NOTE: This depends on the address of LoadLibraryA being the same in
    // the remote process and this process. Given that the library is kernel32.dll,
    // this is likely to be the case (and does seem to be for Morrowind). However,
    // if not, then one could use EnumProcessModules to find kernel32.dll and
    // account for the different base address.
    void *libraryAddress=reinterpret_cast<void *>(GetProcAddress(kernel32Handle,
                                                                 "LoadLibraryA"));
    if (libraryAddress == NULL) {
        CloseHandle(morrowindProcess);
        throw reportError("Could not get LoadLibraryA", true);
    }

    std::string mwsePath = buffer + std::string("\\") + mwseDLL;

    LPVOID hookMemoryBlock = VirtualAllocEx(morrowindProcess,0,
        mwsePath.size() + 1,MEM_COMMIT,PAGE_EXECUTE_READWRITE);
    if (hookMemoryBlock == NULL) {
        CloseHandle(morrowindProcess);
        throw reportError("Could not allocate Morrowind memory", true);
    }

    DWORD bytesWritten;
    if (!WriteProcessMemory(morrowindProcess, hookMemoryBlock,
        mwsePath.c_str(),mwsePath.size()+1,&bytesWritten)) {
        VirtualFreeEx(morrowindProcess,hookMemoryBlock,mwsePath.size()+1,MEM_RELEASE);
        CloseHandle(morrowindProcess);
        throw reportError("Could not write to Morrowind memory", true);
    }


	HANDLE injectorThread =
        CreateRemoteThread(morrowindProcess,0,0,
                           reinterpret_cast<LPTHREAD_START_ROUTINE>(libraryAddress),
                           reinterpret_cast<void *>(hookMemoryBlock),
                           0, 0);
    if (injectorThread == NULL) {
        VirtualFreeEx(morrowindProcess,hookMemoryBlock,mwsePath.size()+1,MEM_RELEASE);
        CloseHandle(morrowindProcess);
        throw reportError("Could not start thread in Morrowind", true);
    }

	(void )WaitForSingleObject(injectorThread, INFINITE);   // ignore return code

    DWORD loadedAddress;
    ::GetExitCodeThread(injectorThread, &loadedAddress );
	CloseHandle(injectorThread);

    VirtualFreeEx(morrowindProcess,hookMemoryBlock,mwsePath.size()+1,MEM_RELEASE);

    if (loadedAddress == 0) {
        CloseHandle(morrowindProcess);
        throw reportError("MWSE.DLL failed to load in Morrowind"); // cannot get error
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
        if (length == 0) {
    	    CloseHandle(morrowindProcess);
            throw reportError("Could not get filename of Morrowind", true);
        }
        try {
            morrowindVersion = ModuleVersion::getModuleVersion(buffer).getVersionString();
        } catch (std::string e) {
            CloseHandle(morrowindProcess);
            throw reportError(e.c_str());
        }

        // strip 'morrowind.exe' from buffer
        int endIndex = length - strlen(morrowindExeSlash);
        if (stricmp(buffer + endIndex, morrowindExeSlash) == 0) {
            buffer[endIndex] = '\0';
        }
        runningModuleLocation = buffer;

        injectedMWSEVersion = ModuleVersion::getModuleVersion(mwsePath).getVersionString();

        CloseHandle(morrowindProcess);

    } else {
        CloseHandle(morrowindProcess);

        throw reportError("MWSE.DLL not loaded in Morrowind");
    }
}

cDllLoader::LoadException *cDllLoader::reportError(const char *source, bool addLastError)
{
    std::string message;
    if (addLastError) {
        LPTSTR lpMsgBuf;

        DWORD dw = GetLastError(); 

        FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | 
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            dw,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            reinterpret_cast<LPSTR>(&lpMsgBuf),
            0, NULL );

        message = std::string(source) + ": " +
            std::string(lpMsgBuf);

        LocalFree(lpMsgBuf);
    } else {
        message = std::string(source);
    }

    return new LoadException(message);

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