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

class cDllLoader
{
private:
	//Later members may want to use these
	//Process items
	STARTUPINFO sSi; //See constructor definition
	PROCESS_INFORMATION sPi;
    std::string runningModuleLocation;
    std::string injectedMWSEVersion;
    std::string morrowindVersion;
public:

	//Start up Morrowind. Guess what? Tis now directory dependent.(I.E. Place it in your desktop folder if you want!)
	//Fills MorroID with Proc ID for use with InjectDll;
	bool LaunchMorrowind();

	//run program from commandline, and just sit until Morrowind starts
	bool LaunchMorrowindCommandline(char* commandline);

	//Inject DLL 
	bool mInjectDll(HWND windowHandle);

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
};

#endif //_ERR_CDLLLOADER