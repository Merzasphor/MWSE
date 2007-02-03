#ifndef _ERR_CDLLLOADER
#define _ERR_CDLLLOADER
#define _CRT_SECURE_NO_DEPRECATE
/*********************************************\
* AnthonyG:                                   *
* Class that contains members to load the DLL *
* Please add funcs to this class as needed    *
\*********************************************/

#include<Windows.h>

#include <string>

#pragma warning(push)
#pragma warning(disable: 4290) // C++ exception specification ignored

class cDllLoader
{
public:
    class LoadException : public std::runtime_error {
    public:
        LoadException(std::string details):
          runtime_error(details)
          {
          }
    };

	//Start up Morrowind. Guess what? Tis now directory dependent.(I.E. Place it in your desktop folder if you want!)
	//Fills MorroID with Proc ID for use with InjectDll;
	void LaunchMorrowind() throw(LoadException);

	//run program from commandline, and just sit until Morrowind starts
	void LaunchMorrowindCommandline(char* commandline) throw(LoadException);

	//Inject DLL 
	void mInjectDll(HWND windowHandle) throw(LoadException);

    std::string getMorrowindDirectory(void) const
    {
        return runningModuleLocation;
    }
    std::string getInjectedMWSEVersion(void) const
    {
        return injectedMWSEVersion;
    }
    std::string getMorrowindVersion(void) const
    {
        return morrowindVersion;
    }
    cDllLoader();
	~cDllLoader();

private:
	//Process items
	STARTUPINFO sSi; //See constructor definition
	PROCESS_INFORMATION sPi;
    std::string runningModuleLocation;
    std::string injectedMWSEVersion;
    std::string morrowindVersion;

    LoadException *reportError(const char *source, bool addLastError=false);
};

#pragma warning(pop)

#endif //_ERR_CDLLLOADER