//FuncExtender.cpp

#include "FUNCEXTENDER.h"
#include "TES3MEMMAP.h"

//this function calls the original function you want to run using the correct opcode
//you'll need to set parameters yourself, this ONLY calls the correct command
bool FUNCEXTENDER::CallOriginalFunction(TES3MACHINE& machine, OPCODE originalopcode)
{
	Context context = machine.GetFlow(); //get the currect 'flow' (registerstates...)
	context.Edx = originalopcode; //set the Edx register to the 'originalopcode' opcode.
	context.Eip = (DWORD)reltolinear(RUNFUNCOPCODETEST); //change the Eip register (instruction pointer) to ...
	//...the converted (from relative to linear), RUNFUNCOPCODETEST (don't know what that is yet...) ...
	//...i think it's the location of the function that will accept the opcode in the Edx register, and check if ...
	//...the correct function exists, and run if yes.
	machine.SetFlow(context); //and set the new flow, so the game will use it.
	
	return true;
}
