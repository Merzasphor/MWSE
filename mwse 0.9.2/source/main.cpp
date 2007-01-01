//Main.cpp

#include "TES3MACHINE.h"
#include "TES3SCRIPTEXTENDER.h"
#include "LOG.h"
#include "DEBUGGING.h"

int main(int argc, char* argv[])
{
	char* logname= "MWScriptExtender.log"; //logfile path, don't change because i can break some mods...
	LOG::open(logname);		
	
	TES3SCRIPTEXTENDER app; //let's create an instance of the actual working part

	int result= app.main(argc,argv); //run the main function
	if(!result) //check for error coding...
		LOG::log("Finished Ok\n");	
	else
		LOG::log("Exited with error code: %d\n",result);
		
	return result; //and quit the program
}
