//Main.cpp

#include "TES3MACHINE.h"
#include "TES3SCRIPTEXTENDER.h"
#include "LOG.h"
#include "DEBUGGING.h"

int main(int argc, char* argv[])
{
	char* logname= "MWScriptExtender.log";
	LOG::open(logname);		
	
	TES3SCRIPTEXTENDER app;

	int result= app.main(argc,argv);
	if(!result)
		LOG::log("Finished Ok\n");	
	else
		LOG::log("Exited with error code: %d\n",result);
		
	return result;
}
