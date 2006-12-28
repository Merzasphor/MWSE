
#include "TES3MACHINE.h"
#include "TES3SCRIPTEXTENDER.h"
#include "LOG.h"
#include "DEBUGGING.h"
/*
#ifdef DEBUG

int main(void)
{
	char* logname= "MWScriptExtender.log";
	LOG::open(logname);	
	DWORD type=NPC;	
	
	TES3MACHINE scriptmachine(0,(void*)0x0400000);
	TES3REFERENCE ref;
	VMPTR<TES3REFERENCE> ptr(scriptmachine,&ref);
	scriptmachine.run();

	LOG::log("Finished Ok\n");	
	return 0;
}

#else
*/
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

//#endif
